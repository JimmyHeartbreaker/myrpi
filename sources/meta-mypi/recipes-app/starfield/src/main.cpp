#include <iostream>
#include <cmath>
#include <gtk/gtk.h>
#include "../include/starfield.h"
#include "../include/starfield_config.h"

#include INCLUDE_FILE( vector4.h)

/* Surface to store current scribbles */
static cairo_surface_t *imageSurface = NULL;
static Starfield starfield;
static Matrix4x4 perspectiveProjectioMatrix = Matrix4x4::CreatePerspectiveProjectioMatrix(0.1,1000,1,1);
static int height;
static int width;
static int intStride;
static uint* surfaceData=NULL;
static void clear_surface (void)
{
  cairo_t *cr;

  cr = cairo_create (imageSurface);

  cairo_set_source_rgb (cr, 1, 1, 1);
  cairo_paint (cr);

  cairo_destroy (cr);
}

/* Create a new surface of the appropriate size to store our scribbles */
static gboolean configure_event_cb (GtkWidget         *widget,
                    GdkEventConfigure *event,
                    gpointer           data)
{
  if (imageSurface)
  {
    g_free(surfaceData);
    cairo_surface_destroy (imageSurface); 
  }
  width = gtk_widget_get_allocated_width (widget);
  height = gtk_widget_get_allocated_height (widget);


  int stride = cairo_format_stride_for_width (CAIRO_FORMAT_RGB24, width);
  surfaceData = (uint* )g_malloc (height * stride);
  intStride =  stride/4;


  imageSurface = cairo_image_surface_create_for_data ((guchar *)surfaceData, CAIRO_FORMAT_RGB24,
                                           width, height, stride);
  
  /* Initialize the surface to white */
  clear_surface ();

  /* We've handled the configure event, no need for further processing. */
  return TRUE;
}
GDateTime *prev=NULL;
gboolean time_handler(GtkWidget *widget) {
    
  GDateTime *now = g_date_time_new_now_utc(); 
  if(prev)
  {
    
    GTimeSpan diff = g_date_time_difference (now,prev);
    for(Star & star : starfield.GetStars())
   {   
      star.Translate(0,0,-diff/ 100000.0);
      if(star.GetPoint().GetZ() < 0.0)
      {
        star.Translate(0,0,100);
      }
   }

    
    gtk_widget_queue_draw (widget);
 
    g_date_time_unref(prev);
  }
  prev = now;
  return TRUE;
}

/* Redraw the screen from the surface. Note that the ::draw
 * signal receives a ready-to-be-used cairo_t that is already
 * clipped to only draw the exposed areas of the widget
 */
static gboolean draw_cb (GtkWidget *widget,
         cairo_t   *cr,
         gpointer   data)
{
  memset(surfaceData, 0, height * intStride * 4);
  for(Star star : starfield.GetStars())
   {
    Vector4 point = star.GetPoint();
    Vector4 perspectivePoint = point.Multiply(perspectiveProjectioMatrix);
    auto w =  perspectivePoint.GetW();
    float screenX = round(((perspectivePoint.GetX() /w)+0.5) * width);    
    float screenY = round(((perspectivePoint.GetY() /w) +0.5) * height);

    if(screenX < width && screenY < height && screenY>=0 && screenX >=0)
    {
      int grey = (100-point.GetZ()) *  5;
      if(grey>255)
      {
        grey=255;
      }
      surfaceData[(int)(screenY) * intStride + (int)screenX] = (grey << 16) | (grey << 8 )| grey ;
    }
  } 

  cairo_set_source_surface (cr, imageSurface, 0, 0);
  cairo_paint (cr);

  return FALSE;
}


static void close_window (void)
{
  if (imageSurface)
    cairo_surface_destroy (imageSurface);

  gtk_main_quit ();
}

/* Handle button press events by either drawing a rectangle
 * or clearing the surface, depending on which button was pressed.
 * The ::button-press signal handler receives a GdkEventButton
 * struct which contains this information.
 */
static gboolean button_press_event_cb (GtkWidget      *widget,
                       GdkEventButton *event,
                       gpointer        data)
{
 
   close_window();
  /* We've handled the event, stop processing */
  return TRUE;
}




static void activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *drawing_area;

  window = gtk_application_window_new (app);
  //gtk_window_set_decorated   (window,FALSE);

  g_signal_connect (window, "destroy", G_CALLBACK (close_window), NULL);

  gtk_container_set_border_width (GTK_CONTAINER (window), 0);


  drawing_area = gtk_drawing_area_new ();
  /* set a minimum size */
  gtk_widget_set_size_request (drawing_area, 100, 100);

  gtk_container_add (GTK_CONTAINER (window), drawing_area);

  /* Signals used to handle the backing surface */
  g_signal_connect (drawing_area, "draw",
                    G_CALLBACK (draw_cb), NULL);
  g_signal_connect (drawing_area,"configure-event",
                    G_CALLBACK (configure_event_cb), NULL);

  g_signal_connect (drawing_area, "button-press-event",
                    G_CALLBACK (button_press_event_cb), NULL);

  g_timeout_add(10, (GSourceFunc) time_handler, (gpointer) window);
  /* Ask to receive events the drawing area doesn't normally
   * subscribe to. In particular, we need to ask for the
   * button press and motion notify events that want to handle.
   */
  gtk_widget_set_events (drawing_area, gtk_widget_get_events (drawing_area)
                                     | GDK_BUTTON_PRESS_MASK
                                     | GDK_POINTER_MOTION_MASK);


  gtk_widget_show_all (window); 
}


int main (int    argc,     char **argv)
{
  if (argc < 2) 
  {
    // report version
    std::cout << argv[0] << " Version " << STARFIELD_VERSION_MAJOR << "."
          << STARFIELD_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
  }

  std::cout << "Hello, from starfield!\n";
  GtkApplication *app;
  int status;


  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);
  
  return status;

}


