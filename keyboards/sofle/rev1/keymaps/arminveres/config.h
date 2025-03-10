#pragma once


/// Set encoder settings
#ifdef ENCODER_RESOLUTION
// Setting the resolution to 4 results in 10% increase e.g., in volume change. 2 is 20% so 8 should
// result in 5%
// WARN: using 8 does not correctly increment the volume by 5%
#    undef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 20000 // 120000 = 2 minutes in ms.
#    define OLED_BRIGHTNESS 50 // Default 100.
#    define SPLIT_WPM_ENABLE   // Enable WPM across split keyboards (+268).
#    define SPLIT_OLED_ENABLE  // Synx on/off OLED state between halves (+100).
#endif                         // OLED_ENABLE

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
/// Left side is the master as plugged in to usb
#define MASTER_LEFT

/// My Definitions
#define USE_WPM_OLED
