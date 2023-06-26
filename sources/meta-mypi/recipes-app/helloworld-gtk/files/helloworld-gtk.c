#include <gtk/gtk.h>
#include <stdio.h>
#include <wayland-client.h>

struct wl_display *display = NULL;

gboolean event_delete(
    GtkWidget *widget,
    GdkEvent *event,
    gpointer user_data)
{
    gtk_main_quit();
    return TRUE;
}

gboolean event_windowState(
    GtkWidget *widget,
    GdkEventWindowState *event,
    gpointer user_data)
{
  
    return TRUE;
}

int main (int argc, char *argv[])
{
    display = wl_display_connect(NULL);
    GtkWindow *window;
    gtk_init (&argc, &argv);

    window= (GtkWindow*)gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_window_set_hide_titlebar_when_maximized (window,TRUE);
    gtk_window_maximize  (window);
    gtk_window_set_decorated   (window,FALSE);
    g_signal_connect(
    G_OBJECT(window), 
    "delete_event", 
    G_CALLBACK(event_delete), 
    NULL);

    g_signal_connect(
    G_OBJECT(window), 
    "window-state-event", 
    G_CALLBACK(event_windowState), 
    NULL);


    gtk_widget_show((GtkWidget*)window);
    gtk_main (); 
    return 0;
}