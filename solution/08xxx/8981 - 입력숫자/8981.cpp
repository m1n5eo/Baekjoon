#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
vector<int> v, result;

int main() {
    FASTIO

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        v.push_back(temp);
        result.push_back(0);
    }

    int idx = 0;

    while(v.size()) {
        while(result[idx] != 0) {
            idx = (idx+1)%n;
        }
        
        result[idx] = v[0];
        idx = (idx+v[0])%n;
        v.erase(v.begin());
    }

    cout << n << "\n";
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}