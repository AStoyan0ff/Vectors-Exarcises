#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    
    string lineA, lineB;
    getline(cin, lineA);
    getline(cin, lineB);
        
    deque<int> trackA, trackB; // Стринг към Вектор
    stringstream ssA(lineA), ssB(lineB);
    int num;

    while (ssA >> num) trackA.push_front(num); 
    while (ssB >> num) trackB.push_front(num); 
        
    vector<char> operations;
    deque<int> mergedTrack;

    while (!trackA.empty() || !trackB.empty()) {
        
        if (trackA.empty()) {
            
            operations.push_back('B'); // Ako "A" е празно... вземи от "В"
            mergedTrack.push_front(trackB.front());
            trackB.pop_front();
        }
        else if (trackB.empty()) {
            
            operations.push_back('A'); // ако "В" е празно ... вземи от "А"
            mergedTrack.push_front(trackA.front());
            trackA.pop_front();
        }
        else if (trackA.front() < trackB.front()) {
           
            operations.push_back('A');
            mergedTrack.push_front(trackA.front());
            trackA.pop_front();
        }
        else {
            
            operations.push_back('B');
            mergedTrack.push_front(trackB.front());
            trackB.pop_front();
        }
    }
       
    for (char op : operations) {
        cout << op;
    }
    cout << endl;
        
    for (int car : mergedTrack) {
        cout << car << " ";
    }
    cout << endl;

    return 0;
}
