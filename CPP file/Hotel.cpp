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
int PCount[12][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
                      {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
int SCount[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sCount[5]={0,0,0,0,0};
int RCount[6]={0,0,0,0,0,0};
int DCount[10]={0,0,0,0,0,0,0,0,0,0};
int SnCount[8]={0,0,0,0,0,0,0,0};
int BCount[2]={0,0};
int DeCount[10]={0,0,0,0,0,0,0,0,0,0};
string Pizza[] = {"MARGHERITA","DOUBLE CHEESE MARGHERITA","FARM HOUSE","PEPPY PANEER","MEXICAN GREEN WAVE",
                  "DELUXE VEGGIE","5 PEPPER","VEG EXTRAVEGANZA","CHEESE N CORN","PANEER MAKHANI",
                  "VEGGIE PARADISE","FRESH VEGGIE","BACK"};
int Pizza_Price[12][3] = {{79,99,119},{119,149,179},{329,379,399},{335,379,410},{320,360,400},{409,509,609},{333,355,388},
                          {459,559,809},{120,150,179},{205,255,309},{329,378,446},{299,345,395}};
string Subgi[21] = {"CHANA MASALA","CHEESE BUTTER MASALA","DUM ALOO","KAJU BUTTER MASALA",
                    "KAJU KARI","KAJU MASALA","KHOYA KAJU","MALAI KOFTA","MIX VEGETABLE",
                    "NAVRATAN KORMA","PALAK PANEER","PANEER ANGARA","PANEER BHURJI","PANEER BUTTER MASALA",
                    "PANEER HANDI","PANEER MAKHANI","PANEER MUTTER","PANEER TADKA","PANEER TIKKA MASALA",
                    "PANEER TOOFANI","BACK"};
int Subgi_Price[20] = {100,140,110,170,180,160,210,177,95,145,180,160,130,180,140,120,130,110,160,155};
string Starter[7]={"CARROT SOUP","LECTTUCE SOUP","TOMATO SOUP","MANCHURIAN DRY","MANCHURIAN GRAVY","FRENCH FRIES","BACK"};
int Starter_Price[6]={40,55,45,60,70,40};
string Roti[7]={"SIMPLE ROTI","BUTTER CHAPATI","TANDURI NAAN","OIL NAAN","BUTTER NAAN","CHEESE NAAN","BACK"};
int Roti_Price[6]={20,25,30,35,40,45};
string Drink[11]={"COCA COLA","FANTA","SPRITE","PEPSI","THUMS UP","COFFEE","MILK","TEA","BUTTERMILK","MINERAL WATER","BACK"};
int Drink_Price[10]={30,20,20,30,25,20,15,25,15,20};
string Snakes[9]={"ALOO PARATHA","FRENCH TOAST","GRILL SANDWICH","IDLI","MASALA DOSA","PAV BHAJI","POORI BHAJI","VEG SANDWICH","BACK"};
int Snakes_Price[8]={40,15,55,80,75,65,70,40};
string Burger[3]={"LAMB BURGER","VEG BURGER","BACK"};
int Burger_Price[2]={75,85};
string Decert[11]={"BASUNDI","GULAB JAMUN","JALEBI","RABDI","CHOCOBAR","MANGO DOLLY","CHOCOLATE ICE-CREAM","MANGO ICE-CREAM","ROSE ICE-CREAM","VANNILA ICE-CREAM","BACK"};
int Decert_Price[10]={85,80,60,80,30,30,55,55,50,50};
void setpath(int i,string c,string s){
    path[0]='\0';
    strcat(path,c.c_str());
    strcat(path,s.c_str());
    strcat(path,".jpg");
}
void instruction_for_menu(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"Press arrow key to select option\n"
        <<"press enter key for add item in to cart\n"
        <<"Press space key for remove item from cart\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout<<"Total selected item is "<<item<<endl;
    cout<<"Total cart value is "<<value<<endl;
}
void printmenu(int n,string p,int l,string S[],int mp[]){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<"Name\n\n";
    for (int i = 0; i < n; ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                setpath(i,p,S[i]);
                readimagefile(path,0,0,500,412);
                if(i==(n-1))
                    cout<<S[i]<<endl;
                else
                    cout <<S[i] <<setw(l-S[i].length())<<mp[i]<<endl;
			}
			else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                if(i==(n-1))
                    cout<<S[i]<<endl;
                else
                    cout <<S[i] <<setw(l-S[i].length())<<mp[i]<<endl;
			}
		}
}
int key_for_menu(int i,int Price[],int Count[]){
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
        item++;
        value+=Price[pointer];
        Count[pointer]++;
        return 1;
    }
    else if (GetAsyncKeyState(VK_SPACE) && (pointer!=i)){
        if(Count[pointer]){
            item--;
            Count[pointer]--;
            value-=Price[pointer];
        }
        return 1;
    }
    else if((GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE))&& (pointer==i)){
        t=0;
        return 1;
    }
}
void STARTER(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(7,"Starter_Photo/",21,Starter,Starter_Price);
		while(1){
            if(key_for_menu(6,Starter_Price,sCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void SUBGI(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(21,"Subgi_Photo/",25,Subgi,Subgi_Price);
		while(1){
			if(key_for_menu(20,Subgi_Price,SCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void ROTI(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(7,"Roti_Photo/",19,Roti,Roti_Price);
		while(1){
			if(key_for_menu(6,Roti_Price,RCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void SNAKES(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(9,"Snakes_Photo/",19,Snakes,Snakes_Price);
		while(1){
			if(key_for_menu(8,Snakes_Price,SnCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void DRINK(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(11,"Drink_Photo/",18,Drink,Drink_Price);
		while(1){
			if(key_for_menu(10,Drink_Price,DCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void BURGER(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(3,"Burger_Photo/",16,Burger,Burger_Price);
		while(1){
			if(key_for_menu(2,Burger_Price,BCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
void PIZZA(){
    t=1,pointer=0,second=0;
    while(t){
		instruction_for_menu();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout<<"Name\t\t\t Small  Medium Large\n";
        cout<<"    \t\t\t size   size   size\n";
		for (int i = 0; i < 13; ++i){
			if (i == pointer){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				setpath(i,"Pizza_Photo/",Pizza[i]);
                readimagefile(path,0,0,500,412);
				if(i==12){
                    cout<<Pizza[i];
				}
                else{
                    cout << Pizza[i]<<setw(25-Pizza[i].length())<<" ";
                    for (int j = 0; j < 3 && i!=12 ; ++j){
                        if (j==second){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                            cout<<setw(3)<<Pizza_Price[i][j]<<"    ";
                        }
                        else{
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            cout<<setw(3)<<Pizza_Price[i][j]<<"    ";
                        }
                    }
                    cout<<endl;
                }
			}
			else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                if(i==12)
                    cout<<Pizza[i];
                else{
                    cout <<Pizza[i] <<setw(28-Pizza[i].length())<<Pizza_Price[i][0]
                     <<setw(7)<<Pizza_Price[i][1]<<setw(7)
                     <<Pizza_Price[i][2]<< endl;
                }
			}
		}
		while(1){
			if (GetAsyncKeyState(VK_UP)){
				pointer -= 1;
				if (pointer == -1)
					pointer = 12;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)){
				pointer += 1;
				if (pointer == 13)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_LEFT)){
                    second-=1;
                    if(second == -1)
                        second = 2;
                    break;
			}
			else if (GetAsyncKeyState(VK_RIGHT)){
                    second+=1;
                    if(second == 3)
                        second = 0;
                    break;
			}
			else if (GetAsyncKeyState(VK_RETURN) && (pointer!=12)){
				item++;
				value+=Pizza_Price[pointer][second];
				PCount[pointer][second]++;
				break;
			}
			else if (GetAsyncKeyState(VK_SPACE) && (pointer!=12)){
                if(PCount[pointer][second]){
                    item--;
                    PCount[pointer][second]--;
                    value-=Pizza_Price[pointer][second];
                }
				break;
			}
			else if((GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE))&& (pointer==12)){
                t=0;
                break;
			}
		}
		Sleep(150);
	}
	closegraph();
}
void DECERT(){
    t=1,pointer=0;
    while(t){
		instruction_for_menu();
        printmenu(11,"Decert_Photo/",24,Decert,Decert_Price);
		while(1){
			if(key_for_menu(10,Decert_Price,DeCount))
                break;
		}
		Sleep(150);
	}
	closegraph();
}
int main(){
    string Type[] = {"STARTER","SABGI","ROTI","SNAKES","DRINK","PIZZA","BURGER","DECERT","SUBMIT ORDER","EXIT"};
    int pointer=0;
    ofstream fptr;
    fptr.open("Data.txt");
    fptr.close();
    while(1){
		instruction_for_menu();
		for (int i = 0; i < 10; ++i){
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
					pointer = 9;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN)){
				pointer += 1;
				if (pointer == 10)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN)){
                if(pointer<8)
                    initwindow(500,412,"Sample photo",1000,0);
				switch (pointer){
					case 0:{
					    Sleep(100);
                        STARTER();
					}break;
					case 1:{
					    Sleep(100);
						SUBGI();
					} break;
					case 2:{
					    Sleep(100);
						ROTI();
					}break;
                    case 3:{
					    Sleep(100);
						SNAKES();
					}break;
					case 4:{
					    Sleep(100);
						DRINK();
					}break;
					case 5:{
					    Sleep(100);
						PIZZA();
					} break;
					case 6:{
					    Sleep(100);
						BURGER();
					} break;
					case 7:{
					    Sleep(100);
						DECERT();
					} break;
					case 8:{
					    ofstream fout;
					    fout.open("Data.txt",ios::app);
					    int i,j;
					    for(i=0;i<7;i++)
                            if(sCount[i]){
                                fout<<Starter[i]<<setw(30-Starter[i].length())<<" "<<sCount[i]<<"\t"<<Starter_Price[i]<<endl;
                                sCount[i]=0;
                            }
                        for(i=0;i<20;i++)
                            if(SCount[i]){
                                fout<<Subgi[i]<<setw(30-Subgi[i].length())<<" "<<SCount[i]<<"\t"<<Subgi_Price[i]<<endl;
                                SCount[i]=0;
                            }
                        for(i=0;i<7;i++)
                            if(RCount[i]){
                                fout<<Roti[i]<<setw(30-Roti[i].length())<<" "<<RCount[i]<<"\t"<<Roti_Price[i]<<endl;
                                RCount[i]=0;
                            }
                        for(i=0;i<10;i++)
                            if(DCount[i]){
                                fout<<Drink[i]<<setw(30-Drink[i].length())<<" "<<DCount[i]<<"\t"<<Drink_Price[i]<<endl;
                                DCount[i]=0;
                            }
                        for(i=0;i<8;i++)
                            if(SnCount[i]){
                                fout<<Snakes[i]<<setw(30-Snakes[i].length())<<" "<<SnCount[i]<<"\t"<<Snakes_Price[i]<<endl;
                                SnCount[i]=0;
                            }
                        for(i=0;i<2;i++)
                            if(BCount[i]){
                                fout<<Burger[i]<<setw(30-Burger[i].length())<<" "<<BCount[i]<<"\t"<<Burger_Price[i]<<endl;
                                BCount[i]=0;
                            }
                        for(i=0;i<10;i++)
                            if(DeCount[i]){
                                fout<<Decert[i]<<setw(30-Decert[i].length())<<" "<<DeCount[i]<<"\t"<<Decert_Price[i]<<endl;
                                DeCount[i]=0;
                            }
					    for(i=0;i<12;i++)
                            for(j=0;j<3;j++)
                                if(PCount[i][j]){
                                    fout<<Pizza[i]<<setw(30-Pizza[i].length())<<" "<<PCount[i][j]<<"\t"<<Pizza_Price[i][j]<<endl;
                                    PCount[i][j]=0;
                                }
                        fout.close();
                        }break;
                        case 9:{
                            ifstream fout;
                            fptr.open("AllData.txt",ios::app);
                            fout.open("Data.txt");
                            fptr<<"******************************************\n";
                            system("cls");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            cout<<"Please pay this bill on cash counter\n";
                            cout<<"******************************************\n";
                            char ch;
                            ch=fout.get();
                            while(!fout.eof()){
                                cout<<ch;
                                fptr<<ch;
                                ch=fout.get();
                            }
                            fout.close();
                            fptr.close();
                        }break;
				}
				break;
			}
		}
		Sleep(150);
	}
    return 0;
}
