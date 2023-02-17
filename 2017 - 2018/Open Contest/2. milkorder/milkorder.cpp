#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");

    int n, m, k;
    fin >> n >> m >> k;

    vector<int> positions (n);
    fill(positions.begin(), positions.end(), -1);

    bool contains_1 = false;
    vector<int> specific_order (m);
    for (int j = 0; j < m; j++) {
        fin >> specific_order[j];
        if (specific_order[j] == 1) {
            contains_1 = true;
        }
    }

    for (int i = 0; i < k; i++) {
        int temp_cow, temp_pos;
        fin >> temp_cow >> temp_pos;
        if (temp_cow == 1) {
            fout << temp_pos;
            return 0;
        }
        else {
            positions[temp_pos - 1] = temp_cow;
        }
    }

    vector<int> present_cows, found_at;
    for (int i = 0; i < specific_order.size(); i++) {
        auto pos = find(positions.begin(), positions.end(), specific_order[i]);    
        if (pos != positions.end()) {
            present_cows.push_back(specific_order[i]);
        }
        found_at.push_back(distance(positions.begin(), pos));
    }

    //if the specified sequence contains 1, we want to start at the front of the array to minimize
    //otherwise, start at the back
    if (!contains_1) {
        int index = specific_order.size() - 1;
        for (int i = positions.size() - 1; i > 0; i--) {
            if (index == -1) {
                break;
            }
            else if (positions[i] == -1) {
                if (find(present_cows.begin(), present_cows.end(), specific_order[index]) != present_cows.end()) {
                    //we have to skip to where it was found since the next cow has to be milked before it.
                    i = found_at[index];
                }
                else {
                    positions[i] = specific_order[index];
                }
                index--;
            }
        }
    }
    else {
        int index = 0;
        for (int i = 0; i < positions.size(); i++) {
            if (index == positions.size()) {
                break;
            }
            else if (positions[i] == -1) {
                if (find(present_cows.begin(), present_cows.end(), specific_order[index]) != present_cows.end()) {
                    i = found_at[index];
                }
                else {
                    positions[i] = specific_order[index];
                }
                index++;
            }
        }
    }
    
    auto cow1_pos = find(positions.begin(), positions.end(), 1);
    if (cow1_pos != positions.end()) {
        fout << distance(positions.begin(), cow1_pos) + 1;
        return 0;
    }
    else {
        for (int i = 0; i < positions.size(); i++) {
            if (positions[i] == -1) {
                fout << i + 1;
                return 0;
            }
        }
    }
}