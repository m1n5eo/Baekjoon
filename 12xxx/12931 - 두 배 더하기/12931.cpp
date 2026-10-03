#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp != 0) v.push_back(temp);
    }

    int cnt = 0, result = 0; n = v.size();

    while(cnt != n) {
        for(int i = 0; i < n; i++) {
            if(v[i] > 0 && v[i]%2 == 1) {
                v[i] -= 1;
                result += 1;

                if(v[i] == 0) cnt += 1;
            }
        }

        if(cnt != n) result += 1;
        for(int i = 0; i < n; i++) {
            v[i] = v[i]/2;
        }
    }

    cout << result;
}