#ifndef HELP_H
#define HELP_H
#endif

#ifndef MAIN_H
#include "../main.h"
#endif

extern GtkApplication *app;
extern int status;
extern GtkWidget *window, *grid, *menubar;
extern int WIDTH;
extern int HEIGHT;

static void hello_world() {
    GtkWidget *popup, *label;

    popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(popup), "Hello world! - Paint 2");

    label = gtk_label_new("<span size=\"36000\">Hello world!</span>");
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
    gtk_container_add(GTK_CONTAINER(popup), label);

    gtk_widget_show_all(popup);
    gtk_window_activate_focus(GTK_WINDOW(popup));
}

static void about() {
    GtkWidget *popup, *label;

    popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(popup), "About - Paint 2");

    label = gtk_label_new("<span size=\"36000\">mspaint2</span>\n<span size=\"18000\">Very bad mspaint clone written in C using GTK3</span>");
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
    gtk_container_add(GTK_CONTAINER(popup), label);

    gtk_widget_show_all(popup);
    gtk_window_activate_focus(GTK_WINDOW(popup));
}

static void helpmenu() {
    GtkWidget *helpmenu, *label, *hwrldbtn, *aboutbtn;

    label = gtk_menu_item_new_with_mnemonic("_Help");
    helpmenu = gtk_menu_new();
    hwrldbtn = gtk_menu_item_new_with_label("Hello World");
    aboutbtn = gtk_menu_item_new_with_label("About");

    g_signal_connect(aboutbtn, "activate", G_CALLBACK(about), NULL);
    g_signal_connect(hwrldbtn, "activate", G_CALLBACK(hello_world), NULL);

    gtk_menu_attach(GTK_MENU(helpmenu), aboutbtn, 0, 1, 0, 1);
    gtk_menu_attach(GTK_MENU(helpmenu), hwrldbtn, 0, 1, 1, 2);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(label), helpmenu);

    gtk_container_add(GTK_CONTAINER(menubar), label);
}