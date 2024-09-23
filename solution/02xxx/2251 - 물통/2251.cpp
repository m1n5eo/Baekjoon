#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct bottle {
    int a, b, c;
};

int main() {
    FASTIO

    bottle amount;
    queue<bottle> bfs;
    map<int, bool> result;

    cin >> amount.a >> amount.b >> amount.c;

    vector<vector<vector<bool>>> check(amount.a+1, vector<vector<bool>>(amount.b+1, vector<bool>(amount.c+1, false)));

    bottle init = {0, 0, amount.c};
    bfs.push(init);
    check[init.a][init.b][init.c] = true;
    result.insert({init.c, true});

    while(bfs.size()) {
        bottle now = bfs.front(), next;
        bfs.pop();

        if(now.a + now.b < amount.b) next = {0, now.a+now.b, now.c};
        else next = {now.a+now.b-amount.b, amount.b, now.c};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }

        if(now.a + now.c < amount.c) next = {0, now.b, now.a+now.c};
        else next = {now.a+now.c-amount.c, now.b, amount.c};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }

        if(now.b + now.a < amount.a) next = {now.b+now.a, 0, now.c};
        else next = {amount.a, now.b+now.a-amount.a, now.c};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }

        if(now.b + now.c < amount.c) next = {now.a, 0, now.b+now.c};
        else next = {now.a, now.b+now.c-amount.c, amount.c};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }

        if(now.c + now.a < amount.a) next = {now.c+now.a, now.b, 0};
        else next = {amount.a, now.b, now.c+now.a-amount.a};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }

        if(now.c + now.b < amount.b) next = {now.a, now.c+now.b, 0};
        else next = {now.a, amount.b, now.c+now.b-amount.b};

        if(check[next.a][next.b][next.c] == false) {
            bfs.push(next);
            check[next.a][next.b][next.c] = true;

            if(next.a == 0) {
                result.insert({next.c, 0});
            }
        }
    }

    for(auto results : result) {
        cout << results.first << " ";
    }
}