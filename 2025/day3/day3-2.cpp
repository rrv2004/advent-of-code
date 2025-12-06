#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("day3.txt");
    string line;
    long long total = 0;
    while (file >> line) {
        int n = line.size();
        vector<char> stack;

        for (int i = 0; i < n; i++) {
            char c = line[i];
            while (!stack.empty() && c > stack.back() && (stack.size() + n - i - 1) >= 12) {
                stack.pop_back();
            }
            if (stack.size() < 12) {
                stack.push_back(c);
            }
        }
        string res(stack.begin(), stack.end());
        total += stoll(res);
    }

    cout << total << endl;
}
