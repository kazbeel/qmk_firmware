#include QMK_KEYBOARD_H

#include "babel.h"

__attribute__((weak)) void BABEL_os_switched_callback(uint8_t new_os) {}

static uint8_t current_os = BABEL_OS_MAC;

// Return value indicates whether the keystroke has been handled
bool BABEL_process(uint16_t keycode, bool pressed) {
    if (keycode <= BABEL_START || keycode >= BABEL_END_RANGE) {
        return false;
    }

    if (pressed == false) {
        return false;
    }

    if (keycode == BABEL_SET_OS_LINUX) {
        BABEL_set_os(BABEL_OS_LINUX);
        return true;
    }

    if (keycode == BABEL_SET_OS_WINDOWS) {
        BABEL_set_os(BABEL_OS_WINDOWS);
        return true;
    }

    if (keycode == BABEL_SET_OS_MAC) {
        BABEL_set_os(BABEL_OS_MAC);
        return true;
    }

    if (keycode == BABEL_SHIFT_OS) {
        BABEL_shift_os();
        return true;
    }

    if (current_os == BABEL_OS_LINUX) {
        BABEL_process_linux(keycode);
    } else if (current_os == BABEL_OS_WINDOWS) {
        BABEL_process_windows(keycode);
    } else if (current_os == BABEL_OS_MAC) {
        BABEL_process_mac(keycode);
    }

    return true;
}

void BABEL_set_os(uint8_t new_os) {
    current_os = new_os;
    BABEL_os_switched_callback(new_os);
}

void BABEL_shift_os(void) {
    uint8_t next_os = (current_os + 1) % BABEL_OS_MAX;
    BABEL_set_os(next_os);
}

uint8_t BABEL_get_current_os(void) {
    return current_os;
}
