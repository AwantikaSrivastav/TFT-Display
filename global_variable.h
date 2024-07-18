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
| File name   : main.h
| Description :
| Author      :
| Version     :
| Reviewer    :
| Review date :
+-----------------------------------------------------------------------------------*/
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <gst/gst.h>
#include <gst/video/videooverlay.h>
#include "global_constant.h"
/* variables declaration */

typedef struct {
    GtkWidget *label;
    gboolean running;
} ThreadData;


typedef struct {
    GtkWidget *fixed;
    GtkWidget *video_areas[NUM_VIDEOS];
    GtkWidget *image_areas[NUM_IMAGES];
    GtkWidget *banner_areas[BAN_TEXTS];
    GtkWidget *text_areas[NUM_TEXTS];
    GstElement *playbins[NUM_VIDEOS];

    char h_next[3][50];
    char h_speed[3][50];
    char h_timetr[3][100];
    char h_date[3][32];
    char h_time[3][32];
    char t_number[3][10];
    char t_name[3][100];
    char t_src[3][32];
    char t_dest[3][32];
    char t_speed[3][20];
    char t_next[3][50];
    char t_timetr[3][50];
    char t_time[3][6];
    char t_date[3][20];
    char m_message[3][250];
    char prm_message[3][250];
    char lang_id;

    int current_view;
    int current_video;
    int current_image;
    int current_text;

} AppWidgets;




/* function declaration */


/* WORK AREA */
/*-----------------------------------------------------------------------------------+
| © 2024, PT Communication Systems Pvt. Ltd. or its subsidiaries.
| All rights reserved. Company confidential.
+-----------------------------------------------------------------------------------*/


