#include"user_login.h"
#include"DIALOGUE.h"
#include"SONG.h"
#include"GAME.h"
#include "PROGRESSBAR.h"
#include"Main_menu.h"
int main(){
    if(!user_login())
        exit(1);
    Main_menuu();
}
