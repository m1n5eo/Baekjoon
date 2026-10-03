#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int monkey, dog;

    cin >> monkey >> dog;

    int day, diff = dog-monkey;

    for(day = 1; diff > 0; day++) {
        diff -= (day+1)/2;
    }

    cout << day-1;
}