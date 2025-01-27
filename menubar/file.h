#ifndef FILE_H
#define FILE_H
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
extern char *current_name;

static void quit() {
    window = NULL;
    g_application_quit(G_APPLICATION(app));
}

static void image_to_file() {
    GtkAllocation allocation;
    GdkWindow *gwindow = gtk_widget_get_parent_window(drawing_area);
    gtk_widget_get_allocation(drawing_area, &allocation);
    GdkPixbuf *pixbuf = gdk_pixbuf_get_from_window(gwindow, allocation.x, allocation.y, drawwidth, drawheight);
    gdk_pixbuf_save(pixbuf, current_name, "png", NULL);
}

static void save() {
    GtkWidget *dialog;
    GtkFileChooser *chooser;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Save File", GTK_WINDOW(window), action, ("Cancel"), GTK_RESPONSE_CANCEL, ("Save"), GTK_RESPONSE_ACCEPT);
    chooser = GTK_FILE_CHOOSER(dialog);
    gtk_file_chooser_set_do_overwrite_confirmation(chooser, TRUE);
    gtk_file_chooser_set_current_name(chooser, current_name);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        current_name = gtk_file_chooser_get_filename(chooser);
        image_to_file();
    }
    gtk_widget_destroy(dialog);
    g_print("%s\n", current_name);
}

static void filemenu() {
    GtkWidget *file, *file_menu_label, *quit_btn, *saveas_btn;

    file_menu_label = gtk_menu_item_new_with_mnemonic("_File");
    file = gtk_menu_new();
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_label), file);

    // btns
    saveas_btn = gtk_menu_item_new_with_label("Save as...");
    g_signal_connect(saveas_btn, "activate", G_CALLBACK(save), NULL);

    quit_btn = gtk_menu_item_new_with_label("Quit");
    g_signal_connect(quit_btn, "activate", G_CALLBACK(quit), NULL);

    gtk_menu_attach(GTK_MENU(file), saveas_btn, 0, 1, 0, 1);
    gtk_menu_attach(GTK_MENU(file), quit_btn, 0, 1, 1, 2);

    gtk_container_add(GTK_CONTAINER(menubar), file_menu_label);
}
