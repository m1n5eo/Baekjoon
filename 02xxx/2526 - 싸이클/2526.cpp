#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, p, k = 1, cnt[111] = {0};
    cin >> n >> p;
    int temp = n;
    while(1) {
        temp = (n*temp)%p;
        if(!cnt[temp]) cnt[temp] = k++;
        else {
            cout << k-cnt[temp];
            break;
        }
    }
}