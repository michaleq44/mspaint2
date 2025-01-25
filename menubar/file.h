#ifndef FILE_H
#define FILE_H
#endif

#ifndef MAIN_H
#include "../main.h"
#endif

extern GtkApplication *app;
extern int status;
extern GtkWidget *window, *toolbar, *fixed, *menubar;
extern const int WIDTH;
extern const int HEIGHT;

static void quit() {
    g_application_quit(G_APPLICATION(app));
}

static void filemenu() {
    GtkWidget *file, *file_menu_label, *quit_btn;

    file_menu_label = gtk_menu_item_new_with_mnemonic("_File");
    file = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_label), file);

    // btns

    quit_btn = gtk_menu_item_new_with_label("Quit");
    g_signal_connect(quit_btn, "activate", G_CALLBACK(quit), NULL);

    gtk_menu_attach(GTK_MENU(file), quit_btn, 0, 1, 1, 2);

    gtk_container_add(GTK_CONTAINER(menubar), file_menu_label);
}
