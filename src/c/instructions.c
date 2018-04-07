#include <pebble.h>
#include "instructions.h"
#include "instructions2.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_14;
static GBitmap *s_res_img_separator;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_3;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_4;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_img_separator = gbitmap_create_with_resource(RESOURCE_ID_IMG_SEPARATOR);
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(2, 1, 141, 30));
  text_layer_set_text(s_textlayer_1, "Welcome to Steamed Hams: Pebble Edition!");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(1, 82, 143, 87));
  text_layer_set_text(s_textlayer_2, "The gameplay is pretty simple.  Just press select to progress dialogue, and use the up and down buttons to select a choice when one is presented.                           ");
  text_layer_set_text_alignment(s_textlayer_2, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_2, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(1, 33, 142, 45));
  text_layer_set_text(s_textlayer_3, "This game dynamically changes based on your choices. Choose wisely.");
  text_layer_set_text_alignment(s_textlayer_3, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_3, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_3);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(-4, 77, 156, 7));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_img_separator);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(61, 152, 100, 20));
  text_layer_set_text(s_textlayer_4, "Press select >");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_4);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_3);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_4);
  gbitmap_destroy(s_res_img_separator);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void one_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_instructions2();
}

void instructions_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, one_click_handler);
}

void show_instructions(void) {
  initialise_ui();
  window_set_click_config_provider(s_window, (ClickConfigProvider) instructions_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_instructions(void) {
  window_stack_remove(s_window, true);
}
