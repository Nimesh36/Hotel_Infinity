#include<limits>
string LIST[8]={"Brazil","China","Colloseum","Egypt","Eiffel","Rom","Switzerland","Taj Mahal"};
class play;
void check(play[],int);
class play{
private:
    int tsteps;
    int steps;
public:
    play():steps(0),tsteps(0){}
    int value_of_dice();
    int rolling(int);
    int step(){
        return tsteps;
    }
    void showimage(string c,string s)
    {
        path[0]='\0';
        strcat(path,c.c_str());
        strcat(path,s.c_str());
        strcat(path,".jpg");
        initwindow(500,500,"WORLD TOUR",500,0);
        readimagefile(path,0,0,500,500);
    }
    void friend check(play[],int);
};
int play:: value_of_dice(){
    int answer;
    do{
        answer = rand() % 7;
    } while (!answer > 0);
    return answer;
}
int play:: rolling(int i){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout << "\nDice is Rolling...";
    Sleep(1500);
    steps = value_of_dice();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9+i);
    cout<<"\nNumber of steps for player "<<i<<" is... "<<steps;
    if(tsteps==0 && steps!=6)
        steps=0;
    if(tsteps==0 && steps==6)
        steps=1;
    if (tsteps+steps <= MAX) {
        tsteps+=steps;
        if(tsteps==8)
            showimage("WORLD/",LIST[0]);
        if(tsteps==14)
            showimage("WORLD/",LIST[1]);
        else if(tsteps==21)
            showimage("WORLD/",LIST[2]);
        else if(tsteps==29)
            showimage("WORLD/",LIST[3]);
        else if(tsteps==36)
            showimage("WORLD/",LIST[4]);
        else if(tsteps==43)
            showimage("WORLD/",LIST[5]);
        else if(tsteps==50)
            showimage("WORLD/",LIST[6]);
        else if(tsteps==58)
            showimage("WORLD/",LIST[7]);
    }
    cout << "\nTotal Steps of player "<<i<<" is "<< setw(8) << ":" << tsteps;
    if(tsteps==MAX){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"\n\nHurry!!!!\nPlayer "<<i<<" wins.....\n\nPress any key to back";
        _getch();
        closegraph();
        return 1;
    }
    return 0;
}
void check(play p[],int n){
    for(int i=0;i<4;i++){
        if(n!=i && p[n].tsteps==p[i].tsteps && p[i].tsteps){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            if(rand()%2){
                p[n].tsteps=0;
                cout<<"\n\nPlayer "<<n+1<<" Have To Start His/Her Journey Again..\n";
            }
            else{
                p[i].tsteps=0;
                cout<<"\n\nPlayer "<<i+1<<" Have To Start His/Her Journey Again..\n";
            }
        }
    }
}
int GAME(){
    int user;
    system("cls");
    cout <<"\nRules For Games :\n(1) One Cycle = 58 Squares\n(2) Who Complete This Cycle First Will Be Winner!!!\n"
         <<"(3) Dice Have 1 To 6 Values.\n(4) You Can Only Knocked Down Others If Both Are In Same Place and Your Luck Decide Who Will Stay And Who Will Out.\n(5) Press ESCAPE key for quit game.";
    do{
        cout<<"\nEnter How Many User Wants To play (Maximum capacity 4):";
        for(int i=1;i<Count_Enter;i++)
            _getch();
        Count_Enter=0;
        cin>>user;
        if(user==0)
            return 1;
    }while(user<1||user>4);
    play p[4];
    int i=0,j=0;
    cout<<"\nGame is Started ...";
    srand(time(NULL));
    switch(user){
    case 1:
        while(p[0].step()<MAX && p[1].step()<MAX && p[2].step()<MAX && p[3].step()<MAX){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "\n\nTurn " << j + 1 << " : " << endl;
            i=0;
            if(_getch()==VK_ESCAPE)
                return 0;
            closegraph();
            if(p[i].rolling(i+1))
                return 0;
            check(p,i);
            for(i=1;i<4;i++){
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            j++;
        }
        break;
    case 2:
        while(p[0].step()<MAX && p[1].step()<MAX && p[2].step()<MAX && p[3].step()<MAX){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "\n\nTurn " << j + 1 << " : " << endl;
            for(i=0;i<2;i++){
                if(_getch()==VK_ESCAPE)
                    return 0;
                closegraph();
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            for(;i<4;i++){
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            j++;
        }
        break;
    case 3:
        while(p[0].step()<MAX && p[1].step()<MAX && p[2].step()<MAX && p[3].step()<MAX){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "\n\nTurn " << j + 1 << " : " << endl;
            for(i=0;i<3;i++){
                if(_getch()==VK_ESCAPE)
                    return 0;
                closegraph();
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            for(;i<4;i++){
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            j++;
        }
        break;
    case 4:
        while(p[0].step()<MAX && p[1].step()<MAX && p[2].step()<MAX && p[3].step()<MAX){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "\n\nTurn " << j + 1 << " : " << endl;
            for(i=0;i<4;i++){
                if(_getch()==VK_ESCAPE)
                    return 0;
                closegraph();
                if(p[i].rolling(i+1))
                    return 0;
                check(p,i);
            }
            j++;
        }
    }
}
