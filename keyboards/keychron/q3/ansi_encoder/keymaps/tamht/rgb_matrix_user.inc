RGB_MATRIX_EFFECT(BACKLIGHT)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool BACKLIGHT(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

	HSV hsv = rgb_matrix_config.hsv;
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
	
	return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS