#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//1 2 3
//2 1 3
//2 3 1
//1 3 2

int printList(vector<int> list) {
    for (int number : list) {
        std::cout << number;
    }
    cout << '\n';
    return 0;
}

int main() {
    ifstream fin("shell.in"); 
    ofstream fout("shell.out");

    int num;
    fin >> num;

    vector<int> shells = {0, 1, 2}; //positions of the shells
    vector<int> choosen = {0, 0, 0}; //number of times that shells 1, 2, 3 were choosen
    
    for (int i = 0; i < num; i++) {
        int a, b, g;
        fin >> a >> b >> g;
        a--, b--, g--;
        
        swap(shells.at(a), shells.at(b));
        //printList(shells);
        //cout << shells.at(g) << '\n';
        choosen.at(shells.at(g))++;
        //printList(choosen);


    }
    fout << *max_element(choosen.begin(), choosen.end());
}