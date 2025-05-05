/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "alt.h"
#include "led_matrix.h"

//Teal <-> Salmon
led_setup_t leds_teal_salmon[] = {
    { .hs = 0,  .he = 33,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
    { .hs = 33, .he = 66,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE },
    { .hs = 66, .he = 100, .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE },
    { .end = 1 },
};

//Yellow
led_setup_t leds_yellow[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Off
led_setup_t leds_off[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Red
led_setup_t leds_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Green
led_setup_t leds_green[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Blue
led_setup_t leds_blue[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White
led_setup_t leds_white[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White with moving red stripe
led_setup_t leds_white_with_red_stripe[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 0, .re = 0, .gs = 0, .ge = 255, .bs = 0, .be = 255, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .end = 1 },
};

//Black with moving red stripe
led_setup_t leds_black_with_red_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .end = 1 },
};

//Rainbow no scrolling
led_setup_t leds_rainbow_ns[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER },
    { .end = 1 },
};

//Rainbow scrolling
led_setup_t leds_rainbow_s[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//pink and cyan scrolling
led_setup_t leds_pleasuretek_s[] = {
    { .hs = 0,      .he = 8.33,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 8.33,   .he = 16.6,  .rs = 255,  .re = 255, .gs = 255, .ge = 20,  .bs = 255, .be = 147, .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.6,   .he = 24.9,  .rs = 255,  .re = 255, .gs = 20,  .ge = 20,  .bs = 147, .be = 147, .ef = EF_OVER | EF_SCR_R },
    { .hs = 24.9,   .he = 33.2,  .rs = 255,  .re = 255, .gs = 20,  .ge = 255, .bs = 147, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.2,   .he = 41.5,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 41.5,   .he = 49.8,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 49.8,   .he = 58.1,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 58.1,   .he = 66.4,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.4,   .he = 74.7,  .rs = 255,  .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 74.7,   .he = 83,    .rs = 255,  .re = 0,   .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83,     .he = 91.3,  .rs = 0,    .re = 0,   .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 91.3,   .he = 100,   .rs = 0,    .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//C2077 colors
led_setup_t leds_c2077[] = {
    { .hs = 0,      .he = 25,     .rs = 211, .re = 211, .gs = 79,  .ge = 79,  .bs = 191, .be = 191, .ef = EF_OVER | EF_SCR_R },
    { .hs = 25,     .he = 50,     .rs = 211, .re = 219, .gs = 79,  .ge = 48,  .bs = 191, .be = 65,  .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 75,     .rs = 219, .re = 219, .gs = 48,  .ge = 48,  .bs = 65,  .be = 65,  .ef = EF_OVER | EF_SCR_R },
    { .hs = 75,     .he = 100,    .rs = 219, .re = 211, .gs = 48,  .ge = 79,  .bs = 65,  .be = 191, .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//white with black stripe scrolling
led_setup_t leds_blackandwhite[] = {
    { .hs = 0,      .he = 16.67,  .rs = 0, .re = 0, .gs = 0,   .ge = 0, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 0, .re = 255,   .gs = 0, .ge = 255, .bs = 0,   .be = 255,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 255,   .re = 255,   .gs = 255, .ge = 255, .bs = 255,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 255,   .re = 255,   .gs = 255, .ge = 255,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 255,   .re = 255, .gs = 255,   .ge = 255,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 0, .gs = 255,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//Teal <-> Salmon scroll
led_setup_t leds_teal_salmon_s[] = {
    { .hs = 0,  .he = 25,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE | EF_SCR_R },
    { .hs = 25, .he = 50,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE | EF_SCR_R },
    { .hs = 50, .he = 75,  .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE | EF_SCR_R },
    { .hs = 75, .he = 100, .rs = 255,  .re = 24, .gs = 114, .ge = 215, .bs = 118, .be = 204, .ef = EF_NONE | EF_SCR_R },
    { .end = 1 },
};

//Teal <-> Salmon scroll
led_setup_t leds_cyan_pinkaf_s[] = {
    { .hs = 0,  .he = 25,  .rs = 0,  .re = 0,  .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .hs = 25, .he = 50,  .rs = 0,  .re = 255, .gs = 255, .ge = 20, .bs = 255, .be = 147, .ef = EF_NONE | EF_SCR_R },
    { .hs = 50, .he = 75,  .rs = 255, .re = 255, .gs = 20, .ge = 20, .bs = 147, .be = 147, .ef = EF_NONE | EF_SCR_R },
    { .hs = 75, .he = 100, .rs = 255,  .re = 0, .gs = 20, .ge = 255, .bs = 147, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .end = 1 },
};

led_setup_t leds_cyan_pinkaf_si[] = {
    { .hs = 0, .he = 25,  .rs = 255, .re = 255, .gs = 20, .ge = 20, .bs = 147, .be = 147, .ef = EF_NONE | EF_SCR_R },
    { .hs = 25, .he = 50, .rs = 255,  .re = 0, .gs = 20, .ge = 255, .bs = 147, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .hs = 50,  .he = 75,  .rs = 0,  .re = 0,  .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .hs = 75, .he = 100,  .rs = 0,  .re = 255, .gs = 255, .ge = 20, .bs = 255, .be = 147, .ef = EF_NONE | EF_SCR_R },
    { .end = 1 },
};

led_setup_t leds_funkbutt[] = {   //I was raised in the hood
    { .hs = 0,  .he = 25,  .rs = 0,  .re = 0,  .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .hs = 25, .he = 50,  .rs = 0,  .re = 255, .gs = 255, .ge = 0, .bs = 0, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .hs = 50, .he = 75,  .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE | EF_SCR_R },
    { .hs = 75, .he = 100, .rs = 255,  .re = 0, .gs = 0, .ge = 255, .bs = 255, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .end = 1 },
};

// greenish teal
led_setup_t leds_teal1[] = {
    { .hs = 0, .he = 100, .rs = 32, .re = 32, .gs = 255, .ge = 255, .bs = 80, .be = 80, .ef = EF_NONE },
    { .end = 1 },
};

// more blueish teal
led_setup_t leds_teal2[] = {
    { .hs = 0, .he = 100, .rs = 47, .re = 47, .gs = 198, .ge = 198, .bs = 178, .be = 178, .ef = EF_NONE },
    { .end = 1 },
};

//White with moving teal stripe
led_setup_t leds_teal1_with_teal2_stripe[] = {
    { .hs = 0, .he = 100, .rs = 47, .re = 47, .gs = 198, .ge = 198, .bs = 178, .be = 178, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 0, .re = 5, .gs = 0, .ge = 37, .bs = 0, .be = 26, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 5, .re = 0, .gs = 37, .ge = 0, .bs = 26, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .end = 1 },
};

//teal with moving white stripe
led_setup_t leds_teal1_with_white_stripe[] = {
    { .hs = 0, .he = 100, .rs = 32, .re = 32, .gs = 255, .ge = 255, .bs = 80, .be = 80, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 32, .re = 255, .gs = 255, .ge = 255, .bs = 80, .be = 255, .ef = EF_SCR_R | EF_OVER },
    { .hs = 15, .he = 30, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_SCR_R | EF_OVER },
    { .hs = 30, .he = 45, .rs = 255, .re = 32, .gs = 255, .ge = 255, .bs = 255, .be = 80, .ef = EF_SCR_R | EF_OVER },
    { .end = 1 },
};

//White with moving teal stripe
led_setup_t leds_white_with_teal1_stripe[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 0, .re = 223, .gs = 0, .ge = 0, .bs = 0, .be = 175, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 223, .re = 0, .gs = 0, .ge = 0, .bs = 175, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .end = 1 },
};

//Black with moving teal stripe
led_setup_t leds_black_with_teal1_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 32, .gs = 0, .ge = 255, .bs = 0, .be = 80, .ef = EF_SCR_R },
    { .hs = 15, .he = 30, .rs = 32, .re = 0, .gs = 255, .ge = 0, .bs = 80, .be = 0, .ef = EF_SCR_R },
    { .end = 1 },
};

led_setup_t leds_xmas_stripes[] = {
    { .hs = 0,  .he = 30,  .rs = 255,  .re = 255,  .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .hs = 30, .he = 50,  .rs = 255,  .re = 0, .gs = 0, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .hs = 50, .he = 80,  .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .hs = 80, .he = 100, .rs = 0,  .re = 255, .gs = 255, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE | EF_SCR_R },
    { .end = 1 },
};

void *led_setups[] = {
    leds_pleasuretek_s,           //0
    leds_cyan_pinkaf_s,           //1
    leds_cyan_pinkaf_si,          //2
    leds_blackandwhite,           //3
    leds_rainbow_s,               //4
    leds_rainbow_ns,              //5
//    leds_teal_salmon_s,
//    leds_teal_salmon,
    leds_red,                     //6
    leds_green,                   //7
    leds_teal1,                   //8
    leds_teal2,                   //9
    leds_blue,                    //10
    leds_white,                   //11
    leds_teal1_with_white_stripe, //12
    leds_white_with_teal1_stripe, //13
    leds_black_with_teal1_stripe, //14
//    leds_white_with_red_stripe,
    leds_black_with_red_stripe,   //15
    leds_funkbutt,                //16
    leds_xmas_stripes,            //17
    leds_c2077,                   //18
};

const uint8_t led_setups_count = sizeof(led_setups) / sizeof(led_setups[0]);
