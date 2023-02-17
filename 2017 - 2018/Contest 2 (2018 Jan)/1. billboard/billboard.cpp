#include <bits/stdc++.h>
using namespace std;


struct Billboard{
    int x1, y1, x2, y2;
};


int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");

    Billboard board1{}, board2{};
    fin >> board1.x1 >> board1.y1 >> board1.x2 >> board1.y2;
    fin >> board2.x1 >> board2.y1 >> board2.x2 >> board2.y2;

    bool covers_x = board2.x1 <= board1.x1 && board2.x2 >= board1.x2;
    bool covers_y = board2.y1 <= board1.y1 && board2.y2 >= board1.y2;
    //bool other_x = board2.y1 < board1.y1 && board1.y1 < board2.y2 && board2.y2 < board1.y2;
    //bool other_y = board2.x1 < board1.x1 && board1.x1 < board2.x2 && board2.x2 < board1.x2;
    
    if (covers_y && covers_x) {
        fout << 0;
    }
    else if (covers_x) {
        if (board2.y1 < board1.y1 && board1.y1 < board2.y2 && board2.y2 < board1.y2) {
            //board2 covers the bottom part of board1
            fout << abs(board1.x1 - board1.x2) * abs(board1.y2 - board2.y1);
        }
        else if (board1.y1 < board2.y1 && board2.y1 < board1.y2 && board1.y2 < board2.y2) {
            fout << abs(board1.x1 - board1.x2) * abs(board2.y1 - board1.y1);
        }
        else {
            fout << abs(board1.x2 - board1.x1) *  abs(board1.y2 - board1.y1);
        }
    }
    else if (covers_y) {
        if (board2.x1 < board1.x1 && board1.x1 < board2.x2 && board2.x2 < board1.x2) {
            fout << abs(board1.x2 - board2.x2) * abs(board1.y1 - board1.y2);
        }
        else if (board1.y2 < board2.y2 && board2.y2 < board1.y1 && board1.y1 < board2.y1) {
            fout << abs(board2.x1 - board1.x1) * abs(board1.y1 - board1.y2);
        }
        else {
            fout << abs(board1.x2 - board1.x1) *  abs(board1.y2 - board1.y1);
        }
    }
    else {
        fout << abs(board1.x2 - board1.x1) *  abs(board1.y2 - board1.y1);
    }
}