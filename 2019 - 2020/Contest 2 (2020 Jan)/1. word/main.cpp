#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");

    int n, k; fin >> n >> k;

    string words[n];
    for (int i = 0; i < n; i++) {
        fin >> words[i];
    }

    int cur_len = 0;
    for (const string& word : words) {
        //cur_len += word.size();
        if (cur_len + word.size() > k) {
            fout << '\n' << word;
            cur_len = word.size();
        }
        else {
            if (cur_len > 0) fout << " ";
            fout << word;
            cur_len += word.size();
        }
    }
}