#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
#include "babel/babel.h"
#include "print.h"

#ifdef OLED_ENABLE
static const char PROGMEM crkbd_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
#endif

// Mod-tap keys
#define A_CTL     LCTL_T(KC_A)
#define S_ALT     LALT_T(KC_S)
#define D_GUI     LGUI_T(KC_D)
#define F_SFT     LSFT_T(KC_F)

#define J_SFT     LSFT_T(KC_J)
#define K_GUI     LGUI_T(KC_K)
#define L_ALT     RALT_T(KC_L)
#define NTIL_CTL  LCTL_T(ES_NTIL)

// Multifunction layer toggle and simple keycode
#define NAV_TAB   LT(NAV, KC_TAB)
#define NUM_ENT   LT(NUM, KC_ENT)

enum custom_keycodes {
    NEXT_CUSTOM_KEYCODE = BABEL_END_RANGE,
};

enum layer_names {
    BASE,
    // GAMING,
    NAV,
    NUM,
    SYM,
    MEDIA,
    FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_Q,   KC_W,   KC_E,   KC_R,         KC_T,                       KC_Y,     KC_U,   KC_I,      KC_O,    KC_P,      KC_BACKSPACE,
    KC_ESC,   A_CTL,  S_ALT,  D_GUI,  F_SFT,        KC_G,                       KC_H,     J_SFT,  K_GUI,     L_ALT,   NTIL_CTL,  ES_ACUT,
    KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,         KC_B,                       KC_N,     KC_M,   KC_COMMA,  KC_DOT,  ES_MINS,   XXXXXXX,
                                      BBL_CONSOLE,  NAV_TAB,  NUM_ENT,  KC_SPC, MO(SYM),  MO(FUNC)
  ),

//   [GAMING] = LAYOUT_split_3x6_3(
//     XXXXXXX,  KC_Q,   KC_W,   KC_E,   KC_R,         KC_T,                      KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,      KC_BACKSPACE,
//     KC_ESC,   A_CTL,  S_ALT,  D_GUI,  F_SFT,        KC_G,                      KC_H,     J_SFT,    K_GUI,     L_ALT,    NTIL_CTL,  ES_ACUT,
//     KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,         KC_B,                      KC_N,     KC_M,     KC_COMMA,  KC_DOT,   ES_MINS,   XXXXXXX,
//                                       BBL_CONSOLE,  NAV_TAB, NUM_ENT  KC_SPC,  MO(SYM),  MO(FUNC)
//   ),

  [NAV] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,    XXXXXXX,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_LCTL,   KC_LALT,  KC_LGUI,   KC_LSFT,    XXXXXXX,                       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  BBL_UNDO,  BBL_CUT,  BBL_COPY,  BBL_PASTE,  BBL_REDO,                      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,    XXXXXXX,  XXXXXXX,
                                              _______,    _______,   XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
  ),

  [NUM] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      KC_PERC,  KC_7,  KC_8,  KC_9,  KC_PSLS,  KC_BACKSPACE,
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  XXXXXXX,                      ES_LPRN,  KC_4,  KC_5,  KC_6,  KC_PPLS,  KC_PAST,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      ES_RPRN,  KC_1,  KC_2,  KC_3,  KC_PMNS,  ES_EQL,
                                            XXXXXXX,  XXXXXXX,  _______,  _______,  KC_0,     KC_DOT
  ),

  [SYM] = LAYOUT_split_3x6_3(
    ES_CIRC,      ES_PIPE,  ES_AT,    KC_PERC,  KC_DLR,   XXXXXXX,                        XXXXXXX,  ES_LBRC,  ES_RBRC,  ES_IQUE,  ES_QUES,  KC_DELETE,
    BBL_ES_TILD,  ES_AMPR,  ES_HASH,  ES_BSLS,  ES_SLSH,  XXXXXXX,                        XXXXXXX,  ES_LPRN,  ES_RPRN,  ES_EQL,   ES_PLUS,  ES_ASTR,
    XXXXXXX,      ES_LABK,  ES_RABK,  ES_DQUO,  ES_QUOT,  ES_GRV,                         XXXXXXX,  ES_LCBR,  ES_RCBR,  ES_IEXL,  KC_EXLM,  XXXXXXX,
                                                XXXXXXX,  MO(MEDIA),  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX
  ),

  [MEDIA] = LAYOUT_split_3x6_3(
    QK_BOOT,  XXXXXXX,       RGB_TOG,  RGB_MOD,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  BBL_LOCK,        XXXXXXX,
    XXXXXXX,  BBL_OS_SHIFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  BBL_SUSPEND,     XXXXXXX,
    XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                     XXXXXXX,  KC_VOLD,  KC_MUTE,  KC_VOLU,  BBL_POWER_DOWN,  XXXXXXX,
                                                 XXXXXXX,  _______,  XXXXXXX, _______,  XXXXXXX,  XXXXXXX
  ),

  [FUNC] = LAYOUT_split_3x6_3(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,                     XXXXXXX,           XXXXXXX,          BBL_SYSTEM_SEARCH,    XXXXXXX,           XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,                     BBL_DESKTOP_PREV,  BBL_APP_WINDOWS,  BBL_MULTI_TASK_VIEW,  BBL_DESKTOP_NEXT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,                     XXXXXXX,           BBL_SCREENSHOT,   XXXXXXX,              XXXXXXX,           XXXXXXX,  XXXXXXX,
                                            KC_LCTL,  KC_LALT,  KC_LSFT, XXXXXXX,  XXXXXXX,  _______
  ),
};

