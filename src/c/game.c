#include <pebble.h>
#include "game.h"
#include "main.h"

int currChoice;
bool choiceActive = true;
int currentText;
bool grumpy;
GBitmap *s_res_frame1_bmp;
GBitmap *s_res_frame2_bmp;
GBitmap *s_res_frame3_bmp;
GBitmap *s_res_frame4_bmp;
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_dialogue_bmp;
static GFont s_res_gothic_14;
static GBitmap *s_res_frame_one;
static BitmapLayer *s_bitmaplayer_2;
static BitmapLayer *s_bitmaplayer_1;
static BitmapLayer *s_bitmaplayer_3;
static TextLayer *s_textlayer_3;
static TextLayer *s_textlayer_2;
static TextLayer *s_textlayer_1;
static TextLayer *s_textlayer_4;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_dialogue_bmp = gbitmap_create_with_resource(RESOURCE_ID_DIALOGUE_BMP);
  s_res_gothic_14 = fonts_get_system_font(FONT_KEY_GOTHIC_14);
  s_res_frame_one = gbitmap_create_with_resource(RESOURCE_ID_FRAME_ONE);
  // s_bitmaplayer_2
  s_bitmaplayer_2 = bitmap_layer_create(GRect(0, 0, 146, 120));
  bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame_one);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_2);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 118, 144, 50));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_dialogue_bmp);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_bitmaplayer_3
  s_bitmaplayer_3 = bitmap_layer_create(GRect(0, 79, 144, 40));
  bitmap_layer_set_bitmap(s_bitmaplayer_3, s_res_dialogue_bmp);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_3);
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(7, 102, 131, 15));
  text_layer_set_background_color(s_textlayer_3, GColorClear);
  text_layer_set_text(s_textlayer_3, "Here");
  text_layer_set_font(s_textlayer_3, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_3);
  
  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(7, 85, 130, 17));
  text_layer_set_background_color(s_textlayer_2, GColorClear);
  text_layer_set_text(s_textlayer_2, "There should be choices");
  text_layer_set_font(s_textlayer_2, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_2);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(8, 133, 130, 29));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text(s_textlayer_1, "Rip dialogue?");
  text_layer_set_font(s_textlayer_1, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  
  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(9, 122, 129, 15));
  text_layer_set_background_color(s_textlayer_4, GColorClear);
  text_layer_set_text(s_textlayer_4, "Name");
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_4);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_2);
  bitmap_layer_destroy(s_bitmaplayer_1);
  bitmap_layer_destroy(s_bitmaplayer_3);
  text_layer_destroy(s_textlayer_3);
  text_layer_destroy(s_textlayer_2);
  text_layer_destroy(s_textlayer_1);
  text_layer_destroy(s_textlayer_4);
  gbitmap_destroy(s_res_dialogue_bmp);
  gbitmap_destroy(s_res_frame_one);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_menu(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void presentChoices(void) {
  bitmap_layer_set_bitmap(s_bitmaplayer_3, s_res_dialogue_bmp);
  text_layer_set_text(s_textlayer_2, "I guess I forgot");
  text_layer_set_text(s_textlayer_3, "to include a choice");
  choiceActive = true;
}

void hideChoices(void) {
  bitmap_layer_set_bitmap(s_bitmaplayer_3, NULL);
  text_layer_set_text(s_textlayer_2, "");
  text_layer_set_text(s_textlayer_3, "");
  choiceActive = false;
}

void continueDialogue(void) {
  currentText++;
  if(choiceActive==true) {
    hideChoices();
  }
  hideChoices();
  if(currentText==-1) {
    text_layer_set_text(s_textlayer_1, "Well Seymour, I made it, despite your directions.");
    text_layer_set_text(s_textlayer_4, "Chalmers");
    presentChoices();
    bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame_one);
    text_layer_set_text(s_textlayer_2, "Welcome!");
    text_layer_set_text(s_textlayer_3, "Hey.");
  }
  if (currentText == 0) {
    if(currChoice == 1) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Oh. You're here. Come in, I suppose.");
        grumpy = true;
    }
    if(currChoice == 0){
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Ah, Superintendent Chalmers welcome! I");
    }
  }
  if (currentText == 1) {
    if(grumpy==true) {
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "Quite rude, Skinner.");
    }
    if(grumpy==false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "hope you're prepared for an unforgettable");
    }
  }
    if (currentText == 2) {
    if(grumpy==true) {
      gbitmap_destroy(s_res_frame1_bmp);
      s_res_frame2_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWO);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame2_bmp);
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "*Seymour leaves to the kitched, and");
    }
    if(grumpy==false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "luncheon!");
    }
    }
      if (currentText == 3) {
        if(grumpy==true) {
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "Chalmers leaves to the dining table*");
    }
    if(grumpy==false) {
      gbitmap_destroy(s_res_frame1_bmp);
      s_res_frame2_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWO);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame2_bmp);
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "*Seymour leaves to the kitched, and");
    }
  }
  if (currentText == 4) {
        if(grumpy==true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      gbitmap_destroy(s_res_frame2_bmp);
      s_res_frame3_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_THREE);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame3_bmp);
      text_layer_set_text(s_textlayer_1, "*His roast is completely engulfed!*");
    }
    if(grumpy==false) {
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "Chalmers leaves to the dining table*");
    }
  }
  if (currentText == 5) {
        if(grumpy==true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Oh egads! My roast is ruined!");
      presentChoices();
      text_layer_set_text(s_textlayer_2, "Purchase hamburgers");
      text_layer_set_text(s_textlayer_3, "Purchase chinese food");
    }
    if(grumpy==false) {
      gbitmap_destroy(s_res_frame2_bmp);
      s_res_frame3_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_THREE);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame3_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "*His roast is completely engulfed!*");
    }
  }
  if (currentText == 6) {
     if(grumpy==true) {
          if(currChoice==0) {
            gbitmap_destroy(s_res_frame3_bmp);
            s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
            bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
            text_layer_set_text(s_textlayer_4, "Seymour");
            text_layer_set_text(s_textlayer_1, "What if I were to purchase fast");
          }
          if(currChoice==1) {
            gbitmap_destroy(s_res_frame3_bmp);
            s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
            bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
            text_layer_set_text(s_textlayer_4, "Seymour");
            text_layer_set_text(s_textlayer_1, "What if I were to purchase chinese");
          }
    }
    if(grumpy==false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Oh egads! My roast is ruined!");
      presentChoices();
      text_layer_set_text(s_textlayer_2, "Purchase hamburgers");
      text_layer_set_text(s_textlayer_3, "Own up");
    }
  }
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Continued Dialogue");
  APP_LOG(APP_LOG_LEVEL_DEBUG, "choiceAcitve is %d", choiceActive);
}

void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (choiceActive == false) {
    continueDialogue();
  }
}

void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (choiceActive == true) {
    currChoice = 1;
    continueDialogue();
  }
}

void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  if (choiceActive == true) {
    currChoice = 0;
    continueDialogue();
  }
}

void game_config_provider(Window *window) {
 // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
}

void start_game(void) {
  show_menu();
  choiceActive = false;
  currentText = -2;
  window_set_click_config_provider(s_window, (ClickConfigProvider) game_config_provider);
  continueDialogue();
  APP_LOG(APP_LOG_LEVEL_DEBUG, "currentText is %d", currentText);
}

void hide_menu(void) {
  window_stack_remove(s_window, true);
  //window_set_click_config_provider(s_window_main, (ClickConfigProvider) config_provider);
}
