#include <pebble.h>
#include "extrastory.h"
#include "game.h"

void continueDialogue2(void) {
  currentText++;
  if (choiceActive == true) {
    hideChoices();
  }
  APP_LOG(APP_LOG_LEVEL_DEBUG, "currentText is %d", currentText);
  if(currentText == 0) {
      if(stay==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Heres some fries and steak.");
      } else if(love==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "Superintendent. I really enjoyed that.");
      } else if (normal==true) {
        text_layer_set_text(s_textlayer_4, "Chalmers");
        text_layer_set_text(s_textlayer_1, "I call hamburgers.'");
      } else if (honest==true) {
        text_layer_set_text(s_textlayer_4, "Seymour");
        text_layer_set_text(s_textlayer_1, "*Seymour realizes that they must-*");
        presentChoices();
        text_layer_set_text(s_textlayer_2, "Split up");
        text_layer_set_text(s_textlayer_3, "Stay together");
      }
  }
}