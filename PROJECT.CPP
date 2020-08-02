#include"h_file/user_login.h"
#include"h_file/DIALOGUE.h"
#include"h_file/SONG.h"
#include"h_file/GAME.h"
#include"h_file/PROGRESSBAR.h"
#include"h_file/Main_menu.h"
#include"h_file/logo.h"
int main(){
    logo();
    if(!user_login())
        exit(1);
    Main_menuu();
}
