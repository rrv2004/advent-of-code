#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("day1.txt");
    long long ans = 0;
    int p = 50;
    string instruction;

    while (file >> instruction) {
        char d = instruction[0];
        long long steps = stoll(instruction.substr(1));
        long long fh;

        if (d == 'R') {
            fh = (100 - p) % 100;
        } else {
            fh = p % 100;
        }
        if (fh == 0) fh = 100;
        if (steps >= fh) {
            ans += 1 + (steps - fh) / 100;
        }
        int move = steps % 100;
        if (d == 'R') {
            p = (p + move) % 100;
        } else {
            p = (p - move) % 100;
            if (p < 0) p += 100;
        }
    }

    cout << ans << endl;
    return 0;
}
