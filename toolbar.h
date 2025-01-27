#ifndef TOOLBAR_H
#define TOOLBAR_H
#include "draw.h"
#endif

#ifndef MAIN_H
#include "main.h"
#endif

extern GtkApplication *app;
extern int status;
extern GtkWidget *window, *toolbar, *grid, *menubar, *menubarframe, *drawing_area;
extern int WIDTH;
extern int HEIGHT;
extern GdkRGBA fgcolor, bgcolor;

static void bg_choose_rgba() {
    GtkWidget *dialog;
    dialog = gtk_color_chooser_dialog_new("Choose background color", GTK_WINDOW(window));
    g_object_set(G_OBJECT(dialog), "show-editor", TRUE);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(dialog), &bgcolor);
}

static void fg_choose_rgba() {
    GtkWidget *dialog;
    dialog = gtk_color_chooser_dialog_new("Choose foreground color", GTK_WINDOW(window));
    g_object_set(G_OBJECT(dialog), "show-editor", TRUE);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(dialog), &fgcolor);
}

static void toolbar_init() {
    GtkWidget *closeimage, *bgimage, *fgimage;
    GtkToolItem *close, *bg, *fg;

    toolbar = gtk_toolbar_new();
    gtk_widget_set_size_request(toolbar, WIDTH, 32);
    gtk_grid_attach(GTK_GRID(grid), toolbar, 0, 1, 1, 1);

    fgimage = gtk_image_new_from_file("../data/fg.png");
    fg = gtk_tool_button_new(fgimage, "Choose foreground color");
    g_signal_connect(fg, "clicked", G_CALLBACK(fg_choose_rgba), NULL);

    bgimage = gtk_image_new_from_file("../data/bg.png");
    bg = gtk_tool_button_new(bgimage, "Choose background color");
    g_signal_connect(bg, "clicked", G_CALLBACK(bg_choose_rgba), NULL);

    closeimage = gtk_image_new_from_file("../data/close.png");
    close = gtk_tool_button_new(closeimage, "Quit");
    g_signal_connect(close, "clicked", G_CALLBACK(quit), NULL);

    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), fg, 0);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), bg, 1);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), close, 2);
}