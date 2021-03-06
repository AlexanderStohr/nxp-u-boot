/*
 * Copyright 2015 Freescale Semiconductor, Inc.
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


#ifndef __ARCH_ARM_MACH_S32V234_SIUL_H__
#define __ARCH_ARM_MACH_S32V234_SIUL_H__

#include "ddr.h"

#define SIUL2_MIDR1				(SIUL2_BASE_ADDR + 0x00000004)
#define SIUL2_MIDR2				(SIUL2_BASE_ADDR + 0x00000008)
#define SIUL2_DISR0				(SIUL2_BASE_ADDR + 0x00000010)
#define SIUL2_DIRER0				(SIUL2_BASE_ADDR + 0x00000018)
#define SIUL2_DIRSR0				(SIUL2_BASE_ADDR + 0x00000020)
#define SIUL2_IREER0				(SIUL2_BASE_ADDR + 0x00000028)
#define SIUL2_IFEER0				(SIUL2_BASE_ADDR + 0x00000030)
#define SIUL2_IFER0				(SIUL2_BASE_ADDR + 0x00000038)

#define SIUL2_IFMCR_BASE			(SIUL2_BASE_ADDR + 0x00000040)
#define SIUL2_IFMCRn(i)				(SIUL2_IFMCR_BASE + 4 * (i))

#define SIUL2_IFCPR				(SIUL2_BASE_ADDR + 0x000000C0)

/* SIUL2_MSCR specifications as stated in Reference Manual:
 * 0 - 359 Output Multiplexed Signal Configuration Registers
 * 512- 1023 Input Multiplexed Signal Configuration Registers */
#define SIUL2_MSCR_BASE			(SIUL2_BASE_ADDR + 0x00000240)
#define SIUL2_MSCRn(i)			(SIUL2_MSCR_BASE + 4 * (i))

#define SIUL2_IMCR_BASE			(SIUL2_BASE_ADDR + 0x00000A40)
#define SIUL2_IMCRn(i)			(SIUL2_IMCR_BASE +  4 * (i))

#define SIUL2_GPDO_BASE			(SIUL2_BASE_ADDR + 0x00001300)
#define SIUL2_GPDOn(i)			(SIUL2_GPDO_BASE + 4 * (i))

#define SIUL2_GPDI_BASE			(SIUL2_BASE_ADDR + 0x00001500)
#define SIUL2_GPDIn(i)			(SIUL2_GPDI_BASE + 4 * (i))

#define SIUL2_PGPDO_BASE		(SIUL2_BASE_ADDR + 0x00001700)
#define SIUL2_PGPDOn(i)			(SIUL2_PGPDO_BASE +  2 * (i))

#define SIUL2_PGPDI_BASE		(SIUL2_BASE_ADDR + 0x00001740)
#define SIUL2_PGPDIn(i)			(SIUL2_PGPDI_BASE + 2 * (i))

#define SIUL2_MPGPDO_BASE		(SIUL2_BASE_ADDR + 0x00001780)
#define SIUL2_MPGPDOn(i)		(SIUL2_MPGPDO_BASE + 4 * (i))

/* GPIO */
/* 163 GPIOs in output mode, we assume the GPIO number is in range */
#define SIUL2_GPDO_for_GPIO(i)		(((i) & (~0x3))>>2)
#define SIUL2_GPDO_PDO_off_for_GPIO(i)	(((i) & (0x3))
#define SIUL2_PDOn(i)			(SIUL2_GPDOn(SIUL2_GPDO_for_GPIO(i) + \
						SIUL2_GPDO_PDO_off_for_GPIO(i))
#define SIUL2_GPIO_VALUE0		(0x00)
#define SIUL2_GPIO_VALUE1		(0x01)

/* SIUL2_MSCR masks */
#define SIUL2_MSCR_DDR_DO_TRIM(v)	((v) & 0xC0000000)
#define SIUL2_MSCR_DDR_DO_TRIM_MIN	(0 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_50PS	(1 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_100PS	(2 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_150PS	(3 << 30)


#define SIUL2_MSCR_DDR_INPUT(v)		((v) & 0x20000000)
#define SIUL2_MSCR_DDR_INPUT_CMOS	(0 << 29)
#define SIUL2_MSCR_DDR_INPUT_DIFF_DDR	(1 << 29)

#define SIUL2_MSCR_DDR_SEL(v)		((v) & 0x18000000)
#define SIUL2_MSCR_DDR_SEL_DDR3		(0 << 27)
#define SIUL2_MSCR_DDR_SEL_LPDDR2	(2 << 27)

