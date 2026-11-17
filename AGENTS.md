# QMK userspace (arminveres)

External QMK userspace. `qmk_firmware/` is a git submodule pinned to upstream `master`.

## Layout

- `keyboards/<kb>/keymaps/arminveres/` — per-board keymap, `config.h`, `rules.mk`, `keymap.json` (modules).
  Boards: `crkbd/rev1` (AVR, tight flash), `sofle/rev1`, `zsa/moonlander`, `handwired/dactyl_manuform` (not in build targets).
- `users/arminveres/` — shared code for all boards: `config.h` (tap-hold tuning), `home_row.h` (GACS home-row mods `HOME_*`),
  `flow_tap.c`, `enums.h` (layer X-macro), `user_caps.c`.
- `modules/getreuer/` — community modules (`sentence_case`).
- `qmk.json` — build targets for `qmk userspace-compile`.

## Build

- Single board: `make crkbd/rev1:arminveres` (or `qmk compile -kb crkbd/rev1 -km arminveres`). All: `qmk userspace-compile`.
- Always build after touching `users/arminveres/`; it affects every board. Crkbd is the flash-size canary (~71% used).
- After updating `qmk_firmware`, `rm -rf qmk_firmware/.build` before building; stale generated files cause bogus
  `implicit declaration` errors (e.g. `eeconfig_*_modules_datablock`).
- Build outputs (`*.hex`, `*.uf2`, `*.bin`) land in the repo root; don't commit them unless asked.

## Updating qmk_firmware

1. `cd qmk_firmware && git fetch && git log --oneline HEAD..origin/master`
2. Read new `docs/ChangeLog/*.md` for breaking changes; check against `users/` and `keyboards/` with `rg`.
3. `git pull --ff-only && git submodule update --init --recursive`
4. Clean `.build`, rebuild all targets.

## Tap-hold conventions

- Home-row mods are GACS (Gui/Alt/Ctrl/Shift from pinky inward), defined only via `HOME_*` macros.
- Tuning lives in `users/arminveres/config.h`: `TAPPING_TERM 240`, `FLOW_TAP_TERM`, `CHORDAL_HOLD`, `PERMISSIVE_HOLD`,
  `SPECULATIVE_HOLD` (+ `_ONE_KEY`, `_FLOW_TERM`).
- Flow Tap is deliberately limited to GUI/Alt keys (A, S, L, ;) in `flow_tap.c`; Shift/Ctrl are excluded so fast
  capitals and Ctrl chords keep working. Don't widen it without asking.
- Known issue: occasional GUI/Alt misfires in fast typing. Levers, in order: raise `FLOW_TAP_TERM_GACS`,
  drop `PERMISSIVE_HOLD`, per-key `get_tapping_term`.

## Tooling

- Search with `rg`, find files with `fd`. Exclude `qmk_firmware/` unless the question is about upstream.
- Never edit files inside `qmk_firmware/`; override via userspace `config.h`/`rules.mk` instead.
