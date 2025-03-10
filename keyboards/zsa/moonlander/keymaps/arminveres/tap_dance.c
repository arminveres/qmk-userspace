#include "tap_dance.h"

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_RALT);
        tap_code16(KC_RALT);
        tap_code16(KC_RALT);
    }
    if (state->count > 3) {
        tap_code16(KC_RALT);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_RALT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RALT);
            register_code16(KC_RALT);
            break;
        case DOUBLE_HOLD:
            layer_on(3);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RALT);
            register_code16(KC_RALT);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_RALT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RALT);
            break;
        case DOUBLE_HOLD:
            layer_off(3);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RALT);
            break;
    }
    dance_state[0].step = 0;
}

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_RALT);
        tap_code16(KC_RALT);
        tap_code16(KC_RALT);
    }
    if (state->count > 3) {
        tap_code16(KC_RALT);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(KC_RALT);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RALT);
            register_code16(KC_RALT);
            break;
        case DOUBLE_HOLD:
            layer_on(3);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RALT);
            register_code16(KC_RALT);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(KC_RALT);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RALT);
            break;
        case DOUBLE_HOLD:
            layer_off(3);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RALT);
            break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
