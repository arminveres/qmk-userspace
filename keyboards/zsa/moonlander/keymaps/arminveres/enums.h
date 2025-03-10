#pragma once
#include QMK_KEYBOARD_H // IWYU pragma: keep

enum eCustomKeycodes {
    RGB_SLD = SAFE_RANGE, //
    HSV_0_255_255,        //
    HSV_86_255_128,       //
    HSV_172_255_255,      //
    KC_QWERTY,            //
    KC_GAMING
};

enum eLayers {
    _QWERTY,  //
    _GAMING,  //
    _SPECIAL, //
    _ADJUST   //
};
