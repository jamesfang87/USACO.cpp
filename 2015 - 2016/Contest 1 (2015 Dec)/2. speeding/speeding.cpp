#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int road_segs, bessie_segs;
    fin >> road_segs >> bessie_segs;

    vector<int> road;
    vector<int> bessie;
    
    for (int i = 0; i < road_segs; i++) {
        int len, speed;
        fin >> len >> speed;
        for (int j = 0; j < len; j++) {
            road.push_back(speed);
        }
    }

    for (int a = 0; a < bessie_segs; a++) {
        int len1, speed1;
        fin >> len1 >> speed1;
        for (int b = 0; b < len1; b++) {
            bessie.push_back(speed1);
        }
    }
    
    int answer = 0;
    
    for (int d = 0; d < 100; d++) {
        if (bessie[d] > road[d]) {
            int diff = bessie[d] - road[d];
            if (diff > answer) {
                answer = diff;
            }
        }
    }
    
    fout << answer;
}
