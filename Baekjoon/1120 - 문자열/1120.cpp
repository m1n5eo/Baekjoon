#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

int main() {
    FASTIO
    
    string a, b;
    int result = INF;

    cin >> a >> b;

    int a_size = a.size(), b_size = b.size();

    for(int i = 0; i <= b_size-a_size; i++) {
        int cnt = 0;

        for(int j = 0; j < a_size; j++) {
            if(a[j] != b[i+j]) cnt += 1;
        }

        result = min(result, cnt);
    }

    cout << result;
}