#include <bits/stdc++.h>
using namespace std;


struct Event {
    int person, time, milk = -1;
};


bool compare(Event event1, Event event2) {
    if (event1.time != event2.time) return (event1.time < event2.time);
    else return (event1.milk < event2.milk);
}


int main() {
    ifstream fin("badmilk.in");
    int N, M, D, S;
    fin >> N >> M >> D >> S;



    Event events[D + S];

    for (int i = 0; i < D; i++) {
        int person, milk, time;
        fin >> person >> milk >> time;
        events[i] = {person, time, milk};
    }
    

    for (int i = D; i < D + S; i++) {
        int person, time;
        fin >> person >> time;
        events[i] = {person, time, -1};
    }
    sort(events, events + (D + S), compare);


    int max_num = 0;
    for (int i = 1; i <= M; i++) {
        bool sick[N];
        fill(sick, sick + N, false);
        bool possible = true;
        for (Event event : events) {
            if (event.milk == -1) {
                if (!sick[event.person - 1]) {
                    possible = false;
                    break;
                }
            }
            else if (event.milk == i) {
                sick[event.person - 1] = true;
            }
        }

        if (possible) {
            int num = 0;
            for (bool person : sick) {
                num += person;
            }
            max_num = max(max_num, num);
        }
    }
    ofstream fout("badmilk.out");
    fout << max_num;
    
}