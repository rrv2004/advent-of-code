#include <bits/stdc++.h>
using namespace std;

bool repeatedTwice(const string &s) {
    int n = s.size();
    if (n % 2 != 0) return false;  

    int half = n / 2;
    return s.substr(0, half) == s.substr(half);
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
            if(repeatedTwice(temp)){
                ans+=i;
            }
        }
   }
   cout<<ans;
}
