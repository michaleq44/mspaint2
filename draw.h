#ifndef DRAW_H
#define DRAW_H
#endif

#ifndef MAIN_H
#include "../main.h"
#endif

extern GtkApplication *app;
extern int status;
extern GtkWidget *window, *toolbar, *grid, *menubar, *drawing_area;
extern int WIDTH;
extern int HEIGHT;
extern int drawwidth, drawheight;
extern GdkRGBA fgcolor, bgcolor;

cairo_surface_t *surf;

static gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
    GtkStyleContext *context;

    context = gtk_widget_get_style_context(widget);

    gtk_render_background(context, cr, 0, 0, drawwidth, drawheight);

    cairo_rectangle(cr, 0, 0, drawwidth, drawheight);
    gdk_cairo_set_source_rgba(cr, &bgcolor);

    cairo_fill(cr);

    cairo_arc(cr, drawwidth / 2.0, drawheight / 2.0, MIN(drawwidth, drawheight) / 2.0,0, 2 * G_PI);
    gdk_cairo_set_source_rgba(cr, &fgcolor);
    cairo_stroke(cr);



    return TRUE;
}

static void da_init() {
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, drawwidth, drawheight);

    bgcolor.red = 1;
    bgcolor.green = 1;
    bgcolor.blue = 1;
    bgcolor.alpha = 1;
    fgcolor.red = 0;
    fgcolor.green = 0;
    fgcolor.blue = 0;
    fgcolor.alpha = 1;
    g_signal_connect(drawing_area, "draw", G_CALLBACK(draw_callback), NULL);
    gtk_grid_attach(GTK_GRID(grid), drawing_area, 0, 2, 1, 1);
}