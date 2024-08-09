RGB_MATRIX_EFFECT(derby_base);

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define N_HALF_CORNE_LEDS (4)

static bool derby_base(effect_params_t* params)
{

    static uint8_t left_indices[N_HALF_CORNE_LEDS] = {0, 1, 2, 3}; 
    static uint8_t right_indices[N_HALF_CORNE_LEDS] = {4, 5, 6, 7, 8}; 

    rgb_matrix_set_flags(LED_FLAG_MODIFIER|LED_FLAG_KEYLIGHT)


    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (unsigned int i = 0; i < N_HALF_CORNE_LEDS; i++)
    {
        rgb_matrix_set_color(left_indices[i], RGB_AZURE);
        rgb_matrix_set_color(right_indices[i], RGB_CORAL);
    }

    return rgb_matrix_check_finished_leds(led_max);
}


#endif
