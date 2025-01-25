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
GtkWidget *window, *toolbar, *fixed, *menubar;
const int WIDTH = 600;
const int HEIGHT = 400;

static void activate(GtkApplication* app, gpointer user_data) {
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Paint 2 (but worse)");
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    menubar = gtk_menu_bar_new();
    gtk_menu_bar_set_pack_direction(GTK_MENU_BAR(menubar), GTK_PACK_DIRECTION_LTR);
    gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, 0);

    filemenu();

    gtk_widget_show_all(window);
}