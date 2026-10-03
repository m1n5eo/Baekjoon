#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int main() {
    FASTIO
    
    int n, temp, result = 0;
    vector<int> count(MAX, 0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        count[temp] += 1;

        if(count[temp+1] > 0) count[temp+1] -= 1;
        else result += 1;
    }

    cout << result;
}