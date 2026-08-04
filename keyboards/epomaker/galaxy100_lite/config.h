/* Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
 * Copyright 2025 EPOMAKER <https://github.com/Epomaker>
 * Copyright 2021 QMK <https://github.com/qmk/qmk_firmware>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define MATRIX_UNSELECT_DRIVE_HIGH
#define CORTEX_ENABLE_WFI_IDLE FALSE

/* Ensure we jump to bootloader if the RESET keycode was pressed */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

#ifndef NOP_FUDGE
#    define NOP_FUDGE 0.4
#endif

// Shared EEPROM sizing + layer count for all Epomaker FS026 boards.
// This board overrides the defaults: its 7x16 matrix costs 224 bytes per VIA
// layer, so 8 layers alone eat 1792 of the shared 1983-byte budget and leave
// almost nothing for macros (the stock firmware, with 4 layers, offered 194
// bytes). Growing the budget to 3072 gives ~1.1 KB of macro storage:
//
//     dynamic keymap start (eeconfig + VIA config) :   46
//     8 layers * 7 * 16 * 2 bytes                  : 1792  -> ends at 1838
//     8 layers * 1 encoder * 2 * 2 bytes           :   32  -> ends at 1870
//     macro region (up to DYNAMIC_KEYMAP_EEPROM_MAX_ADDR) : 1138
//
// The cost is RAM: user_eeprom.c shadows the whole EEPROM in .bss, so this adds
// 1 KB to a 16 KB budget. Measured headroom after the bump is ~900 bytes.
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 3007
#define EEPROM_SIZE 3072
#include "fs026_eeprom.h"
#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)
#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)
#define EECONFIG_USER_DATA_SIZE 4
#define EECONFIG_KB_DATA_SIZE 1
#define TRANSIENT_EEPROM_SIZE 4096

#define RGB_MATRIX_LED_COUNT 101
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_AFTER_TIMEOUT 0
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_SLEEP

// BLE configuration for Galaxy100 Lite
#define USER_BLE_ID (0X0100) // Galaxy100 Lite BLE ID
#define USER_BLE1_NAME "Galaxy100Lite-1"
#define USER_BLE2_NAME "Galaxy100Lite-2"
#define USER_BLE3_NAME "Galaxy100Lite-3"

/* LED Index Definitions required by lib/rdmctmzt_common/keyboard_common.h */
#define LED_CAP_INDEX 56        // Caps Lock indicator (Caps key)
#define LED_WIN_L_INDEX 90      // Win Lock indicator (left GUI key)
#define LED_BATT_INDEX 19       // Low battery warning (number row '1' key)
#define LED_BLE_1_INDEX 38      // 'Q' key position for BLE 1
#define LED_BLE_2_INDEX 39      // 'W' key position for BLE 2
#define LED_BLE_3_INDEX 40      // 'E' key position for BLE 3
#define LED_2P4G_INDEX 41       // 'R' key position for 2.4G
#define LED_USB_INDEX 42        // 'T' key position for USB
// Only used when LED_CONNECTION_INDICATOR_ENABLE is turned on. LED 17 sits on
// the unpopulated (5,8) matrix slot next to the knob, so it never doubles as a
// key backlight.
#define LED_CONNECTION_INDEX 17
