#include<iostream>
#include <string>
#include <windows.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<graphics.h>
#include<fstream>
using namespace std;
char path[50];
int item,value,pointer=0,second=0,t=1;
string SUNNY_DEOL_DNAME[14]={"Life Ka Dosara Naam Hain Problem","Dhai Kilo Ka Haath","Arguing in Court with Amrish Puri",
                "Tarikh Pe Tarikh","Hindustan Zindabad","Ye Mazddor Ka Haath","Saato Ko Saath Marunga",
                "Mere Liye Maa Or Mulkh Ek Hain","Talking Damn Truth About Police System","Arguing with Om Puri",
                "Corrupted Law System","Overview Of Movie","Showing Secularism Of Our Country","Back"};
string SUNNY_DEOL_FNAME[14]={"Border","Damini","Damini","Damini","Gadar","Ghatak","Ghatak","Indian","Indian","Narshimha","Salakhen",
                  "Singh Saab The Great","Zor","Back"};
string AKASHAY_KUMAR_FNAME[6]={"Ab Tumhare Hawale Watan Saathiyon","Baby","JOlly LLB 2","Khakhi","Namastey London","Back"};
string AKASHAY_KUMAR_DNAME[6]={"Ab Tumhare Hawale Watan Saathiyon","Baby","JOlly LLB 2","Khakhi","Namastey London","Back"};
string NANA_PATEKAR_FNAME[3]={"Krantiveer","Tirangaa","Back"};
string NANA_PATEKAR_DNAME[3]={"Krantiveer","Tirangaa","Back"};
class Actor
{
public:
    virtual void DIALOGUE();
};
class Functions
{
public:
    void play(string teg)
    {
        path[0]='\0';
        strcat(path,"Dialogues/");
        strcat(path,teg.c_str());
        strcat(path,".wav");
        PlaySound(TEXT(path),NULL,SND_ASYNC);
    }
        void instruction(){
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout<<"Press arrow key to select option\n";
    }
    int key(int i,string teg[]){
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
        else if (GetAsyncKeyState(VK_RETURN) && (pointer!=i)){
            play(teg[pointer]);
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && (pointer==i)){
            t=0;
            return 1;
        }
        return 0;
    }
    void printname(int n,int l,string s[],string ss[]){
        for (int i = 0; i < n; ++i){
                if (i == pointer){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    if(i<9)
                        cout<<"(0"<<i+1<<") ";
                    else
                        cout<<"("<<i+1<<") ";
                    cout<<s[i]<<setw(l-s[i].length())<<"-"<<ss[i]<<endl;
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    if(i<9)
                        cout<<"(0"<<i+1<<") ";
                    else
                        cout<<"("<<i+1<<") ";
                    cout<<s[i]<<setw(l-s[i].length())<<"-"<<ss[i]<<endl;
                }
            }
    }
};

class Sunny : public Actor, public Functions
{
public:
    void DIALOGUE(){
    t=1,pointer=0;
    while(t){
		instruction();
        printname(14,22,SUNNY_DEOL_FNAME,SUNNY_DEOL_DNAME);
		while(1){
			if(key(13,SUNNY_DEOL_DNAME))
                break;
		}
		Sleep(150);
	}
}
};

class Akshay : public Actor,public Functions
{
public:
    void DIALOGUE(){
    t=1,pointer=0;
    while(t){
		instruction();
        printname(6,35,AKASHAY_KUMAR_FNAME,AKASHAY_KUMAR_DNAME);
		while(1){
            if(key(5,AKASHAY_KUMAR_FNAME))
                break;
		}
		Sleep(150);
	}
}
};

class Nana : public Actor,public Functions
{
public:
    void DIALOGUE(){
    t=1,pointer=0;
    while(t){
		instruction();
        printname(3,13,NANA_PATEKAR_FNAME,NANA_PATEKAR_DNAME);
		while(1){
			if(key(2,NANA_PATEKAR_FNAME))
                break;
		}
		Sleep(150);
	}
}
};

int main(){
    Actor *ptr;
    Sunny s_d;
    Akshay a_d;
    Nana n_d;
    string Type[] = {"SUNNY DEOL","AKASHAY KUMAR","NANA PATEKAR","BACK"};
    int pointer=0;
    while(1){
		s_d.instruction();
		for (int i=0;i<4;++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << Type[i] << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Type[i] << endl;
			}
		}
		while(1){
			if (GetAsyncKeyState(VK_UP)){
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)){
				pointer += 1;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN)){
				switch (pointer){
					case 0:{
					    Sleep(100);
                        ptr=&s_d;
                        ptr->DIALOGUE();

					}break;
					case 1:{
					    Sleep(100);
						ptr=&a_d;
						ptr->DIALOGUE();
					} break;
					case 2:{
					    Sleep(100);
						ptr=&n_d;
						ptr->DIALOGUE();
					}break;
                    case 3:{
                        return 0;
                    }break;
				}
				break;
			}
		}
		Sleep(150);
	}
    return 0;
}