#define SIUL2_MSCR_DDR_ODT(v)		((v) & 0x07000000)
#define SIUL2_MSCR_DDR_ODT_120ohm	(1 << 24)
#define SIUL2_MSCR_DDR_ODT_60ohm	(2 << 24)
#define SIUL2_MSCR_DDR_ODT_40ohm	(3 << 24)
#define SIUL2_MSCR_DDR_ODT_30ohm	(4 << 24)
#define SIUL2_MSCR_DDR_ODT_24ohm	(5 << 24)
#define SIUL2_MSCR_DDR_ODT_20ohm	(6 << 24)
#define SIUL2_MSCR_DDR_ODT_17ohm	(7 << 24)

#define SIUL2_MSCR_DCYCLE_TRIM(v)	((v) & 0x00C00000)
#define SIUL2_MSCR_DCYCLE_TRIM_NONE	(0 << 22)
#define SIUL2_MSCR_DCYCLE_TRIM_LEFT	(1 << 22)
#define SIUL2_MSCR_DCYCLE_TRIM_RIGHT	(2 << 22)

#define SIUL2_MSCR_OBE(v)		((v) & 0x00200000)
#define SIUL2_MSCR_OBE_EN		(1 << 21)

#define SIUL2_MSCR_ODE(v)		((v) & 0x00100000)
#define SIUL2_MSCR_ODE_EN		(1 << 20)

#define SIUL2_MSCR_IBE(v)		((v) & 0x00010000)
#define SIUL2_MSCR_IBE_EN		(1 << 19)

#define SIUL2_MSCR_HYS(v)		((v) & 0x00400000)
#define SIUL2_MSCR_HYS_EN		(1 << 18)

#define SIUL2_MSCR_INV(v)		((v) & 0x00020000)
#define SIUL2_MSCR_INV_EN		(1 << 17)

#define SIUL2_MSCR_PKE(v)		((v) & 0x00010000)
#define SIUL2_MSCR_PKE_EN		(1 << 16)

#define SIUL2_MSCR_SRE(v)		((v) & 0x0000C000)
#define SIUL2_MSCR_SRE_SPEED_LOW_50	(0 << 14)
#define SIUL2_MSCR_SRE_SPEED_LOW_100	(1 << 14)
#define SIUL2_MSCR_SRE_SPEED_HIGH_100	(2 << 14)
#define SIUL2_MSCR_SRE_SPEED_HIGH_200	(3 << 14)


#define SIUL2_MSCR_PUE(v)		((v) & 0x00002000)
#define SIUL2_MSCR_PUE_EN		(1 << 13)

#define SIUL2_MSCR_PUS(v)		((v) & 0x00001800)
#define SIUL2_MSCR_PUS_100K_DOWN	(0 << 11)
#define SIUL2_MSCR_PUS_50K_DOWN		(1 << 11)
#define SIUL2_MSCR_PUS_100K_UP		(2 << 11)
#define SIUL2_MSCR_PUS_33K_UP		(3 << 11)

#define SIUL2_MSCR_DSE(v)			((v) & 0x00000700)
#define SIUL2_MSCR_DSE_240ohm		(1 << 8)
#define SIUL2_MSCR_DSE_120ohm		(2 << 8)
#define SIUL2_MSCR_DSE_80ohm		(3 << 8)
#define SIUL2_MSCR_DSE_60ohm		(4 << 8)
#define SIUL2_MSCR_DSE_48ohm		(5 << 8)
#define SIUL2_MSCR_DSE_40ohm		(6 << 8)
#define SIUL2_MSCR_DSE_34ohm		(7 << 8)

#define SIUL2_MSCR_CRPOINT_TRIM(v)	((v) & 0x000000C0)
#define SIUL2_MSCR_CRPOINT_TRIM_1	(1 << 6)

#define SIUL2_MSCR_SMC(v)			((v) & 0x00000020)
#define SIUL2_MSCR_MUX_MODE(v)		((v) & 0x0000000f)
#define SIUL2_MSCR_MUX_MODE_ALT0	(0x0)
#define SIUL2_MSCR_MUX_MODE_ALT1	(0x1)
#define SIUL2_MSCR_MUX_MODE_ALT2	(0x2)
#define SIUL2_MSCR_MUX_MODE_ALT3	(0x3)


/* UART settings */

/* UART0 */
#define SIUL2_UART0_TXD_PAD		12
#define SIUL2_UART0_MSCR_RXD_PAD	11
#define SIUL2_UART0_IMCR_RXD_PAD	200

/* UART1 */
#define SIUL2_UART1_TXD_PAD		14
#define SIUL2_UART1_MSCR_RXD_PAD	13
#define SIUL2_UART1_IMCR_RXD_PAD	202

