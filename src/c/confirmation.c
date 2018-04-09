#include <pebble.h>
#include "confirmation.h"
#include "game.h"

const int delay_ms = 1000;
int currRain = 1;
bool oneLoaded;
bool twoLoaded;

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
  text_layer_set_text(s_textlayer_1, "Pebble is a great smartwatch, and it's sad to see it go. We will miss you, Pebble.");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  if(oneLoaded==true) {
    APP_LOG(APP_LOG_LEVEL_INFO, "destroyed 1");
    gbitmap_destroy(s_res_funeral_one);
  } else if (twoLoaded==true) {
    APP_LOG(APP_LOG_LEVEL_INFO, "destroyed 2");
    gbitmap_destroy(s_res_funeral_two);
  }
  gameStarted = true;
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

static void timer_callback(void *context) {
  if(gameStarted==false) {
  if(currRain==1) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Timer called! Also currRain ist %d also gameStarted is %d", currRain, gameStarted);
    gbitmap_destroy(s_res_funeral_one);
    s_res_funeral_two = gbitmap_create_with_resource(RESOURCE_ID_FUNERAL_TWO);
    bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_funeral_two);
    currRain = 2;
    APP_LOG(APP_LOG_LEVEL_INFO, "Set currRain to 2!");
    oneLoaded = false;
    twoLoaded = true;
  app_timer_register(delay_ms, timer_callback, NULL);
  } else if(currRain==2) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Timer called! Also currRain ist %d", currRain);
    gbitmap_destroy(s_res_funeral_two);
    s_res_funeral_one = gbitmap_create_with_resource(RESOURCE_ID_FUNERAL_ONE);
    bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_funeral_one);
    currRain = 1;
    APP_LOG(APP_LOG_LEVEL_INFO, "Set currRain to 1!");
    oneLoaded = true;
    twoLoaded = false;
  app_timer_register(delay_ms, timer_callback, NULL);
  }
  }
}

void show_confirmation(void) {
  // Schedule the timer
  app_timer_register(delay_ms, timer_callback, NULL);
  gameStarted = false;
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_confirmation(void) {
  gameStarted = true;
  window_stack_remove(s_window, true);
}
