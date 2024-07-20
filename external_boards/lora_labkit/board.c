/*
 * Copyright (C) 2024 ???
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_lora_labkit
 * @{
 *
 * @file
 * @brief       Board specific definitions for the LoRa LabKit v1.0
 *
 * @author      klim4685e <kjiumer@gmail.com>
 */


#include <assert.h>
#include "kernel_defines.h"
#include "cpu.h"
#include "board.h"
#include "periph/gpio.h"

#if IS_USED(MODULE_SX126X_STM32WL)
#include "sx126x.h"
#endif

void board_init(void)
{
#if IS_USED(MODULE_SX126X_STM32WL)
        /* Initialize the GPIO control for RF 3-port switch (SP3T) */
        gpio_init(FE_CTRL1, GPIO_OUT);
        gpio_init(FE_CTRL2, GPIO_OUT);
#endif
    gpio_init(LED_STATUS, GPIO_OUT);
    gpio_init(LED_USB_LINK, GPIO_OUT);
    gpio_set(LED_STATUS);
}

#if IS_USED(MODULE_SX126X_STM32WL)
/**
 * @brief Callback to set RF switch mode
 *
 * This function sets the GPIO's wired to the SP3T RF Switch. LoRa-E5-dev
 * supports two modes of operation.
 */
void lora_e5_dev_sx126x_set_rf_mode(sx126x_t *dev, sx126x_rf_mode_t rf_mode)
{
    (void) dev;
    switch (rf_mode) {
    case SX126X_RF_MODE_RX:
        gpio_set(FE_CTRL1);
        gpio_clear(FE_CTRL2);
        #ifdef SX126X_LED_PIN
        gpio_clear(SX126X_LED_PIN);
        #endif
        break;
    case SX126X_RF_MODE_TX_HPA:
        gpio_clear(FE_CTRL1);
        gpio_set(FE_CTRL2);
    #ifdef SX126X_LED_PIN
        gpio_set(SX126X_LED_PIN);
    #endif
        break;
    default:
        /* SX126X_RF_MODE_TX_LPA is not supported */
        assert(0);
        break;
    }
}
#endif
