#include <gtk/gtk.h>

void greet(GtkWidget *widget, gpointer  data )
{
   g_print("Butona tiklandi\n");
}
void destroy( GtkWidget *widget,gpointer   data )
{
   gtk_main_quit();
}
int main(int argc,char *argv[] )
{
   GtkWidget *window;
   GtkWidget *button;
   gtk_init(&argc, &argv);
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   g_signal_connect (window, "destroy",
   G_CALLBACK (destroy), NULL);
   gtk_container_set_border_width
      (GTK_CONTAINER (window), 20);
   button = gtk_button_new_with_label ("Buton");
   g_signal_connect (GTK_OBJECT(button), "clicked",G_CALLBACK (greet), "button");
   gtk_container_add (GTK_CONTAINER (window), button);
   gtk_widget_show_all(window); 
   gtk_main();
   return 0;
}