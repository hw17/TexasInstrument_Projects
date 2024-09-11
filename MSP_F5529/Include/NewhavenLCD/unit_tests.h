/*
 * unit_tests.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef UNIT_TESTS_H_
#define UNIT_TESTS_H_

/** Make random "exploding circles" */
void glcd_test_circles(void);

/* Shows a 8-bit counter incorementing, with a verticla and horizontal bar graph */
void glcd_test_counter_and_graph(void);

/* Shows a 16-bit counter incrementing, using glcdutils font format */
void glcd_test_glcdutils(void);

/** Scroll some text up and down the screen */
void glcd_test_text_up_down(void);

/** Display all chars of tiny 5x7 font, scrolling previous lines one by one every second */
void glcd_test_tiny_text(void);

/** Print hello world to display */
void glcd_test_hello_world(void);

/** Demonstrating rectangle drawing */
void glcd_test_rectangles(void);

/** Demonstrate scrolling bar graph */
void glcd_test_scrolling_graph(void);

/** Demonstrate bitmap display */
void glcd_test_bitmap_128x64(void);


#endif /* UNIT_TESTS_H_ */
