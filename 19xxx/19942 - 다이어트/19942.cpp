#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

struct type {
    int protein, fat, carb, vitamin;
};

int n;
type minimum;
vector<pair<type, int>> food;
pair<int, deque<int>> sol = {INF, {}};

void backtracking(int go, type now, int cost, deque<int> index) {
    if(now.protein >= minimum.protein && now.fat >= minimum.fat && now.carb >= minimum.carb && now.vitamin >= minimum.vitamin) {
        if(sol.first > cost) {
            sol.first = cost;
            sol.second = index;
        }
        return;
    }

    for(int i = go+1; i < n; i++) {
        type next = {now.protein+food[i].first.protein, now.fat+food[i].first.fat, now.carb+food[i].first.carb, now.vitamin+food[i].first.vitamin};
        index.push_back(i);
        backtracking(i, next, cost+food[i].second, index);
        index.pop_back();
    }
}

void solve() {
    cin >> n;
    cin >> minimum.protein >> minimum.fat >> minimum.carb >> minimum.vitamin;
    for(int i = 0; i < n; i++) {
        int p, f, s, v, c; cin >> p >> f >> s >> v >> c;
        food.push_back({{p, f, s, v}, c});
    }
    backtracking(-1, {0, 0, 0, 0}, 0, {});
}

int main() {
    FASTIO
    solve();
    cout << (sol.first != INF? sol.first : -1) << "\n";
    for(int s : sol.second) cout << s+1 << " ";
}