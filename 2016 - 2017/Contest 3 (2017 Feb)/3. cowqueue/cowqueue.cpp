#include <fstream>
#include <algorithm>
using namespace std;


int main () {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int n; fin >> n;

    pair<int, int> cows[n];

    for (int i = 0; i < n; i++) {
        int time_arrived, time_taken;
        fin >> time_arrived >> time_taken;
        cows[i].first = time_arrived, cows[i].second = time_taken;
    }

    sort(cows, cows + n);

    int time = 0;
    for (int i = 0; i < n - 1; i++) {
        time = cows[i].first + cows[i].second;
        if (cows[i].first + cows[i].second > cows[i + 1].first) {
            cows[i + 1].first = cows[i].first + cows[i].second; 
        }
    }
    time = cows[n - 1].first + cows[n - 1].second;
    fout << time;
}