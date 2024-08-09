RGB_MATRIX_EFFECT(derby_base)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define N_HALF_CORNE_LEDS (27)

uint8_t rgb_left_g[3];
uint8_t rgb_right_g[3];

uint8_t rgb_left_idx_g;
uint8_t rgb_right_idx_g;


static void derby_base_init(effect_params_t* params) {

  rgb_left_idx_g = 0;
  rgb_right_idx_g = 0;

  rgb_left_g[0] = 0xff; 
  rgb_left_g[1] = 0x0a; 
  rgb_left_g[2] = 0x0a; 

  rgb_right_g[0] = 0x0a; 
  rgb_right_g[1] = 0x0a; 
  rgb_right_g[2] = 0xff; 

}


static bool derby_base_run(effect_params_t* params) {
  //RGB_MATRIX_USE_LIMITS(led_min, led_max);
  const uint8_t led_min = 0;
  const uint8_t half = N_HALF_CORNE_LEDS;
  const uint8_t led_max = 2 * half;

  for (uint8_t i = led_min; i < half; i++) {
    rgb_matrix_set_color(i, rgb_left_g[0], rgb_left_g[1], rgb_left_g[2]);
  }

  for (uint8_t i = half; i < led_max; i++) {
    rgb_matrix_set_color(i, rgb_right_g[0], rgb_right_g[1], rgb_right_g[2]);
  }

  return rgb_matrix_check_finished_leds(led_max);
}

static bool derby_base(effect_params_t* params) {
  if (params->init) derby_base_init(params);
  return derby_base_run(params);
}

#endif
