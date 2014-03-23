/* ----------------------------------------------------------------------------
 * ergoDOX layout : colemak-ak
 * ----------------------------------------------------------------------------
 * Modified by Andrew Kvalheim <Andrew@Kvalhe.im>
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

//
// Aliases
//

// Basic
#define kprrel  &kbfun_press_release
#define ktog    &kbfun_toggle
#define ktrans  &kbfun_transparent

// Layer
#define lpush1  &kbfun_layer_push_1
#define lpush2  &kbfun_layer_push_2
#define lpush3  &kbfun_layer_push_3
#define lpush4  &kbfun_layer_push_4
#define lpush5  &kbfun_layer_push_5
#define lpush6  &kbfun_layer_push_6
#define lpush7  &kbfun_layer_push_7
#define lpush8  &kbfun_layer_push_8
#define lpush9  &kbfun_layer_push_9
#define lpush10 &kbfun_layer_push_10
#define lpop1   &kbfun_layer_pop_1
#define lpop2   &kbfun_layer_pop_2
#define lpop3   &kbfun_layer_pop_3
#define lpop4   &kbfun_layer_pop_4
#define lpop5   &kbfun_layer_pop_5
#define lpop6   &kbfun_layer_pop_6
#define lpop7   &kbfun_layer_pop_7
#define lpop8   &kbfun_layer_pop_8
#define lpop9   &kbfun_layer_pop_9
#define lpop10  &kbfun_layer_pop_10

// Device
#define dbtldr  &kbfun_jump_to_bootloader

// Special
#define sshprre &kbfun_shift_press_release
#define s2kcap  &kbfun_2_keys_capslock_press_release
#define slpunum &kbfun_layer_push_numpad
#define slponum &kbfun_layer_pop_numpad

//
// Layout
//

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Default
  KB_MATRIX_LAYER(
    // Unused
    0,

    // Left
        _equal,     _1,         _2,      _3,      _4, _5, _esc,
    _backslash,     _Q,         _W,      _E,      _R, _T,    1,
          _tab,     _A,         _S,      _D,      _F, _G,
       _shiftL,     _Z,         _X,      _C,      _V, _B,    1,
         _guiL, _grave, _backslash, _arrowL, _arrowR,
                                                                _ctrlL, _altL,
                                                             0,      0, _home,
                                                           _bs,   _del,  _end,

    // Right
                       3, _6,      _7,      _8,      _9,         _0,     _dash,
               _bracketL, _Y,      _U,      _I,      _O,         _P, _bracketR,
                          _H,      _J,      _K,      _L, _semicolon,    _quote,
                       1, _N,      _M,  _comma, _period,     _slash,   _shiftR,
                              _arrowL, _arrowD, _arrowU,    _arrowR,     _guiR,
    _altR,  _ctrlR,
    _pageU,      0,      0,
    _pageD, _enter, _space
  ),

  // Layer 1: Function and symbol keys
  KB_MATRIX_LAYER(
    // Unused
    0,

    // Left
    0,        _F1,       _F2,       _F3,       _F4,        _F5, _F11,
    0,  _bracketL, _bracketR, _bracketL, _bracketR,          0,    1,
    0, _semicolon,    _slash,     _dash,     _0_kp, _semicolon,
    0,      _6_kp,     _7_kp,     _8_kp,     _9_kp,     _equal,    2,
    0,          0,         0,         0,         0,
                                                                      0, 0,
                                                                   0, 0, 0,
                                                                   0, 0, 0,
    // Right
       _F12,        _F6,   _F7,    _F8,     _F9,          _F10,   _power,
          0,          0, _dash, _comma, _period, _currencyUnit, _volumeU,
             _backslash, _1_kp,     _9,      _0,        _equal, _volumeD,
          2,         _8, _2_kp,  _3_kp,   _4_kp,         _5_kp,    _mute,
                             0,      0,       0,             0,        0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  ),

  // Layer 2: Keyboard functions
  KB_MATRIX_LAYER(
    // Unused
    0,

    // Left
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
                         0, 0,
                      0, 0, 0,
                      0, 0, 0,

    // Right
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  ),

  // Layer 3: Numpad
  KB_MATRIX_LAYER(
    // Unused
    0,

    // Left
    0,       0, 0, 0, 0, 0, 0,
    0,       0, 0, 0, 0, 0, 0,
    0,       0, 0, 0, 0, 0,
    0,       0, 0, 0, 0, 0, 0,
    0, _insert, 0, 0, 0,
                               0, 0,
                            0, 0, 0,
                            0, 0, 0,

    // Right
              3, 0,     3, _equal_kp, _div_kp,   _mul_kp, 0,
              0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp, 0,
                 0, _4_kp,     _5_kp,   _6_kp,   _add_kp, 0,
              0, 0, _1_kp,     _2_kp,   _3_kp, _enter_kp, 0,
                        0,         0, _period, _enter_kp, 0,
    0, 0,
    0, 0,     0,
    0, 0, _0_kp
  ),
};

//
// Press
//

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Default
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
    kprrel, kprrel, kprrel, kprrel, kprrel,
                                                            kprrel, kprrel,
                                                      NULL,   NULL, kprrel,
                                                    kprrel, kprrel, kprrel,

    // Right
                    slpunum, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                             kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     lpush1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                                     kprrel, kprrel, kprrel, kprrel, kprrel,
     kprrel, kprrel,
     kprrel,   NULL,   NULL,
     kprrel, kprrel, kprrel
  ),

  // Layer 1: Function and symbol keys
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
      NULL,  kprrel,  kprrel, kprrel, kprrel,  kprrel, kprrel,
    ktrans, sshprre, sshprre, kprrel, kprrel,    NULL,  lpop1,
    ktrans,  kprrel,  kprrel, kprrel, kprrel, sshprre,
    ktrans,  kprrel,  kprrel, kprrel, kprrel, sshprre, lpush2,
    ktrans,  ktrans,  ktrans, ktrans, ktrans,
                                                               ktrans, ktrans,
                                                       ktrans, ktrans, ktrans,
                                                       ktrans, ktrans, ktrans,

    // Right
                    kprrel,  kprrel, kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                    ktrans,    NULL, kprrel, sshprre, sshprre,  kprrel, kprrel,
                             kprrel, kprrel, sshprre, sshprre, sshprre, kprrel,
                    lpush2, sshprre, kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                                     ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 2: Keyboard functions
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left hand
    dbtldr, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL, NULL, NULL,
      NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL,
                                          NULL, NULL, NULL,
                                          NULL, NULL, NULL,

    // Right
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL,
    NULL, NULL,
    NULL, NULL, NULL,
    NULL, NULL, NULL
  ),

  // Layer 3: Numpad
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, kprrel, ktrans, ktrans, ktrans,
                                                    ktrans, ktrans,
                                            ktrans, ktrans, ktrans,
                                            ktrans, ktrans, ktrans,

    // Right
                   slponum, ktrans, slponum, kprrel, kprrel, kprrel, ktrans,
                    ktrans, ktrans,  kprrel, kprrel, kprrel, kprrel, ktrans,
                            ktrans,  kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans, ktrans,  kprrel, kprrel, kprrel, kprrel, ktrans,
                                     ktrans, ktrans, kprrel, kprrel, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, kprrel
  ),
};

//
// Release
//

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Default
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    s2kcap, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop1,
    kprrel, kprrel, kprrel, kprrel, kprrel,
                                                            kprrel, kprrel,
                                                      NULL,   NULL, kprrel,
                                                    kprrel, kprrel, kprrel,

    // Right
                      NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                            kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     lpop1, kprrel, kprrel, kprrel, kprrel, kprrel, s2kcap,
                                    kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel,
    kprrel,   NULL,   NULL,
    kprrel, kprrel, kprrel
  ),

  // Layer 1: Function and symbol keys
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
      NULL,  kprrel,  kprrel, kprrel, kprrel,  kprrel, kprrel,
    ktrans, sshprre, sshprre, kprrel, kprrel,    NULL,   NULL,
    ktrans,  kprrel,  kprrel, kprrel, kprrel, sshprre,
    ktrans,  kprrel,  kprrel, kprrel, kprrel, sshprre,  lpop2,
    ktrans,  ktrans,  ktrans, ktrans, ktrans,
                                                               ktrans, ktrans,
                                                       ktrans, ktrans, ktrans,
                                                       ktrans, ktrans, ktrans,

    // Right
                    kprrel,  kprrel, kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                    ktrans,    NULL, kprrel, sshprre, sshprre,  kprrel, kprrel,
                             kprrel, kprrel, sshprre, sshprre, sshprre, kprrel,
                     lpop2, sshprre, kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                                     ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 2: Keyboard functions
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL,
                                              NULL, NULL,
                                        NULL, NULL, NULL,
                                        NULL, NULL, NULL,

    // Right
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                            NULL, NULL, NULL, NULL, NULL,
    NULL, NULL,
    NULL, NULL, NULL,
    NULL, NULL, NULL
  ),

  // Layer 3: Numpad
  KB_MATRIX_LAYER(
    // Unused
    NULL,

    // Left
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, kprrel, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                      NULL, ktrans,   NULL, kprrel, kprrel, kprrel, ktrans,
                    ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                            ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                                    ktrans, ktrans, kprrel, kprrel, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, kprrel
  )
};
