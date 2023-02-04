#include <bits/stdc++.h>
using namespace std;

int main (){
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");

    int num;
    fin >> num;

    int barn[num * 2];
    for (int i = 0; i < num; i++) {
        fin >> barn[i];
        barn[i + num] = barn[i]; 
    }

    int answer = 1410065408;


    for (int start = 0; start < num; start++) {
        //cout << "start at " << start << ' ' << barn[start] << ' ';
        int curr_answer = 0;
        for (int curr = start; curr < start + num; curr++) {
            curr_answer += barn[curr] * (curr - start);
            //cout << curr_answer << ' ';
        }
        //cout << curr_answer << ' ';
        if (curr_answer < answer) {
            answer = curr_answer;
        }

    }  
    fout << answer << '\n';
}