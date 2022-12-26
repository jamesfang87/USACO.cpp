#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");

    int miles;
    fin >> miles;

    vector<string> modes;
    vector<int> upper;
    vector<int> lower;

    for (int i = 0; i < miles; i++) {
        string mode;
        int floor, ceil;
        fin >> mode >> floor >> ceil;
        modes.push_back(mode);
        lower.push_back(floor);
        upper.push_back(ceil);
    }


    int start = distance(modes.begin() ,find(modes.begin(), modes.end(), "none")); // convert to int distance(modes.begin, start);
    cout << start;
    for (; start >= 0; start--) {
        //calculate the number of cars on the highway with the info from the on and off ramps
        //if (on)
        //else if (off) or just else
        if (modes[start] == "none") {
            pair<int, int> answer1 = {lower[start], upper[start]}; 
        }
        else if (modes[start] == "on") {

        }
        else if (modes[start] == "off") {

        }
    }

    vector<string> temp = {"none"};
    int last = distance(modes.begin(), std::find_end(modes.begin(), modes.end(), temp.begin(), temp.end())); //conver to int
    cout << last;
    for (; last < miles; last++) {
        if (modes[last] == "none") {
            pair<int, int> answer2 = {lower[start], upper[start]}; 
        }
        else if (modes[last] == "on") {

        }
        else if (modes[last] == "off") {

        }
    }
}