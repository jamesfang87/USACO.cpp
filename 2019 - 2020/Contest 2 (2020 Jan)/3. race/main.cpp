#include <bits/stdc++.h>
using namespace std;
//9 7 4 2 1 0
//1 2 3 3 2 1
int solve(int min_speed, int dist) {
    int acceleration_dist = 0, deceleration_dist = 0, time = 0;
    for (int speed = 1; ; speed++) {
        acceleration_dist += speed;
        time++;
        if (acceleration_dist + deceleration_dist >= dist) {
            return time;
        }

        if (speed >= min_speed) {
            deceleration_dist += speed;
            time++;
            if (acceleration_dist + deceleration_dist >= dist) {
                return time;
            }
        }
    }
}

int main() {
    ifstream fin("race.in");
    ofstream fout("race.out");

    int dist, n;
    fin >> dist >> n;

    for (int i = 0; i < n; i++) {
        int min_speed; fin >> min_speed;
        fout << solve(min_speed, dist) << '\n';
    }
}
