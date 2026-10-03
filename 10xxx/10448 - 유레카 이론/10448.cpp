#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int main() {
    FASTIO

    map<int, bool> m;

    for(int i = 1; i*(i+1)/2 < MAX; i++) {
        m.insert({i*(i+1)/2, true});
    }

    int t, k;
    bool stop_point;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        stop_point = true;

        cin >> k;

        for(int i = 1; i*(i+1)/2 < MAX && stop_point; i++) {
            for(int j = i; j*(j+1)/2 < MAX && stop_point; j++) {
                if(m.find(k-i*(i+1)/2-j*(j+1)/2) != m.end()) {
                    cout << "1" << "\n";
                    stop_point = false;
                }
            }
        }

        if(stop_point == true) {
            cout << "0" << "\n";
        }
    }
}