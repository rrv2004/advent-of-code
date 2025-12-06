#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("day3.txt");
    string s;
    long long total = 0;

    while (file >> s) {
        int n = s.size();
        vector<char> maxRight(n + 1, '0');
        for (int i = n - 1; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], s[i]);
        }

        int best = 0;
        for (int i = 0; i < n - 1; i++) {
            int d1 = s[i] - '0';
            int d2 = maxRight[i + 1] - '0';
            best = max(best, d1 * 10 + d2);
        }

        total += best;
    }

    cout << total << endl;
}
