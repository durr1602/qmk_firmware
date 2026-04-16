# Journey into bilingual Colemak-DH

## Intro

I've tried for a few weeks with the following configuration:

- Default (QWERTY) layer on "Win" layer
- Colemak-DH with Angle mod on "Mac" layer (physical switch at the back of the keyboard)
- Colemak-DH with Angle mod on 5th layer, accessible upon double tap on RWin

This last layer differed from the other Colemak one (layer 0) by a few French Canadian specific aliases, notably for "é" and a few dead keys.

My rationale was that I needed to have an English/coding oriented layer, while the French layer would be separate for punctual use.

In the end, I find almost all keys too far to reach, especially ` (above Enter) and decided to move to the use of a leader key (CAPS).

Ultimately I should be able to get rid of that last layer which isn't really useful.

Another thing that I want to do is to implement some custom combos like `` s + t = ` ``

## Visual

Using [keymap-drawer](https://github.com/caksoylar/keymap-drawer/tree/main), I generated [a YAML](./keymap.yaml) with `qmk c2json --no-cpp keymap.c | keymap parse -c 10 -q - >keymap.yaml`.

Then, I edited manually and generated a SVG with `keymap draw keymap.yaml -j ../../../../info.json >keymap.svg`

> [!WARNING]
> The visual **does not** currently include the newly implemented leader key combos

![Keymap layout](./keymap.svg)