static uint8_t current_os = BBL_OS_MAC;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_processed = BABEL_process(keycode, record->event.pressed);

    if (is_processed == true) {
        uint8_t cur_os = BABEL_get_current_os();

        if (current_os != cur_os) {
            current_os = cur_os;
        }

        return false;
    }

    switch (keycode) {
        default:
            return true;
    }

    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  uint8_t current_os = BABEL_get_current_os();

  switch(keycode) {
    case S_ALT:
    case D_GUI:
    case K_GUI:
    case L_ALT:
        if (current_os == BBL_OS_LINUX || current_os == BBL_OS_WINDOWS) {
            // Disable selection of App's menu when pressing ALT without any combination
            // Disable Windows Menu and Linux Desktop Manager when pressing GUI without any combination
            return -1;
        } else if (current_os == BBL_OS_MAC) {
            return TAPPING_TERM + 50;
        }
    case A_CTL:
    case F_SFT:
    case J_SFT:
    case NTIL_CTL:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

// layer_state_t layer_state_set_user(layer_state_t state) {
    // uint8_t is_gaming_layer_on = IS_LAYER_ON(GAMING);

    // if (is_gaming_layer_on) {
    //     rgb_matrix_mode_noeeprom(RGB_MATRIX_ALPHAS_MODS);
    // } else {
    //     rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
    // }

    // return state;
// }

static deferred_token token = -1;
static bool show_os_mode_change = false;

static uint32_t turn_off_os_mode_led(uint32_t trigger_time, void *cb_arg) {
    token = -1;
    show_os_mode_change = false;
    rgb_matrix_set_color(6, RGB_OFF);
    rgb_matrix_set_color(33, RGB_OFF);

    return 0;
}

void BABEL_os_switched_callback(uint8_t new_os) {
    show_os_mode_change = true;

    if(token != -1) {
      cancel_deferred_exec(token);
    }

    token = defer_exec(2000, turn_off_os_mode_led, NULL);
}

bool rgb_matrix_indicators_user(void) {
    if(show_os_mode_change) {
        switch(current_os) {
            case BBL_OS_LINUX:
                rgb_matrix_set_color(6, RGB_ORANGE);
                rgb_matrix_set_color(33, RGB_ORANGE);
            break;

            case BBL_OS_WINDOWS:
                rgb_matrix_set_color(6, RGB_BLUE);
                rgb_matrix_set_color(33, RGB_BLUE);
            break;

            case BBL_OS_MAC:
                rgb_matrix_set_color(6, RGB_WHITE);
                rgb_matrix_set_color(33, RGB_WHITE);
            break;
        }
    }

    return false;
}

void keyboard_post_init_user(void) {
//   debug_enable = true;
//   debug_matrix = true;
//   debug_keyboard = true;
//   debug_mouse = true;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  } else {
    return rotation;
  }
}

void render_layer_state(void) {
  oled_write_P(PSTR("Layr:"), false);

  switch (biton32(layer_state)) {
    case BASE:
      oled_write_P(PSTR(" DFLT"), false);
      break;
    case NAV:
      oled_write_P(PSTR("  NAV"), false);
      break;
    case NUM:
      oled_write_P(PSTR("  NUM"), false);
      break;
    case SYM:
      oled_write_P(PSTR("  SYM"), false);
      break;
    case MEDIA:
      oled_write_P(PSTR("MEDIA"), false);
      break;
    case FUNC:
      oled_write_P(PSTR(" FUNC"), false);
      break;
    default:
      oled_write_P(PSTR("?????"), false);
  }
}

void render_mod_status(uint8_t modifiers) {
  oled_write_P(PSTR("     "), false);
  oled_write_P(PSTR("Mods:"), false);
  oled_write_P(PSTR(" SHFT"), (modifiers & MOD_MASK_SHIFT));
  oled_write_P(PSTR(" CTRL"), (modifiers & MOD_MASK_CTRL));
  oled_write_P(PSTR(" META"), (modifiers & MOD_MASK_GUI));
  oled_write_P(PSTR("  ALT"), (modifiers & MOD_MASK_ALT));
}

void render_operating_system(void) {
    oled_write_P(PSTR("     "), false);
    oled_write_P(PSTR("OS:  "), false);
    switch (current_os) {
        case BBL_OS_LINUX:
            oled_write_P(PSTR("Linux"), false);
            break;
        case BBL_OS_WINDOWS:
            oled_write_P(PSTR("WIN  "), false);
            break;
        case BBL_OS_MAC:
            oled_write_P(PSTR("macOS"), false);
            break;
        default:
            oled_write_P(PSTR("?????"), false);
    }
}

void render_status_main(void) {
  render_layer_state();
  render_mod_status(get_mods() | get_oneshot_mods());
  render_operating_system();
}

void render_crkbd_logo(void) {
  oled_write_P(crkbd_logo, false);
}

void render_status_secondary(void) {
  render_crkbd_logo();
  oled_scroll_left();
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    render_status_secondary();
  }

  return false;
}

#endif /* OLED_ENABLE */
