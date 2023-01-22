#include <fstream>
#include <unordered_set>
using namespace std;


unordered_set<string> considered_alliance;
unordered_set<char> considered_solo;


void test(unordered_set<char> comb, char value) {
    if (comb.size() == 1) {
        considered_solo.insert(value);
    }
    else if (comb.size() == 2) {
        string temp;
        for (char temp_char : comb) {
            temp += temp_char;
        }
        considered_alliance.insert(temp);
        string reverse_str = string(temp.rbegin(), temp.rend());
        considered_alliance.insert(reverse_str);
    }
}


int main() {
    ifstream fin("tttt.in");
    

    string board[3];
    for (int i = 0; i < 3; i++) {
        fin >> board[i];
    }
    
    //how to access columns
    for (int i = 0; i < 3; i++) {
        unordered_set<char> comb;
        for (int j = 0; j < 3; j++) {
            comb.insert(board[j][i]);
        }
        test(comb, board[0][i]);
    }


    for (int i = 0; i < 3; i++) {
        unordered_set<char> comb;
        for (int j = 0; j < 3; j++) {
            comb.insert(board[i][j]);
        }
        test(comb, board[i][0]);
    }
    

    unordered_set<char> diagonal1;
    for (int i = 0; i < 3; i++) {
        diagonal1.insert(board[i][i]);
    }
    test(diagonal1, board[0][0]);
    
    
    unordered_set<char> diagonal2;
    for (int i = 0; i < 3; i++) {
        diagonal2.insert(board[i][2 - i]);
    }
    test(diagonal2, board[0][2]);


    ofstream fout("tttt.out");
    fout << considered_solo.size() << '\n';
    fout << considered_alliance.size() / 2;
}