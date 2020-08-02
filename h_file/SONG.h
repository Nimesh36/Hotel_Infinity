string SONG_NAME_A[24]={"Random","Aa To Sahi","Aaj Unse Milna Hai","Aap Mujhe Achay Lagne Lage","Akele Hain To Kya Gum","Apni Yaadon Ko",
                        "Baarish","Badri Ki Dulhaniya","Besabriyaan","Bin Tere Sanam","Bol Do Na Zara","Bolo Har Har","Bulleya",
                        "Chalti Hain Kya 9 se 12","Channa Meraya","Chinta Ta Chinta Ta","Desi Desi Na Bolya Kar","Dil Deewana Bin Sajna",
                        "Dil Diyan Gallan","Dil Kehta Hai","Dil Ne Ye Kaha Hai","More...","Back"};
string SONG_NAME_B[24]={"Random","Dil To Pagal Hain","Ding Dang","Disco Deewane","Do Lafzo Ki Hain Dil Ki Kahani","Duniya Main Aaye Ho To",
                        "Ek Doosre Se Karte Hain Pyaar Hum","Ghoomar","Golmaal Again","Har kisi ko nahi milta","Hum Saath Saath Hain",
                        "Hum Yaar Hain Tumhare","Jag Ghommeya","Jay-Jaykara","Jio Re Bahubali","Kabhi Jo Baadal Barse","Kabhi Kabhi Mere Dil Mein",
                        "Kaho Naa Pyaar Hai","Khaike Paan Banaras Wala","Koi Ladki Hain","Mahi Aaja Mahi Aa","More...","Back"};
string SONG_NAME_C[24]={"Random","Main Ek Raja Hoon","Main Shayar To Nahin","Main Tera Boyfriend","Maine Tujhko Dekhan","Malhari",
                        "Mehndi Laga Ke Rakhna","Mere Angne Main","Mere Khwabon Mein","Mere Rang Main","Mere Rashke Qamar","Meri Maa",
                        "Mile Ho Tum","Mujhse Juda Ho Kar","O Khuda","Oochi Hain Building","Pal Pal Dil Ke Paas","Parwah Nahi","Raat Baki Baat Baki",
                        "Radio","Raja Ko Rani Se","More...","Back"};
string SONG_NAME_D[23]={"Random","Saat Ajoobe Is Duniya Mein","Saat samundar Paar","Sau Tarah Ke","Soch Na Sake","Sochna Kya Jo Bhi Honga",
                        "Sultan","Suno Na Sangemarmar","Swag Se Swagat","Taang Uthake","Tere Mast Mast Do Nain","Tere Sang Yaara",
                        "Tip Tip Barsa Pani","Tu Cheez Badi Hain","Tu Dua Hain Dua","Tu Jo Kahe","Tum Dil Ki Dhadkan Main",
                        "Tum Mile Dil Khile","Yaar Mod Do","Yaara Teri Yari Ko","Yeh Dosti(Happy)","BACK"};
class SONGS : public Functions
{
public:
    void Play_Random_Song(string teg[]){
        srand(time(NULL));
        int random_number=rand()%20+1;
        play(teg[random_number],"Songs/");
    }
    int key_For_Song(int i,string teg[],int &f,int j=1){
        if (GetAsyncKeyState(VK_RSHIFT)){
            pointer -= 1;
            if (pointer == -1)
                pointer = i;
            return 1;
        }
        else if (GetAsyncKeyState(VK_CONTROL)){
            pointer += 1;
            if (pointer == i+1)
                pointer = 0;
            return 1;
        }
        else if (GetAsyncKeyState(VK_RETURN) && pointer>0 && pointer<i-1){
            Count_Enter++;
            play(teg[pointer],"Songs/");
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==i){
            Count_Enter++;
            t=0;
            f=0;
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==i-1 && j){
            Count_Enter++;
            t=0;
            return 1;
        }
        else if (GetAsyncKeyState(VK_RETURN) && pointer>0 && !j){
            Count_Enter++;
            play(teg[pointer],"Songs/");
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && pointer==0){
            Count_Enter++;
            Play_Random_Song(teg);
            return 1;
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
            printname(23,SONG_NAME_C,SONG_NAME_C);
            while(1){
                if(key_For_Song(22,SONG_NAME_C,f))
                    break;
            }
            Sleep(150);
        }
    t=1,pointer=0;
    if(f)
        while(t){
            instruction();
            printname(22,SONG_NAME_D,SONG_NAME_D);
            while(1){
                if(key_For_Song(21,SONG_NAME_D,f,0))
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
