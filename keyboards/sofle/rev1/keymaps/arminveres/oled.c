#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H // IWYU pragma: keep
#    include "oled_driver.h"
#    include "enums.h"

#    ifdef USE_WPM_OLED
// ================================================================================================
// WPM Calculator
// ================================================================================================
#        define WPM_GRAPH_SPEED_MAX 130.0f    // WPM value at the top of the graph window
#        define WPM_GRAPH_REFRESH_INTERVAL 80 // how often screen will be refreshed with WPM values; in milliseconds
#        define WPM_GRAPH_REFRESH_TIMEOUT 800 // how often screen will be refreshed with WPM values; in milliseconds
#        define WPM_GRAPH_LINE_THICKNESS 3    // determines thickness of graph line in pixels
#        if defined(OLED_BRIGHTNESS) && OLED_BRIGHTNESS < 100
#            define __WPM_GRAPH_BRIGHTNESS_DEFINED 1

#            define WPM_GRAPH_SPEED_HIGHLIGHT 50.0f // At what WPM screen brightness will start increasing
#            define WPM_GRAPH_BRIGHTNESS_MAX 255    // Max screen brightness
#        endif

#        define DISPLAY_WIDTH 32

static inline void render_wpm(void) {
    uint8_t   currwpm = 0;
    uint8_t   oldwpm  = 0;
    uint16_t  timer   = 0;
    const int elapsed = timer_elapsed(timer);

    // get current WPM value
    oldwpm  = currwpm;
    currwpm = get_current_wpm();

    if (elapsed > WPM_GRAPH_REFRESH_INTERVAL) {
        int i = 0;
        int y;
        // main calculation to plot graph line
        y = DISPLAY_WIDTH - ((currwpm / WPM_GRAPH_SPEED_MAX) * DISPLAY_WIDTH);

        // first draw actual value line
        for (i = 0; i < WPM_GRAPH_LINE_THICKNESS; i++) {
            oled_write_pixel(1, y + i, true);
        }

        // then fill in area below the value line
        for (i = DISPLAY_WIDTH; i > y && 0 <= i; i--) {
            oled_write_pixel(1, i, true);
        }

        // then move the entire graph one pixel to the right
        oled_pan(false);

        // refresh the timer for the next iteration
        timer = timer_read();
    }

    // formatting for triple digit WPM vs double digits, then print WPM readout,
    // or does not print anything if WPM is 0
    int8_t pos_offset = -1;
    if (100 <= currwpm) {
        pos_offset = 0;
    } else if (10 <= currwpm) {
        pos_offset = 1;
    } else if (0 < currwpm) {
        pos_offset = 2;
    }
    if (0 <= pos_offset) {
        char wpm_text[8] = "WPM: ";
        if (currwpm != oldwpm) {
            itoa(currwpm, wpm_text + 4, 10);
        }
        oled_set_cursor(14 + pos_offset, 3);
        oled_write(wpm_text, false);
    }

// brightness adjust when riched WPM_GRAPH_SPEED_HIGHLIGHT
#        ifdef __WPM_GRAPH_BRIGHTNESS_DEFINED
    const uint8_t currbr = oled_get_brightness();
    uint8_t       newbr  = currbr;

    if (WPM_GRAPH_SPEED_HIGHLIGHT <= currwpm) {
        const int   brsteps = (WPM_GRAPH_SPEED_MAX - WPM_GRAPH_SPEED_HIGHLIGHT) - (WPM_GRAPH_SPEED_MAX - ((currwpm > WPM_GRAPH_SPEED_MAX) ? WPM_GRAPH_SPEED_MAX : currwpm));
        const float _newbr  = OLED_BRIGHTNESS + (((float)(WPM_GRAPH_BRIGHTNESS_MAX - OLED_BRIGHTNESS) / (WPM_GRAPH_SPEED_MAX - WPM_GRAPH_SPEED_HIGHLIGHT)) * (float)brsteps);

        newbr = (uint8_t)((_newbr > WPM_GRAPH_BRIGHTNESS_MAX) ? WPM_GRAPH_BRIGHTNESS_MAX : _newbr);
    } else if (currbr != OLED_BRIGHTNESS) {
        newbr = OLED_BRIGHTNESS;
    }

    if (currbr != newbr) {
        oled_set_brightness(newbr);
    }
#        endif // __WPM_GRAPH_BRIGHTNESS_DEFINED
}
#    else
// Simple qmk logo rendering
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}
#    endif /* ifdef USE_WPM_OLED */

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    }
    // We don't need to print if we are in a non-swapped branch
    // else {
    //     oled_write_ln_P(PSTR("LINUX"), false);
    // }

    // default layer
    oled_write_P(PSTR(gSofleModeNames[get_highest_layer(default_layer_state)]), false);
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    oled_write_P(PSTR(gSofleLayerNames[get_highest_layer(layer_state)]), false);
    oled_write_P(PSTR("\n\n"), false);

    // Print capslock status
    oled_write_ln_P(PSTR("CPSLK"), host_keyboard_led_state().caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
#    ifdef USE_WPM_OLED
    // forcibly rotate screen for wpm
    return OLED_ROTATION_180;
#    else
    return rotation;
#    endif /* ifdef USE_WPM_OLED */
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
#    ifdef USE_WPM_OLED
        render_wpm();
#    else
        render_logo();
#    endif
    }
    return false;
}

#endif
