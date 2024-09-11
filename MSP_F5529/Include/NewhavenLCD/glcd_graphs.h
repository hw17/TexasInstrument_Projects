/*
 * glcd_graphs.h
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#ifndef GLCD_GRAPHS_H_
#define GLCD_GRAPHS_H_

/** \addtogroup Graphing
 *  Functions for graphing, e.g drawing bar graphs etc.
 *  @{
 */

/** Draw horizontal bar graph with 1 px wide border.
 *  The bar graph draws from left to right as val increases.
 *  \param x x location for top-left of border
 *  \param y y location for top-left of border
 *  \param width width of the border
 *  \param height height of the border (must be over 2)
 *  \param val value to display in graph (0-255 8 bit value).
 */
void glcd_bar_graph_horizontal(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val);

/** Draw horizontal bar graph with no border.
 *  The bar graph draws from left to right as val increases.
 *  \param x x location for top-left of bar
 *  \param y y location for top-left of bar
 *  \param width width of the bar at full val
 *  \param height height of the bar
 *  \param val value to display in graph (0-255 8 bit value).
 */
void glcd_bar_graph_horizontal_no_border(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val);

/** Draw vertical bar graph with 1px wide border.
 *  The bar graph draws from bottom to top as val increases.
 *  \param x x location for top-left of border
 *  \param y y location for top-left of border
 *  \param width width of the border
 *  \param height height of the border
 *  \param val value to display in graph (0-255 8 bit value).
 */
void glcd_bar_graph_vertical(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val);

/** Draw vertical bar graph with no border.
 *  The bar graph draws from bottom to top as val increases.
 *  \param x x location for top-left of bar
 *  \param y y location for top-left of bar
 *  \param width width of the bar
 *  \param height height of the bar
 *  \param val value to display in graph (0-255 8 bit value).
 */
void glcd_bar_graph_vertical_no_border(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val);

/** \todo write doc */
void glcd_scrolling_bar_graph(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val);

/** @}*/



#endif /* GLCD_GRAPHS_H_ */
