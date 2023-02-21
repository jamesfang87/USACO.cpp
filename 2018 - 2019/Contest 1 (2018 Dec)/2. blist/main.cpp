/*
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int N;
int S[101], T[101], B[101];

int main(void) {
    ifstream fin ("blist.in");
    fin >> N;
    for (int i=1; i<=N; i++) {
        fin >> S[i] >> T[i] >> B[i];
    }

    int max_buckets = 0;
    for (int time=1; time<=1000; time++) {
        int buckets_at_this_time = 0;
        for (int i=1; i<=N; i++) {
            if (S[i] <= time && time <= T[i]) {
                buckets_at_this_time += B[i];
            }
        }
        max_buckets = max(max_buckets, buckets_at_this_time);
    }

    ofstream fout ("blist.out");
    fout << max_buckets << "\n";

    return 0;
}

*/
#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int start_t, end_t, needed_buckets;
};

bool compare(Cow cow1, Cow cow2) {
    if (cow1.start_t != cow2.start_t) {
        return cow1.start_t < cow2.start_t;
    }
    else {
        return cow1.end_t < cow2.end_t;
    }
}

int main() {
    std::ifstream fin("blist.in");
    std::ofstream fout("blist.out");

    int n; fin >> n;

    Cow cows[n];

    int max_time = 0;
    for (int i = 0; i < n; i++) {
        fin >> cows[i].start_t >> cows[i].end_t >> cows[i].needed_buckets;
        max_time = max(max_time, cows[i].end_t + 1);
    }

    std::sort(cows, cows + n, compare);

    int time[max_time];
    fill(time, time + max_time, 0);

    for (auto cow : cows) {
        for (int i = cow.start_t; i <= cow.end_t; i++) {
            time[i] += cow.needed_buckets;
        }
    }

    int reserve = 0, total_needed = 0;
    int prev = time[0];
    for (int i : time) {
        if (i > prev) {
            int needed_now = i - prev;
            if (needed_now >= reserve) {
                total_needed += needed_now - reserve;
                reserve = 0;
            }
            else {
                reserve -= needed_now;
            }
        }
        else if (i < prev) {
            reserve += prev - i;
        }
        prev = i;
    }
    fout << total_needed;
}

