#pragma once
#include QMK_KEYBOARD_H // IWYU pragma: keep

// clang-format off
// Create an X macro to define layers and their names for printing later on OLED
#define MY_LAYERS                      \
    X_LAYER(_QWERTY, "Qwrt", "BASE\n") \
    X_LAYER(_GAMING, "Game", "GAMING") \
    X_LAYER(_NAV,    "----", "NAV\n")  \
    X_LAYER(_MOUSE,  "----", "MOUSE")  \
    X_LAYER(_MEDIA,  "----", "MEDIA")  \
    X_LAYER(_NUM,    "----", "NUM\n")  \
    X_LAYER(_SYM,    "----", "SYM\n")  \
    X_LAYER(_FUN,    "----", "FUN\n")  \
    X_LAYER(_ADJUST, "----", "ADJST")
// clang-format on

#define X_LAYER(layer, mode_name, layer_name) layer,
enum eLayers { MY_LAYERS };
#undef X_LAYER

extern char const* gOledModeNames[];
extern char const* gOledLayerNames[];

enum eCustomKeycodes {
    RGB_SLD = SAFE_RANGE, //
    HSV_0_255_255,        //
    HSV_86_255_128,       //
    HSV_172_255_255,      //
    KC_QWERTY,            //
    KC_GAMING
};


