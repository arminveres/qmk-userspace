#include QMK_KEYBOARD_H // IWYU pragma: keep

#include "achordion.h"
#include "enums.h"
#include "home_row.h"
#include "sentence_case.h"

#define CAPS_WORD CW_TOGG

// clang-format off
constexpr uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────┬────────┬───────────┬────────┬──────────────┬─────────────┬────┐   ┌────┬─────────────┬──────────────┬───────────────────┬───────────┬───────────┬───────────────┐
//    │      esc      │   1    │     2     │   3    │      4       │      5      │ no │   │ no │      6      │      7       │         8         │     9     │     0     │     bspc      │
//    ├───────────────┼────────┼───────────┼────────┼──────────────┼─────────────┼────┤   ├────┼─────────────┼──────────────┼───────────────────┼───────────┼───────────┼───────────────┤
//    │      tab      │   q    │     w     │   e    │      r       │      t      │ no │   │ no │      y      │      u       │         i         │     o     │     p     │       \       │
//    ├───────────────┼────────┼───────────┼────────┼──────────────┼─────────────┼────┤   ├────┼─────────────┼──────────────┼───────────────────┼───────────┼───────────┼───────────────┤
//    │ OSM(MOD_LCTL) │ HOME_A │  HOME_S   │ HOME_D │    HOME_F    │      g      │ no │   │ no │      h      │    HOME_J    │      HOME_K       │  HOME_L   │ HOME_SCLN │   RCTL_T(')   │
//    ├───────────────┼────────┼───────────┼────────┼──────────────┼─────────────┼────┘   └────┼─────────────┼──────────────┼───────────────────┼───────────┼───────────┼───────────────┤
//    │ OSM(MOD_LSFT) │   z    │ RALT_T(x) │   c    │      v       │      b      │             │      n      │      m       │         ,         │ RALT_T(.) │     /     │ OSM(MOD_RSFT) │
//    ├───────────────┼────────┼───────────┼────────┼──────────────┼─────────────┼────┐   ┌────┼─────────────┼──────────────┼───────────────────┼───────────┼───────────┼───────────────┤
//    │      no       │   no   │    esc    │  lalt  │     lgui     │             │ no │   │ no │             │     rgui     │ MT(MOD_LALT, esc) │    no     │    no     │      no       │
//    └───────────────┴────────┴───────────┼────────┼──────────────┼─────────────┼────┘   └────┼─────────────┼──────────────┼───────────────────┼───────────┴───────────┴───────────────┘
//                                         │  spc   │ MO(_SPECIAL) │ MO(_ADJUST) │             │ MO(_ADJUST) │ MO(_SPECIAL) │        ent        │
//                                         └────────┴──────────────┴─────────────┘             └─────────────┴──────────────┴───────────────────┘
[_QWERTY] = LAYOUT_moonlander(
  KC_ESC        , KC_1    , KC_2         , KC_3     , KC_4         , KC_5        , XXXXXXX ,     XXXXXXX , KC_6        , KC_7         , KC_8                    , KC_9           , KC_0      , KC_BSPC         ,
  KC_TAB        , KC_Q    , KC_W         , KC_E     , KC_R         , KC_T        , XXXXXXX ,     XXXXXXX , KC_Y        , KC_U         , KC_I                    , KC_O           , KC_P      , KC_BSLS         ,
  OSM(MOD_LCTL) , HOME_A  , HOME_S       , HOME_D   , HOME_F       , KC_G        , XXXXXXX ,     XXXXXXX , KC_H        , HOME_J       , HOME_K                  , HOME_L         , HOME_SCLN , RCTL_T(KC_QUOTE),
  OSM(MOD_LSFT) , KC_Z    , RALT_T(KC_X) , KC_C     , KC_V         , KC_B        ,                         KC_N        , KC_M         , KC_COMMA                , RALT_T(KC_DOT) , KC_SLASH  , OSM(MOD_RSFT)   ,
  XXXXXXX       , XXXXXXX , KC_ESC       , KC_LALT  , KC_LGUI      ,               XXXXXXX ,     XXXXXXX ,               KC_RGUI      , MT(MOD_LALT, KC_ESCAPE) , XXXXXXX        , XXXXXXX   , XXXXXXX         ,
                                           KC_SPACE , MO(_SPECIAL) , MO(_ADJUST) ,                         MO(_ADJUST) , MO(_SPECIAL) , KC_ENTER
),

