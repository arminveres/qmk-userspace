/// Add custom defines, that are valid for all my keymaps
#pragma once

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

/// To do individual keys: https://docs.qmk.fm/#/tap_hold?id=tapping-term
#undef TAPPING_TERM
/// Change Tapping Term from the default 200ms!
#define TAPPING_TERM 250

/// In combination with fast typing and home row mods, PERMISSIVE_HOLD enables to register keys instead of layer changes
/// For more information see: https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
#define PERMISSIVE_HOLD

/// My Defines
#define USE_HOMEROW_MODS
#undef PARTIAL_HOME_MODS

/// https://docs.qmk.fm/tap_hold#chordal-hold
#define CHORDAL_HOLD

#define auto __auto_type
