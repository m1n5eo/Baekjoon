#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct type {
    int num, cnt, chk;
};

int a, b;
bool visited[1111111][2];
queue<type> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    q.push({a, 0, 0});

    while(q.size()) {
        int number = q.front().num;
        int count = q.front().cnt;
        int check = q.front().chk;

        q.pop();

        if(number+1 == b || number*2 == b || (number*10 == b && check == false)) {
            cout << count+1;
            break;
        }

        visited[number][check] = true;

        if(number+1 < b && visited[number+1][check] == false) {
            q.push({number+1, count+1, check});
        }
        if(number*2 < b && visited[number*2][check] == false) {
            q.push({number*2, count+1, check});
        }
        if(number*10 < b && visited[number*10][check] == false && check == 0) {
            q.push({number*10, count+1, 1});
        }
    }

    return 0;
}