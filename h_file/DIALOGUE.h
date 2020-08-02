char path[50];
int pointer=0,second=0,t=1;
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
    void play(string teg,char p[]){
        path[0]='\0';
        strcat(path,p);
        strcat(path,teg.c_str());
        strcat(path,".wav");
        PlaySound(TEXT(path),NULL,SND_ASYNC);
    }
    int key_For_Dialogue(int i,string teg[]){
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
        else if (GetAsyncKeyState(VK_RETURN) && (pointer!=i)){
            Count_Enter++;
            play(teg[pointer],"Dialogues/");
            return 1;
        }
        else if(GetAsyncKeyState(VK_RETURN) && (pointer==i)){
            Count_Enter++;
            t=0;
            return 1;
        }
        return 0;
    }
    void printname(int n,string s[],string ss[],int l=0,int f=0){
        for (int i = 0; i < n; ++i){
                if (i == pointer){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    if(i<9)
                        cout<<"(0"<<i+1<<") ";
                    else
                        cout<<"("<<i+1<<") ";
                    cout<<s[i];
                    if(f)
                        cout<<setw(l-s[i].length())<<" "<<ss[i];
                    cout<<endl;
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    if(i<9)
                        cout<<"(0"<<i+1<<") ";
                    else
                        cout<<"("<<i+1<<") ";
                    cout<<s[i];
                    if(f)
                        cout<<setw(l-s[i].length())<<" "<<ss[i];
                    cout<<endl;
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
        printname(14,SUNNY_DEOL_FNAME,SUNNY_DEOL_DNAME,22,1);
		while(1){
			if(key_For_Dialogue(13,SUNNY_DEOL_DNAME))
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
            printname(6,AKASHAY_KUMAR_FNAME,AKASHAY_KUMAR_FNAME,35);
            while(1){
                if(key_For_Dialogue(5,AKASHAY_KUMAR_FNAME))
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
        printname(3,NANA_PATEKAR_FNAME,NANA_PATEKAR_FNAME,13);
		while(1){
			if(key_For_Dialogue(2,NANA_PATEKAR_FNAME))
                break;
		}
		Sleep(150);
	}
    }
};
int DIALOGUE(){
    Actor *ptr;
    Sunny s_d;
    Akshay a_d;
    Nana n_d;
    string Type[] = {"SUNNY DEOL","AKASHAY KUMAR","NANA PATEKAR","BACK"};
    int pointer=0;
    while(1){
		instruction();
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
			if (GetAsyncKeyState(VK_RSHIFT)){
				pointer -= 1;
				if (pointer == -1)
					pointer = 3;
				break;
			}
			else if (GetAsyncKeyState(VK_CONTROL)){
				pointer += 1;
				if (pointer == 4)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN)){
				Count_Enter++;
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
