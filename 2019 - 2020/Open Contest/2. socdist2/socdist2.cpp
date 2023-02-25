#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("socdist2.in");
    ofstream fout("socdist2.out");

    int n; fin >> n;
    vector<pair<int,int>> pos (n);

    int num_infected = 0, num_healthy = 0;
    for (int i = 0; i < n; i++) {
        fin >> pos[i].first >> pos[i].second;
        if (pos[i].second == 0) {
            num_healthy++;
        }
        else {
            num_infected++;
        }
    }
    sort(pos.begin(), pos.end());

    //cows can be all infected
    //none can be infected
    //only some are infected


    int R = 10000000;
    for (int i = 0; i < n - 1; i++) {
        if ((pos[i].second == 0 && pos[i + 1].second == 1) || (pos[i].second == 1 && pos[i + 1].second == 0)) {
            R = min(abs(pos[i + 1].first - pos[i].first), R);
        }
    }

    pos.insert(pos.begin(), {0, 0});

    int num_source = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i + 1].second == 1 && pos[i].second == 0) {
            num_source++;
        }
        else if (pos[i + 1].second == 1 && pos[i].second == 1) {
            if (pos[i + 1].first - pos[i].first > R - 1) {
                num_source++;
            }
        }

    }
    fout << num_source;
}


