/*
 * graphs.c
 *
 *  Created on: 24/06/2020
 *      Author: Hector Guarneros
 */

#include "../../Include/NewhavenLCD/glcd.h"

static uint8_t glcd_map(uint8_t x1, uint8_t x2, uint8_t x);

void glcd_bar_graph_horizontal(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val)
{
    if (height < 3) {
        return;
    }
    glcd_draw_rect(x, y, width, height, BLACK);
    glcd_fill_rect(x+1, y+1, glcd_map(0,width-2,val), height-2 , BLACK);
}

void glcd_bar_graph_horizontal_no_border(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val)
{
    if (height < 3) {
        return;
    }
    glcd_fill_rect(x, y, glcd_map(0,width,val), height , BLACK);
}

void glcd_bar_graph_vertical(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val)
{
    glcd_draw_rect(x, y, width, height, BLACK);
    glcd_fill_rect(x+1, y+1+glcd_map(0,height-2,255-val), width-2, height-2-glcd_map(0,height-2,255-val), BLACK);
}

void glcd_bar_graph_vertical_no_border(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val)
{
    glcd_fill_rect(x, y+glcd_map(0,height-2,255-val), width, height-2-glcd_map(0,height-2,255-val), BLACK);
}

void glcd_scrolling_bar_graph(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val)
{
    uint8_t nx, ny;
    uint8_t color;

    /* Draw border of graph */
    glcd_draw_rect(x,y,width,height,BLACK);

    /* Scroll inner contents left by one pixel width */
    for (ny = 1; ny <= (height-2); ny++) {
        /* Redraw each horizontal line */
        for (nx = 1; nx <= (width-2); nx += 1) {
            color = glcd_get_pixel(x+nx+1,y+ny);
            glcd_set_pixel(x+nx,y+ny,color);
        }
    }

    val = val * (height-3) / 255;

    /* Make sure we're not exceeding the size of box interior */
    if (val > (height-3)) {
        val = height - 3;
    }

    /* Draw new bar - both black and white portions*/
    glcd_draw_line(x+width-2,y+height-2,x+width-2,y+height-2-val,BLACK);
    glcd_draw_line(x+width-2,y+height-3-val,x+width-2,y+1,WHITE);

    /* Write to display */
    glcd_write();
}

void glcd_scrolling_bar_graph_timing(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t val, uint8_t line_width, uint16_t delay)
{
    uint8_t n;
    if (line_width == 0) {
        line_width = 1;
    }

    /* Adjust graph line's width by just running glcd_scrolling_bar_graph() x number of times */
    /* \todo This should be done differently! */
    for (n=0; n<line_width; n++) {
        glcd_scrolling_bar_graph(x,y,width,height,val);
    }

    if (delay) {
        //delay_ms(delay);
        DelayMs(delay);
    }
}

static uint8_t glcd_map(uint8_t x1, uint8_t x2, uint8_t x)
{
    return x1+(x2-x1)*x/255;
}

