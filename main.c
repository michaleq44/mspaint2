#ifndef FILE_H
#include "menubar/file.h"
#endif

GtkApplication *app;
int status;
GtkWidget *window, *toolbar, *fixed;
const int WIDTH = 600;
const int HEIGHT = 400;

static void quit() {
    g_application_quit(G_APPLICATION(app));
}

static void filemenu() {
    GtkWidget *menubar, *file, *file_menu_label, *hworld_btn, *quit_btn;

    menubar = gtk_menu_bar_new();
    gtk_menu_bar_set_pack_direction(GTK_MENU_BAR(menubar), GTK_PACK_DIRECTION_LTR);

    file_menu_label = gtk_menu_item_new_with_mnemonic("_File");
    file = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_label), file);

    // btns
    hworld_btn = gtk_menu_item_new_with_label("Hello world");
    g_signal_connect(hworld_btn, "activate", G_CALLBACK(hello_world), NULL);
    gtk_menu_attach(GTK_MENU(file), hworld_btn, 0, 1, 0, 1);

    quit_btn = gtk_menu_item_new_with_label("Quit");
    g_signal_connect(quit_btn, "activate", G_CALLBACK(quit), NULL);

    gtk_menu_attach(GTK_MENU(file), quit_btn, 0, 1, 1, 2);

    gtk_container_add(GTK_CONTAINER(menubar), file_menu_label);
    gtk_fixed_put(GTK_FIXED(fixed), menubar, 0, 0);
}

static void activate (GtkApplication* app, gpointer user_data) {
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Paint 2 (but worse)");
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);
    //g_signal_connect_swapped(window, "button_press_event", G_CALLBACK(file_popup), file);
    filemenu();

    gtk_widget_show_all(window);
}

int main (const int argc, char **argv) {
    app = gtk_application_new("io.github.michaleq44.mspaint", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

