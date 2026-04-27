# Journey into bilingual Colemak-DH

## Intro

This is a journal to document my attempts at trying to design a Colemak-inspired layout to be used for:
- English
- Coding (mainly Python for now)
- French

The Colemak base is the DH variant with an Angle mod (suits this ANSI keyboard).

I'm keeping a default (standard QWERTY) layer that can be activated with a physical switch at the back of the keyboard.

## Accented characters

I'm using the local aliases from [the French Canadian header](/quantum/keymap_extras/keymap_canadian_french.h)

Tap dance:
- `ee` = `é`

Combos (chords):
- `n` + `i` = `` ` ``
- `f` + `t` = `^`
- `c` + `,` = `ç`

Leader combos (soon to be deprecated):
- `QK_LEAD` (`CAPS`), `n` = `` ` ``
- `QK_LEAD` (`CAPS`), `u` = `^`

## Visual

Using [`keymap-drawer`](https://github.com/caksoylar/keymap-drawer/tree/main), I generated [a YAML](./keymap.yaml) with `qmk c2json --no-cpp keymap.c | keymap parse -c 10 -q - >keymap.yaml`.

Then, I edited manually and generated a SVG with `keymap draw keymap.yaml -j ../../../../info.json >keymap.svg`

![Keymap layout](./keymap.svg)

## Roadmap

- [x] Better combos for dead keys (chording)