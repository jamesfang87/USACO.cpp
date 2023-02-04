#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> find_sides(vector<string> lines) {
    int top = lines.size(), bottom = 0, left = lines.size() - 1, right = 0;
    for (int i = 0; i < lines.size(); i++) {
        int left_pos = lines[i].find("#");
        int right_pos = lines[i].find_last_of("#");

        if (left_pos != string::npos) {
            left = min(left_pos, left); 
            top = min(i, top); 
            bottom = max(i, bottom);
        }
        if (right_pos != string::npos) 
            right = max(right_pos, right);
    }
    return {top, bottom, left, right};
}


int main() {
    ifstream fin("bcs.in");
    ofstream fout("bcs.out");
    int k;
    fin >> n >> k;

    vector<vector<string>> pieces;
    vector<vector<int>> sides;
    int left, right, top, bottom;
    for (int i = 0; i <= k; i++) {
        vector<string> temp (n);
        for (int i = 0; i < n; i++) {
            fin >> temp[i];
        }
		pieces.push_back(temp);
        sides.push_back(find_sides(pieces[i]));
	}
    






    vector<bool> v(k);
    fill(v.begin(), v.begin() + 2, true);

    do {
        vector<int> comb;
        for (int i = 0; i < k; i++) {
            if (v[i]) {
                comb.push_back(i + 1);
            }
        }

        int idx1 = comb[0], idx2 = comb[1];
        
        
        int min_up1 = -sides[idx1][0]; //negative
        int min_down1 = (n - 1) - sides[idx1][1]; //positive
        
        int min_left1 = -sides[idx1][2]; //negative
        int min_right1 = (n - 1) - sides[idx1][3]; //positive

        int min_up2 = -sides[idx2][0]; //negative
        int min_down2 = (n - 1) - sides[idx2][1]; //positive
        
        int min_left2 = -sides[idx2][2]; //negative
        int min_right2 = (n - 1) - sides[idx2][3]; //positive

        for (int a = min_up1; a <= min_down1; a++) {
            for (int b = min_left1; b <= min_right1; b++) {
                for (int c = min_up2; c <= min_down2; c++) {
                    for (int d = min_left2; d <= min_right2; d++) {
                        bool possible = true;

                        vector<string> temp (n); 
                        string str(n, '.');
                        for (int i = 0; i < n; i++) {
                            temp[i] = str;
                        }


                        for (int i = sides[idx1][0]; i <= sides[idx1][1]; i++) {
                            for (int j = sides[idx1][2]; j <= sides[idx1][3]; j++) {
                                if (pieces[idx1][i][j] == '.') {
                                    temp[i + a][j + b] = '.';
                                }
                                else {
                                    temp[i + a][j + b]= '#';
                                }
                            }
                        }


                        for (int i = sides[idx2][0]; i <= sides[idx2][1]; i++) {
                            for (int j = sides[idx2][2]; j <= sides[idx2][3]; j++) {
                                if (temp[i + c][j + d] == '.') {
                                    temp[i + c][j + d] = pieces[idx2][i][j];
                                }
                                else if (temp[i + c][j + d] == '#') {
                                    if (pieces[idx2][i][j] == '#') {
                                        possible = false;
                                        break;
                                    }
                                }
                            }
                            if (!possible) {
                                break;
                            }
                        } 
                                
                        if (temp == pieces[0]) {
                            fout << comb[0] << ' ' << comb[1];
                            break;
                        }
                    }
                }
            }
        }
    } while (std::prev_permutation(v.begin(), v.end()));
}