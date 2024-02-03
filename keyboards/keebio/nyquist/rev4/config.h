// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_HAND_PIN GP23
#define USB_VBUS_PIN GP18
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP8
#define SERIAL_USART_RX_PIN GP9
#define SERIAL_USART_PIN_SWAP
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#define I2C_DRIVER I2CD0
#define I2C0_SDA_PIN GP4
#define I2C0_SCL_PIN GP5

// RGB Matrix
#define RGB_MATRIX_LED_COUNT 72
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
