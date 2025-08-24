/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define RGB_MATRIX_STARTUP_SPD 60

/// only define this if we are using up to 8 layers, if more use 16 bit or disable altogether
#define LAYER_STATE_16BIT
#define ORYX_CONFIGURATOR
#define MOONLANDER_USER_LEDS
