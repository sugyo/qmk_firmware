/*
Copyright 2011,2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

/*         ,-----------------------------------------------.
 *         |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
 * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|     |PrS|ScL|Pau|     |VDn|VUp|Mut|
 * `---'   `-----------------------------------------------'     `-----------'     `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| ^a|Entr|               |  4|  5|  6|KP,|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |---------------|
 * |Ctl|Gui|Alt|MHEN|     Space      |HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  #|  0|  .|KP=|
 * `-----------------------------------------------------------' `-----------' `---------------'
 *
 * PS/2 scan codes
 * http://download.microsoft.com/download/1/6/1/161ba512-40e2-4cc9-843a-923143f3456c/translate.pdf
 *         ,-----------------------------------------------.
 *         | 08| 10| 18| 20| 28| 30| 38| 40| 48| 50| 57| 5F|
 * ,---.   |-----------------------------------------------|     ,-----------.     ,-----------.
 * | 76|   | 05| 06| 04| 0C| 03| 0B| 83| 0A| 01| 09| 78| 07|     | FC| 7E| FE|     | A1| B2| A3|
 * `---'   `-----------------------------------------------'     `-----------'     `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * | 0E| 16| 1E| 26| 25| 2E| 36| 3D| 3E| 46| 45| 4E| 55| 6A| 66| | F0| EC| FD| | 77| CA| 7C| 7B|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * | 0D  | 15| 1D| 24| 2D| 2C| 35| 3C| 43| 44| 4D| 54| 5B|  5D | | F1| E9| FA| | 6C| 75| 7D| 79|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * | 58   | 1C| 1B| 23| 2B| 34| 33| 3B| 42| 4B| 4C| 52| ^a| 5A |               | 6B| 73| 74| 6D|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * | 12 | 61| 1A| 22| 21| 2A| 32| 31| 3A| 41| 49| 4A| 51|  59  |     | F5|     | 69| 72| 7A| DA|
 * |-----------------------------------------------------------| ,-----------. |---------------|
 * | 14| 9F| 11| 67 |     29         | 64 | 13 | 91| A7| AF| 94| | EB| F2| F4| | 68|70 | 71| 63|
 * `-----------------------------------------------------------' `-----------' `---------------'
 * ^a ISO hash key uses identical scancode 5D to US backslash.
 * 51, 63, 68, 6D: hidden keys in IBM model M
 */
