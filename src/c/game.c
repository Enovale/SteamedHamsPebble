
#include <pebble.h> 
#include "game.h"
#include "main.h"
#include "extrastory.h"

int currChoice;
bool choiceActive = true;
int currentText;
bool end;
bool grumpy;
bool honest;
bool normal;
bool chinese;
bool stay;
bool love;
bool nextFunc;
GBitmap * s_res_frame1_bmp;
GBitmap * s_res_frame2_bmp;
GBitmap * s_res_frame3_bmp;
GBitmap * s_res_frame4_bmp;
GBitmap * s_res_frame5_bmp;
GBitmap * s_res_frame6_bmp;
GBitmap * s_res_frame7_bmp;
GBitmap * s_res_frame8_bmp;
GBitmap * s_res_frame9_bmp;
GBitmap * s_res_frame10_bmp;
GBitmap * s_res_frame28_bmp;
// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window * s_window;
static GBitmap * s_res_dialogue_bmp;
static GFont s_res_gothic_14;
static GBitmap * s_res_frame_one;
static BitmapLayer * s_bitmaplayer_2;
static BitmapLayer * s_bitmaplayer_1;
static BitmapLayer * s_bitmaplayer_3;
static TextLayer * s_textlayer_2;
static TextLayer * s_textlayer_3;
static TextLayer * s_textlayer_1;
static TextLayer * s_textlayer_4;

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
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_bitmaplayer_2);

  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(0, 118, 144, 50));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_dialogue_bmp);
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_bitmaplayer_1);

  // s_bitmaplayer_3
  s_bitmaplayer_3 = bitmap_layer_create(GRect(0, 79, 144, 40));
  bitmap_layer_set_bitmap(s_bitmaplayer_3, s_res_dialogue_bmp);
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_bitmaplayer_3);

  // s_textlayer_2
  s_textlayer_2 = text_layer_create(GRect(8, 85, 130, 17));
  text_layer_set_background_color(s_textlayer_2, GColorClear);
  text_layer_set_text(s_textlayer_2, "There should be choices");
  text_layer_set_font(s_textlayer_2, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_textlayer_2);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "created choice2");
  
  // s_textlayer_3
  s_textlayer_3 = text_layer_create(GRect(8, 102, 130, 17));
  text_layer_set_background_color(s_textlayer_3, GColorClear);
  text_layer_set_text(s_textlayer_3, "There should be choices");
  text_layer_set_font(s_textlayer_3, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_textlayer_3);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "created choice1");

  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(8, 133, 130, 29));
  text_layer_set_background_color(s_textlayer_1, GColorClear);
  text_layer_set_text(s_textlayer_1, "Rip dialogue?");
  text_layer_set_font(s_textlayer_1, s_res_gothic_14);
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_textlayer_1);

  // s_textlayer_4
  s_textlayer_4 = text_layer_create(GRect(8, 122, 129, 15));
  text_layer_set_background_color(s_textlayer_4, GColorClear);
  text_layer_set_text(s_textlayer_4, "Name");
  layer_add_child(window_get_root_layer(s_window), (Layer * ) s_textlayer_4);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "done");
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

static void handle_window_unload(Window * window) {
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
  text_layer_set_text(s_textlayer_4, "Choose:");
  choiceActive = true;
  APP_LOG(APP_LOG_LEVEL_DEBUG, "choices is %d", choiceActive);
}

void hideChoices(void) {
  bitmap_layer_set_bitmap(s_bitmaplayer_3, NULL);
  text_layer_set_text(s_textlayer_2, "");
  text_layer_set_text(s_textlayer_3, "");
  choiceActive = false;
}

