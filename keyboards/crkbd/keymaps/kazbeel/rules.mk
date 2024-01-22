SRC += babel/babel.c babel/babel_linux.c babel/babel_windows.c babel/babel_mac.c

BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes

RGB_MATRIX_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = ssd1306

CONSOLE_ENABLE = no
DEFERRED_EXEC_ENABLE = yes

EXTRAFLAGS += -flto
