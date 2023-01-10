#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


struct event {
    int time, cow1, cow2;
};

int n, t;
string end_status;
vector<event> events (t);


bool comp(event event1, event event2) {
    return event1.time < event2.time;
}


bool possible(int patient_zero, int k) {
    vector<int> infected (n); 
    fill(infected.begin(), infected.end(), 0);
    infected[patient_zero] = 1;
    vector<int> num_handshakes (n);
    fill(num_handshakes.begin(), num_handshakes.end(), 0);

    for (event cur_event : events) {
        //make both cows infected by changing the value at index cow number - 1 equal to 1
        //increment the value at index cow number - 1 in vector num_handshakes
        if (cur_event.cow1 == 1 || cur_event.cow2 == 1) {
            num_handshakes[cur_event.cow1 - 1]++;
            num_handshakes[cur_event.cow2 - 1]++;
            if (num_handshakes[cur_event.cow1 - 1] >= k) infected[cur_event.cow1 - 1] = 1;
            if (num_handshakes[cur_event.cow2 - 1] >= k) infected[cur_event.cow2 - 1] = 1;

        }
    }

    for (int i = 0; i < n; i++) {
        if (infected[i] != end_status[i]) {
            return false;
        }
    }
    return true;
}




int main() {
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    fin >> n >> t;

    fin >> end_status;
    cout << t;

    int max_time = 0;
    
    for (int i = 0; i < t; i++) {
        
        int temp_time, temp_cow1, temp_cow2;
        fin >> temp_time >> temp_cow1 >> temp_cow2;
        events[i] = {temp_time, temp_cow1, temp_cow2};
        max_time = max(max_time, temp_time);
    }


    sort(events.begin(), events.end(), comp);

    for (event cur_event : events) {
        cout << cur_event.time << '\n';
    }

    vector<int> possible_k;



    int count = 0;
    for (int patient_zero = 1; patient_zero <= n; patient_zero++) {
        for (int k = 0; k <= max_time; k++) {
            //test if the combination of patient zero and k are ok
            //if they are, increment the counter and adjust max and min k accordingly

            if (possible(patient_zero, k)) {
                count++;
                possible_k.push_back(k);
            }
        }
    }
    

    
    int min_k = *min_element(possible_k.begin(), possible_k.end());
    cout << min_k;
    int max_k = *max_element(possible_k.begin(), possible_k.end());
    cout << max_k;




    if (max_k == 250) {
        fout << count << ' ' << min_k << " Infinity";
    }
    else if (max_k < 250) {
        fout << count << ' ' << min_k << ' ' << max_k;
    }
    
}