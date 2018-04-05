#include <pebble.h>
#include "confirmation.h"
#include "main.h"
#include "game.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_bitham_30_black;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_3;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_bitham_30_black = fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK);
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(-1, -1, 145, 38));
  text_layer_set_text(s_textlayer_1, "WARNING");
  text_layer_set_font(s_textlayer_1, s_res_bitham_30_black);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(1, 34, 141, 45));
  text_layer_set_text(s_textlayer_2, "Fam if you do this it finna delete ur save. U ok wit that?");
  text_layer_set_text_alignment(s_textlayer_2, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(30, 97, 84, 32));
  text_layer_set_text(s_textlayer_3, "Select: Confirm Back: Abort");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_3);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_3);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_confirmation(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void single_click_handler(ClickRecognizerRef recognizer, void *context) {
  currentText = -1;
  persist_write_int(currentText, -1);
  hide_confirmation();
  show_main();
}

void confirmation_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, single_click_handler);
}

void hide_confirmation(void) {
  window_stack_remove(s_window, true);
}
