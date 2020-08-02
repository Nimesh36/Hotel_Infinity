#include<iostream>
#include<string>
#include<iomanip>
#include<string.h>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
string user_name,pass,pass1,Phone_Number,temp_string;
char ch;
void instruction(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Press arrow and enter key to select option\n";
}
int chack(string c){
    for(int i=0;c[i]!='\0';i++)
        if(!isalnum(c[i]))
            return 1;
    return 0;
}
void GetLP(int i=0){
    int t=1;
    while(t){
        do{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"Please enter a name\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"Enter user name : ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cin>>user_name;
        }while(chack(user_name));
        do{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"Please enter a password\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"Enter password : ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            pass="\0";
            ch=_getch();
            while(ch!=13){
                pass.push_back(ch);
                cout<<'*';
                ch=_getch();
            }
        }while(chack(pass));
        do{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"Please enter a conform password\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"Enter conform password : ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            pass1="\0";
            ch=_getch();
            while(ch!=13){
                pass1.push_back(ch);
                cout<<'*';
                ch=_getch();
            }
        }while(chack(pass1));
        if(pass==pass1){
            t=0;
            if(i){
                do{
                    system("cls");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"Please enter a 10-digit phone number\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                    cout<<"Enter phone number : ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    Phone_Number="\0";
                    ch=_getch();
                    while(ch!=13){
                        Phone_Number.push_back(ch);
                        cout<<'*';
                        ch=_getch();
                    }
                }while(Phone_Number.length()!=10);
                cout<<"\nCongratulation you are create account completely";
                Sleep(2000);
            }
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\nYou enter different password enter data again";
            Sleep(2000);
        }
    }
}
int Log_On(){
    char c[1];
    cin.getline(c,1);
    GetLP(1);
    ofstream fout;
    fout.open("password.txt",ios::app);
    fout<<user_name<<pass<<Phone_Number<<0<<endl;
    fout.close();
    return 1;
}
int Log_In(){
    char c[1];
    cin.getline(c,1);
    int Try=3;
    ifstream fin;
    int i;
    while(Try>0){
        Try--;
        GetLP();
        fin.open("password.txt");
        temp_string.clear();
        temp_string=user_name+pass;
        do{
            fin>>pass1;
            for(i=0;i<temp_string.length();i++){
                if(temp_string[i]!=pass1[i])
                    break;
            }
            if(i==temp_string.length()){
                system("cls");
                cout<<"You are login completely";
                Sleep(2000);
                return 1;
            }
        }while(!fin.eof());
        fin.close();
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"Password is wrong. Please enter correct password or forgot password\n";
        Sleep(2000);
    }
    if(!Try){
        cout<<"\nSorry... You enter maximum try to login";
    }
    return 0;
}
int user_login(){
    string Account[] = {"Log_In","Log_On","EXIT"};
    int pointer=0,t=1;
    while(t){
		instruction();
		for (int i = 0; i < 3; ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout <<Account[i] << endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout <<Account[i] << endl;
			}
		}
		while(1){
			if (GetAsyncKeyState(VK_UP)){
				pointer -= 1;
				if (pointer == -1)
					pointer = 2;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)){
				pointer += 1;
				if (pointer == 3)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN)){
				switch (pointer){
					case 0:{
					    Sleep(100);
                        if(Log_In())
                            return 1;
                        return 0;
					}break;
					case 1:{
					    Sleep(100);
						if(Log_On())
                            return 1;
                        return 0;
					} break;
					case 2:{
                        return 0;
					}
				}
				break;
			}
		}
		Sleep(150);
	}
    return 0;
}
int main(){
    if(!user_login())
        exit(1);
}
