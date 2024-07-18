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
| File name   : m_window.c
| Description :
| Author      :
| Version     :
| Reviewer    :
| Review date :
+-----------------------------------------------------------------------------------*/
#include <string.h>
#include <glib.h>
#include "global_variable.h"
#include "global_constant.h"
#include "m_window.h"

void activate(GtkApplication *app, gpointer user_data)
 {
    AppWidgets *widgets = g_new0(AppWidgets, 1);
    gtk_init(NULL, NULL);
    gst_init(NULL, NULL);

    // Create the main window
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "PTCS_IPPIS");
    gtk_window_set_default_size(GTK_WINDOW(window), X_RES, Y_RES);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a fixed container
    widgets->fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), widgets->fixed);

    GtkWidget *drawing_area1 = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area1, X_RES, Y_RES);
    g_signal_connect(drawing_area1, "draw", G_CALLBACK(on_draw_event1), NULL);
    gtk_fixed_put(GTK_FIXED(widgets->fixed), drawing_area1, 0, 0);

    widgets->lang_id = 0;


    strcpy(widgets->h_next[0],"NEXT STATION");
    strcpy(widgets->h_speed[0],"SPEED");
    strcpy(widgets->h_timetr[0],"TIME TO REACH NEXT STATION");
    strcpy(widgets->h_date[0],"DATE");
    strcpy(widgets->h_time[0],"TIME");
    strcpy(widgets->t_number[0],"12904");
    strcpy(widgets->t_name[0],"GOLDEN TEMPLE");
    strcpy(widgets->t_src[0],"NDLS");
    strcpy(widgets->t_dest[0],"CSMT");
    strcpy(widgets->t_next[0],"BORIVALI");
    strcpy(widgets->t_speed[0],"45 Kmph");
    strcpy(widgets->t_timetr[0],"45 Min.");
    strcpy(widgets->t_date[0],"24:06:24");
    strcpy(widgets->t_time[0],"16:08");

    strcpy(widgets->prm_message[0],"INDIAN RAILWAYS WISHES YOU HAPPY AND COMFORTABLE JOURNEY");
    strcpy(widgets->prm_message[1],"भारतीय रेलवे आपकी सुखद एवं आरामदायक यात्रा की कामना करता है");

    widgets->lang_id = 0;

    create_video_view(widgets);
    text_banner(widgets);
    train_number(widgets);
    train_name(widgets);
    train_src(widgets);
    train_dest(widgets);
    train_name_seperator(widgets);
    train_src_dest(widgets);
    train_next_station(widgets);
    train_speed(widgets);
    train_time_to_reach(widgets);
    train_date(widgets);
    train_time(widgets);

    // Initialize the views to start with the first video
    widgets->current_view = 0;
    widgets->current_video = 0;
    widgets->current_image = 0;
    widgets->current_text = 0;

    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, XX8-20, YY8);
    gtk_fixed_put(GTK_FIXED(widgets->fixed), drawing_area, 10, Y8);

    gchar *texts[] = {

        "ભારતીય રેલ્વે તમને સુખી અને આરામદાયક મુસાફરીની શુભેચ્છા આપે છે ",
        "INDIAN RAILWAYS WISHES YOU HAPPY AND COMFORTABLE JOURNEY",
        "भारतीय रेलवे आपकी सुखद एवं आरामदायक यात्रा की कामना करता है",

       };
    gint num_texts = sizeof(texts) / sizeof(texts[0]);

    MarqueeData marquee_data = {
        .drawing_area = drawing_area,
        .x_position = 0, // Initial position
        .text_width = 0,
        .view_width = XX1-10, // Adjust width to fit within window's content area
        .scroll_enabled = FALSE,
        .texts = texts,
        .current_text_index = 0,
        .num_texts = num_texts
    };

     // Get the height and width of the text
    switch_text(&marquee_data);

    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw_event), &marquee_data);






    // Apply CSS styles to the main window
    apply_css(window, "style.css");

    // Show all widgets
    gtk_widget_show_all(window);



    // Switch text every 5 seconds
    g_timeout_add_seconds(15, switch_text, &marquee_data);


    g_timeout_add(3, scroll_text, &marquee_data); // Adjust the timeout value to change the refresh rate


   // Set a timer to update the text view every second
    g_timeout_add_seconds(15, update_label_text, widgets);

    gst_element_set_state(widgets->playbins[widgets->current_video], GST_STATE_PLAYING);
    gtk_widget_show(widgets->video_areas[widgets->current_video]);


    gtk_main();




}


