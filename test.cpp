#include<iostream>
#include<graphics.h>
#include<time.h>
#include<fstream>

using namespace std;
int Chack_PNO(string c){
    for(int i=0;i<c.length();i++)
        if(c[i]>='0' && c[i]<='9'){
            cout<<"\nPlease enter digit only";
            Sleep(2000);
            return 1;
        }
    return 0;
}
int main(){
    string s;
    cin>>s;
    while(Chack_PNO(s))
        cin>>s;
}
