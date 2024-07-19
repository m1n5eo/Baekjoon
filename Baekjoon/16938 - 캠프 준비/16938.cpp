#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000
#define MAX 22

int problem, min_sum, max_sum, gap, result;
bool check[MAX];
vector<int> level;

void solve(int idx, int sum, int min_level, int max_level) {
    if(!(idx == -1 && sum == 0 && min_level == INF && max_level == -INF)) {
        if(min_sum <= sum && sum <= max_sum && max_level-min_level >= gap) {
            result += 1;
        }
    }

    for(int i = idx+1; i < problem; i++) {
        if(check[i] == false) {
            check[i] = true;
            solve(i, sum+level[i], min(min_level, level[i]), max(max_level, level[i]));
            check[i] = false;
        }
    }

    return;
}

int main() {
    FASTIO

    cin >> problem >> min_sum >> max_sum >> gap;

    for(int i = 0; i < problem; i++) {
        int temp;
        cin >> temp;

        level.push_back(temp);
    }

    solve(-1, 0, INF, -INF);

    cout << result;
}