#include<iostream>
#include<string>
#include<iomanip>
#include<string.h>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdio.h>
#include<limits>
#define MAX 58
using namespace std;
string user_name,pass,pass1,Phone_Number,temp_string;
int pos;
int Count_Enter=0;
char ch;
void instruction(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Press Control Key For Go Down.\nPress Right Shift Key For Go Up.\n";
}
int chack(string c){
    for(int i=0;i<c.length();i++)
        if(!isalnum(c[i])){
            cout<<"\nPlease enter only alphanumeric value";
            Sleep(2000);
            return 1;
        }
    return 0;
}
int ChackUsername(string UserName,int i){
    ifstream fin("h_file/Username.docx",ios::app);
    fin.seekg(0,ios::beg);
    if(i)
        while(fin){
            fin>>temp_string;
            if(temp_string==UserName){
                fin.close();
                cout<<"User name is already exist please enter another user name.";
                Sleep(2000);
                return 1;
            }
        }
    fin.close();
    return 0;
}
int Chack_PNO(string c){
    for(int i=0;i<c.length();i++)
        if(!(c[i]>='0' && c[i]<='9')){
            cout<<"\nPlease enter digit only";
            Sleep(2000);
            return 1;
        }
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
        }while(chack(user_name) || ChackUsername(user_name,i));
        do{
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"Please enter a password\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            cout<<"Enter password : ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            pass="\0";
            while ((ch=_getch())!='\r'){
                if (ch=='\b'){
                    if (pass.size()>0) {
                        pass.erase(pass.size()-1,1);
                        cout<<"\b \b";
                        }
                    }
                else {
                    pass.push_back(ch);
                    cout.put('*');
                }
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
            while ((ch=_getch())!='\r') {
                if (ch=='\b') {
                    if(pass1.size()>0){
                        pass1.erase(pass1.size()-1,1);
                        cout<<"\b \b";
                        }
                    }
                else{
                    pass1.push_back(ch);
                    cout.put('*');
                }
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
                }while(Chack_PNO(Phone_Number) || Phone_Number.length()!=10);
                cout<<"\nCongratulation You are Create new account successfully.";
                Sleep(2000);
            }
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            cout<<"\nYou enter different password So Enter data again";
            Sleep(2000);
        }
    }
}
int LocatePos(){
    ifstream fin;
    pos=0;
    fin.open("h_file/Password.docx");
    temp_string.clear();
    temp_string=user_name+pass;
    do{
        fin>>pass1;
        if(pass1==temp_string){
            return 1;
        }
        pos++;
    }while(!fin.eof());
    fin.close();
    return 0;
}
int Log_On(){
    char c[1];
    cin.getline(c,1);
    GetLP(1);
    ofstream fout;
    fout.open("h_file/Password.docx",ios::app);
    fout.seekp(0,ios::beg);
    fout<<user_name<<pass<<endl;
    fout.close();
    fout.open("h_file/Username.docx",ios::app);
    fout<<user_name<<endl;
    fout.close();
    fout.open("h_file/PhoneNumber.docx",ios::app);
    fout.seekp(0,ios::beg);
    fout<<user_name<<Phone_Number<<endl;
    fout.close();
    fout.open("h_file/Discount.docx",ios::app);
    fout.seekp(0,ios::beg);
    fout<<pos;
    fout.close();
    LocatePos();
    return 1;
}
int Log_In(){
    char c[1];
    cin.getline(c,1);
    int Try=3;
    int i;
    while(Try>0){
        Try--;
        GetLP();
        if(LocatePos()){
            system("cls");
            cout<<"You are login successfully.";
            Sleep(2000);
            return 1;
        }
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout<<"Password is wrong. Please enter correct password\n";
        Sleep(2000);
    }
    if(!Try){
        cout<<"\nSorry...\nYou Reached Maximum Limit..";
    }
    return 0;
}
int user_login(){
    string Account[] = {"Log_In","Create_An_Account","EXIT"};
    int pointer=0,t=1;
    while(t){
		instruction();
		for (int i = 0; i < 3; ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout<<Account[i]<<endl;
			}
			else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<Account[i]<<endl;
			}
		}
		while(1){
			if (GetAsyncKeyState(VK_RSHIFT)){
				pointer-=1;
				if(pointer==-1)
					pointer=2;
				break;
			}
			else if(GetAsyncKeyState(VK_CONTROL)){
				pointer+=1;
				if(pointer==3)
					pointer=0;
				break;
			}
			else if(GetAsyncKeyState(VK_RETURN)){
                Count_Enter++;
				switch(pointer){
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
					}break;
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