//    ┌───────────┬────┬─────┬──────┬──────────────┬─────────────┬──────┐   ┌──────┬─────────────┬──────────────┬───────────────────┬────┬────┬───────────┐
//    │    esc    │ 1  │  2  │  3   │      4       │      5      │  no  │   │  no  │      6      │      7       │         8         │ 9  │ 0  │   bspc    │
//    ├───────────┼────┼─────┼──────┼──────────────┼─────────────┼──────┤   ├──────┼─────────────┼──────────────┼───────────────────┼────┼────┼───────────┤
//    │    tab    │ q  │  w  │  e   │      r       │      t      │  =   │   │  -   │      y      │      u       │         i         │ o  │ p  │     \     │
//    ├───────────┼────┼─────┼──────┼──────────────┼─────────────┼──────┤   ├──────┼─────────────┼──────────────┼───────────────────┼────┼────┼───────────┤
//    │   lctl    │ a  │  s  │  d   │      f       │      g      │  [   │   │  ]   │      h      │      j       │         k         │ l  │ ;  │ RCTL_T(') │
//    ├───────────┼────┼─────┼──────┼──────────────┼─────────────┼──────┘   └──────┼─────────────┼──────────────┼───────────────────┼────┼────┼───────────┤
//    │   lsft    │ z  │  x  │  c   │      v       │      b      │                 │      n      │      m       │         ,         │ .  │ /  │   rsft    │
//    ├───────────┼────┼─────┼──────┼──────────────┼─────────────┼──────┐   ┌──────┼─────────────┼──────────────┼───────────────────┼────┼────┼───────────┤
//    │ caps_LOCK │ no │ esc │ lalt │     lgui     │             │ ralt │   │ ralt │             │     rgui     │ MT(MOD_LALT, esc) │ no │ no │    no     │
//    └───────────┴────┴─────┼──────┼──────────────┼─────────────┼──────┘   └──────┼─────────────┼──────────────┼───────────────────┼────┴────┴───────────┘
//                           │ spc  │ MO(_SPECIAL) │ MO(_ADJUST) │                 │ MO(_ADJUST) │ MO(_SPECIAL) │        ent        │
//                           └──────┴──────────────┴─────────────┘                 └─────────────┴──────────────┴───────────────────┘
[_GAMING] = LAYOUT_moonlander(
  KC_ESC       , KC_1    , KC_2   , KC_3     , KC_4         , KC_5        , XXXXXXX  ,     XXXXXXX  , KC_6        , KC_7         , KC_8                    , KC_9    , KC_0     , KC_BSPC         ,
  KC_TAB       , KC_Q    , KC_W   , KC_E     , KC_R         , KC_T        , KC_EQUAL ,     KC_MINUS , KC_Y        , KC_U         , KC_I                    , KC_O    , KC_P     , KC_BSLS         ,
  KC_LCTL      , KC_A    , KC_S   , KC_D     , KC_F         , KC_G        , KC_LBRC  ,     KC_RBRC  , KC_H        , KC_J         , KC_K                    , KC_L    , KC_SCLN  , RCTL_T(KC_QUOTE),
  KC_LSFT      , KC_Z    , KC_X   , KC_C     , KC_V         , KC_B        ,                           KC_N        , KC_M         , KC_COMMA                , KC_DOT  , KC_SLASH , KC_RSFT         ,
  KC_CAPS_LOCK , XXXXXXX , KC_ESC , KC_LALT  , KC_LGUI      ,               KC_RALT  ,     KC_RALT  ,               KC_RGUI      , MT(MOD_LALT, KC_ESCAPE) , XXXXXXX , XXXXXXX  , XXXXXXX         ,
                                    KC_SPACE , MO(_SPECIAL) , MO(_ADJUST) ,                           MO(_ADJUST) , MO(_SPECIAL) , KC_ENTER
),

//    ┌───────────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬──────┬──────┬──────┬──────┬──────┬─────┐
//    │           │ f1  │ f2  │ f3  │ f4  │ f5  │     │   │     │  f6  │  f7  │  f8  │  f9  │ f10  │ del │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │  ~  │  {  │  }  │  =  │  +  │     │   │     │ pgup │ home │      │      │      │ f11 │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │ CAPS_WORD │  `  │  [  │  ]  │  -  │  _  │     │   │     │ left │ down │  up  │ rght │      │ f12 │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┘   └─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │     │     │     │     │     │               │ pgdn │ end  │ mprv │ mnxt │ mply │     │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │     │     │     │     │     │     │   │     │      │ vold │ volu │ mute │      │     │
//    └───────────┴─────┴─────┼─────┼─────┼─────┼─────┘   └─────┼──────┼──────┼──────┼──────┴──────┴─────┘
//                            │     │     │     │               │      │      │      │
//                            └─────┴─────┴─────┘               └──────┴──────┴──────┘
[_SPECIAL] = LAYOUT_moonlander(
  _______   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,     _______ , KC_F6   , KC_F7             , KC_F8               , KC_F9               , KC_F10              , KC_DELETE,
  _______   , KC_TILD , KC_LCBR , KC_RCBR , KC_EQL  , KC_PLUS , _______ ,     _______ , KC_PGUP , KC_HOME           , _______             , _______             , _______             , KC_F11   ,
  CAPS_WORD , KC_GRV  , KC_LBRC , KC_RBRC , KC_MINS , KC_UNDS , _______ ,     _______ , KC_LEFT , KC_DOWN           , KC_UP               , KC_RIGHT            , _______             , KC_F12   ,
  _______   , _______ , _______ , _______ , _______ , _______ ,                         KC_PGDN , KC_END            , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_MEDIA_PLAY_PAUSE , _______  ,
  _______   , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP     , KC_AUDIO_MUTE       , _______             , _______  ,
                                  _______ , _______ , _______ ,                         _______ , _______           , _______
),

