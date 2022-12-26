#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    vector<int> max_size = {0, 0, 0};
    vector<int> curr_size = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        fin >> max_size[i] >> curr_size[i];
    }


    for (int j = 1; j <= 25; j++) {
        int i = 1;
        for (; i <= 4; i++) {
            if (i == 1 || i == 4) {
                //move from 1 to 2
                int sum = curr_size[0] + curr_size[1];
                if (sum > max_size[1]) {
                    curr_size[1] = max_size[1];
                    curr_size[0] = sum - max_size[1];
                }
                else {
                    curr_size[1] = sum;
                    curr_size[0] = 0;
                }
            }
            else if (i == 2) {
                //move from 2 to 3
                int sum = curr_size[1] + curr_size[2];
                if (sum > max_size[2]) {
                    curr_size[2] = max_size[2];
                    curr_size[1] = sum - max_size[2];
                }
                else {
                    curr_size[2] = sum;
                    curr_size[1] = 0;
                }
            }
            else {
                //move from 3 to 1
                int sum = curr_size[0] + curr_size[2];
                if (sum > max_size[0]) {
                    curr_size[0] = max_size[0];
                    curr_size[2] = sum - max_size[0];
                }
                else {
                    curr_size[0] = sum;
                    curr_size[2] = 0;
                }
            }
        }
    }

    for (int amount : curr_size) {
        fout << amount << '\n';
    }

}