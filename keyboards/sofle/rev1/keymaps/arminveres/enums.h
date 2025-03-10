#pragma once
#include QMK_KEYBOARD_H // IWYU pragma: keep

// clang-format off
// Create an X macro to define layers and their names for printing later on OLED
#define MY_LAYERS                      \
    X_LAYER(_QWERTY, "Qwrt", "Base\n") \
    X_LAYER(_GAMING, "Game", "Gaming") \
    X_LAYER(_LOWER,  "----", "Lower")   \
    X_LAYER(_UPPER,  "----", "Upper")   \
    X_LAYER(_ADJUST, "----", "Adjst")
// clang-format on

#define X_LAYER(layer, mode_name, layer_name) layer,
enum eSofleLayers { MY_LAYERS };
#undef X_LAYER

extern char const* gSofleModeNames[];
extern char const* gSofleLayerNames[];

enum eCustomKeycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_COLEMAK,
};