//    ┌─────────┬────────┬──────┬──────┬──────┬─────┬─────────────────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬──────┐
//    │ QK_BOOT │        │      │      │      │     │                 │   │     │     │     │     │     │     │      │
//    ├─────────┼────────┼──────┼──────┼──────┼─────┼─────────────────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼──────┤
//    │         │ qWERTY │ btn2 │ ms_u │ btn1 │     │  bRIGHTNESS_UP  │   │     │  =  │  7  │  8  │  9  │     │      │
//    ├─────────┼────────┼──────┼──────┼──────┼─────┼─────────────────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼──────┤
//    │         │ gAMING │ ms_l │ ms_d │ ms_r │     │ bRIGHTNESS_DOWN │   │     │  +  │  4  │  5  │  6  │  -  │      │
//    ├─────────┼────────┼──────┼──────┼──────┼─────┼─────────────────┘   └─────┼─────┼─────┼─────┼─────┼─────┼──────┤
//    │         │        │      │      │      │     │                           │  *  │  1  │  2  │  3  │  /  │      │
//    ├─────────┼────────┼──────┼──────┼──────┼─────┼─────────────────┐   ┌─────┼─────┼─────┼─────┼─────┼─────┼──────┤
//    │         │        │      │      │      │     │                 │   │     │     │  0  │     │     │     │ boot │
//    └─────────┴────────┴──────┼──────┼──────┼─────┼─────────────────┘   └─────┼─────┼─────┼─────┼─────┴─────┴──────┘
//                              │      │      │     │                           │     │     │     │
//                              └──────┴──────┴─────┘                           └─────┴─────┴─────┘
[_ADJUST] = LAYOUT_moonlander(
  QK_BOOT , _______   , _______    , _______    , _______     , _______ , _______            ,     _______ , _______ , _______ , _______ , _______ , _______  , _______,
  _______ , KC_QWERTY , KC_MS_BTN2 , KC_MS_UP   , KC_MS_BTN1  , _______ , KC_BRIGHTNESS_UP   ,     _______ , KC_EQL  , KC_7    , KC_8    , KC_9    , _______  , _______,
  _______ , KC_GAMING , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , _______ , KC_BRIGHTNESS_DOWN ,     _______ , KC_PLUS , KC_4    , KC_5    , KC_6    , KC_MINS  , _______,
  _______ , _______   , _______    , _______    , _______     , _______ ,                                    KC_ASTR , KC_1    , KC_2    , KC_3    , KC_SLASH , _______,
  _______ , _______   , _______    , _______    , _______     ,           _______            ,     _______ ,           KC_0    , _______ , _______ , _______  , RESET  ,
                                     _______    , _______     , _______ ,                                    _______ , _______ , _______
)
};
// [4] = LAYOUT_moonlander(
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            ,                         _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , HSV_0_255_255 , HSV_86_255_128 , HSV_172_255_255 ,                      RGB_MOD ,     RGB_TOG ,           _______ , _______ , _______ , _______ , _______,
//                                       RGB_VAD        , RGB_VAI         , TOGGLE_LAYER_COLOR ,                         RGB_SLD , RGB_HUD , RGB_HUI
// )
// clang-format on

void keyboard_post_init_user(void) {
    // rgb_matrix_enable();
    rgb_matrix_disable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case KC_QWERTY: {
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        }
        case KC_GAMING: {
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        }
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
        case HSV_86_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86, 255, 128);
            }
            return false;
        case HSV_172_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172, 255, 255);
            }
            return false;
    }
    return true;
}
uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    return 50; // Default of 100 ms.
}
void matrix_scan_user(void) {
    // Achordion doc: https://getreuer.info/posts/keyboards/achordion/index.html#achordion_chord
    achordion_task();
}

/// Custom LED Indicator implementation for layers, see `moonlander.c`
layer_state_t layer_state_set_user(layer_state_t state) {
    bool LED_1 = false;
    bool LED_2 = false;
    bool LED_3 = false;
    bool LED_4 = false;
    bool LED_5 = false;
#if !defined(CAPS_LOCK_STATUS)
    bool LED_6 = false;
#endif
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0 ... 1:
            break;
        // first and second layers are persistent layers!
        case 2:
            LED_1 = true;
            LED_4 = true;
            break;
        case 3:
            LED_2 = true;
            LED_5 = true;
            break;
        default:
            break;
    }
    ML_LED_1(LED_1);
    ML_LED_2(LED_2);
    ML_LED_3(LED_3);
    ML_LED_4(LED_4);
    ML_LED_5(LED_5);
#if !defined(CAPS_LOCK_STATUS)
    ML_LED_6(LED_6);
#endif
    return state;
}
