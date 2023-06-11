#include <bits/stdc++.h>

int barn[200][200], horizontal_prefix[201][201], vertical_prefix[201][201];

int main() {
    std::ifstream fin("paintbarn.in");
    std::ofstream fout("paintbarn.out");
    int n, k, len = 10; // change len
    fin >> n >> k;

    memset(barn, 0, sizeof(barn));
    memset(horizontal_prefix, 0, sizeof(horizontal_prefix));
    memset(vertical_prefix, 0, sizeof(vertical_prefix));

    while (n--) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        for (int i = y1; i < y2; i++) {
            barn[i][x1]++;
            barn[i][x2]--;
        }
    }

    int answer = 0;
    for (auto &i: barn) {
        int sum = 0;
        for (int &j: i) {
            sum += j;
            j = sum;
        }
    }

    for (auto &i: barn) {
        for (int &j: i) {
            if (j == k - 1) {
                j = 1;
            } else if (j == k) {
                j = -1;
                answer++;
            } else {
                j = 0;
            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            horizontal_prefix[i][j + 1] = horizontal_prefix[i][j] + barn[i][j];
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            vertical_prefix[j][i + 1] = vertical_prefix[j][i] + barn[j][i];
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            std::cout << barn[i][j] << '\t';
        }
        std::cout << '\n';
    }

    std::cout << '\n';

    /*
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            std::cout << horizontal_prefix[i][j] << '\t';
        }
        std::cout << '\n';
    }

    std::cout << '\n';
    */

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            std::cout << vertical_prefix[i][j] << '\t';
        }
        std::cout << '\n';
    }



    // horizontal line (moves up and down)
    int best_above[len], best_below[len];
    for (int start = 0; start < len; start++) {
        for (int end = start; end < len; end++) {
            // run Kadane's algo and save the vertical bounds
        }
    }

    // vertical line (moves left and right)
    int best_right[len], best_left[len];
    for (int line = 0; line < len; line++) {

    }


}