void* update_label_thread(void* data)
{
    ThreadData* thread_data = (ThreadData*)data;
    int counter = 0;

    struct sched_param param;
    param.sched_priority = 50;  // Set priority (0-99, higher is more critical)
    if (pthread_setschedparam(pthread_self(), SCHED_RR, &param) != 0) {
        g_warning("Failed to set real-time scheduling");
    }


   while (1) {
         usleep(1000000);  // Sleep for 1 second

        // Use g_idle_add to safely update the GTK widget from the thread

        printf("COUNTER %d\n",counter++);

    }

    return NULL;
}

void on_window_destroy(GtkWidget *widget, gpointer data)
{
    ThreadData *thread_data = (ThreadData *)data;
    thread_data->running = FALSE; // Stop the thread
    gtk_main_quit();
}







static gboolean toggle_views(gpointer data)
 {
    AppWidgets *widgets = (AppWidgets *)data;

    return TRUE;
 }



static gboolean update_label_text(gpointer data)
{
    AppWidgets *widgets = (AppWidgets *)data;
    char buffer[256];
    static char i = 0;
 //  widgets->lang_id ^= 1;

     widgets->lang_id++;
     if(widgets->lang_id >=3)
        widgets->lang_id = 0;

    strcpy(widgets->h_next[0],"NEXT STATION");
    strcpy(widgets->h_speed[0],"SPEED");
    strcpy(widgets->h_timetr[0],"TIME TO REACH NEXT STATION");
    strcpy(widgets->h_date[0],"DATE");
    strcpy(widgets->h_time[0],"TIME");
    strcpy(widgets->t_number[0],"12904");
    strcpy(widgets->t_name[0],"GOLDEN TEMPLE");
    strcpy(widgets->t_src[0],"NDLS");
    strcpy(widgets->t_dest[0],"CSMT");
    strcpy(widgets->t_next[0],"BORIVALI");
    strcpy(widgets->t_speed[0],"45 Kmph");
    strcpy(widgets->t_timetr[0],"45 Min.");
    strcpy(widgets->t_date[0],"24:06:24");
    strcpy(widgets->t_time[0],"16:08");

    strcpy(widgets->h_next[1],"अगला स्टेशन");
    strcpy(widgets->h_speed[1],"गति");
    strcpy(widgets->h_timetr[1],"अगले स्टेशन तक पहुंचने का समय");
    strcpy(widgets->h_date[1],"दिनांक");
    strcpy(widgets->h_time[1],"समय");
    strcpy(widgets->t_number[1],"12904");
    strcpy(widgets->t_name[1],"गोल्डन टेम्पल");
    strcpy(widgets->t_src[1],"नई दिल्ली");
    strcpy(widgets->t_dest[1],"सीएसएमटी");
    strcpy(widgets->t_next[1],"बोरीवली");
    strcpy(widgets->t_speed[1],"45 Kmph");
    strcpy(widgets->t_timetr[1],"45 Min.");
    strcpy(widgets->t_date[1],"24:06:24");
    strcpy(widgets->t_time[1],"16:08");

    strcpy(widgets->h_next[2],"આગલું સ્ટેશન ");
    strcpy(widgets->h_speed[2],"ગતિ");
    strcpy(widgets->h_timetr[2],"આગામી સ્ટેશન પર પહોંચવાનો સમય ");
    strcpy(widgets->h_date[2],"તારીખ ");
    strcpy(widgets->h_time[2],"સમય ");
    strcpy(widgets->t_number[2],"12904");
    strcpy(widgets->t_name[2],"સુવર્ણ મંદિર ");
    strcpy(widgets->t_src[2],"નવી દિલ્લી ");
    strcpy(widgets->t_dest[2],"સીએસએમટી ");
    strcpy(widgets->t_next[2],"બોરીવલી ");
    strcpy(widgets->t_speed[2],"45 Kmph");
    strcpy(widgets->t_timetr[2],"45 Min.");
    strcpy(widgets->t_date[2],"24:06:24");
    strcpy(widgets->t_time[2],"16:08");




    strcpy(widgets->prm_message[0],"INDIAN RAILWAYS WISHES YOU HAPPY AND COMFORTABLE JOURNEY");
    strcpy(widgets->prm_message[1],"भारतीय रेलवे आपकी सुखद एवं आरामदायक यात्रा की कामना करता है");
    strcpy(widgets->prm_message[2],"ભારતીય રેલ્વે તમને સુખી અને આરામદાયક મુસાફરીની શુભેચ્છા આપે છે ");




    snprintf(buffer, sizeof(buffer), widgets->h_next[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->banner_areas[0]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->h_speed[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->banner_areas[1]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->h_timetr[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->banner_areas[2]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->h_date[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->banner_areas[3]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->h_time[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->banner_areas[4]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->t_number[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->text_areas[0]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->t_name[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->text_areas[1]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->t_src[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->text_areas[2]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->t_dest[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->text_areas[3]), buffer);

    snprintf(buffer, sizeof(buffer), widgets->t_next[widgets->lang_id]);
    gtk_label_set_text(GTK_LABEL(widgets->text_areas[6]), buffer);

    return TRUE;
}



// Callback function for the first drawing area
static gboolean on_draw_event1(GtkWidget *widget, cairo_t *cr, gpointer user_data)
{
   // Drawing a red rectangle
   cairo_set_source_rgb(cr, 0.5, 0.5, 0.5); // Red color
   cairo_set_line_width(cr, 10.0);  // Line width
   cairo_rectangle(cr, X0, Y0, XX0, YY0);
   cairo_rectangle(cr, X1, Y1, XX1, YY1);
   cairo_rectangle(cr, X2, Y2, XX2, YY2);
   cairo_rectangle(cr, X3, Y3, XX3, YY3);
   cairo_rectangle(cr, X4, Y4, XX4, YY4);
   cairo_rectangle(cr, X5, Y5, XX5, YY5);
   cairo_rectangle(cr, X6, Y6, XX6, YY6);
   cairo_rectangle(cr, X7, Y7, XX7, YY7);
   cairo_stroke(cr);
    return FALSE;
}




gboolean switch_text(gpointer data)
{
    MarqueeData *marquee_data = (MarqueeData *)data;
    marquee_data->current_text_index = (marquee_data->current_text_index + 1) % marquee_data->num_texts;
    printf("nt %d\n",marquee_data->num_texts);
    printf("ti %d\n",marquee_data->current_text_index);
    // Reset the x_position for new text
    PangoLayout *layout = gtk_widget_create_pango_layout(marquee_data->drawing_area, marquee_data->texts[marquee_data->current_text_index]);
    // Create a PangoAttrList to hold the attributes
    PangoAttrList *attr_list = pango_attr_list_new();

    PangoFontDescription *desc = pango_font_description_from_string("80");

    pango_layout_set_font_description(layout, desc);
    pango_font_description_free(desc);

    // Set the foreground color (red)
    PangoAttribute *attr_color = pango_attr_foreground_new(0, 65535, 0); // Red color (R, G, B in 16-bit)
    pango_attr_list_insert(attr_list, attr_color);

    // Apply the attributes to the layout
    pango_layout_set_attributes(layout, attr_list);

    // Release the reference to the PangoAttrList
    pango_attr_list_unref(attr_list);

    // Disable word wrapping to keep text in a single line
    pango_layout_set_width(layout, -1);
    pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);



    int text_width, text_height;
    pango_layout_get_pixel_size(layout, &text_width, &text_height);
    marquee_data->text_width = text_width;

  if (text_width > marquee_data->view_width)
    {
        marquee_data->scroll_enabled = TRUE;
        marquee_data->x_position = marquee_data->view_width;
    }
  else
    {
        marquee_data->scroll_enabled = FALSE;
        marquee_data->x_position = (marquee_data->view_width - text_width) / 2;
    }

    g_object_unref(layout);

    // Queue redraw to update the new text
    gtk_widget_queue_draw(marquee_data->drawing_area);

    return TRUE;
}





gboolean scroll_text(gpointer data)
{
    MarqueeData *marquee_data = (MarqueeData *)data;
    if (!marquee_data->scroll_enabled) {
        return TRUE;
    }

    marquee_data->x_position -= 1; // Adjust this value to change scrolling speed

    if (marquee_data->x_position < -marquee_data->text_width) {
        marquee_data->x_position = marquee_data->view_width;
    }

    gtk_widget_queue_draw(marquee_data->drawing_area);
    return TRUE;
}




gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer data)
{

    MarqueeData *marquee_data = (MarqueeData *)data;
   const gchar *text = marquee_data->texts[marquee_data->current_text_index];

    PangoLayout *layout = gtk_widget_create_pango_layout(widget, text);

 // Create a PangoAttrList to hold the attributes
    PangoAttrList *attr_list = pango_attr_list_new();

    PangoFontDescription *desc = pango_font_description_from_string("80");
    pango_layout_set_font_description(layout, desc);
    pango_font_description_free(desc);

    // Set the foreground color (red)
    PangoAttribute *attr_color = pango_attr_foreground_new(65535, 0, 0); // Red color (R, G, B in 16-bit)
    pango_attr_list_insert(attr_list, attr_color);

    // Apply the attributes to the layout
    pango_layout_set_attributes(layout, attr_list);

    // Release the reference to the PangoAttrList
    pango_attr_list_unref(attr_list);

    // Disable word wrapping to keep text in a single line
    pango_layout_set_width(layout, -1);
    pango_layout_set_wrap(layout, PANGO_WRAP_WORD_CHAR);

    cairo_move_to(cr, marquee_data->x_position, 10); // Adjust y-position as needed
    pango_cairo_show_layout(cr, layout);

    g_object_unref(layout);


    return FALSE;
}

/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/







