#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n; fin >> n;
    string s; fin >> s;


    for (int len = 1; len <= n; len++) {
        vector<string> unique = {};
        bool possible = true;
        for (int start = 0; start <= n - len; start++) {
            if (find(unique.begin(), unique.end(), s.substr(start, len)) == unique.end()) {
                unique.push_back(s.substr(start, len));
            }
            else {
                possible = false;
                break;
            }
        }
        if (possible) {
            fout << len;
            return 0;
        }
    }


}