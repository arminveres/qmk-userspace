#include QMK_KEYBOARD_H // IWYU pragma: keep

#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

// clang-format off
#define LAYER(layer, h, s, v)                                                                \
    [(layer)] = {                                                                            \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, {(h), (s), (v)}, \
        {(h), (s), (v)}, {(h), (s), (v)}                                                     \
    }
// clang-format on

const static uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    LAYER(0, 24, 255, 255), // orange
    LAYER(1, 0, 255, 255),  // red
    LAYER(2, 67, 255, 255)  // green
};

extern rgb_config_t rgb_matrix_config;

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return true;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}
