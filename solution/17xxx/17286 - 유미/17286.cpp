#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

struct point {
    int x, y;
};

int a, b;
double first_dist, second_dist, third_dist, res;
point yumi;
vector<point> human;
vector<double> dist;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> yumi.x >> yumi.y;
    for(int i = 0; i < 3; i++) {
        cin >> a >> b;
        human.push_back({a, b});
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) continue;

            for(int k = 0; k < 3; k++) {
                if(i == k || j == k) continue;

                first_dist = sqrt((yumi.x-human[i].x)*(yumi.x-human[i].x) + (yumi.y-human[i].y)*(yumi.y-human[i].y));
                second_dist = sqrt((human[i].x-human[j].x)*(human[i].x-human[j].x) + (human[i].y-human[j].y)*(human[i].y-human[j].y));
                third_dist = sqrt((human[j].x-human[k].x)*(human[j].x-human[k].x) + (human[j].y-human[k].y)*(human[j].y-human[k].y));

                dist.push_back(first_dist + second_dist + third_dist);
            }
        }
    }

    res = dist[0];
    for(int i = 1; i < dist.size(); i++) {
        res = min(res, dist[i]);
    }
    
    cout << floor(res);

    return 0;
}