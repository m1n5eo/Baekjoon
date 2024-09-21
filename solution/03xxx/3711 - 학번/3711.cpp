#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1e6 - 1

int main() {
    FASTIO

    int t;

    cin >> t;

    for(int _ = 0; _ < t; _++) {
        int n;
        bool stop_point = true;
        vector<int> v;

        cin >> n;

        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;

            v.push_back(temp);
        }

        for(int k = 1; k <= MAX && stop_point; k++) {
            map<int, bool> m;

            for(int i = 0; i < n && stop_point; i++) {
                if(m.find(v[i]%k) != m.end()) {
                    break;
                }
                else {
                    m.insert({v[i]%k, true});
                }

                if(i == n-1) {
                    cout << k << "\n";
                    stop_point = false;
                    break;
                }
            }
        }
    }
}