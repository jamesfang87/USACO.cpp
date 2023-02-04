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


    //some cows will always have to be in a certain position so we will have to take care of that first
    //secondly, some cows want to be milked in a certain order.  they don't have to be right next to each other
    //some of the cows that have to be in a certian position are also in the specified order sequence.
    //we will have to take into account that.
    

    //change this to see if the number is 1 and then keep iterating down until it sees the cow it must be milked after 
    //then set the last -1 after it to 1

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