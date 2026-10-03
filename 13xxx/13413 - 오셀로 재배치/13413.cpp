#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

struct type {
    int W, B;
};

int t;

int main() {
    FASTIO

    cin >> t;

    for(int testcase = 1; testcase <= t; testcase++) {
        int n, init_cnt = 0, goal_cnt = 0, diff = 0;
        string init, goal;
        
        cin >> n;
        cin >> init;
        cin >> goal;

        for(int i = 0; i < n; i++) {
            if(init[i] == 'W') init_cnt += 1;
            if(goal[i] == 'W') goal_cnt += 1;
            if(init[i] != goal[i]) diff += 1;
        }

        int result = 0;

        result += abs(init_cnt-goal_cnt);
        diff -= abs(init_cnt-goal_cnt);

        result += diff/2;

        cout << result << "\n";
    }

    return 0;
}