# MCU name
MCU = atmega32u4


# Bootloader selection
BOOTLOADER = caterina

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no       # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
#RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
#WS2812_DRIVER = pwm

RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
ENCODER_ENABLE = yes
DIP_SWITCH_ENABLE = no

LAYOUTS = ortho_4x4
LAYOUTS_HAS_RGB = no

LTO_ENABLE = yes
# if firmware size over limit, try this option
# LTO_ENABLE = yes
