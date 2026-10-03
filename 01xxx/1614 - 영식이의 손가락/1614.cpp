#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define ulli unsigned long long int

ulli broken, max_count, result;

int main() {
    FASTIO

    cin >> broken >> max_count;

    if(broken == 2 || broken == 3 || broken == 4) {
        if(max_count == 0) result = broken-1;
        else if(max_count%2 == 0) result += 5+(max_count-1)*4+broken-2;
        else if(max_count%2 == 1) result += 5+(max_count-1)*4+4-broken;
    }
    else if(broken == 1) {
        if(max_count == 0) result = 0;
        else if(max_count%2 == 0) result += 5+(max_count/2*4-3)*4+7;
        else if(max_count%2 == 1) result += 5+(max_count/2*4-1)*4+7;
    }
    else if(broken == 5) {
        if(max_count == 0) result = broken-1;
        else if(max_count%2 == 0) result += 5+(max_count/2*4-2)*4+7;
        else if(max_count%2 == 1) result += 5+(max_count/2*4)*4+7;
    }

    cout << result;

    return 0;
}