#include <bits/stdc++.h>
using namespace std;


int n;


int find_nearest(int arr[], int pos) {
    if (pos == 0) {
        return pos + 1;
    }
    else if (pos == n - 1) {
        return pos - 1;
    }
    else {
        int left_diff = arr[pos] - arr[pos - 1];
        int right_diff = arr[pos + 1] - arr[pos];

        if (left_diff <= right_diff) {
            return pos - 1;
        }
        else {
            return pos + 1;
        }
    }

}


bool is_isolated(int arr[], int pos) {
    int nearest = find_nearest(arr, pos);


    if (find_nearest(arr, nearest) == pos) {
        return true;
    }
    return false;
}


int main() {
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    fin >> n;
    int cow_pos[n];
    for (int i = 0; i < n; i++) {
        fin >> cow_pos[i];
    }
    sort(cow_pos, cow_pos + n);

    int passed_to[n];
    fill(passed_to, passed_to + n, 0);

    int answer = 0;
    for (int j = 0; j < n; j++) {
        passed_to[find_nearest(cow_pos, j)]++;
    }

    for (int j = 0; j < n; j++) {
        if (passed_to[j] == 0) {
            answer++;
        }
        int nearest = find_nearest(cow_pos, j);
        if (j < nearest && is_isolated(cow_pos, j) && passed_to[nearest] == 1 && passed_to[j] == 1) {
            answer++;
        }
    }
    fout << answer;
}