/* All keys */
#define LAYOUT_all( \
        K08,K10,K18,K20,K28,K30,K38,K40,K48,K50,K57,K5F,                                        \
    K76,K05,K06,K04,K0C,K03,K0B,K83,K0A,K01,K09,K78,K07,         KFC,K7E,KFE,      KA1,KB2,KA3, \
    K0E,K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,K6A,K66, KF0,KEC,KFD,  K77,KCA,K7C,K7B, \
    K0D,K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,    K5D, KF1,KE9,KFA,  K6C,K75,K7D,K79, \
    K58,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,        K5A,               K6B,K73,K74,K6D, \
    K12,K61,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,    K51,K59,     KF5,      K69,K72,K7A,KDA, \
    K14,K9F,K11,K67,        K29,        K64,K13,K91,KA7,KAF,K94, KEB,KF2,KF4,  K68,K70,K71,K63, \
                                                                                                \
    KB7, KBF, KDE,           /* System Power, Sleep, Wake */                                    \
    KCD, K95, KBB, KB4, KD0, /* Next, Previous, Stop, Pause, Media Select */                    \
    KC8, KAB, KC0,           /* Mail, Calculator, My Computer */                                \
    K90, KBA, KB8, KB0,      /* WWW Search, WWW Home, WWW Back, WWW Forward */                  \
    KA8, KA0, K98            /* WWW Stop, WWW Refresh, WWW Favorites */                         \
) { \
    { XXXXXXX, K01,     XXXXXXX, K03,     K04,     K05,     K06,     K07     }, \
    { K08,     K09,     K0A,     K0B,     K0C,     K0D,     K0E,     XXXXXXX }, \
    { K10,     K11,     K12,     K13,     K14,     K15,     K16,     XXXXXXX }, \
    { K18,     XXXXXXX, K1A,     K1B,     K1C,     K1D,     K1E,     XXXXXXX }, \
    { K20,     K21,     K22,     K23,     K24,     K25,     K26,     XXXXXXX }, \
    { K28,     K29,     K2A,     K2B,     K2C,     K2D,     K2E,     XXXXXXX }, \
    { K30,     K31,     K32,     K33,     K34,     K35,     K36,     XXXXXXX }, \
    { K38,     XXXXXXX, K3A,     K3B,     K3C,     K3D,     K3E,     XXXXXXX }, \
    { K40,     K41,     K42,     K43,     K44,     K45,     K46,     XXXXXXX }, \
    { K48,     K49,     K4A,     K4B,     K4C,     K4D,     K4E,     XXXXXXX }, \
    { K50,     K51,     K52,     XXXXXXX, K54,     K55,     XXXXXXX, K57     }, \
    { K58,     K59,     K5A,     K5B,     XXXXXXX, K5D,     XXXXXXX, K5F     }, \
    { XXXXXXX, K61,     XXXXXXX, K63,     K64,     XXXXXXX, K66,     K67     }, \
    { K68,     K69,     K6A,     K6B,     K6C,     K6D,     XXXXXXX, XXXXXXX }, \
    { K70,     K71,     K72,     K73,     K74,     K75,     K76,     K77     }, \
    { K78,     K79,     K7A,     K7B,     K7C,     K7D,     K7E,     XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, K83,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { K90,     K91,     XXXXXXX, XXXXXXX, K94,     K95,     XXXXXXX, XXXXXXX }, \
    { K98,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K9F     }, \
    { KA0,     KA1,     XXXXXXX, KA3,     XXXXXXX, XXXXXXX, XXXXXXX, KA7     }, \
    { KA8,     XXXXXXX, XXXXXXX, KAB,     XXXXXXX, XXXXXXX, XXXXXXX, KAF     }, \
    { KB0,     XXXXXXX, KB2,     XXXXXXX, KB4,     XXXXXXX, XXXXXXX, KB7     }, \
    { KB8,     XXXXXXX, KBA,     KBB,     XXXXXXX, XXXXXXX, XXXXXXX, KBF     }, \
    { KC0,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC8,     XXXXXXX, KCA,     XXXXXXX, XXXXXXX, KCD,     XXXXXXX, XXXXXXX }, \
    { KD0,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KDA,     XXXXXXX, XXXXXXX, XXXXXXX, KDE,     XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, KE9,     XXXXXXX, KEB,     KEC,     XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KF0,     KF1,     KF2,     XXXXXXX, KF4,     KF5,     XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KFA,     XXXXXXX, KFC,     KFD,     KFE,     XXXXXXX }, \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspa| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
 * |-----------------------------------------------------------| `-----------' |-----------|  +|
 * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|Ent|
 * |Ctrl |Gui |Alt |         Space         |Alt |Gui |Menu|Ctrl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
/* US layout */
#define LAYOUT_ansi( \
    K76,K05,K06,K04,K0C,K03,K0B,K83,K0A,K01,K09,K78,K07,     KFC,K7E,KFE,                   \
    K0E,K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,K66, KF0,KEC,KFD,  K77,KCA,K7C,K7B, \
    K0D,K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,K5D, KF1,KE9,KFA,  K6C,K75,K7D,     \
    K58,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,    K5A,               K6B,K73,K74,K79, \
    K12,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,        K59,     KF5,      K69,K72,K7A,     \
    K14,K9F,K11,            K29,            K91,KA7,KAF,K94, KEB,KF2,KF4,  K70,    K71,KDA  \
) { \
    { XXXXXXX, K01,     XXXXXXX, K03,     K04,     K05,     K06,     K07     }, \
    { KC_F13,  K09,     K0A,     K0B,     K0C,     K0D,     K0E,     XXXXXXX }, \
    { KC_F14,  K11,     K12,     KC_KANA, K14,     K15,     K16,     XXXXXXX }, \
    { KC_F15,  XXXXXXX, K1A,     K1B,     K1C,     K1D,     K1E,     XXXXXXX }, \
    { KC_F16,  K21,     K22,     K23,     K24,     K25,     K26,     XXXXXXX }, \
    { KC_F17,  K29,     K2A,     K2B,     K2C,     K2D,     K2E,     XXXXXXX }, \
    { KC_F18,  K31,     K32,     K33,     K34,     K35,     K36,     XXXXXXX }, \
    { KC_F19,  XXXXXXX, K3A,     K3B,     K3C,     K3D,     K3E,     XXXXXXX }, \
    { KC_F20,  K41,     K42,     K43,     K44,     K45,     K46,     XXXXXXX }, \
    { KC_F21,  K49,     K4A,     K4B,     K4C,     K4D,     K4E,     XXXXXXX }, \
    { KC_F22,  KC_RO,   K52,     XXXXXXX, K54,     K55,     XXXXXXX, KC_F23  }, \
    { K58,     K59,     K5A,     K5B,     XXXXXXX, K5D,     XXXXXXX, KC_F24  }, \
    { XXXXXXX, KC_NUBS, XXXXXXX, KC_PEQL, KC_HENK, XXXXXXX, K66,     KC_MHEN }, \
    { KC_PWR,  K69,     KC_JYEN, K6B,     K6C,     KC_PCMM, XXXXXXX, XXXXXXX }, \
    { K70,     K71,     K72,     K73,     K74,     K75,     K76,     K77     }, \
    { K78,     K79,     K7A,     K7B,     K7C,     K7D,     K7E,     XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, K83,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_WSCH, K91,     XXXXXXX, XXXXXXX, K94,     KC_MPRV, XXXXXXX, XXXXXXX }, \
    { KC_WFAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K9F     }, \
    { KC_WREF, KC_VOLD, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KA7     }, \
    { KC_WSTP, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, KAF     }, \
    { KC_WFWD, XXXXXXX, KC_VOLU, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, KC_PWR  }, \
    { KC_WBAK, XXXXXXX, KC_WHOM, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP }, \
    { KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_MAIL, XXXXXXX, KCA,     XXXXXXX, XXXXXXX, KC_MNXT, XXXXXXX, XXXXXXX }, \
    { KC_MSEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KDA,     XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, KE9,     XXXXXXX, KEB,     KEC,     XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KF0,     KF1,     KF2,     XXXXXXX, KF4,     KF5,     XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KFA,     XXXXXXX, KFC,     KFD,     KFE,     XXXXXXX }, \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
/* ISO layout */
#define LAYOUT_iso( \
    K76,K05,K06,K04,K0C,K03,K0B,K83,K0A,K01,K09,K78,K07,     KFC,K7E,KFE,                   \
    K0E,K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,K66, KF0,KEC,KFD,  K77,KCA,K7C,K7B, \
    K0D,K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,K5A, KF1,KE9,KFA,  K6C,K75,K7D,     \
    K58,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,K5D,                   K6B,K73,K74,K79, \
    K12,K61,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,    K59,     KF5,      K69,K72,K7A,     \
    K14,K9F,K11,            K29,            K91,KA7,KAF,K94, KEB,KF2,KF4,  K70,    K71,KDA  \
) { \
    { XXXXXXX, K01,     XXXXXXX, K03,     K04,     K05,     K06,     K07     }, \
    { KC_F13,  K09,     K0A,     K0B,     K0C,     K0D,     K0E,     XXXXXXX }, \
    { KC_F14,  K11,     K12,     KC_KANA, K14,     K15,     K16,     XXXXXXX }, \
    { KC_F15,  XXXXXXX, K1A,     K1B,     K1C,     K1D,     K1E,     XXXXXXX }, \
    { KC_F16,  K21,     K22,     K23,     K24,     K25,     K26,     XXXXXXX }, \
    { KC_F17,  K29,     K2A,     K2B,     K2C,     K2D,     K2E,     XXXXXXX }, \
    { KC_F18,  K31,     K32,     K33,     K34,     K35,     K36,     XXXXXXX }, \
    { KC_F19,  XXXXXXX, K3A,     K3B,     K3C,     K3D,     K3E,     XXXXXXX }, \
    { KC_F20,  K41,     K42,     K43,     K44,     K45,     K46,     XXXXXXX }, \
    { KC_F21,  K49,     K4A,     K4B,     K4C,     K4D,     K4E,     XXXXXXX }, \
    { KC_F22,  KC_RO,   K52,     XXXXXXX, K54,     K55,     XXXXXXX, KC_F23  }, \
    { K58,     K59,     K5A,     K5B,     XXXXXXX, K5D,     XXXXXXX, KC_F24  }, \
    { XXXXXXX, K61,     XXXXXXX, KC_PEQL, KC_HENK, XXXXXXX, K66,     KC_MHEN }, \
    { KC_PWR,  K69,     KC_JYEN, K6B,     K6C,     KC_PCMM, XXXXXXX, XXXXXXX }, \
    { K70,     K71,     K72,     K73,     K74,     K75,     K76,     K77     }, \
    { K78,     K79,     K7A,     K7B,     K7C,     K7D,     K7E,     XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, K83,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_WSCH, K91,     XXXXXXX, XXXXXXX, K94,     KC_MPRV, XXXXXXX, XXXXXXX }, \
    { KC_WFAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K9F     }, \
    { KC_WREF, KC_VOLD, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KA7     }, \
    { KC_WSTP, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, KAF     }, \
    { KC_WFWD, XXXXXXX, KC_VOLU, XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, KC_PWR  }, \
    { KC_WBAK, XXXXXXX, KC_WHOM, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP }, \
    { KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_MAIL, XXXXXXX, KCA,     XXXXXXX, XXXXXXX, KC_MNXT, XXXXXXX, XXXXXXX }, \
    { KC_MSEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KDA,     XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, KE9,     XXXXXXX, KEB,     KEC,     XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KF0,     KF1,     KF2,     XXXXXXX, KF4,     KF5,     XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KFA,     XXXXXXX, KFC,     KFD,     KFE,     XXXXXXX }, \
}

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  ^|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  @|  [| Retn| |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  ]|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shft    |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|MHEN|      Space      |HENK|KNA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
/* JIS layout */
#define LAYOUT_jis( \
    K76,K05,K06,K04,K0C,K03,K0B,K83,K0A,K01,K09,K78,K07,         KFC,K7E,KFE,                   \
    K0E,K16,K1E,K26,K25,K2E,K36,K3D,K3E,K46,K45,K4E,K55,K6A,K66, KF0,KEC,KFD,  K77,KCA,K7C,K7B, \
    K0D,K15,K1D,K24,K2D,K2C,K35,K3C,K43,K44,K4D,K54,K5B,    K5A, KF1,KE9,KFA,  K6C,K75,K7D,     \
    K58,K1C,K1B,K23,K2B,K34,K33,K3B,K42,K4B,K4C,K52,K5D,                       K6B,K73,K74,K79, \
    K12,K1A,K22,K21,K2A,K32,K31,K3A,K41,K49,K4A,K51,        K59,     KF5,      K69,K72,K7A,     \
    K14,K9F,K11,K67,        K29,        K64,K13,K91,KA7,KAF,K94, KEB,KF2,KF4,  K70,    K71,KDA  \
) { \
    { XXXXXXX, K01,     XXXXXXX, K03,     K04,     K05,     K06,     K07     }, \
    { KC_F13,  K09,     K0A,     K0B,     K0C,     K0D,     K0E,     XXXXXXX }, \
    { KC_F14,  K11,     K12,     K13,     K14,     K15,     K16,     XXXXXXX }, \
    { KC_F15,  XXXXXXX, K1A,     K1B,     K1C,     K1D,     K1E,     XXXXXXX }, \
    { KC_F16,  K21,     K22,     K23,     K24,     K25,     K26,     XXXXXXX }, \
    { KC_F17,  K29,     K2A,     K2B,     K2C,     K2D,     K2E,     XXXXXXX }, \
    { KC_F18,  K31,     K32,     K33,     K34,     K35,     K36,     XXXXXXX }, \
    { KC_F19,  XXXXXXX, K3A,     K3B,     K3C,     K3D,     K3E,     XXXXXXX }, \
    { KC_F20,  K41,     K42,     K43,     K44,     K45,     K46,     XXXXXXX }, \
    { KC_F21,  K49,     K4A,     K4B,     K4C,     K4D,     K4E,     XXXXXXX }, \
    { KC_F22,  K51,     K52,     XXXXXXX, K54,     K55,     XXXXXXX, KC_F23  }, \
    { K58,     K59,     K5A,     K5B,     XXXXXXX, K5D,     XXXXXXX, KC_F24  }, \
    { XXXXXXX, KC_NUBS, XXXXXXX, KC_PEQL, K64,     XXXXXXX, K66,     K67     }, \
    { KC_PWR,  K69,     K6A,     K6B,     K6C,     KC_PCMM, XXXXXXX, XXXXXXX }, \
    { K70,     K71,     K72,     K73,     K74,     K75,     K76,     K77     }, \
    { K78,     K79,     K7A,     K7B,     K7C,     K7D,     K7E,     XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, K83,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_WSCH, K91,     XXXXXXX, XXXXXXX, K94,     KC_MPRV, XXXXXXX, XXXXXXX }, \
    { KC_WFAV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K9F     }, \
    { KC_WREF, KC_VOLD, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KA7     }, \
    { KC_WSTP, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, XXXXXXX, KAF     }, \
    { KC_WFWD, XXXXXXX, KC_VOLU, XXXXXXX, KC_MPLY,XXXXXXX,  XXXXXXX, KC_PWR  }, \
    { KC_WBAK, XXXXXXX, KC_WHOM, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP }, \
    { KC_MYCM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KC_MAIL, XXXXXXX, KCA,     XXXXXXX, XXXXXXX, KC_MNXT, XXXXXXX, XXXXXXX }, \
    { KC_MSEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KDA,     XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, \
    { XXXXXXX, KE9,     XXXXXXX, KEB,     KEC,     XXXXXXX, XXXXXXX, XXXXXXX }, \
    { KF0,     KF1,     KF2,     XXXXXXX, KF4,     KF5,     XXXXXXX, XXXXXXX }, \
    { XXXXXXX, XXXXXXX, KFA,     XXXXXXX, KFC,     KFD,     KFE,     XXXXXXX }, \
}
