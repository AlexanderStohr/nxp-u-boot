/*
 * Copyright 2013 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale Vybrid vf610twr board.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/imx-regs.h>
#include <config_cmd_default.h>

#define CONFIG_SAC58R
#define CONFIG_PALLADIUM

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_MACH_TYPE		4146 /* MATT: to change later */

#define CONFIG_SKIP_LOWLEVEL_INIT

/* Enable passing of ATAGs */
#define CONFIG_CMDLINE_TAG

#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 2 * 1024 * 1024)

#define CONFIG_BOARD_EARLY_INIT_F

#define CONFIG_FSL_LPUART
#define LPUART_BASE			UART1_BASE_ADDR /* MATT: to check wich UART to use */

/* Allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_SYS_UART_PORT		(1)
#define CONFIG_BAUDRATE			115200

#undef CONFIG_CMD_IMLS

#define CONFIG_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CONFIG_SYS_FSL_ESDHC_NUM	1

#define CONFIG_SYS_FSL_ERRATUM_ESDHC111

#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_CMD_EXT2		/* EXT2 Support			*/
#define CONFIG_CMD_FAT		/* FAT support			*/
#define CONFIG_DOS_PARTITION

#if 0 /* MATT: enable Ethernet in a second step */
/* Ethernet config */
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RMII
#define CONFIG_FEC_MXC_PHYADDR          0
#define CONFIG_PHYLIB
#define CONFIG_PHY_MICREL
#endif

#if 0 /* MATT: enable I2C in a second step */
/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_HARD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_BASE		I2C0_BASE_ADDR
#define CONFIG_SYS_I2C_SPEED		100000
#endif

#if 0 /* MATT: enable NAND in a second step */
#define CONFIG_SYS_USE_NAND */

#ifdef CONFIG_SYS_USE_NAND
/* Nand Flash Configs */
#define	CONFIG_CMD_NAND
#define CONFIG_JFFS2_NAND
#define MTD_NAND_FSL_NFC_SWECC 1
#define CONFIG_NAND_FSL_NFC
#define CONFIG_SYS_NAND_BASE		0x400E0000
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define NAND_MAX_CHIPS			CONFIG_SYS_MAX_NAND_DEVICE
#define CONFIG_SYS_NAND_SELECT_DEVICE
#define CONFIG_SYS_64BIT_VSPRINTF  /* needed for nand_util.c */
#endif
#endif

#define CONFIG_BOOTDELAY		3

#define CONFIG_LOADADDR			0x82000000
#define CONFIG_SYS_TEXT_BASE		0x3f408000 // OCRAM - need to check on final RM version


#if 0 /* MATT: no need to have env settings now, will enable later when booting Linux */
#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"uimage=uImage\0" \
	"console=ttyLP1\0" \
	"fdt_high=0xffffffff\0" \
	"initrd_high=0xffffffff\0" \
	"fdt_file=vf610-twr.dtb\0" \
	"fdt_addr=0x81000000\0" \
	"boot_fdt=try\0" \
	"ip_dyn=yes\0" \
	"mmcdev=" __stringify(CONFIG_SYS_MMC_ENV_DEV) "\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p2 rootwait rw\0" \
	"update_sd_firmware_filename=u-boot.imx\0" \
	"update_sd_firmware=" \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"if mmc dev ${mmcdev}; then "	\
			"if ${get_cmd} ${update_sd_firmware_filename}; then " \
				"setexpr fw_sz ${filesize} / 0x200; " \
				"setexpr fw_sz ${fw_sz} + 1; "	\
				"mmc write ${loadaddr} 0x2 ${fw_sz}; " \
			"fi; "	\
		"fi\0" \
	"mmcargs=setenv bootargs console=${console},${baudrate} " \
		"root=${mmcroot}\0" \
	"loadbootscript=" \
		"fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; " \
		"source\0" \
	"loaduimage=fatload mmc ${mmcdev}:${mmcpart} ${loadaddr} ${uimage}\0" \
	"loadfdt=fatload mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootm ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootm; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootm; " \
		"fi;\0" \
	"netargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/nfs " \
	"ip=dhcp nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
		"netboot=echo Booting from net ...; " \
		"run netargs; " \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"${get_cmd} ${uimage}; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if ${get_cmd} ${fdt_addr} ${fdt_file}; then " \
				"bootm ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootm; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootm; " \
		"fi;\0"

#define CONFIG_BOOTCOMMAND \
	   "mmc dev ${mmcdev}; if mmc rescan; then " \
		   "if run loadbootscript; then " \
			   "run bootscript; " \
		   "else " \
			   "if run loaduimage; then " \
				   "run mmcboot; " \
			   "else run netboot; " \
			   "fi; " \
		   "fi; " \
	   "else run netboot; fi"

#endif //#if 0

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"=> "
#undef CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE		\
			(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_CMDLINE_EDITING

#define CONFIG_CMD_MEMTEST
#define CONFIG_SYS_MEMTEST_START	0x80010000
#define CONFIG_SYS_MEMTEST_END		0x87C00000

#define CONFIG_SYS_LOAD_ADDR		CONFIG_LOADADDR
#define CONFIG_SYS_HZ			1000

/*
 * Stack sizes
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE		(128 * 1024)	/* regular stack */

/* Physical memory map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			(0x80000000)
#define PHYS_SDRAM_SIZE			(128 * 1024 * 1024)

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(8 * 1024)
#define CONFIG_ENV_IS_IN_MMC

#define CONFIG_ENV_OFFSET		(12 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV		0

#define CONFIG_OF_LIBFDT
#define CONFIG_CMD_BOOTZ

#endif
