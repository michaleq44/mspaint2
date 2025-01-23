#ifndef ACTIONS_H
#include "actions.h"
#endif

GtkApplication *app;
int status;
GtkWidget *window, *toolbar, *fixed, *menubar;
const int WIDTH = 600;
const int HEIGHT = 400;

static void activate (GtkApplication* app, gpointer user_data) {
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Paint 2 (but worse)");
    gtk_window_set_default_size(GTK_WINDOW(window), WIDTH, HEIGHT);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);


    //gtk_fixed_put(GTK_FIXED(fixed), toolbar, 0, 0);

    gtk_widget_show_all(window);
}

int main (const int argc, char **argv) {
    hello_world();
    app = gtk_application_new("io.github.michaleq44.mspaint", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

