#include <fstream>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    int num;
    fin >> num;

    vector<string> blocks;
    vector<string> blocks2;



    int answer[26];
    for (int i = 0; i < num; i++) {
        string temp;
        fin >> temp;
        blocks.push_back(temp);
    }

    
    //pair.first
    
    for (int i = 1; i < num; i++) {

        
    }

    //pair.second



    return 0;
}