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
#define lpop1    &kbfun_layer_pop_1
#define lpop2    &kbfun_layer_pop_2
#define lpop3    &kbfun_layer_pop_3
#define lpop4    &kbfun_layer_pop_4
#define lsticky1 &kbfun_layer_sticky_1
#define lsticky2 &kbfun_layer_sticky_2
#define lsticky3 &kbfun_layer_sticky_3
#define lsticky4 &kbfun_layer_sticky_4

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
                                                       _guiL, _altL,
                                                    0,     0,  _F23,
                                               _ctrlL,     1,     2,

    // Right
                      _F7, _F8,  _F9,   _F10,    _F11,       _F12, MEDIAKEY_PLAY_PAUSE,
                   _pageU,  _Y,   _U,     _I,      _O,         _P,                _del,
                            _H,   _J,     _K,      _L, _semicolon,                _tab,
                   _pageD,  _N,   _M, _comma, _period,     _slash,             _shiftR,
                                _F18,   _F19,    _F20,       _F21,                _F22,
    _altR, _guiR,
     _F24,     0,       0,
        3, _enter, _space
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
          0,          0,         0,         0,      0,          0, MEDIAKEY_NEXT_TRACK,
          0,          0, _bracketL, _bracketR, _grave, _semicolon,                   0,
             _backslash,        _9,        _0, _quote,     _quote,                   0,
          0,          0, _bracketL, _bracketR,     _1, _backslash,                   0,
                                 0,         0,      0,          0,                   0,
    0, 0,
    0, 0, 0,
    4, 0, 0
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
          0,         0,  0,      0,       0,         0, 0,
          0, _bracketL, _7,     _8,      _9, _bracketR, 0,
                    _9, _4,     _5,      _6,        _0, 0,
          0, _bracketL, _1,     _2,      _3, _bracketR, 0,
                        _0, _comma, _period,         0, 0,
    0, 0,
    0, 0, 0,
    0, 0, 0
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    0,

    // Left
    0, 0,  0,  0,  0, 0,  0,
    0, 0,  0, _W,  0, 0, _H,
    0, 0, _A, _D, _G, 0,
    0, 0,  0,  0,  0, 0, _U,
    0, 0,  0,  0,  0,
                          0, 0,
                       0, 0, 0,
                       0, 0, 0,

    // Right
           0, 0,       0,       0,       0, 0, 0,
          _N, 0,       0, _arrowU,       0, 0, 0,
              0, _arrowL, _arrowD, _arrowR, 0, 0,
          _Y, 0,       0,       0,       0, 0, 0,
                       0,       0,       0, 0, 0,
    0, 0,
    0, 0,  0,
    0, 0,  0
  ),

  // Layer 4: System
  KB_MATRIX_LAYER(
    0,

    // Left
         0, 0, 0, 0, 0, 0, 0,
    _ctrlR, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0,
                              0, 0,
                           0, 0, 0,
                       _altL, 0, 0,

    // Right
          0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,
    0, 0,
    0, 0, 0,
    4, 0, _sysReq
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
                                                    kprrel, lpush1, lpush2,

    // Right
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, mprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                             kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                                     kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel,
    kprrel,   NULL,   NULL,
    lpush3, kprrel, kprrel
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
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, mprrel,
                    ktrans,    NULL,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                            sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
                    ktrans,    NULL, sshprre, sshprre, sshprre,  kprrel,   NULL,
                                      ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    lpush4, ktrans, ktrans
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
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
                    ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, ktrans,
                            sshprre,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                    ktrans, sshprre,  kprrel,  kprrel,  kprrel, sshprre,   NULL,
                                      kprrel,  kprrel,  kprrel,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans,   NULL,   NULL, kprrel,   NULL,   NULL, kprrel,
    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,
    ktrans,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                kprrel,   NULL,   NULL, kprrel,   NULL,   NULL, ktrans,
                          NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                kprrel,   NULL,   NULL,   NULL,   NULL,   NULL, ktrans,
                                ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 4: System
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
      NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
    kprrel, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans,
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
      NULL,   NULL,   NULL,   NULL,   NULL,
                                                            NULL,   NULL,
                                                    NULL,   NULL,   NULL,
                                                  kprrel,   NULL,   NULL,

    // Right
                   NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                   NULL, ktrans, ktrans, ktrans, ktrans,   NULL, NULL,
                         ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
                   NULL, ktrans, ktrans,   NULL,   NULL,   NULL, NULL,
                                   NULL,   NULL,   NULL,   NULL, NULL,
     NULL, NULL,
     NULL, NULL,   NULL,
    lpop4, NULL, kprrel
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
                                                    kprrel,  lpop1,  lpop2,

    // Right
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, mprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                             kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                     kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                                     kprrel, kprrel, kprrel, kprrel, kprrel,
    kprrel, kprrel,
    kprrel,   NULL,   NULL,
     lpop3, kprrel, kprrel
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
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, mprrel,
                    ktrans,    NULL,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                            sshprre, sshprre, sshprre,  kprrel, sshprre, ktrans,
                    ktrans,    NULL, sshprre, sshprre, sshprre,  kprrel,   NULL,
                                      ktrans,  ktrans,  ktrans,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
      NULL, ktrans, ktrans
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
                    ktrans,  ktrans,  ktrans,  ktrans,  ktrans,  ktrans, ktrans,
                    ktrans,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, ktrans,
                            sshprre,  kprrel,  kprrel,  kprrel, sshprre, ktrans,
                    ktrans, sshprre,  kprrel,  kprrel,  kprrel, sshprre,   NULL,
                                      kprrel,  kprrel,  kprrel,  ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 3: Navigation
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
    ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans,   NULL,   NULL, kprrel,   NULL,   NULL, kprrel,
    ktrans,   NULL, kprrel, kprrel, kprrel,   NULL,
    ktrans,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
    ktrans, ktrans, ktrans, ktrans, ktrans,
                                                            ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,
                                                    ktrans, ktrans, ktrans,

    // Right
                ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
                kprrel,   NULL,   NULL, kprrel,   NULL,   NULL, ktrans,
                          NULL, kprrel, kprrel, kprrel,   NULL, ktrans,
                kprrel,   NULL,   NULL,   NULL,   NULL,   NULL, ktrans,
                                ktrans, ktrans, ktrans, ktrans, ktrans,
    ktrans, ktrans,
    ktrans, ktrans, ktrans,
    ktrans, ktrans, ktrans
  ),

  // Layer 4: System
  KB_MATRIX_LAYER(
    NULL,

    // Left hand
      NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
    kprrel, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans,
      NULL, ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
      NULL,   NULL,   NULL,   NULL,   NULL,
                                                            NULL,   NULL,
                                                    NULL,   NULL,   NULL,
                                                  kprrel,   NULL,   NULL,

    // Right
                   NULL,   NULL,   NULL,   NULL,   NULL,   NULL, NULL,
                   NULL, ktrans, ktrans, ktrans, ktrans,   NULL, NULL,
                         ktrans, ktrans, ktrans, ktrans, ktrans, NULL,
                   NULL, ktrans, ktrans,   NULL,   NULL,   NULL, NULL,
                                   NULL,   NULL,   NULL,   NULL, NULL,
     NULL, NULL,
     NULL, NULL,   NULL,
     NULL, NULL, kprrel
  )
};