#define SIUL2_UART_TXD		(SIUL2_MSCR_OBE_EN | SIUL2_MSCR_PUS_100K_UP | SIUL2_MSCR_DSE_60ohm |	\
				SIUL2_MSCR_SRE_SPEED_LOW_100 | SIUL2_MSCR_MUX_MODE_ALT1)

#define SIUL2_UART_MSCR_RXD	(SIUL2_MSCR_PUE_EN | SIUL2_MSCR_IBE_EN | SIUL2_MSCR_DCYCLE_TRIM_RIGHT)
#define SIUL2_UART_IMCR_RXD	(SIUL2_MSCR_MUX_MODE_ALT2)

/* CAN0 */
#define SIUL2_CAN_FD0_TXD_PAD		2
#define SIUL2_CAN_FD0_MSCR_RXD_PAD	3
#define SIUL2_CAN_FD0_IMCR_RXD_PAD	188

/* CAN1 */
#define SIUL2_CAN_FD1_TXD_PAD		42
#define SIUL2_CAN_FD1_MSCR_RXD_PAD	43
#define SIUL2_CAN_FD1_IMCR_RXD_PAD	189

#define SIUL2_CAN_TXD	(SIUL2_MSCR_OBE_EN | SIUL2_MSCR_PUS_50K_DOWN | SIUL2_MSCR_DSE_34ohm |\
				SIUL2_MSCR_PUE_EN | SIUL2_MSCR_MUX_MODE_ALT1)
#define SIUL2_CAN_MSCR_RXD	(SIUL2_MSCR_PUE_EN | SIUL2_MSCR_IBE_EN | SIUL2_MSCR_PUS_50K_DOWN)
#define SIUL2_CAN_FD0_IMCR_RXD	(SIUL2_MSCR_MUX_MODE_ALT2)
#define SIUL2_CAN_FD1_IMCR_RXD	(SIUL2_MSCR_MUX_MODE_ALT3)

/* uSDHC settings */
#define SIUL2_USDHC_PAD_CTRL_BASE	(SIUL2_MSCR_SRE_SPEED_HIGH_200 | SIUL2_MSCR_OBE_EN |	\
						SIUL2_MSCR_DSE_34ohm | SIUL2_MSCR_PKE_EN | SIUL2_MSCR_IBE_EN |	\
						SIUL2_MSCR_PUS_100K_UP | SIUL2_MSCR_PUE_EN )
#define SIUL2_USDHC_PAD_CTRL_CMD	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT1)
#define SIUL2_USDHC_PAD_CTRL_CLK	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT2)
#define SIUL2_USDHC_PAD_CTRL_DAT0_3	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT2)
#define SIUL2_USDHC_PAD_CTRL_DAT4_7	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C settings */
/* I2C0 - Serial Data Input */
#define SIUL2_PAD_CTRL_I2C0_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C0_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT3)


/* I2C0 - Serial Clock Input */
#define SIUL2_PAD_CTRL_I2C0_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C0_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C1 - Serial Data Input */
#define SIUL2_PAD_CTRL_I2C1_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C1_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C1 - Serial Clock Input */
#define SIUL2_PAD_CTRL_I2C1_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C1_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C2 - Serial Data Input */
#define SIUL2_PAD_CTRL_I2C2_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT1 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C2_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2)

/* I2C2 - Serial Clock Input */
#define SIUL2_PAD_CTRL_I2C2_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT1 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
						SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C2_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2)


/* QuadSPI settings */

#define SIUL2_PK6_MSCR	150
#define SIUL2_PK6_MSCR_MUX_MODE_QSPI_A_SCK	SIUL2_MSCR_MUX_MODE_ALT1

#define SIUL2_PK5_MSCR	149
#define SIUL2_PK5_MSCR_MUX_MODE_QSPI_A_CS0	SIUL2_MSCR_MUX_MODE_ALT1

#define SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA_BASE	\
		(SIUL2_MSCR_DSE_34ohm |		\
		SIUL2_MSCR_SRE_SPEED_HIGH_200 |	\
		SIUL2_MSCR_IBE_EN |		\
		SIUL2_MSCR_OBE_EN)
#define SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA0_3	\
		(SIUL2_MSCR_MUX_MODE_ALT1 |	\
		SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA_BASE)
#define SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA4_7	\
		(SIUL2_MSCR_MUX_MODE_ALT2 |	\
		SIUL2_PORT_MSCR_CTRL_QSPI_A_DATA_BASE)

#define SIUL2_PORT_IMCR_MUX_MODE_QSPI_A_DATA0_7	SIUL2_MSCR_MUX_MODE_ALT2

