/*
 * Copyright 2014-2015 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/arch/mc_me_regs.h>
#include "mp.h"

DECLARE_GLOBAL_DATA_PTR;

void *get_spin_tbl_addr(void)
{
	void *ptr = (void *)SECONDARY_CPU_BOOT_PAGE;

	/*
	 * Spin table is at the beginning of secondary boot page. It is
	 * copied to SECONDARY_CPU_BOOT_PAGE.
	 */
	ptr += (u64)&__spin_table - (u64)&secondary_boot_page;

	return ptr;
}

phys_addr_t determine_mp_bootpg(void)
{
	return (phys_addr_t)SECONDARY_CPU_BOOT_PAGE;
}

int fsl_s32v234_wake_seconday_cores(void)
{
	u64 *table = get_spin_tbl_addr();

	/* Clear spin table so that secondary processors
	 * observe the correct value after waking up from wfe.
	 */
	memset(table, 0, CONFIG_MAX_CPUS * ENTRY_SIZE);
	writew(0xFA, 0x4004A1CA);
	writew(0xFA, 0x4004A1C8);
	writew(0xFA, 0x4004A1CE);
	
	writel(0x3E820000 | 0x1, 0x4004A1E8);
	writel(0x3E820000 | 0x1, 0x4004A1EC);
	writel(0x3E820000 | 0x1, 0x4004A1F0);

	writel(0x40005AF0, 0x4004A004);
	writel(0x4000A50F, 0x4004A004);

	while( (readl(MC_ME_GS) & MC_ME_GS_S_MTRANS) != 0x00000000 );

	smp_kick_all_cpus();

	printf("All (%d) cores are up.\n", cpu_numcores());

	return 0;
}

int is_core_valid(unsigned int core)
{
	if (core == 0)
		return 0;

	return !!((1 << core) & cpu_mask());
}

int cpu_reset(int nr)
{
	puts("Feature is not implemented.\n");

	return 0;
}

int cpu_disable(int nr)
{
	puts("Feature is not implemented.\n");

	return 0;
}

int core_to_pos(int nr)
{
	u32 cores = cpu_mask();
	int i, count = 0;

	if (nr == 0) {
		return 0;
	} else if (nr >= hweight32(cores)) {
		puts("Not a valid core number.\n");
		return -1;
	}

	for (i = 1; i < 32; i++) {
		if (is_core_valid(i)) {
			count++;
			if (count == nr)
				break;
		}
	}

	return count;
}

int cpu_status(int nr)
{
	u64 *table;
	int valid;

	if (nr == 0) {
		table = (u64 *)get_spin_tbl_addr();
		printf("table base @ 0x%p\n", table);
	} else {
		valid = is_core_valid(nr);
		if (!valid)
			return -1;
		table = (u64 *)get_spin_tbl_addr() + nr * NUM_BOOT_ENTRY;
		printf("table @ 0x%p\n", table);
		printf("   addr - 0x%016llx\n", table[BOOT_ENTRY_ADDR]);
		printf("   r3   - 0x%016llx\n", table[BOOT_ENTRY_R3]);
		printf("   pir  - 0x%016llx\n", table[BOOT_ENTRY_PIR]);
	}

	return 0;
}

int cpu_release(int nr, int argc, char * const argv[])
{
	u64 boot_addr;
	u64 *table = (u64 *)get_spin_tbl_addr();
#ifndef CONFIG_FSL_SMP_RELEASE_ALL
	int valid;

	valid = is_core_valid(nr);
	if (!valid)
		return 0;

	table += nr * NUM_BOOT_ENTRY;
#endif
	boot_addr = simple_strtoull(argv[0], NULL, 16);
	table[BOOT_ENTRY_ADDR] = boot_addr;
	flush_dcache_range((unsigned long)table,
			   (unsigned long)table + SIZE_BOOT_ENTRY);
	asm volatile("dsb st");
	smp_kick_all_cpus();	/* only those with entry addr set will run */

	return 0;
}