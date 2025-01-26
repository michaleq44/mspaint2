#ifndef MAIN_H
#define MAIN_H
#endif

#include <gtk/gtk.h>

#ifndef FILE_H
#include "menubar/file.h"
#endif

#ifndef HELP_H
#include "menubar/help.h"
#endif

GtkApplication *app;
int status;
GtkWidget *window, *toolbar, *grid, *menubar, *menubarframe;
GtkCssProvider *css;
GtkStyleContext *windowcontext;
int WIDTH = 600;
int HEIGHT = 400;

static void update_window_size() {
    gtk_window_get_size(GTK_WINDOW(window), &WIDTH, &HEIGHT);
}

static void activate(GtkApplication* app, gpointer user_data) {
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Paint 2 (but worse)");
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);

    g_signal_connect(window, "size-allocate", G_CALLBACK(update_window_size), NULL);

    css = gtk_css_provider_new();
    GFile* cssfile;
    cssfile = g_file_new_for_path("../data/style.css");

    gtk_css_provider_load_from_file(css, cssfile, NULL);
    windowcontext = gtk_style_context_new();
    GdkScreen* screen = gdk_screen_get_default();
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(css), 500);
    gtk_widget_set_name(window, "window");

    grid = gtk_grid_new();
    gtk_style_context_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    menubar = gtk_menu_bar_new();
    gtk_menu_bar_set_pack_direction(GTK_MENU_BAR(menubar), GTK_PACK_DIRECTION_LTR);

    menubarframe = gtk_frame_new(NULL);
    gtk_widget_set_hexpand(menubarframe, TRUE);
    gtk_widget_set_size_request(menubarframe, WIDTH, 16);
    gtk_container_add(GTK_CONTAINER(menubarframe), menubar);
    gtk_grid_attach(GTK_GRID(grid), menubarframe, 0, 0, 1, 1);

    filemenu();
    helpmenu();

    gtk_widget_show_all(window);
    gtk_style_context_reset_widgets(screen);
}