#include <pebble.h>
void show_menu(void);
void hide_menu(void);
void start_game(void);
void continueDialogue(void) ;
int currentText;
GBitmap *s_res_frame1_bmp;
GBitmap *s_res_frame2_bmp;
GBitmap *s_res_frame3_bmp;
bool grumpy;
int currChoice;
bool choiceActive;