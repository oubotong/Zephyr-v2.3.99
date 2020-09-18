/*
 * Copyright (c) 2018, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <fsl_iomuxc.h>
#include <fsl_gpio.h>

#if DT_NODE_HAS_STATUS(DT_NODELABEL(enet), okay) && CONFIG_NET_L2_ETHERNET
static gpio_pin_config_t enet_gpio_config = {
	.direction = kGPIO_DigitalOutput,
	.outputLogic = 0,
	.interruptMode = kGPIO_NoIntmode
};
#endif

static int mimxrt1020_evk_init(struct device *dev)
{
	ARG_UNUSED(dev);

	CLOCK_EnableClock(kCLOCK_Iomuxc);
	CLOCK_EnableClock(kCLOCK_IomuxcSnvs);

	/* LED */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_05_GPIO1_IO05, 0);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_05_GPIO1_IO05,
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	/* SW0 */
	IOMUXC_SetPinMux(IOMUXC_SNVS_WAKEUP_GPIO5_IO00, 0);

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpuart1), okay) && CONFIG_SERIAL
	/* LPUART1 TX/RX */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_06_LPUART1_TX, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_07_LPUART1_RX, 0);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_06_LPUART1_TX,
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_07_LPUART1_RX,
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpuart2), okay) && CONFIG_SERIAL
	/* LPUART2 TX/RX */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_LPUART2_TX, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_09_LPUART2_RX, 0);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_08_LPUART2_TX,
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_09_LPUART2_RX,
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpi2c1), okay) && CONFIG_I2C
	/* LPI2C1 SCL, SDA */
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_14_LPI2C1_SCL, 1);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_15_LPI2C1_SDA, 1);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_14_LPI2C1_SCL,
			    IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_15_LPI2C1_SDA,
			    IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(lpi2c4), okay) && CONFIG_I2C
	/* LPI2C4 SCL, SDA */
	IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_02_LPI2C4_SCL, 1);
	IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_03_LPI2C4_SDA, 1);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_02_LPI2C4_SCL,
			    IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));

	IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_03_LPI2C4_SDA,
			    IOMUXC_SW_PAD_CTL_PAD_PUS(3) |
			    IOMUXC_SW_PAD_CTL_PAD_PKE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_ODE_MASK |
			    IOMUXC_SW_PAD_CTL_PAD_SPEED(2) |
			    IOMUXC_SW_PAD_CTL_PAD_DSE(6));
#endif

#if DT_NODE_HAS_STATUS(DT_NODELABEL(enet), okay) && CONFIG_NET_L2_ETHERNET
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_04_GPIO1_IO04, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_GPIO1_IO22, 0U);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_10_ENET_RDATA00, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_09_ENET_RDATA01, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_11_ENET_RX_EN, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_ENET_TDATA00, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_ENET_TDATA01, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_ENET_TX_EN, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_08_ENET_REF_CLK1, 1);
	IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_ENET_RX_ER, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_41_ENET_MDC, 0);
	IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_40_ENET_MDIO, 0);

	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_04_GPIO1_IO04, 0xB0A9u);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_06_GPIO1_IO22, 0xB0A9u);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_10_ENET_RDATA00, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_09_ENET_RDATA01, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_11_ENET_RX_EN, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_14_ENET_TDATA00, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_15_ENET_TDATA01, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_ENET_TX_EN, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_08_ENET_REF_CLK1, 0x31);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_ENET_RX_ER, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_41_ENET_MDC, 0xB0E9);
	IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_40_ENET_MDIO, 0xB829);

	IOMUXC_EnableMode(IOMUXC_GPR, kIOMUXC_GPR_ENET1TxClkOutputDir, true);

	/* Initialize ENET_INT GPIO */
	GPIO_PinInit(GPIO1, 4, &enet_gpio_config);
	GPIO_PinInit(GPIO1, 22, &enet_gpio_config);

	/* pull up the ENET_INT before RESET. */
	GPIO_WritePinOutput(GPIO1, 22, 1);
	GPIO_WritePinOutput(GPIO1, 4, 0);
#endif

	return 0;
}

#if DT_NODE_HAS_STATUS(DT_NODELABEL(enet), okay) && CONFIG_NET_L2_ETHERNET
static int mimxrt1020_evk_phy_reset(struct device *dev)
{
	/* RESET PHY chip. */
	k_busy_wait(USEC_PER_MSEC * 10U);
	GPIO_WritePinOutput(GPIO1, 4, 1);

	return 0;
}
#endif

SYS_INIT(mimxrt1020_evk_init, PRE_KERNEL_1, 0);
#if DT_NODE_HAS_STATUS(DT_NODELABEL(enet), okay) && CONFIG_NET_L2_ETHERNET
SYS_INIT(mimxrt1020_evk_phy_reset, PRE_KERNEL_2, 0);
#endif