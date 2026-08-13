/* Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
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

/*
 * Shared EEPROM sizing for all Epomaker FS026 (ES32, Cortex-M0) keyboards.
 *
 * These boards emulate EEPROM inside two 8 KB internal-flash pages via the
 * custom driver in user_eeprom.c. For the wear-levelling page transfer to
 * work, every live 16-bit variable must fit inside a single page, which caps
 * the usable space at roughly 4092 bytes.
 *
 * We provision enough for 8 VIA layers on the largest FS026 matrix
 * (6x16 = 96 keys => 192 bytes/layer):
 *
 *     dynamic keymap start (eeconfig + VIA config) : 46
 *     8 layers * 192 bytes                         : 1536  -> ends at 1582
 *     macro region                                 : ~400 bytes (up to MAX_ADDR)
 *
 * EEPROM_SIZE is kept at DYNAMIC_KEYMAP_EEPROM_MAX_ADDR + 65 on purpose: the
 * driver reserves 64 "private" bytes (NB_OF_PRIVATE_VAR) and refuses to persist
 * any variable whose index is >= EEPROM_SIZE, so this margin guarantees every
 * keymap/macro byte is actually written to flash.
 *
 * Smaller boards (e.g. th40, 5x12 = 60 keys => 120 bytes/layer) simply use less
 * of the same budget.
 *
 * These defaults cannot simply be raised for everyone: the FS026 only has 16 KB
 * of RAM and user_eeprom.c keeps a shadow copy of the whole EEPROM in it
 * (EEPROM_SIZE + 64 bytes of .bss), so a board like th85 already links with
 * under 1 KB to spare. A board that needs a bigger budget -- and can afford the
 * RAM -- therefore defines its own values *before* including this header, e.g.:
 *
 *     #define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 3007
 *     #define EEPROM_SIZE                    3072
 *     #include "fs026_eeprom.h"
 *
 * Check the headroom afterwards with `arm-none-eabi-size` on the .elf: data+bss
 * must stay below 16384 bytes, and leaving a few hundred bytes free is wise.
 */

#pragma once

#ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif
#ifndef DYNAMIC_KEYMAP_EEPROM_MAX_ADDR
#    define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1983
#endif
#ifndef EEPROM_SIZE
#    define EEPROM_SIZE 2048
#endif