void continueDialogue(void) {
  currentText++;
  if (choiceActive == true) {
    hideChoices();
  }
  APP_LOG(APP_LOG_LEVEL_DEBUG, "currchoice is %d", currChoice);
  if (currentText == -1) {
    text_layer_set_text(s_textlayer_1, "Well Seymour, I made it, despite your directions.");
    text_layer_set_text(s_textlayer_4, "Chalmers");
    presentChoices();
    bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame_one);
    text_layer_set_text(s_textlayer_2, "Welcome!");
    text_layer_set_text(s_textlayer_3, "Hey.");
  }
  if (currentText == 0) {
    if (currChoice == 1) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Oh. You're here. Come in, I suppose.");
      grumpy = true;
    }
    if (currChoice == 0) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Ah, Superintendent Chalmers welcome! I");
      grumpy = false;
    }
  }
  if (currentText == 1) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "Quite rude, Skinner.");
    }
    if (grumpy == false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "hope you're prepared for an unforgettable");
    }
  }
  if (currentText == 2) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame1_bmp);
      s_res_frame2_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWO);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame2_bmp);
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "*Seymour leaves to the kitched, and");
    }
    if (grumpy == false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "luncheon!");
    }
  }
  if (currentText == 3) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "Chalmers leaves to the dining table*");
    }
    if (grumpy == false) {
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "Yeah.");
    }
  }
  if (currentText == 4) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      gbitmap_destroy(s_res_frame2_bmp);
      s_res_frame3_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_THREE);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame3_bmp);
      text_layer_set_text(s_textlayer_1, "*His roast is completely engulfed!*");
    }
    if (grumpy == false) {
      gbitmap_destroy(s_res_frame1_bmp);
      s_res_frame2_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWO);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame2_bmp);
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "*Seymour leaves to the kitched, and");
    }
  }
  if (currentText == 5) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Oh egads! My roast is ruined!");
      presentChoices();
      text_layer_set_text(s_textlayer_2, "Purchase hamburgers");
      text_layer_set_text(s_textlayer_3, "Purchase chinese food");
    }
    if (grumpy == false) {
      text_layer_set_text(s_textlayer_4, "");
      text_layer_set_text(s_textlayer_1, "Chalmers leaves to the dining table*");
    }
  }
  if (currentText == 6) {
    if (grumpy == true) {
      if (currChoice == 0) {
        chinese = false;
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "What if I were to purchase fast");
      }
      if (currChoice == 1) {
        chinese = true;
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "What if I were to purchase chinese");
      }
    }
    if (grumpy == false) {
      gbitmap_destroy(s_res_frame2_bmp);
      s_res_frame3_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_THREE);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame3_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "*His roast is completely engulfed!*");
    }
  }
  if (currentText == 7) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "food and desguise it as my own cooking?");
    }
    if (grumpy == false) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Oh egads! My roast is ruined!");
      presentChoices();
      text_layer_set_text(s_textlayer_2, "Purchase hamburgers");
      text_layer_set_text(s_textlayer_3, "Own up");
    }
  }
  if (currentText == 8) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame4_bmp);
      s_res_frame5_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FIVE);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame5_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Hohoho, delightfully devilish, Seymour!");
    }
    if (grumpy == false) {
      if (currChoice == 0) {
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "What if I were to purchase fast");
        normal = true;
      }
      if (currChoice == 1) {
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I suppose I may have to tell the Superintendent");
        honest = true;
      }
    }
  }
  if (currentText == 9) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame5_bmp);
      s_res_frame6_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_SIX);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame6_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "*Seymour goes to exit the kitchen via window*");
    }
    if (grumpy == false) {
      if (normal) {
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "What if I were to purchase fast");
      }
      if (honest) {
        gbitmap_destroy(s_res_frame3_bmp);
        s_res_frame4_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FOUR);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame4_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I suppose I may have to tell the Superintendent");
      }
    }
  }
  if (currentText == 10) {
    if (grumpy) {
      gbitmap_destroy(s_res_frame6_bmp);
      s_res_frame7_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_SEVEN);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame7_bmp);
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "I-");
    }
    if (grumpy == false) {
      if (normal) {
        gbitmap_destroy(s_res_frame4_bmp);
        s_res_frame5_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_FIVE);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame5_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Hohoho, delightfully devilish, Seymour!");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "about the ruined roast. *Leaves to meet him*");
      }
    }
  }
  if (currentText == 11) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame7_bmp);
      s_res_frame8_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_EIGHT);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame8_bmp);
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "SEEYYYYYYMMMOUR!");
    }
    if (grumpy == false) {
      if (normal) {
        gbitmap_destroy(s_res_frame5_bmp);
        s_res_frame6_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_SIX);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame6_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Goes to leave kitchen via window*");
      }
      if (honest) {
        gbitmap_destroy(s_res_frame5_bmp);
        s_res_frame28_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWENTY_EIGHT);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame28_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Superintendent, I'm afraid the roast is ruined.");
      }
    }
  }
  if (currentText == 12) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame7_bmp);
      s_res_frame8_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_EIGHT);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame8_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "SUPERINTENDENT! I was just- uh-");
    }
    if (grumpy == false) {
      if (normal) {
        gbitmap_destroy(s_res_frame6_bmp);
        s_res_frame7_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_SEVEN);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame7_bmp);
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "I-");
      }
      if (honest) {
        gbitmap_destroy(s_res_frame28_bmp);
        s_res_frame8_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_EIGHT);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame8_bmp);
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "*Slams desk* Seeeeymooouuuurr!!!!!");
      }
    }
  }
  if (currentText == 13) {
    if (grumpy == true) {
      gbitmap_destroy(s_res_frame8_bmp);
      s_res_frame10_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TEN);
      bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame10_bmp);
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Stretching my calfs on the windowsill!");
    }
    if (grumpy == false) {
      if (normal) {
        gbitmap_destroy(s_res_frame7_bmp);
        s_res_frame8_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_EIGHT);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame8_bmp);
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "SEEYYYYYYMMMOUR!");
      }
      if (honest) {
        gbitmap_destroy(s_res_frame8_bmp);
        s_res_frame28_bmp = gbitmap_create_with_resource(RESOURCE_ID_FRAME_TWENTY_EIGHT);
        bitmap_layer_set_bitmap(s_bitmaplayer_2, s_res_frame28_bmp);
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Y-yes, Superintendent?");
      }
    }
  }
  if (currentText == 14) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Isometric exercise, Care to join me?");
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "SUPERINTENDENT! I was just- uh-");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Everyday of the week I see you");
      }
    }
  }
  if (currentText == 15) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Chalmers");
      text_layer_set_text(s_textlayer_1, "Seymour, I think i'd better leave.");
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Why is there smoke coming out of your");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "screwing up! Lying to me! Making");
      }
    }
  }
  if (currentText == 15) {
    if (grumpy == true) {
      text_layer_set_text(s_textlayer_4, "Seymour");
      text_layer_set_text(s_textlayer_1, "Superintendent wait! I-");
      presentChoices();
      text_layer_set_text(s_textlayer_2, "Want you to stay");
      text_layer_set_text(s_textlayer_3, "Love you");
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "oven, Seymour?");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "a fool out of me!");
      }
    }
  }
  if (currentText == 16) {
    if (grumpy == true) {
      if(currChoice==0) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Want you to stay! What about lunch?");
        stay = true;
      }
      if(currChoice==1) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "...Love you. With passion.");
        love = true;
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Oh, that's not smoke! Thats steam!");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "*rolls up his sleeves and begins to");
      }
    }
  }
  if (currentText == 17) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Fine Seymour, You win. Ill wait here.");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Good lord! I-... I feel the same.");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Steam from the steamed clams we're");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "slowly advance to Seymour*");
      }
    }
  }
  if (currentText == 18) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Phew");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I must get us steamed hams!");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "having! Mmm, steamed clams");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "*Puts out hand in a threatening manner*");
      }
    }
  }
  if (currentText == 19) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Leaves to Krusty Burger*");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Zooms through the window*");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "*Squints, leaves*");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Let’s get us another roast, howsabout it?");
      }
    }
  }
  if (currentText == 20) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I would like to order 3 Krusty Bur-");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "*Seymour arrives back at the kitchen with");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Runs to Krusty Burger*");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I know I know! I really scre- wait, what?");
      }
    }
  }
  if (currentText == 21) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Cashier");
        text_layer_set_text(s_textlayer_1, "Sorry mate, burger machine broke.");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "mouthwatering steamed hams*");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Superintendent, I hope you're ready for some");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "*Laughs* We mustn’t dawdle Seymour. A");
      }
    }
  }
  if (currentText == 22) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Cashier");
        text_layer_set_text(s_textlayer_1, "We got fries though.");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Now we may resume our unforgettable luncheon!");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "mouth-watering hamburgers!");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "Gentlemen never keeps a good roast waiting!");
      }
    }
  }
  if (currentText == 23) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Fine. Ill take those. *grumble*");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "*The two peacefully eat their ham, and");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "I thought we were having steamed clams.");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "To Walmart!");
      }
    }
  }
  if (currentText == 24) {
    if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Back at the house, Seymour must choose");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "talk about their lives together*");
      }
   if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "No, no! I said steamed hams! That's what");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "*The pair set off on their journey, and");
      }
  }/*
  if (currentText == 25) {
    if (grumpy == true) {
      if(stay) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "what dish to pair with the fries. Be wise*");
        presentChoices();
        text_layer_set_text(s_textlayer_3, "Steak");
        text_layer_set_text(s_textlayer_2, "Porkchops");
      }
      if(love) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*yawn* That was a beautiful evening,");
      }
    }
    if (grumpy == false) {
      if (normal) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "I call hamburgers!");
      }
      if (honest) {
        text_layer_set_text(s_textlayer_4, "");
        text_layer_set_text(s_textlayer_1, "encounter a dangerous intersection*");
      }
    }
  }
  if (currentText == 26) {
    if (grumpy == true) {
      if(stay==true) {
        if(currChoice==0) {
          text_layer_set_text(s_textlayer_4, "Seymour");
          text_layer_set_text(s_textlayer_1, "Heres some fries and steak.");
        }
        if(currChoice==1) {
          text_layer_set_text(s_textlayer_4, "Seymour");
          text_layer_set_text(s_textlayer_1, "Have some fries and porkchops.");
        }
      }
      if(love==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Superintendent. I really enjoyed that.");
      }
    }
    if (grumpy == false) {
      if (normal==true) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "You call hamburgers 'Steamed hams'");
      }
      if (honest==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Seymour realizes that they must-*");
        presentChoices();
        text_layer_set_text(s_textlayer_2, "Split up");
        text_layer_set_text(s_textlayer_3, "Stay together");
      }
    }
  }
  if (currentText == 27) {
    if (grumpy == true) {
      if(stay==true) {
          text_layer_set_text(s_textlayer_4, "Seymour");
          text_layer_set_text(s_textlayer_1, "Have some fries and porkchops.");
      }
      if(love==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Superintendent. I really enjoyed that.");
      }
    }
    if (grumpy == false) {
      if (normal==true) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "You call hamburgers 'Steamed hams'");
      }
      if (honest==true) {
        if(currChoice==0) {
          text_layer_set_text(s_textlayer_4, "Seymour");
          text_layer_set_text(s_textlayer_1, "We should split up, Superintendent!");
        }
        if(currChoice==1) {
          text_layer_set_text(s_textlayer_4, "Seymour");
          text_layer_set_text(s_textlayer_1, "We must stick together, Superintendent!");
        }
      }
    }
  }*/
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Continued Dialogue");
  APP_LOG(APP_LOG_LEVEL_DEBUG, "choiceAcitve is %d", choiceActive);
}

void select_click_handler(ClickRecognizerRef recognizer, void * context) {
  if (choiceActive == false) {
    if(currentText > 24) {
      currentText = -1;
      nextFunc = true;
      continueDialogue2();
    }
    if(nextFunc==true) {
      continueDialogue2();
    }
    if(nextFunc==false) {
      continueDialogue();
    }
  }
}

void down_click_handler(ClickRecognizerRef recognizer, void * context) {
  if (choiceActive == true) {
    currChoice = 1;
    continueDialogue();
  }
}

void up_click_handler(ClickRecognizerRef recognizer, void * context) {
  if (choiceActive == true) {
    currChoice = 0;
    continueDialogue();
  }
}

void game_config_provider(Window * window) {
  // single click / repeat-on-hold config:
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
}

void start_game(void) {
  show_menu();
  chinese = false;
  nextFunc = false;
  honest = false;
  stay = false;
  love = false;
  normal = false;
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