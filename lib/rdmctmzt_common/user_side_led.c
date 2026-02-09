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

#include "rdmctmzt_common.h"

#if SIDE_LED_ENABLE

// Side LED animation state
static uint16_t side_animation_timer = 0;
static uint8_t  side_animation_step  = 0;

// Side LED effect functions
// Use rgb_matrix_driver_set_color directly to bypass RGB matrix enable state
void Side_Led_Set_Color(uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < SIDE_LED_COUNT; i++) {
        rgb_matrix_driver_set_color(LED_SIDE_INDEX + i, r, g, b);
    }
}

void Side_Led_Effect_Solid(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    HSV hsv = {Keyboard_Info.Side_Hue, Keyboard_Info.Side_Saturation, Keyboard_Info.Side_Brightness};
    RGB rgb = hsv_to_rgb(hsv);
    Side_Led_Set_Color(rgb.r, rgb.g, rgb.b);
}

void Side_Led_Effect_Breathe(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    // Breathing effect - varies brightness
    uint8_t speed_multiplier = (Keyboard_Info.Side_Speed + 1) * 10;
    uint8_t breath_val       = Led_Wave_Pwm_Tab[(side_animation_step * speed_multiplier / 10) % 128];
    uint8_t scaled_val       = (breath_val * Keyboard_Info.Side_Brightness) / 255;

    HSV hsv = {Keyboard_Info.Side_Hue, Keyboard_Info.Side_Saturation, scaled_val};
    RGB rgb = hsv_to_rgb(hsv);
    Side_Led_Set_Color(rgb.r, rgb.g, rgb.b);
}

void Side_Led_Effect_Breathe_RGB(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    // RGB breathing - cycles through hues while breathing
    uint8_t speed_multiplier = (Keyboard_Info.Side_Speed + 1) * 10;
    uint8_t breath_val       = Led_Wave_Pwm_Tab[(side_animation_step * speed_multiplier / 10) % 128];
    uint8_t scaled_val       = (breath_val * Keyboard_Info.Side_Brightness) / 255;
    uint8_t hue              = (side_animation_step * speed_multiplier / 5) % 256;

    HSV hsv = {hue, Keyboard_Info.Side_Saturation, scaled_val};
    RGB rgb = hsv_to_rgb(hsv);
    Side_Led_Set_Color(rgb.r, rgb.g, rgb.b);
}

void Side_Led_Effect_Spectrum(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    // Spectrum/rainbow cycle - smoothly cycles through all hues
    uint8_t speed_multiplier = (Keyboard_Info.Side_Speed + 1) * 5;
    uint8_t hue              = (side_animation_step * speed_multiplier / 5) % 256;

    HSV hsv = {hue, Keyboard_Info.Side_Saturation, Keyboard_Info.Side_Brightness};
    RGB rgb = hsv_to_rgb(hsv);
    Side_Led_Set_Color(rgb.r, rgb.g, rgb.b);
}

void Side_Led_Effect_Wave(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    // Wave effect - each LED slightly offset in brightness
    uint8_t speed_multiplier = (Keyboard_Info.Side_Speed + 1) * 10;

    for (uint8_t i = 0; i < SIDE_LED_COUNT; i++) {
        uint8_t offset     = (side_animation_step * speed_multiplier / 10 + i * 25) % 128;
        uint8_t wave_val   = Led_Wave_Pwm_Tab[offset];
        uint8_t scaled_val = (wave_val * Keyboard_Info.Side_Brightness) / 255;

        HSV hsv = {Keyboard_Info.Side_Hue, Keyboard_Info.Side_Saturation, scaled_val};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(LED_SIDE_INDEX + i, rgb.r, rgb.g, rgb.b);
    }
}

void Side_Led_Effect_Wave_RGB(void) {
    if (!Keyboard_Info.Side_On_Off) {
        Side_Led_Set_Color(0, 0, 0);
        return;
    }

    // Wave RGB - wave effect with cycling hues
    uint8_t speed_multiplier = (Keyboard_Info.Side_Speed + 1) * 10;

    for (uint8_t i = 0; i < SIDE_LED_COUNT; i++) {
        uint8_t offset     = (side_animation_step * speed_multiplier / 10 + i * 25) % 128;
        uint8_t wave_val   = Led_Wave_Pwm_Tab[offset];
        uint8_t scaled_val = (wave_val * Keyboard_Info.Side_Brightness) / 255;
        uint8_t hue        = (side_animation_step * speed_multiplier / 10 + i * 50) % 256;

        HSV hsv = {hue, Keyboard_Info.Side_Saturation, scaled_val};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_driver_set_color(LED_SIDE_INDEX + i, rgb.r, rgb.g, rgb.b);
    }
}

