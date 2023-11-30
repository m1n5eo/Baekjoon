#include <iostream>
using namespace std;

// 789,000 * 789,000 = 622,521,000,000

int main() {
    bool arr[789999] = {true, true, };
    for(int i = 2; i <= 789999; i++) {
        if(arr[i] == true) continue;
        else {
            for(int j = i*2; j <= 789999; j += i) arr[j] = true;
        }
    }
    for(int i = 789999; i >= 1; i--) {
        if(arr[i] == false && 600851475143%i == 0) {
            cout << i;
            break;
        }
    }
}