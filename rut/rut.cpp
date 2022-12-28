#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

// data structure for cow
struct Cow {
  char dir;
  int x, y, stopped_at;
  bool hasStopped;
};

// data structure for each event
struct event {
  int time; // time occured
  Cow stopped, stopper; // which cow was stopped by which cow
};

bool cmp(event a, event b) {
  return (a.time < b.time);
};

int findCow(Cow cow, int num_cows, vector<Cow> cows) {
  for (int i = 0; i < num_cows; i++) {
    if (cows[i].x == cow.x && cows[i].y == cow.y && cows[i].dir == cow.dir) {
      return i;
    }
  }
}


int main() {
  int num_cows;
  cin >> num_cows;

  vector<Cow> cows;
  vector<event> stopping_info;

  for (int i = 0; i < num_cows; i++) {
    char direction;
    int x, y;
    cin >> direction >> x >> y;
    cows.push_back({direction, x, y, 0, false});
  }

  vector<bool> v(num_cows);
  fill(v.begin(), v.begin() + 2, true);

  int ahah = 0;
  do {
    ahah++;
    int times = 0;
    int temp[2];
    for (int i = 0; i < num_cows; i++) {
      if (v[i]) {
        temp[times] = i;
        times++;
      }
    }
      
    if (cows[temp[0]].dir == 'E' && cows[temp[1]].dir == 'N') { 
      if (cows[temp[0]].x > cows[temp[1]].x || cows[temp[1]].y > cows[temp[0]].y) {
      }

      else {

        int x_diff = abs(cows[temp[0]].x - cows[temp[1]].x);
        int y_diff = abs(cows[temp[1]].y - cows[temp[0]].y);
                
        if (x_diff > y_diff) {
          stopping_info.push_back({x_diff, cows[temp[0]], cows[temp[1]]}); //first value is stopped, second is stopper
        }
        else if (y_diff > x_diff) {
          stopping_info.push_back({y_diff, cows[temp[1]], cows[temp[0]]}); //first value is stopped, second is stopper
        }
      }
    }
      

    else if (cows[temp[0]].dir == 'N' && cows[temp[1]].dir == 'E') { 
      if (cows[temp[0]].y > cows[temp[1]].y || cows[temp[1]].x > cows[temp[0]].x) {
      }
      else {
        int x_diff = abs(cows[temp[0]].x - cows[temp[1]].x);
        int y_diff = abs(cows[temp[1]].y - cows[temp[0]].y);
                
        if (x_diff > y_diff) {
          stopping_info.push_back({x_diff, cows[temp[1]], cows[temp[0]]}); //first value is stopped, second is stopper
        }
        else if (y_diff > x_diff) {
          stopping_info.push_back({y_diff, cows[temp[0]], cows[temp[1]]}); //first value is stopped, second is stopper
        }
      }
    }
  } while (prev_permutation(v.begin(), v.end()));
  


  sort(stopping_info.begin(), stopping_info.end(), cmp);
  
  

  for (event cur_event : stopping_info) {
    //cout << cur_event.time << " (" << cur_event.stopped.x << ", " << cur_event.stopped.y << ") " << " (" << cur_event.stopper.x << ", " << cur_event.stopper.y << ") " << '\n';
    int index_of_stopper = findCow(cur_event.stopper, num_cows, cows);
    int index_of_stopped = findCow(cur_event.stopped, num_cows, cows);


    
    if (cows[index_of_stopper].hasStopped == true) {
      if (cows[index_of_stopper].dir == 'E') {
        if (cows[index_of_stopper].x + cows[index_of_stopper].stopped_at >= cows[index_of_stopped].x && !cows[index_of_stopped].hasStopped) {
          //cout << "changed\n";
          cows.at(index_of_stopped).hasStopped = true;
          cows.at(index_of_stopped).stopped_at = cur_event.time;
        }
      }
      else if (cows[index_of_stopper].dir == 'N') {
        if (cows[index_of_stopper].y + cows[index_of_stopper].stopped_at >= cows[index_of_stopped].y && !cows[index_of_stopped].hasStopped) {
          //cout << "changed " << cows[index_of_stopper].y + cows[index_of_stopper].stopped_at << " " << cows[index_of_stopped].x << cows[index_of_stopper].hasStopped << '\n';
          cows.at(index_of_stopped).hasStopped = true;
          cows.at(index_of_stopped).stopped_at = cur_event.time;
        }
      }
    }
    else if (!cows[index_of_stopper].hasStopped && !cows[index_of_stopped].hasStopped) {
      //cout << "changed\n";
      cows.at(index_of_stopped).hasStopped = true;
      cows.at(index_of_stopped).stopped_at = cur_event.time;
    }
    
  }

  //Prints out answer
  for (Cow cow : cows) {
    if (cow.stopped_at == 0) {
      cout << "Infinity\n";
    }
    else {
      cout << cow.stopped_at << '\n';
    }
  }
}