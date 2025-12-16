#ifdef FLOW_TAP_TERM
#    include QMK_KEYBOARD_H // IWYU pragma: keep
#    include <stdint.h>
#    include "home_row.h"

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
// Use pgetreuers function: https://github.com/getreuer/qmk-keymap/blob/main/getreuer.c

    // Only apply Flow Tap when following a letter key, and not hotkeys.
    if (get_tap_keycode(prev_keycode) <= KC_Z && (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) == 0) {
        switch (keycode) {
            // Alt and Gui
            case HOME_A:
            case HOME_S:
            case HOME_SCLN:
            case HOME_L:
                return FLOW_TAP_TERM;
        }
    }
    // Disable Flow Tap otherwise.
    // - e.g., for shift
    return 0;
}
#endif // FLOW_TAP_TERM
