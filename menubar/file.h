#ifndef FILE_H
#define FILE_H
#endif


#include <gtk/gtk.h>

static void hello_world() {
    GtkWidget *popup, *label;

    popup = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(popup), "Hello world!");

    label = gtk_label_new("<span size=\"36000\">Hello world!</span>");
    gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
    gtk_container_add(GTK_CONTAINER(popup), label);

    gtk_widget_show_all(popup);
    gtk_window_activate_focus(GTK_WINDOW(popup));
}