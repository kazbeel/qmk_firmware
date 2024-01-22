#include QMK_KEYBOARD_H

#include "babel.h"

void BABEL_process_linux(uint16_t keycode) {
    if (keycode == BABEL_COPY) {
        SEND_STRING(SS_LCTL("c"));
    } else if (keycode == BABEL_CUT) {
        SEND_STRING(SS_LCTL("x"));
    } else if (keycode == BABEL_PASTE) {
        SEND_STRING(SS_LCTL("v"));
    } else if (keycode == BABEL_UNDO) {
        SEND_STRING(SS_LCTL("z"));
    } else if (keycode == BABEL_REDO) {
        SEND_STRING(SS_LCTL("y"));
    } else if (keycode == BABEL_LOCK) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_ALT) SS_TAP(X_L) SS_UP(X_LEFT_ALT) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_SUSPEND) {
        SEND_STRING(SS_DOWN(X_SLEP) SS_UP(X_SLEP));
    } else if (keycode == BABEL_POWER_DOWN) {
        SEND_STRING(SS_DOWN(X_PWR) SS_UP(X_PWR));
    } else if (keycode == BABEL_SCREENSHOT) {
        SEND_STRING(SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_PSCR) SS_UP(X_LEFT_SHIFT));
    } else if (keycode == BABEL_MULTI_TASK_VIEW) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_TAP(X_F9) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_APP_WINDOWS) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_TAP(X_F7) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_DESKTOP_NEXT) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_GUI) SS_TAP(X_LEFT) SS_UP(X_LEFT_GUI) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_DESKTOP_PREV) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_GUI) SS_TAP(X_RIGHT) SS_UP(X_LEFT_GUI) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_SYSTEM_SEARCH) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_SPC) SS_UP(X_LEFT_CTRL) SS_UP(X_LEFT_SHIFT));
    } else if (keycode == BABEL_CONSOLE) {
        SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_DOWN(X_LEFT_ALT) SS_DOWN(X_LEFT_GUI) SS_TAP(X_SPC) SS_UP(X_LEFT_GUI) SS_UP(X_LEFT_ALT) SS_UP(X_LEFT_CTRL));
    } else if (keycode == BABEL_ES_TILD) {
        SEND_STRING(SS_DOWN(X_RIGHT_ALT) SS_TAP(X_4) SS_UP(X_RIGHT_ALT));
    }
}
