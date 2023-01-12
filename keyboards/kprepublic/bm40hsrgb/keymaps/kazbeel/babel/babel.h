#pragma once

#include "quantum.h"


enum babel_operating_systems {
    BABEL_OS_LINUX,
    BABEL_OS_WINDOWS,
    BABEL_OS_MAC,
    BABEL_OS_MAX
};

// Babel should be loaded first to prevent conflicts
#if defined(NEW_SAFE_RANGE)
#   define BABEL_START NEW_SAFE_RANGE
#else
#    if defined(KEYMAP_SAFE_RANGE)
#        define BABEL_START KEYMAP_SAFE_RANGE
#    else
#        define BABEL_START SAFE_RANGE
#    endif
#endif

enum babel_keycodes {
    FIRST = BABEL_START,

    BABEL_COPY,
    BABEL_CUT,
    BABEL_PASTE,
    BABEL_UNDO,
    BABEL_REDO,
    BABEL_LOCK,
    BABEL_SUSPEND,
    BABEL_POWER_DOWN,
    BABEL_SCREENSHOT,
    BABEL_MULTI_TASK_VIEW,
    BABEL_APP_WINDOWS,
    BABEL_DESKTOP_NEXT,
    BABEL_DESKTOP_PREV,
    BABEL_SYSTEM_SEARCH,
    BABEL_CONSOLE,
    BABEL_ES_TILD,

    BABEL_SET_OS_LINUX,
    BABEL_SET_OS_WINDOWS,
    BABEL_SET_OS_MAC,
    BABEL_SHIFT_OS,

    BABEL_END_RANGE
};

bool BABEL_process(uint16_t keycode, bool pressed);

void BABEL_process_linux(uint16_t keycode);
void BABEL_process_windows(uint16_t keycode);
void BABEL_process_mac(uint16_t keycode);

void BABEL_set_os(uint8_t new_os);
void BABEL_shift_os(void);
uint8_t BABEL_get_current_os(void);

#define BBL_COPY                BABEL_COPY
#define BBL_CUT                 BABEL_CUT
#define BBL_PASTE               BABEL_PASTE
#define BBL_UNDO                BABEL_UNDO
#define BBL_REDO                BABEL_REDO
#define BBL_LOCK                BABEL_LOCK
#define BBL_SUSPEND             BABEL_SUSPEND
#define BBL_POWER_DOWN          BABEL_POWER_DOWN
#define BBL_SCREENSHOT          BABEL_SCREENSHOT
#define BBL_MULTI_TASK_VIEW     BABEL_MULTI_TASK_VIEW
#define BBL_APP_WINDOWS         BABEL_APP_WINDOWS
#define BBL_DESKTOP_NEXT        BABEL_DESKTOP_NEXT
#define BBL_DESKTOP_PREV        BABEL_DESKTOP_PREV
#define BBL_SYSTEM_SEARCH       BABEL_SYSTEM_SEARCH
#define BBL_CONSOLE             BABEL_CONSOLE
#define BBL_ES_TILD             BABEL_ES_TILD

#define BBL_OS_LINUX      BABEL_OS_LINUX
#define BBL_OS_WINDOWS    BABEL_OS_WINDOWS
#define BBL_OS_MAC        BABEL_OS_MAC
#define BBL_OS_SHIFT      BABEL_SHIFT_OS
