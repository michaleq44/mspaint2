#ifndef ACTIONS_H
#define ACTIONS_H
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

static gint file_popup(GtkWidget *widget, GdkEvent *event) {
    g_return_val_if_fail (widget != NULL, FALSE);
    g_return_val_if_fail (GTK_IS_MENU(widget), FALSE);
    g_return_val_if_fail (event != NULL, FALSE);

    GtkMenu *menu = GTK_MENU(widget);

    if (event->type == GDK_BUTTON_PRESS) {
        GdkEventButton *button = (GdkEventButton *) event;
        if (button->button == GDK_BUTTON_SECONDARY) {
            gtk_menu_popup_at_widget(menu, widget, GDK_GRAVITY_NORTH_WEST, GDK_GRAVITY_NORTH_WEST, event);
            hello_world();
            return TRUE;
        }
    }

    return FALSE;
}