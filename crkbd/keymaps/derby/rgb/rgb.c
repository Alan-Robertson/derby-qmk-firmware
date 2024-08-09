#include "color.h"

extern uint8_t rgb_left_idx_g;
extern uint8_t rgb_right_idx_g;

extern uint8_t rgb_left_g[3];
extern uint8_t rgb_right_g[3];


// Custom macros for rgb modes
enum custom_keycodes {
    RGB_BOARD_LEFT = SAFE_RANGE,
    RGB_BOARD_RIGHT
};

#define N_RGB_COLOURS (11)

void colour_update(uint8_t* idx, uint8_t* rgbs)
{
    static uint8_t colours[N_RGB_COLOURS][3] = { 
        {RGB_AZURE},
        {RGB_BLUE},
        {RGB_PURPLE},
        {RGB_MAGENTA},
        {RGB_PINK},
        {RGB_RED},
        {RGB_ORANGE},
        {RGB_YELLOW},
        {RGB_GREEN},
        {RGB_WHITE},
        {RGB_BLACK}
    };

    *idx = *idx + 1;

    if (*idx > N_RGB_COLOURS)
    {
        *idx = 0;
    } 

    rgbs[0] = colours[*idx][0];
    rgbs[1] = colours[*idx][1];
    rgbs[2] = colours[*idx][2];

    return;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) 
{
    switch(keycode)
    {
        case RGB_BOARD_LEFT:
            if (record->event.pressed)
            {
                colour_update(&rgb_left_idx_g, rgb_left_g);
                //rgb_matrix_mode(RGB_MATRIX_CUSTOM_derby_base);
            }
        break;


        case RGB_BOARD_RIGHT:
            if (record->event.pressed)
            {
                colour_update(&rgb_right_idx_g, rgb_right_g);
                //rgb_matrix_mode(RGB_MATRIX_CUSTOM_derby_base);
            }
        break;
    }

    return true;
}


 
// Combos
const uint16_t PROGMEM rgb_combo_rl[] = {RGB_BOARD_LEFT, RGB_BOARD_RIGHT, COMBO_END};
const uint16_t PROGMEM rgb_combo_lr[] = {RGB_BOARD_RIGHT, RGB_BOARD_LEFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(rgb_combo_rl, RGB_TOG),
    COMBO(rgb_combo_lr, RGB_TOG)
};


