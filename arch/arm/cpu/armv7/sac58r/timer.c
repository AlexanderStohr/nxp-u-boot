/*
 * Copyright 2013 Freescale Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/io.h>
#include <div64.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>

static struct pit_reg *cur_pit = (struct pit_reg *)PIT_BASE_ADDR;

DECLARE_GLOBAL_DATA_PTR;

#define TIMER_LOAD_VAL	0xffffffff

static inline unsigned long long tick_to_time(unsigned long long tick)
{
	tick *= CONFIG_SYS_HZ;
	do_div(tick, mxc_get_clock(MXC_BUS_CLK));

	return tick;
}

static inline unsigned long long us_to_tick(unsigned long long usec)
{
	usec = usec * mxc_get_clock(MXC_BUS_CLK)  + 999999;
	do_div(usec, 1000000);

	return usec;
}

int timer_init(void)
{
	__raw_writel(0, &cur_pit->mcr);

	__raw_writel(TIMER_LOAD_VAL, &cur_pit->ldval1);
	__raw_writel(0, &cur_pit->tctrl1);
	__raw_writel(1, &cur_pit->tctrl1);

	gd->arch.tbl = 0;
	gd->arch.tbu = 0;

	return 0;
}

unsigned long long get_ticks(void)
{
	ulong now = TIMER_LOAD_VAL - __raw_readl(&cur_pit->cval1);

	/* increment tbu if tbl has rolled over */
	if (now < gd->arch.tbl)
		gd->arch.tbu++;
	gd->arch.tbl = now;

	return (((unsigned long long)gd->arch.tbu) << 32) | gd->arch.tbl;
}

ulong get_timer_masked(void)
{
	return tick_to_time(get_ticks());
}

ulong get_timer(ulong base)
{
	return get_timer_masked() - base;
}

/* delay x useconds AND preserve advance timstamp value */
void __udelay(unsigned long usec)
{
	unsigned long long start;
	ulong tmo;

	start = get_ticks();			/* get current timestamp */
	tmo = us_to_tick(usec);			/* convert usecs to ticks */
	while ((get_ticks() - start) < tmo)
		;				/* loop till time has passed */
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk(void)
{
	return mxc_get_clock(MXC_BUS_CLK);
}
