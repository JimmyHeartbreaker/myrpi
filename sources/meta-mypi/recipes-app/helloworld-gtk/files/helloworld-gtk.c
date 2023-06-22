#include <gtk/gtk.h>
#include <stdio.h>
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
  
//some more other code
    return TRUE;
}

int main (int argc, char *argv[])
{
    int x= 1;
    int y = x + 1;

    printf("Helloworld\n");
    GtkWidget *window;// GtkWidget is the storage type for widgets
    gtk_init (&argc, &argv);// This is called in all GTK applications. Arguments are parsed
     			        //from the command line and are returned to the application.
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL); //creating a new window.

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

    gtk_widget_show(window);
    gtk_main (); //All GTK applications must have a gtk_main(). Control ends here
     	               //and waits for an event to occur (like a key press or mouse event).
   return 0;
}