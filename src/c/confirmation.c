#include <pebble.h>
#include "confirmation.h"

const int delay_ms = 1000;
int currRain = 1;

static GBitmap *s_res_funeral_two;
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_funeral_one;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_funeral_one = gbitmap_create_with_resource(RESOURCE_ID_FUNERAL_ONE);
  s_res_funeral_two = gbitmap_create_with_resource(RESOURCE_ID_FUNERAL_TWO);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(-1, 53, 146, 120));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_funeral_one);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(0, -2, 145, 71));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text(s_textlayer_1, "Pebble was an amazing smart watch that deserved its praise and didnt deserve its ubrupt demise.");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_funeral_one);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

static void timer_callback(void *context) {
  app_timer_register(delay_ms, timer_callback, NULL);
  APP_LOG(APP_LOG_LEVEL_INFO, "Timer called! Also currRain ist %d", currRain);
  if(currRain==1) {
    bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_funeral_two);
    currRain = 2;
    APP_LOG(APP_LOG_LEVEL_INFO, "Set currRain to 2!");
  } else if(currRain==2) {
    bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_funeral_one);
    currRain = 1;
    APP_LOG(APP_LOG_LEVEL_INFO, "Set currRain to 1!");
  }
}

void show_confirmation(void) {
  // Schedule the timer
  app_timer_register(delay_ms, timer_callback, NULL);
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_confirmation(void) {
  window_stack_remove(s_window, true);
}
