#include <bits/stdc++.h>
using namespace std;


vector<pair<string, string>> constraints;

bool works(vector<pair<string, string>> constraints, string order) {
    for (const auto& c : constraints) {
        string str1 = c.first + c.second, str2 = c.second + c.first;
        if (order.find(str1) == string::npos && order.find(str2) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");

    int n;
    fin >> n;


    for (int i = 0; i < n; i++) {
        string cow1, cow2, must, be, milked, beside;
        fin >> cow1 >> must >> be >> milked >> beside >> cow2;
        constraints.emplace_back(cow1, cow2);
    }

    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    do {
        string temp_order;
        for (const string& c : cows) {
            temp_order += c;
        }

        if (works(constraints, temp_order)) {
            for (const string& c : cows) {
                fout << c << '\n';
            }
            return 0;
        }
    } while (next_permutation(cows.begin(), cows.end()));


}