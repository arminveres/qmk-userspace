SPLIT_KEYBOARD = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
ENCODER_ENABLE = yes
WPM_ENABLE = yes
# TRI_LAYER_ENABLE = yes
# TAP_DANCE_ENABLE = yes

# Bootloader/ MCU configs
# BOOTLOADER = rp2040
# PROCESSOR = cortex-m0plus
CONVERT_TO = rp2040_ce

SRC += \
	oled.c \
	encoder.c \
	enums.c

# Disable some stuff
RGB_ENABLE = no
