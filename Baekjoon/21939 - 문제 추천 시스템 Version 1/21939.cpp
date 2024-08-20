#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>

int main() {
    FASTIO
    
    int n, m;
    map<int, pair<int, bool>> level;
    priority_queue<pii> maxProblem;
    priority_queue<pii, vector<pii>, greater<pii>> minProblem;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        int p, l;

        cin >> p >> l;

        level[p] = {l, true};
        minProblem.push({l, p});
        maxProblem.push({l, p});
    }

    cin >> m;

    for(int _ = 0; _ < m; _++) {
        string mode;
        int a, b;

        cin >> mode;

        if(mode == "recommend") {
            cin >> a;

            if(a == -1) {
                while(minProblem.size() && (level[minProblem.top().second].second == false || level[minProblem.top().second].first != minProblem.top().first)) minProblem.pop();
                cout << minProblem.top().second << "\n";
            }
            else if(a == 1) {
                while(maxProblem.size() && (level[maxProblem.top().second].second == false || level[maxProblem.top().second].first != maxProblem.top().first)) maxProblem.pop();
                cout << maxProblem.top().second << "\n";
            }
        }
        else if(mode == "add") {
            cin >> a >> b;

            level[a] = {b, true};
            minProblem.push({b, a});
            maxProblem.push({b, a});
        }
        else if(mode == "solved") {
            cin >> a;

            level[a].second = false;
        }
    }
}