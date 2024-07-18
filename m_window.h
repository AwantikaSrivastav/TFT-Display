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
| File name   : m_window.h
| Description :
| Author      :
| Version     :
| Reviewer    :
| Review date :
+-----------------------------------------------------------------------------------*/


/* variables declaration */

/* function declaration */
typedef struct {
    GtkWidget *drawing_area;
    gint x_position;
    gint text_width;
    gint view_width;
    gboolean scroll_enabled;
    gchar **texts;
    gint current_text_index;
    gint num_texts;
} MarqueeData;

void activate(GtkApplication *app, gpointer user_data);
//static gboolean scroll_text(gpointer data);
//static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer data);
static gboolean on_draw_event1(GtkWidget *widget, cairo_t *cr, gpointer data);
static gboolean toggle_views(gpointer data) ;
static gboolean update_label_text(gpointer data);
//MarqueeData prm_marquee_data(AppWidgets *widgets);
GtkWidget* m_text_view(AppWidgets *widgets);
extern void apply_css(GtkWidget *widget, const gchar *css_file_path);
extern void add_css_class(GtkWidget *widget, const gchar *css_class);
extern void create_video_view(AppWidgets *widgets);
extern void text_banner(AppWidgets *widgets);
//extern void marquee_text_view(AppWidgets *widgets);
extern void train_number(AppWidgets *widgets);
extern void train_name(AppWidgets *widgets);
extern void train_src(AppWidgets *widgets);
extern void train_dest(AppWidgets *widgets);
extern void train_name_seperator(AppWidgets *widgets);
extern void train_src_dest(AppWidgets *widgets);
extern void train_next_station(AppWidgets *widgets);
extern void train_speed(AppWidgets *widgets);
extern void train_time_to_reach(AppWidgets *widgets);
extern void train_date(AppWidgets *widgets);
extern void train_time(AppWidgets *widgets);

gboolean switch_text(gpointer data);
gboolean scroll_text(gpointer data);
gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer data);



/* WORK AREA */
/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/







