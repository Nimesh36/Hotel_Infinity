#include<iostream>
#include<windows.h>
#include "user_login.h"
#include "DIALOGUE.h"
using namespace std;
string SONG_NAME_A[23]={"Random","Aa To Sahi","Apni Yaadon Ko","Baarish","Badri Ki Dulhaniya","Besabriyaan","Bin Tere Sanam","Bol Do Na Zara",
                      "Bolo Har Har","Bulleya","Chalti Hain Kya 9 se 12","Channa Meraya","Chinta Ta Chinta Ta","Desi Desi Na Bolya Kar",
                      "Dil Diyan Gallan","Dil To Pagal Hain","Ding Dang","Disco Deewane","Do Lafzo Ki Hain Dil Ki Kahani",
                      "Duniya Main Aaye Ho To","Ek Doosre Se Karte Hain Pyaar Hum","More...","Back"};
string SONG_NAME_B[23]={"Random","Ghoomar","Golmaal Again","Har kisi ko nahi milta","Hum Saath Saath Hain","Hum Yaar Hain Tumhare","Jag Ghommeya",
                      "Jay-Jaykara","Jio Re Bahubali","Koi Ladki Hain","Mahi Aaja Mahi Aa","Main Tera Boyfriend","Maine Tujhko Dekhan",
                      "Malhari","Mere Angne Main","Mere Rashke Qamar","Meri Maa","Mile Ho Tum","O Khuda","Oochi Hain Building","Parwah Nahi","More...","Back"};
string SONG_NAME_C[22]={"Random","Raat Baki Baat Baki","Radio","Saat Ajoobe Is Duniya Mein","Saat samundar Paar","Sau Tarah Ke","Soch Na Sake","Sochna Kya Jo Bhi Honga","Sultan",
                      "Swag Se Swagat","Taang Uthake","Tere Sang Yaara","Tip Tip Barsa Pani","Tu Cheez Badi Hain","Tu Dua Hain Dua","Tu Jo Kahe",
                      "Tum Dil Ki Dhadkan Main","Tum Mile Dil Khile","Yaar Mod Do","Yaara Teri Yari Ko","Yeh Dosti(Happy)","Back"};

class SONGS : public Functions
{
public:
    void Play_Random_Song(){
    }
    int key_For_Song(int i,string teg[],int &f,int j=1){
        if (GetAsyncKeyState(VK_UP)){
            pointer -= 1;
            if (pointer == -1)
                pointer = i;
            return 1;
        }
        else if (GetAsyncKeyState(VK_DOWN)){
            pointer += 1;
            if (pointer == i+1)
                pointer = 0;
            return 1;
        }
        else if (GetAsyncKeyState(VK_RETURN) && pointer>0 && pointer<i-1){
            play(teg[pointer],"Songs/");
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==i){
            t=0;
            f=0;
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==i-1 && j){
            t=0;
            return 1;
        }
        else if (GetAsyncKeyState(VK_RETURN) && pointer>0 && !j){
            play(teg[pointer],"Songs/");
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==0){
            Play_Random_Song();
        }
        return 0;
    }
    void album(){
    t=1,pointer=0;
    int f=1;
    if(f)
        while(t){
            instruction();
            printname(23,SONG_NAME_A,SONG_NAME_A);
            while(1){
                if(key_For_Song(22,SONG_NAME_A,f))
                    break;
            }
            Sleep(150);
        }
    t=1,pointer=0;
    if(f)
        while(t){
            instruction();
            printname(23,SONG_NAME_B,SONG_NAME_B);
            while(1){
                if(key_For_Song(22,SONG_NAME_B,f))
                    break;
            }
            Sleep(150);
        }
    t=1,pointer=0;
    if(f)
        while(t){
            instruction();
            printname(22,SONG_NAME_C,SONG_NAME_C);
            while(1){
                if(key_For_Song(21,SONG_NAME_C,f,0))
                    break;
            }
            Sleep(150);
        }
    }
};
void SONG(){
    SONGS s_obj;
    s_obj.album();
}
int main()
{
    SONG();
    return 0;
}
