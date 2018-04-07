#include <pebble.h>
#include "instructions2.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static TextLayer *s_textlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(0, 0, 145, 170));
  text_layer_set_text(s_textlayer_1, "This game is dedicated to my homeboi Noah and Ami-1up on discord, and pebble for being a great smart watch platform :) I just wish I hadn't learned to code at the end of the life cycle of pebble, but what are you going to do I suppose. Also, thank you for playing! It really means a lot to me.");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_instructions2(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_instructions2(void) {
  window_stack_remove(s_window, true);
}
