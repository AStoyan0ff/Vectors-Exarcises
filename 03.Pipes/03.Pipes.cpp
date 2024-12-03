#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    
    int N; 
    cin >> N;

    vector<int> check(N), install(N);
        
    for (int i = 0; i < N; ++i) {
        cin >> check[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> install[i];
    }

    vector<int> time(N);

    for (int i = 0; i < N; ++i) {
        int corrosion = install[i] - check[i]; 
                
        if (corrosion > 0) {
            time[i] = ceil(install[i] / corrosion); // Êתל ןמ ÃÎË‗ÌÎÒÎ
        }
        else {
            
            time[i] = 0;
        }
    }
        
    for (int i = 0; i < N; ++i) {
        cout << time[i] << " ";
    }
   
    cout << endl;

    return 0;
}
