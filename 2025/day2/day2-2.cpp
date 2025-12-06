#include <bits/stdc++.h>
using namespace std;

bool repeated(const string &s) {
   string t=s+s;
   return t.substr(1,t.size()-2).find(s)!=string::npos;
}
int main(){
   ifstream file("day2.txt");
   string line;
   getline(file,line);
   stringstream ss(line);
   string part;
   long long ans=0;
   while(getline(ss,part,',')){
     int dashPos = part.find('-');
        long long a =stoll(part.substr(0, dashPos));
        long long b =stoll(part.substr(dashPos + 1));
        for(long long i=a;i<=b;i++){
            string temp=to_string(i);
            if(repeated(temp)){
                ans+=i;
            }
        }
   }
   cout<<ans;
}
