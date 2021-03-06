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
#define kprrel   &kbfun_press_release
#define kprpst   &kbfun_press_release_preserve_sticky
#define ktog     &kbfun_toggle
#define ktrans   &kbfun_transparent

// Layer
#define lpush1   &kbfun_layer_push_1
#define lpush2   &kbfun_layer_push_2
#define lpush3   &kbfun_layer_push_3
#define lpush4   &kbfun_layer_push_4
#define lpush5   &kbfun_layer_push_5
#define lpop1    &kbfun_layer_pop_1
#define lpop2    &kbfun_layer_pop_2
#define lpop3    &kbfun_layer_pop_3
#define lpop4    &kbfun_layer_pop_4
#define lpop5    &kbfun_layer_pop_5
#define lsticky1 &kbfun_layer_sticky_1
#define lsticky2 &kbfun_layer_sticky_2
#define lsticky3 &kbfun_layer_sticky_3
#define lsticky4 &kbfun_layer_sticky_4
#define lsticky5 &kbfun_layer_sticky_5

// Device
#define dbtldr   &kbfun_jump_to_bootloader

// Special
#define sshprre  &kbfun_shift_press_release
#define s2kcap   &kbfun_2_keys_capslock_press_release
#define slpunum  &kbfun_layer_push_numpad
#define slponum  &kbfun_layer_pop_numpad

// Media keys
#define mprrel   &kbfun_mediakey_press_release

//
// Layout
//

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Soft Colemak
  KB_MATRIX_LAYER(
    0,

    // Left
    _application,   _F1,  _F2,  _F3,  _F4, _F5,   _F6,
            _esc,    _Q,   _W,   _E,   _R,  _T, _home,
             _bs,    _A,   _S,   _D,   _F,  _G,
         _shiftL,    _Z,   _X,   _C,   _V,  _B,  _end,
            _F13,  _F14, _F15, _F16, _F17,
                                                        _F18,   _F19,
                                                    0,     0, _enter,
                                               _ctrlL, _altL,  _guiL,

    // Right
                      _F7, _F8, _F9,   _F10,    _F11,       _F12, MEDIAKEY_PLAY_PAUSE,
                   _pageU,  _Y,  _U,     _I,      _O,         _P,                _del,
                            _H,  _J,     _K,      _L, _semicolon,                _tab,
                   _pageD,  _N,  _M, _comma, _period,     _slash,                   1,
                                  3,      2,    _F22,       _F23,                _F24,
    _F20,    _F21,
    _bs,        0,      0,
    _altR, _enter, _space
  ),

  // Layer 1: Symbol
  KB_MATRIX_LAYER(
    0,

    // Left
    0,      0,       0,      0,      0,  0, 0,
    0,     _4,      _5,     _8, _slash, _6, 0,
    0,     _2,   _dash, _equal,  _dash, _7,
    0, _comma, _period, _equal, _grave, _3, 0,
    0,      0,       0,      0,      0,
                                               0, 0,
                                            0, 0, 0,
                                            0, 0, 0,

    // Right
          0,          0,         0,         0,      0,          0, 0,
          0,          0, _bracketL, _bracketR, _grave, _semicolon, 0,
             _backslash,        _9,        _0, _quote,     _quote, 0,
          0,          0, _bracketL, _bracketR,     _1, _backslash, 0,
                                 0,         0,      0,          0, 0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  ),

  // Layer 2: Number
  KB_MATRIX_LAYER(
    0,

    // Left
    0,      0,       0,      0,      0,  0, 0,
    0,     _4,      _5,     _8, _slash, _6, 0,
    0,     _2,   _dash, _equal,  _dash, _7,
    0, _comma, _period, _equal, _grave, _3, 0,
    0,      0,       0,      0,      0,
                                               0, 0,
                                            0, 0, 0,
                                            0, 0, 0,

    // Right
          0,  0,  0,  0,  0,       0, 0,
          0,  0, _7, _8, _9,       0, 0,
             _0, _4, _5, _6, _period, 0,
          0,  0, _1, _2, _3,       0, 0,
                  0,  0,  0,       0, 0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    0,

    // Left
    5, 0,  0,  0,  0, 0,  0,
    4, 0,  0, _W,  0, 0, _H,
    0, 0, _A, _D, _G, 0,
    0, 0,  0,  0,  0, 0, _U,
    0, 0,  0,  0,  0,
                          0, 0,
                       0, 0, 0,
                       0, 0, 0,

    // Right
           0, 0,       0,       0,       0, 0, MEDIAKEY_NEXT_TRACK,
          _N, 0,       0, _arrowU,       0, 0,                   0,
              0, _arrowL, _arrowD, _arrowR, 0,                   0,
          _Y, 0,       0,       0,       0, 0,                   0,
                       0,       0,       0, 0,                   0,
    0, 0,
    0, 0,  0,
    0, 0,  0
  ),

  // Layer 4: Recovery
  KB_MATRIX_LAYER(
    0,

    // Left
         0, 0, 0, 0, 0, 0, 0,
         4, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0,
                              0, 0,
                           0, 0, 0,
                      _ctrlR, 0, 0,

    // Right
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,
    0, 0,
    0, 0, 0,
    0, 0, _sysReq
  ),

  // Layer 5: Hard Colemak
  KB_MATRIX_LAYER(
    0,

    // Left
    5,  0,  0,  0,  0,  0, 0,
    0, _Q, _W, _F, _P, _G, 0,
    0, _A, _R, _S, _T, _D,
    0, _Z, _X, _C, _V, _B, 0,
    0,  0,  0,  0,  0,
                           0, 0,
                           0, 0, 0,
                           0, 0, 0,

    // Right
          0,  0,  0,      0,       0,          0, 0,
          0, _J, _L,     _U,      _Y, _semicolon, 0,
             _H, _N,     _E,      _I,         _O, 0,
          0, _K, _M, _comma, _period,     _slash, 0,
                  0,      0,       0,          0, 0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  )
};

