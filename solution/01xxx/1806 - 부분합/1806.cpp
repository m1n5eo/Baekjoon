#include <iostream>
#include <vector>
using namespace std;

#define INF 1234567890

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m;
    vector<int> v;

    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int start = 0, end = -1, sum = 0;
    int result = INF;

    while(end <= n) {
        if(sum < m) {
            end += 1;
            sum += v[end];
        }
        else if(sum >= m) {
            sum -= v[start];
            start += 1;
        }

        if(sum >= m) {
            result = min(result, end-start+1);
        }
    }

    if(result == INF) cout << 0;
    else cout << result;
}