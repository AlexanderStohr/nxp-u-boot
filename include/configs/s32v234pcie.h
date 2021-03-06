/*
 * Copyright 2015-2016 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale S32V234PCIE board.
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

#undef CONFIG_RUN_FROM_IRAM_ONLY

/* S32V234PCIE has LPDDR2 */
#define CONFIG_S32V234_LPDDR2

#define CONFIG_RUN_FROM_DDR0
#undef CONFIG_RUN_FROM_DDR1

/* PCIE board has 2x256 MB DDR chips, DDR0 and DDR1, u-boot is using just one */
#define DDR_SIZE		(256 * 1024 * 1024)

/* Enable DDR handshake at functional reset event */
#define CONFIG_DDR_HANDSHAKE_AT_RESET

#define CONFIG_MACH_TYPE		4146

/* Config CACHE */
#define CONFIG_CMD_CACHE

/* Enable DCU QoS fix */
#define CONFIG_DCU_QOS_FIX

#define CONFIG_ARCH_EARLY_INIT_R

/* System Timer */
#define CONFIG_SYS_GENERIC_TIMER
/* #define CONFIG_SYS_PIT_TIMER */

#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC_BASE_ADDR

/* #define CONFIG_CMD_EXT2 EXT2 Support */

#define CONFIG_FEC_XCV_TYPE     RGMII
#define CONFIG_PHYLIB

/* CONFIG_PHY_RGMII_DIRECT_CONNECTED should be enabled when
 * BCM switch is configured.
 */
/* #define CONFIG_PHY_RGMII_DIRECT_CONNECTED */
#ifdef CONFIG_PHY_RGMII_DIRECT_CONNECTED
#define CONFIG_BCM_SPEED    SPEED_1000
#else
#define CONFIG_FEC_MXC_PHYADDR  1
#define CONFIG_PHY_BROADCOM
#endif

#define FDT_FILE s32v234-pcie.dtb

#define CONFIG_LOADADDR		LOADADDR

#define CONFIG_BOARD_EXTRA_ENV_SETTINGS \
	"ipaddr=10.0.0.100\0" \
	"serverip=10.0.0.1\0" \
	"netmask=255.255.255.0\0" \
	"nfsbootargs=setenv bootargs console=${console},${baudrate} " \
		"root=/dev/nfs rw " \
		"ip=${ipaddr}:${serverip}::${netmask}::eth0:off " \
		"nfsroot=${serverip}:/tftpboot/rfs,nolock \0" \
	"loadtftpimage=tftp ${loadaddr} ${image};\0" \
	"loadtftpfdt=tftp ${fdt_addr} ${fdt_file};\0" \
	"nfsboot=echo Booting from net using tftp and nfs...; " \
		"run nfsbootargs;"\
		"run loadtftpimage; run loadtftpfdt;"\
		"${boot_mtd} ${loadaddr} - ${fdt_addr};\0"\


#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE - CONFIG_SYS_TEXT_OFFSET)

/* #define CONFIG_CMD_PCI */
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCIE_EP_MODE
#define CONFIG_GICSUPPORT
#define CONFIG_USE_IRQ
#define CONFIG_CMD_IRQ
#endif

/* we include this file here because it depends on the above definitions */
#include <configs/s32v234_common.h>

#endif
