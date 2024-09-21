#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define x first
#define y second

int result = INF;

void find_chicken_road(int idx, vector<int> v, int m, int house_size, int chicken_size, vector<vector<int>> dist) {
    if(m == v.size()) {
        int sum = 0;

        for(int i = 0; i < house_size; i++) {
            int min_dist = INF;

            for(auto j : v) min_dist = min(min_dist, dist[i][j]);
            sum += min_dist;
        }

        result = min(result, sum);
    }

    for(int i = idx+1; i < chicken_size; i++) {
        v.push_back(i);
        find_chicken_road(i, v, m, house_size, chicken_size, dist);
        v.pop_back();
    }
}

int main() {
    FASTIO

    int n, m;

    cin >> n >> m;

    vector<vector<int>> city(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dist(n*2, vector<int>(13, 0));
    vector<pair<int, int>> house, chicken;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> city[i][j];

            if(city[i][j] == 1) house.push_back({i, j});
            else if(city[i][j] == 2) chicken.push_back({i, j});
        }
    }

    int house_size = house.size(), chicken_size = chicken.size();

    for(int i = 0; i < house_size; i++) {
        for(int j = 0; j < chicken_size; j++) {
            dist[i][j] = abs(house[i].x-chicken[j].x) + abs(house[i].y-chicken[j].y);
        }
    }

    find_chicken_road(-1, {}, m, house_size, chicken_size, dist);

    cout << result;
}