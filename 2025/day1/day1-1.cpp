#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("day1.txt");
    int p=50;
    int ans=0;
    string instruction;
    while(file>>instruction){
        char d= instruction[0];
        int steps=stoi(instruction.substr(1));
        steps%=100;
        if(d=='L'){
            p-=steps;
            if(p<0){
                p+=100;
            }
        }
        else{
            p+=steps;
            if(p>=100){
                p-=100;
            }
        }
        if(!p) ans++;
    }
    cout<<ans<<endl;
}