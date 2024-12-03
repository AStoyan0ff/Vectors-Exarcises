#include <iostream>
#include <vector>
#include <cmath>
#include <climits> 
using namespace std;

static int timeToMinutes(int time) {
    
    int hours = time / 100;
    int minutes = time % 100;
    
    return hours * 60 + minutes;
}

int main() {
   
    int N; 
    cin >> N;

    vector<int> busTimes(N); 
    
    for (int i = 0; i < N; ++i) {
        
        cin >> busTimes[i];
    }

    int trainTime; 
    cin >> trainTime;

    int trainMinutes = timeToMinutes(trainTime); 

    int minWaitTime = INT_MAX; 
    int busIdx = -1;

    for (int i = 0; i < N; ++i) {
        
        int busMinutes = timeToMinutes(busTimes[i]); 
        int waitTime = trainMinutes - busMinutes;           

        if (waitTime >= 0 && waitTime < minWaitTime) {
            
            minWaitTime = waitTime;
            busIdx = i + 1;
        }
    }

    cout << busIdx << endl; // Yabba-Dabba-Dooo =)

    return 0;
}
