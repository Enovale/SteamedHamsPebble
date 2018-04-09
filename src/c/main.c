#include <pebble.h>
#include "main.h"
#include "game.h"
#include "instructions.h"
#include "confirmation.h"

bool gameStarted;
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window_main;
static GFont s_res_gothic_18_bold;
static GFont s_res_font_osp_din_44;
static GBitmap *s_res_menu_logo;
static GFont s_res_gothic_14;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_3;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_4;

static void initialise_ui(void) {
  s_window_main = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window_main, 0);
  #endif
  
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_font_osp_din_44 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_OSP_DIN_44));
  s_res_menu_logo = gbitmap_create_with_resource(RESOURCE_ID_MENU_LOGO);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(22, 73, 94, 24));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text(s_textlayer_1, "Pebble Edition");
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window_main), (Layer *)s_textlayer_1);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(26, 93, 89, 43));
  text_layer_set_background_color(s_textlayer_2, GColorClear);
  text_layer_set_text(s_textlayer_2, "Press Select to play!");
  text_layer_set_text_alignment(s_textlayer_2, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_2, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window_main), (Layer *)s_textlayer_2);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(113, 56, 25, 44));
  text_layer_set_background_color(s_textlayer_3, GColorClear);
  text_layer_set_text(s_textlayer_3, ">");
  text_layer_set_font(s_textlayer_3, s_res_font_osp_din_44);
  layer_add_child(window_get_root_layer(s_window_main), (Layer *)s_textlayer_3);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 1, 146, 70));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_menu_logo);
  layer_add_child(window_get_root_layer(s_window_main), (Layer *)s_bitmaplayer_1);
  
  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(29, 131, 79, 33));
  text_layer_set_background_color(s_textlayer_4, GColorClear);
  text_layer_set_text(s_textlayer_4, "Or down to see instructions!");
  text_layer_set_text_alignment(s_textlayer_4, GTextAlignmentCenter);
  text_layer_set_font(s_textlayer_4, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window_main), (Layer *)s_textlayer_4);
}

static void destroy_ui(void) {
  window_destroy(s_window_main);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_3);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_4);
  fonts_unload_custom_font(s_res_font_osp_din_44);
  gbitmap_destroy(s_res_menu_logo);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void select_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  //hide_main();
  start_game();
}

void down_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_instructions();
}

void up_single_click_handler(ClickRecognizerRef recognizer, void *context) {
  show_confirmation();
}

void config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, select_single_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_single_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_single_click_handler);
}

void show_main(void) {
  gameStarted = true;
  currChoice = 0;
  choiceActive = false;
  grumpy = false;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "show_main() called");
  initialise_ui();
  window_set_window_handlers(s_window_main, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window_main, true);
}

void hide_main(void) {
  window_stack_remove(s_window_main, true);
}

int main() {
  currentText = -2;
  grumpy = false;
  s_res_frame1_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_ONE);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Menu opened");
  currentText = -1;
  show_main();
  window_set_click_config_provider(s_window_main, (ClickConfigProvider) config_provider);
  app_event_loop();
  hide_main();
}
