SRC += oneshot.c

MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

NKRO_ENABLE = yes           # Enable N-Key Rollover

LTO_ENABLE = yes
# if firmware size over limit, try this option
# LTO_ENABLE = yes
