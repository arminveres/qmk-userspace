SPLIT_KEYBOARD = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
ENCODER_ENABLE = yes
WPM_ENABLE = yes
# Disable some stuff
RGB_ENABLE = no
TRI_LAYER_ENABLE = no
TAP_DANCE_ENABLE = no

# Bootloader/ MCU configs
CONVERT_TO = rp2040_ce

SRC += \
	oled.c \
	encoder.c \
	enums.c

