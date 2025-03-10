#pragma once
// NOTE: We are using the GACS Home Row mods!

#if defined(USE_HOMEROW_MODS)
// Left-hand home row mods
#    define HOME_A (LGUI_T(KC_A))
#    define HOME_S (LALT_T(KC_S))
#    define HOME_D (LCTL_T(KC_D))
#    define HOME_F (LSFT_T(KC_F))
// Right-hand home row mods
#    define HOME_J (RSFT_T(KC_J))
#    define HOME_K (RCTL_T(KC_K))
#    define HOME_L (LALT_T(KC_L))
#    define HOME_SCLN (RGUI_T(KC_SCLN))

#elif defined(PARTIAL_HOME_MODS)
// Left-hand home row mods
#    define HOME_A (LGUI_T(KC_A))
#    define HOME_S (LALT_T(KC_S))
#    define HOME_D (KC_D)
#    define HOME_F (KC_F)
// Right-hand home row mods
#    define HOME_J (KC_J)
#    define HOME_K (KC_K)
#    define HOME_L (LALT_T(KC_L))
#    define HOME_SCLN (RGUI_T(KC_SCLN))

#else
// Left-hand home row mods
#    define HOME_A (KC_A)
#    define HOME_S (KC_S)
#    define HOME_D (KC_D)
#    define HOME_F (KC_F)
// Right-hand home row mods
#    define HOME_J (KC_J)
#    define HOME_K (KC_K)
#    define HOME_L (KC_L)
#    define HOME_SCLN (KC_SCLN)
#endif /* ifdef USE_HOMEROW_MODS */
