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
| File name   : image_view.c
| Description :
| Author      :
| Version     :
| Reviewer    :
| Review date :
+-----------------------------------------------------------------------------------*/
#include "global_variable.h"
#include "global_constant.h"
#include "image_view.h"

void create_video_view(AppWidgets *widgets)
{
  for (int i = 0; i < NUM_VIDEOS; i++)
   {
        widgets->video_areas[i] = gtk_drawing_area_new();
        gtk_widget_set_size_request(widgets->video_areas[i], XX2-10, YY2);
        g_signal_connect(widgets->video_areas[i], "realize", G_CALLBACK(realize_cb), GINT_TO_POINTER(i));
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->video_areas[i], X2+5, Y2);
        gtk_widget_hide(widgets->video_areas[i]);

        widgets->playbins[i] = gst_element_factory_make("playbin", NULL);
        g_object_set(widgets->playbins[i], "uri", VIDEO_FILES[i], NULL);
        g_object_set_data(G_OBJECT(widgets->video_areas[i]), "appwidgets", widgets);
    }
}


void text_banner(AppWidgets *widgets)
{

       widgets->banner_areas[0] = gtk_label_new(widgets->h_next[widgets->lang_id]);
       gtk_widget_set_size_request(widgets->banner_areas[0], XX3, YY3);
       gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->banner_areas[0], X3, YY3);
       gtk_widget_hide(widgets->banner_areas[0]);
       add_css_class(widgets->banner_areas[0], "head1");
	   apply_css(widgets->banner_areas[0], "style.css");

        widgets->banner_areas[1] = gtk_label_new(widgets->h_speed[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->banner_areas[1], XX4, YY4);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->banner_areas[1], X4, YY3+YY4);
        gtk_widget_hide(widgets->banner_areas[1]);
        add_css_class(widgets->banner_areas[1], "head1");
	    apply_css(widgets->banner_areas[1], "style.css");

        widgets->banner_areas[2] = gtk_label_new(widgets->h_timetr[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->banner_areas[2], XX5, YY5);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->banner_areas[2], X5, YY3+YY4+YY5);
        gtk_widget_hide(widgets->banner_areas[2]);
        add_css_class(widgets->banner_areas[2], "head1");
	    apply_css(widgets->banner_areas[2], "style.css");


        widgets->banner_areas[3] = gtk_label_new(widgets->h_date[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->banner_areas[3], XX6, YY6);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->banner_areas[3], X6, Y6-50);
        gtk_widget_hide(widgets->banner_areas[3]);
        add_css_class(widgets->banner_areas[3], "head1");
	    apply_css(widgets->banner_areas[3], "style.css");

        widgets->banner_areas[4] = gtk_label_new(widgets->h_time[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->banner_areas[4], XX7, YY7);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->banner_areas[4], X7, Y7-50);
        gtk_widget_hide(widgets->banner_areas[4]);
        add_css_class(widgets->banner_areas[4], "head1");
	    apply_css(widgets->banner_areas[4], "style.css");

}

void train_number(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[0] = gtk_label_new(widgets->t_number[widgets->lang_id]);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[0], 0, 10);
        gtk_widget_hide(widgets->text_areas[0]);
        add_css_class(widgets->text_areas[0], "head2");
	    apply_css(widgets->text_areas[0], "style.css");

}
void train_name(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[1] = gtk_label_new(widgets->t_name[widgets->lang_id]);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[1], 400, 10);
        gtk_widget_hide(widgets->text_areas[1]);
        add_css_class(widgets->text_areas[1], "head3");
	    apply_css(widgets->text_areas[1], "style.css");
}

void train_src(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[2] = gtk_label_new(widgets->t_src[widgets->lang_id]);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[2], 1200, 10);
        gtk_widget_hide(widgets->text_areas[2]);
        add_css_class(widgets->text_areas[2], "head4");
	    apply_css(widgets->text_areas[2], "style.css");
}
void train_dest(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[3] = gtk_label_new(widgets->t_dest[widgets->lang_id]);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[3], 1600, 10);
        gtk_widget_hide(widgets->text_areas[3]);
        add_css_class(widgets->text_areas[3], "head5");
	    apply_css(widgets->text_areas[3], "style.css");
}

void train_name_seperator(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[4] = gtk_label_new("|");
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[4], 1100, 10);
        gtk_widget_hide(widgets->text_areas[4]);
        add_css_class(widgets->text_areas[4], "head6");
	    apply_css(widgets->text_areas[4], "style.css");
}
void train_src_dest(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[5] = gtk_label_new("-");
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[5], 1500, 10);
        gtk_widget_hide(widgets->text_areas[5]);
        add_css_class(widgets->text_areas[5], "head7");
	    apply_css(widgets->text_areas[5], "style.css");
}

void train_next_station(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[6] = gtk_label_new(widgets->t_next[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->text_areas[6], XX3, YY3);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[6], X3, YY3);
        gtk_widget_hide(widgets->text_areas[6]);
        add_css_class(widgets->text_areas[6], "head8");
	    apply_css(widgets->text_areas[6], "style.css");
}

void train_speed(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[7] = gtk_label_new(widgets->t_speed[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->text_areas[7], XX4, YY4);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[7], X4, YY3+YY4);
        gtk_widget_hide(widgets->text_areas[7]);
        add_css_class(widgets->text_areas[7], "head8");
	    apply_css(widgets->text_areas[7], "style.css");
}
void train_time_to_reach(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[8] = gtk_label_new(widgets->t_timetr[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->text_areas[8], XX5, YY5);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[8], X5, YY3+YY4+YY5);
        gtk_widget_hide(widgets->text_areas[8]);
        add_css_class(widgets->text_areas[8], "head8");
	    apply_css(widgets->text_areas[8], "style.css");
}

void train_date(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[9] = gtk_label_new(widgets->t_date[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->text_areas[9], XX6, YY6);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[9], X6, Y6-50);
        gtk_widget_hide(widgets->text_areas[9]);
        add_css_class(widgets->text_areas[9], "head8");
	    apply_css(widgets->text_areas[9], "style.css");
}

void train_time(AppWidgets *widgets)
{
// Create text areas
        widgets->text_areas[10] = gtk_label_new(widgets->t_time[widgets->lang_id]);
        gtk_widget_set_size_request(widgets->text_areas[10], XX7, YY7);
        gtk_fixed_put(GTK_FIXED(widgets->fixed), widgets->text_areas[10], X7, Y7-50);
        gtk_widget_hide(widgets->text_areas[10]);
        add_css_class(widgets->text_areas[10], "head8");
	    apply_css(widgets->text_areas[10], "style.css");
}

static void realize_cb(GtkWidget *widget, gpointer data)
 {
    int index = GPOINTER_TO_INT(data);
    AppWidgets *widgets = (AppWidgets *)g_object_get_data(G_OBJECT(widget), "appwidgets");
    GdkWindow *window = gtk_widget_get_window(widget);
    if (!gdk_window_ensure_native(window)) {
        g_error("Couldn't create native window needed for GstVideoOverlay!");
    }

    GstVideoOverlay *overlay = GST_VIDEO_OVERLAY(widgets->playbins[index]);
    gst_video_overlay_set_window_handle(overlay, GDK_WINDOW_XID(window));
}



/* WORK AREA */
/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/
