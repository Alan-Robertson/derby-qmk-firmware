RGB_MATRIX_EFFECT(derby_base);


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS



static bool derby_base(effect_params_t* params) {

  static uint8_t left_indices[] = ; 
  static uint8_t right_indices[] = ; 


  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  for (unsigned int i = 0; i < ; i++)
  rgb_matrix_set_color(i, COLOUR_LEFT);

  return rgb_matrix_check_finished_leds(led_max);
}


#endif
