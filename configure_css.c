/*-----------------------------------------------------------------------------------+
|                         PT Communication Systems Pvt. Ltd.
+-----------------------------------------------------------------------------------*/

/*----------------------------- COPYRIGHT INFORMATION -------------------------------+
| This Program and its Contents are the property of PT Communication Systems Pvt. Ltd.
| or its subsidiaries. This  document contains confidential  proprietary  information,
| which is also protected as an unpublished  work under applicable Copyright Laws. The
| reproduction, distribution, utilization or the communication of this document or any
| part  thereof, without  express authorization is strictly prohibited. Offenders will
| be held liable for the payment of damages.
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------+
| Module      : IPPIS-TFT DISPLAY
| File name   : config_css.c
| Description :
| Author      :
| Version     :
| Reviewer    :
| Review date :
+-----------------------------------------------------------------------------------*/
#include "global_variable.h"
#include "global_constant.h"
#include "configure_css.h"




// Function to apply CSS from a file to a widget
void apply_css(GtkWidget *widget, const gchar *css_file_path)
{
    // Create a new CSS provider
    GtkCssProvider *provider = gtk_css_provider_new();
    // Get the screen of the widget
    GdkScreen *screen = gtk_widget_get_screen(widget);
    // Get the style context of the widget
    GtkStyleContext *context = gtk_widget_get_style_context(widget);

    // Load CSS from the specified file and apply it to the screen
    if (gtk_css_provider_load_from_path(provider, css_file_path, NULL)) {
        gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    } else {
        // Print a warning if CSS file loading fails
        g_warning("Failed to load CSS from file: %s", css_file_path);
    }

    // Unreference the provider to free memory
    g_object_unref(provider);
}

// Function to add a CSS class to a widget
void add_css_class(GtkWidget *widget, const gchar *css_class)
{
    // Get the style context of the widget
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    // Add the specified CSS class to the widget's style context
    gtk_style_context_add_class(context, css_class);
}





/* WORK AREA */
/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/
