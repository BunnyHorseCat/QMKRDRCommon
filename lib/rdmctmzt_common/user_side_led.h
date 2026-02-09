/* Copyright 2024 Finalkey
 * Copyright 2024 LiWenLiu <https://github.com/LiuLiuQMK>
 * Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
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

#include "quantum.h"

// Side LED feature flag - define in keyboard's config.h to enable
#ifndef SIDE_LED_ENABLE
#    define SIDE_LED_ENABLE 1
#endif

#if SIDE_LED_ENABLE

// Default Side LED configuration - can be overridden in keyboard's config.h
#    ifndef LED_SIDE_INDEX
#        define LED_SIDE_INDEX 0
#    endif

#    ifndef SIDE_LED_COUNT
#        define SIDE_LED_COUNT 1
#    endif

// Side LED effect modes (matching VIA config)
#    define SIDE_MODE_NONE 0
#    define SIDE_MODE_WAVE 1
#    define SIDE_MODE_WAVE1 2
#    define SIDE_MODE_WAVE2 3
#    define SIDE_MODE_FIXED_WAVE 4
#    define SIDE_MODE_WAVE_RGB 5
#    define SIDE_MODE_SPECTRUM 6
#    define SIDE_MODE_BREATHE 7
#    define SIDE_MODE_BREATHE_RGB 8
#    define SIDE_MODE_LIGHT 9

// Side LED functions
void Side_Led_Set_Color(uint8_t r, uint8_t g, uint8_t b);
void Side_Led_Effect_Solid(void);
void Side_Led_Effect_Breathe(void);
void Side_Led_Effect_Breathe_RGB(void);
void Side_Led_Effect_Spectrum(void);
void Side_Led_Effect_Wave(void);
void Side_Led_Effect_Wave_RGB(void);
void Side_Led_Update(void);

// Side LED keycode processing - returns true if keycode was handled
bool process_side_led_keycodes(uint16_t keycode, keyrecord_t *record);

// VIA custom handler for Side LED settings (channel 2 - rgblight channel)
void via_side_led_command(uint8_t *data, uint8_t length);

#endif // SIDE_LED_ENABLE