//
// Press
//

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Soft Colemak
  KB_MATRIX_LAYER(
    NULL,

    // Left
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel,
                                                            kprrel, kprrel,
                                                      NULL,   NULL, kprrel,
                                                    kprrel, kprrel, kprrel,

    // Right
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, mprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                             kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
                                     lpush3, lpush2, kprrel, kprrel, kprrel,
    kprrel, kprrel,
    kprrel,   NULL,   NULL,
    kprrel, kprrel, kprrel
  ),

  // Layer 1: Symbol
  KB_MATRIX_LAYER(
    NULL,

    // Left
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
    ktrans, sshprre, sshprre,  kprrel,  kprrel, sshprre,
      NULL, sshprre, sshprre, sshprre, sshprre, sshprre, ktrans,
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
                                                                 ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,

    // Right
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
                    ktrans,    NULL,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                            sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
                    ktrans,    NULL, sshprre, sshprre, sshprre,  kprrel,   NULL,
                                      ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 2: Number
  KB_MATRIX_LAYER(
    NULL,

    // Left
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
    ktrans, sshprre, sshprre,  kprrel,  kprrel, sshprre,
      NULL, sshprre, sshprre, sshprre, sshprre, sshprre, ktrans,
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
                                                                 ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,

    // Right
                    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                            kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,   NULL,
                                    ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
    lpush5, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    lpush4,   NULL,   NULL, kprrel,   NULL,   NULL, kprrel,
    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,
    ktrans,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, mprrel,
                kprrel,   NULL,   NULL, kprrel,   NULL,   NULL, ktrans,
                          NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                kprrel,   NULL,   NULL,   NULL,   NULL,   NULL, ktrans,
                                ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 4: Recovery
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
     NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
    lpop4, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
     NULL, ktrans, ktrans, ktrans, ktrans, ktrans,
     NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
     NULL,   NULL,   NULL,   NULL,   NULL,
                                                           NULL, NULL,
                                                   NULL,   NULL, NULL,
                                                 kprrel, ktrans, NULL,

    // Right
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                  NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
                        ktrans, ktrans, ktrans, ktrans,   NULL, NULL,
                  NULL, ktrans, ktrans,   NULL,   NULL,   NULL, NULL,
                                  NULL,   NULL,   NULL,   NULL, NULL,
    NULL, NULL,
    NULL, NULL,   NULL,
    NULL, NULL, kprrel
  ),

  // Layer 5: Hard Colemak
  KB_MATRIX_LAYER(
    NULL,

    // Left
     lpop5, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                            kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                                    ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  )
};

//
// Release
//

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
  // Layer 0: Soft Colemak
  KB_MATRIX_LAYER(
    NULL,

    // Left
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel, kprrel, kprrel, kprrel,
                                                            kprrel, kprrel,
                                                      NULL,   NULL, kprrel,
                                                    kprrel, kprrel, kprrel,

    // Right
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, mprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                             kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop1,
                                      lpop3,  lpop2, kprrel, kprrel, kprrel,
    kprrel, kprrel,
    kprrel,   NULL,   NULL,
    kprrel, kprrel, kprrel
  ),

  // Layer 1: Symbol
  KB_MATRIX_LAYER(
    NULL,

    // Left
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
    ktrans, sshprre, sshprre,  kprrel,  kprrel, sshprre,
      NULL, sshprre, sshprre, sshprre, sshprre, sshprre, ktrans,
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
                                                                 ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,

    // Right
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
                    ktrans,    NULL,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                            sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
                    ktrans,    NULL, sshprre, sshprre, sshprre,  kprrel,   NULL,
                                      ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 2: Number
  KB_MATRIX_LAYER(
    NULL,

    // Left
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
    ktrans, sshprre, sshprre,  kprrel,  kprrel, sshprre,
      NULL, sshprre, sshprre, sshprre, sshprre, sshprre, ktrans,
    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,
                                                                 ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,
                                                         ktrans, ktrans, ktrans,

    // Right
                    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                            kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,   NULL,
                                    ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
      NULL,   NULL,   NULL, kprrel,   NULL,   NULL, kprrel,
    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,
    ktrans,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, mprrel,
                kprrel,   NULL,   NULL, kprrel,   NULL,   NULL, ktrans,
                          NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                kprrel,   NULL,   NULL,   NULL,   NULL,   NULL, ktrans,
                                ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 4: Recovery
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
    NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
    NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
    NULL, ktrans, ktrans, ktrans, ktrans, ktrans,
    NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
    NULL,   NULL,   NULL,   NULL,   NULL,
                                                          NULL, NULL,
                                                  NULL,   NULL, NULL,
                                                kprrel, ktrans, NULL,

    // Right
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                  NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
                        ktrans, ktrans, ktrans, ktrans,   NULL, NULL,
                  NULL, ktrans, ktrans,   NULL,   NULL,   NULL, NULL,
                                  NULL,   NULL,   NULL,   NULL, NULL,
    NULL, NULL,
    NULL, NULL,   NULL,
    NULL, NULL, kprrel
  ),

  // Layer 5: Hard Colemak
  KB_MATRIX_LAYER(
    NULL,

    // Left
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel,
    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                            kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                    ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
                                    ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  )
};
