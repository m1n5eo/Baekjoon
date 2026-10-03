#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct point {
    int x, y, version;
};

int n, k, t;
point puang;
vector<int> parent, picture;
vector<point> v;

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    FASTIO

    cin >> n >> k >> t;

    for(int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    cin >> puang.x >> puang.y >> puang.version;

    v.push_back({puang.x, puang.y, puang.version});

    for(int i = 1; i <= n; i++) {
        int temp_x, temp_y, temp_version, temp_p;
        cin >> temp_x >> temp_y >> temp_version >> temp_p;

        v.push_back({temp_x, temp_y, temp_version});

        if(temp_p == 1) {
            picture.push_back(i);
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            int distance = (v[i].x-v[j].x)*(v[i].x-v[j].x) + (v[i].y-v[j].y)*(v[i].y-v[j].y);

            if(distance <= k*k && abs(v[i].version-v[j].version) <= t) {
                Union(i, j);
            }
        }
    }

    int picture_size = picture.size();
    bool check = false;

    for(int i = 0; i < picture_size; i++) {
        if(Find(picture[i]) == Find(0)) {
            cout << picture[i] << " ";
            check = true;
        }
    }

    if(check == false) {
        cout << 0;
    }

    return 0;
}