//https://prognotes.net/2019/12/qt-widgets-application-project-structure/

#include <gtk/gtk.h>
#include <stdio.h>

GtkEntryBuffer *termBuffer = NULL;

int main( int argc, char *argv[] )
{
	GtkBuilder *builder;
	GtkWidget *window;

	termBuffer = gtk_entry_buffer_new( "You just pressed a buttion!\n", 20 );

	gtk_init( &argc, &argv );

	builder = gtk_builder_new();
	gtk_builder_add_from_file( builder, "window_main.glade", NULL );

	window = GTK_WIDGET( gtk_builder_get_object( builder, "window_main" ) );
	gtk_builder_connect_signals( builder, NULL );

	g_object_unref( builder );

	gtk_widget_show( window );
	gtk_main();

	return 0;
}

void on_action()
{
	printf( "Old text: %s\n", gtk_entry_buffer_get_text( termBuffer ) );
	gtk_entry_buffer_set_text( termBuffer, "You just pressed a buttion!\n", 20 );
	printf( "New text: %s\n", gtk_entry_buffer_get_text( termBuffer ) );
}

void on_quit( void )
{

	gtk_main_quit();
	printf( "Quit\n" );
}

// called when window is closed
void on_window_main_destroy()
{
	gtk_main_quit();
	printf( "Quit\n" );
}
