#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n; fin >> n;

    vector<pair<int, int>> lifeguards;
    for (int i = 0; i < n; i++) {
        pair<int, int> temp; fin >> temp.first >> temp.second;
        lifeguards.push_back(temp);
    }
    
    int covered[1000];
    fill(covered, covered + 1000, 0);
    
    //remove each lifeguard one by one
    int answer = 0;
    for (pair<int, int> lifeguard : lifeguards) {
        for (int i = lifeguard.first - 1; i < lifeguard.second - 1; i++) {
            covered[i]++;
        }
    }

    int copyCovered[1000]; 
    copy(covered, covered + 1000, copyCovered);

    for (pair<int, int> lifeguard : lifeguards) {
        for (int i = lifeguard.first - 1; i < lifeguard.second - 1; i++) {
            covered[i]--;
        }

        answer = max(1000 - (int) count(covered, covered + 1000, 0), answer);
        copy(copyCovered, copyCovered + 1000, covered);
    }
    fout << answer;
}