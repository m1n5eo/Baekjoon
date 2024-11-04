#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int print = 0;
vector<int> cube(25, 0);

bool same(int a, int b, int c, int d) {
    if(cube[a] == cube[b] && cube[b] == cube[c] && cube[c] == cube[d]) return true;
    else return false;
}

int main() {
    FASTIO

    for(int i = 1; i <= 24; i++) {
        cin >> cube[i];
    }

    if(same(1, 2, 3, 4) && same(9, 10, 11, 12)) {
        if(same(13, 14, 7, 8) && same(5, 6, 19, 20) && same(17, 18, 23, 24) && same(21, 22, 15, 16)) print = 1;
        else if(same(13, 14, 23, 24) && same(5, 6, 15, 16) && same(17, 18, 7, 8) && same(21, 22, 19, 20)) print = 1;
    }
    else if(same(5, 6, 7, 8) && same(21, 22, 23, 24)) {
        if(same(3, 4, 18, 20) && same(17, 19, 11, 12) && same(9, 10, 13, 15) && same(14, 16, 1, 2)) print = 1;
        else if(same(3, 4, 13, 15) && same(17, 19, 1, 2) && same(9, 10, 18, 20) && same(14, 16, 11, 12)) print = 1;
    }
    else if(same(13, 14, 15, 16) && same(17, 18, 19, 20)) {
        if(same(1, 3, 6, 8) && same(5, 7, 10, 12) && same(9, 11, 21, 23) && same(2, 4, 22, 24)) print = 1;
        else if(same(1, 3, 21, 23) && same(5, 7, 2, 4) && same(9, 11, 6, 8) && same(22, 24, 10, 12)) print = 1;
    }

    cout << print;
}