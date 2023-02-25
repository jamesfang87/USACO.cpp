#include <bits/stdc++.h>
using namespace std;

pair<int, int> largest_gap(string stalls) {
    int largest = 0, streak = 1, start_i = 0;
    pair<int, int> range;

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] == '1') {
            if (i - start_i >= largest) {
                range.first = start_i; range.second = i;
                largest = i - start_i;
            }
            streak = 1;
            start_i = i;
        }
        else {
            streak++;
        }
    }
    return range;
}

int smallest_gap(string stalls) {
    /*
    int smallest = 99999999, streak = 0, start_i = 0;
    int first = stalls.find('1') + 1;
    for (int i = first; i < stalls.size(); i++) {
        if (stalls[i] == '1') {
            smallest = min(i - start_i, smallest);
            streak = 1;
            start_i = i;
        }
        else {
            streak++;
        }
    }
    return smallest;
     */
    vector<int> occupied;
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] == '1') {
            occupied.push_back(i);
        }
    }

    int smallest = 99999999;
    for (int i = 0; i < occupied.size() - 1; i++) {
        smallest = min(smallest, occupied[i + 1] - occupied[i]);
    }
    return smallest;
}

int main() {
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");

    int n; fin >> n;
    string stalls; fin >> stalls;

    //we want to maximize the minimum space between two cows
    //there are a few cases
    //1. placing the two new cows at index 0 and n-1
    //2. placing them at a third of the distance between the largest gap
    //3. placing them at the middle of the two largest gaps
    //4. placing one cow at the left or right of the stalls and one in the middle of the largest gap

    int answer = 0;
    //smallest_gap(stalls);
    if (count(stalls.begin(), stalls.end(), '0') == stalls.size()) {
        fout << (n - 1);
        return 0;
    }
    if ((stalls[0] == '0' && stalls[n - 1] == '0')) {
        string temp = stalls;
        temp[0] = '1'; temp[n - 1] = '1';

        if (smallest_gap(temp) != 99999999) answer = max(answer, smallest_gap(temp));
    }
    if (stalls[0] == '0') {
        string temp = stalls;
        temp[0] = '1';

        pair<int, int> cur_largest = largest_gap(temp);
        temp[cur_largest.first + (cur_largest.second - cur_largest.first) / 2] = '1';

        if (smallest_gap(temp) != 99999999) answer = max(answer, smallest_gap(temp));
    }
    if (stalls[n - 1] == '0') {
        string temp = stalls;
        temp[n - 1] = '1';

        pair<int, int> cur_largest = largest_gap(temp);
        temp[cur_largest.first + (cur_largest.second - cur_largest.first) / 2] = '1';

        if (smallest_gap(temp) != 99999999) answer = max(answer, smallest_gap(temp));
    }
    if (smallest_gap(stalls) >= 2) {
        string temp = stalls;
        for (int i = 0; i < 2; i++) {
            pair<int, int> cur_largest = largest_gap(temp);
            temp[cur_largest.first + (cur_largest.second - cur_largest.first) / 2] = '1';
        }
        if (smallest_gap(temp) != 99999999) answer = max(answer, smallest_gap(temp));
    }
    if (smallest_gap(stalls) >= 3) {
        string temp = stalls;
        pair<int, int> cur_largest = largest_gap(temp);
        temp[cur_largest.first + (cur_largest.second - cur_largest.first) / 3] = '1';
        temp[cur_largest.first + (cur_largest.second - cur_largest.first) * 2 / 3] = '1';

        if (smallest_gap(temp) != 99999999) answer = max(answer, smallest_gap(temp));
    }




    fout << answer;


}
