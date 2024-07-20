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

#ifndef GPIO_PARAMS_H
#define GPIO_PARAMS_H

#include "board.h"
#include "saul/periph.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief    GPIO pin configuration
 */
static const  saul_gpio_params_t saul_gpio_params[] =
{
    {
        .name = "LED_STATUS",
        .pin = LED_STATUS,
        .mode = GPIO_OUT
    },
    {
        .name = "LED_USB_LINK",
        .pin = LED_USB_LINK,
        .mode = GPIO_OUT
    },
    {
        .name = "LED_LORA_LINK",
        .pin = LED_LORA_LINK,
        .mode = GPIO_OUT
    },
    {
        .name = "Wireless ID1",
        .pin  = BTN0_PIN,
        .mode = BTN0_MODE,
        .flags = SAUL_GPIO_INVERTED,
    },
    {
        .name = "Wireless ID2",
        .pin  = BTN1_PIN,
        .mode = BTN1_MODE,
        .flags = SAUL_GPIO_INVERTED,
    },
    {
        .name = "Wireless ID3",
        .pin  = BTN2_PIN,
        .mode = BTN2_MODE,
        .flags = SAUL_GPIO_INVERTED,
    },
    {
        .name = "Wireless ID4",
        .pin  = BTN3_PIN,
        .mode = BTN3_MODE,
        .flags = SAUL_GPIO_INVERTED,
    },
};

#ifdef __cplusplus
}
#endif

#endif /* GPIO_PARAMS_H */
/** @} */
