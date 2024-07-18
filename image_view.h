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
const char *VIDEO_FILES[NUM_VIDEOS] = {

    "file:///home/avan18/abcd.mp4"


};

const char *TEXTS[NUM_TEXTS] = {
      "12345"



};
extern void apply_css(GtkWidget *widget, const gchar *css_file_path);
extern void add_css_class(GtkWidget *widget, const gchar *css_class);
void create_video_view(AppWidgets *widgets);
void text_banner(AppWidgets *widgets);
void marquee_text_view(AppWidgets *widgets);
static void realize_cb(GtkWidget *widget, gpointer data);
void train_number(AppWidgets *widgets);
void train_name(AppWidgets *widgets);
void train_src(AppWidgets *widgets);
void train_dest(AppWidgets *widgets);
void train_name_seperator(AppWidgets *widgets);
void train_src_dest(AppWidgets *widgets);
void train_next_station(AppWidgets *widgets);
void train_speed(AppWidgets *widgets);
void train_time_to_reach(AppWidgets *widgets);
void train_date(AppWidgets *widgets);
void train_time(AppWidgets *widgets);


/* WORK AREA */
/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/
