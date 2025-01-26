#ifndef TOOLBAR_H
#define TOOLBAR_H
#endif

#ifndef MAIN_H
#include "main.h"
#endif

extern GtkApplication *app;
extern int status;
extern GtkWidget *window, *toolbar, *grid, *menubar;
extern int WIDTH;
extern int HEIGHT;

static void toolbar_init() {
    toolbar = gtk_toolbar_new();
}