// Main Side LED update function - call from rgb_matrix_indicators_advanced_user
void Side_Led_Update(void) {
    // Update animation step (called from rgb_matrix_indicators)
    if (timer_elapsed(side_animation_timer) > 20) { // Update every 20ms
        side_animation_timer = timer_read();
        side_animation_step++;
        if (side_animation_step > 255) {
            side_animation_step = 0;
        }
    }

    // Apply the current effect
    switch (Keyboard_Info.Side_Mode) {
        case SIDE_MODE_NONE:
            Side_Led_Set_Color(0, 0, 0);
            break;
        case SIDE_MODE_WAVE:
        case SIDE_MODE_WAVE1:
        case SIDE_MODE_WAVE2:
        case SIDE_MODE_FIXED_WAVE:
            Side_Led_Effect_Wave();
            break;
        case SIDE_MODE_WAVE_RGB:
            Side_Led_Effect_Wave_RGB();
            break;
        case SIDE_MODE_SPECTRUM:
            Side_Led_Effect_Spectrum();
            break;
        case SIDE_MODE_BREATHE:
            Side_Led_Effect_Breathe();
            break;
        case SIDE_MODE_BREATHE_RGB:
            Side_Led_Effect_Breathe_RGB();
            break;
        case SIDE_MODE_LIGHT:
        default:
            Side_Led_Effect_Solid();
            break;
    }
}

// Process Side LED keycodes - call from process_record_user
// Returns true if keycode was handled (should return false from process_record_user)
bool process_side_led_keycodes(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SIDE_TOG:
            if (!record->event.pressed) {
                Keyboard_Info.Side_On_Off = !Keyboard_Info.Side_On_Off;
                Save_Flash_Set();
            }
            return true;
        case SIDE_MOD:
            if (!record->event.pressed) {
                Keyboard_Info.Side_Mode++;
                if (Keyboard_Info.Side_Mode > 9) {
                    Keyboard_Info.Side_Mode = 0;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_RMOD:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Mode == 0) {
                    Keyboard_Info.Side_Mode = 9;
                } else {
                    Keyboard_Info.Side_Mode--;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_HUI:
            if (!record->event.pressed) {
                Keyboard_Info.Side_Hue += 8;
                Save_Flash_Set();
            }
            return true;
        case SIDE_HUD:
            if (!record->event.pressed) {
                Keyboard_Info.Side_Hue -= 8;
                Save_Flash_Set();
            }
            return true;
        case SIDE_SAI:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Saturation <= 247) {
                    Keyboard_Info.Side_Saturation += 8;
                } else {
                    Keyboard_Info.Side_Saturation = 255;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_SAD:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Saturation >= 8) {
                    Keyboard_Info.Side_Saturation -= 8;
                } else {
                    Keyboard_Info.Side_Saturation = 0;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_VAI:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Brightness <= 247) {
                    Keyboard_Info.Side_Brightness += 8;
                } else {
                    Keyboard_Info.Side_Brightness = 255;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_VAD:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Brightness >= 8) {
                    Keyboard_Info.Side_Brightness -= 8;
                } else {
                    Keyboard_Info.Side_Brightness = 0;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_SPI:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Speed < 4) {
                    Keyboard_Info.Side_Speed++;
                }
                Save_Flash_Set();
            }
            return true;
        case SIDE_SPD:
            if (!record->event.pressed) {
                if (Keyboard_Info.Side_Speed > 0) {
                    Keyboard_Info.Side_Speed--;
                }
                Save_Flash_Set();
            }
            return true;
        default:
            return false; // Not a side LED keycode
    }
}

// VIA custom handler for Side LED settings (channel 2 - rgblight channel)
void via_side_led_command(uint8_t *data, uint8_t length) {
    // data[0] is the command ID
    // data[1] is the channel ID (4 = rgblight for side LED)
    // data[2] is the value ID
    // data[3+] is the value data

    uint8_t *command_id = &(data[0]);
    uint8_t *channel_id = &(data[1]);
    uint8_t *value_id   = &(data[2]);
    uint8_t *value_data = &(data[3]);

    // Only handle channel 4 (rgblight/side LED)
    if (*channel_id != 4) {
        return;
    }

    switch (*command_id) {
        case 0x07: // id_custom_set_value
            switch (*value_id) {
                case 1: // brightness
                    Keyboard_Info.Side_Brightness = value_data[0];
                    Save_Flash_Set();
                    break;
                case 2: // effect
                    Keyboard_Info.Side_Mode   = value_data[0];
                    Keyboard_Info.Side_On_Off = (value_data[0] > 0) ? 1 : 0;
                    Save_Flash_Set();
                    break;
                case 3: // effect speed
                    Keyboard_Info.Side_Speed = value_data[0];
                    Save_Flash_Set();
                    break;
                case 4: // color (HSV)
                    Keyboard_Info.Side_Hue        = value_data[0];
                    Keyboard_Info.Side_Saturation = value_data[1];
                    Save_Flash_Set();
                    break;
            }
            break;
        case 0x08: // id_custom_get_value
            switch (*value_id) {
                case 1: // brightness
                    value_data[0] = Keyboard_Info.Side_Brightness;
                    break;
                case 2: // effect
                    value_data[0] = Keyboard_Info.Side_On_Off ? Keyboard_Info.Side_Mode : 0;
                    break;
                case 3: // effect speed
                    value_data[0] = Keyboard_Info.Side_Speed;
                    break;
                case 4: // color (HSV)
                    value_data[0] = Keyboard_Info.Side_Hue;
                    value_data[1] = Keyboard_Info.Side_Saturation;
                    break;
            }
            break;
        case 0x09: // id_custom_save
            Save_Flash_Set();
            break;
    }
}

#endif // SIDE_LED_ENABLE
