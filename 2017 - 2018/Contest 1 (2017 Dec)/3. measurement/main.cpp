#include <bits/stdc++.h>
using namespace std;


struct Event {
    string cow;
    int day, change;
};

bool compare(Event a, Event b) {
    return a.day < b.day;
}

int key(string name) {
    if (name == "Bessie") {
        return 0;
    }
    else if (name == "Elsie") {
        return 1;
    }
    else {
        return 2;
    }
}


int main() {
    ifstream in("measurement.in");
    ofstream out("measurement.out");
    int n; in >> n;

    int amount[3] = {7, 7, 7};

    Event log[n];

    for (int i = 0; i < n; i++) {
        in >> log[i].day >> log[i].cow >> log[i].change;
    }

    sort(log, log + n, compare);

    vector<int> previous = {0, 1, 2};
    int count = 0;
    for (const Event& event : log) {
        amount[key(event.cow)] += event.change;

        vector<int> current;
        int highest = *max_element(amount, amount + 3);
        for (int i = 0; i < 3; i++) {
            if (amount[i] == highest) {
                current.push_back(i);
            }
        }

        if (previous != current) {
            count++;
        }
        previous.clear();
        for (const int& cow : current) {
            previous.push_back(cow);
        }
    }
    out << count;
}
