#include <bits/stdc++.h>
using namespace std;

int n, firstCnt, secondCnt, thirdCnt;
int paper[2222][2222];

void func(int x, int y, int num) {
    if(num == 0) return;
    int first = 0, second = 0, third = 0;
    for(int i = x; i < x+num; i++) {
        for(int j = y; j < y+num; j++) {
            if(paper[i][j] == -1) first++;
            else if(paper[i][j] == 0) second++;
            else if(paper[i][j] == 1) third++;
        }
    }
    if(first == num*num) firstCnt++;
    else if(second == num*num) secondCnt++;
    else if(third == num*num) thirdCnt++;
    else {
        func(x, y, num/3);
        func(x, y+num/3, num/3);
        func(x, y+num/3*2, num/3);
        func(x+num/3, y, num/3);
        func(x+num/3, y+num/3, num/3);
        func(x+num/3, y+num/3*2, num/3);
        func(x+num/3*2, y, num/3);
        func(x+num/3*2, y+num/3, num/3);
        func(x+num/3*2, y+num/3*2, num/3);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    func(0, 0, n);
    cout << firstCnt << "\n" << secondCnt << "\n" << thirdCnt;
}