/* 0x0009E000 + SIUL2_MSCR_PUS_100K_DOWN */
#define SIUL2_PORT_MSCR_CTRL_QSPI_A_DQS	\
		(SIUL2_MSCR_IBE_EN |	\
		SIUL2_MSCR_PKE_EN |	\
		SIUL2_MSCR_SRE_SPEED_HIGH_200 |	\
		SIUL2_MSCR_PUE_EN |	\
		SIUL2_MSCR_PUS_100K_DOWN)

#define SIUL2_PORT_MSCR_CTRL_QSPI_CLK_BASE	\
		(	\
		SIUL2_MSCR_DSE_34ohm |	\
		SIUL2_MSCR_PUS_100K_UP |	\
		SIUL2_MSCR_SRE_SPEED_HIGH_200 |	\
		SIUL2_MSCR_OBE_EN)

#define SIUL2_PK11_MSCR	155
#define SIUL2_PK11_MSCR_MUX_MODE_QSPI_A_DATA3	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK11_IMCR_QSPI_A_DATA3	(823 - 512)
#define SIUL2_PK11_IMCR_MUX_MODE_QSPI_A_DATA3	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK10_MSCR	154
#define SIUL2_PK10_MSCR_MUX_MODE_QSPI_A_DATA2	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK10_IMCR_QSPI_A_DATA2	(822 - 512)
#define SIUL2_PK10_IMCR_MUX_MODE_QSPI_A_DATA2	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK9_MSCR	153
#define SIUL2_PK9_MSCR_MUX_MODE_QSPI_A_DATA1	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK9_IMCR_QSPI_A_DATA1	(821 - 512)
#define SIUL2_PK9_IMCR_MUX_MODE_QSPI_A_DATA1	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK8_MSCR	152
#define SIUL2_PK8_MSCR_MUX_MODE_QSPI_A_DATA0	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK8_IMCR_QSPI_A_DATA0	(820 - 512)
#define SIUL2_PK8_IMCR_MUX_MODE_QSPI_A_DATA0	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK7_MSCR	151
#define SIUL2_PK7_IMCR_QSPI_A_DQS	(819 - 512)
#define SIUL2_PK7_IMCR_MUX_MODE_QSPI_A_DQS	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PL2_MSCR	162
#define SIUL2_PL2_MSCR_MUX_MODE_QSPI_B_DATA3	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PL2_MSCR_MUX_MODE_QSPI_A_DATA7	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL2_IMCR_QSPI_A_DATA7	(827 - 512)
#define SIUL2_PL2_IMCR_QSPI_B_DATA3	(832 - 512)
#define SIUL2_PL2_IMCR_MUX_MODE_QSPI_A_DATA7	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL2_IMCR_MUX_MODE_QSPI_B_DATA3	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PL1_MSCR	161
#define SIUL2_PL1_MSCR_MUX_MODE_QSPI_B_DATA2	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PL1_MSCR_MUX_MODE_QSPI_A_DATA6	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL1_IMCR_QSPI_A_DATA6	(826 - 512)
#define SIUL2_PL1_IMCR_QSPI_B_DATA2	(831 - 512)
#define SIUL2_PL1_IMCR_MUX_MODE_QSPI_A_DATA6	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL1_IMCR_MUX_MODE_QSPI_B_DATA2	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PL0_MSCR	160
#define SIUL2_PL0_MSCR_MUX_MODE_QSPI_B_DATA1	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PL0_MSCR_MUX_MODE_QSPI_A_DATA5	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL0_IMCR_QSPI_A_DATA5	(825 - 512)
#define SIUL2_PL0_IMCR_QSPI_B_DATA1	(830 - 512)
#define SIUL2_PL0_IMCR_MUX_MODE_QSPI_A_DATA5	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PL0_IMCR_MUX_MODE_QSPI_B_DATA1	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK15_MSCR	159
#define SIUL2_PK15_MSCR_MUX_MODE_QSPI_B_DATA0	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK15_MSCR_MUX_MODE_QSPI_A_DATA4	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PK15_IMCR_QSPI_A_DATA4	(824 - 512)
#define SIUL2_PK15_IMCR_QSPI_B_DATA0	(829 - 512)
#define SIUL2_PK15_IMCR_MUX_MODE_QSPI_A_DATA4	SIUL2_MSCR_MUX_MODE_ALT2
#define SIUL2_PK15_IMCR_MUX_MODE_QSPI_B_DATA0	SIUL2_MSCR_MUX_MODE_ALT2

#define SIUL2_PK13_MSCR	157
#define SIUL2_PK13_MSCR_MUX_MODE_QSPI_B_SCK	SIUL2_MSCR_MUX_MODE_ALT1
#define SIUL2_PK13_MSCR_MUX_MODE_QSPI_CK2	SIUL2_MSCR_MUX_MODE_ALT2

#endif /*__ARCH_ARM_MACH_S32V234_SIUL_H__ */
