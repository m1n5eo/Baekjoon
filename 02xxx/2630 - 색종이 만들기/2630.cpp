#include <bits/stdc++.h>
using namespace std;

int n, whitePaper, blackPaper;
int paper[222][222];

void func(int x, int y, int num) {
    if(num == 0) return;
    int cnt = 0;
    for(int i = x; i < x+num; i++) {
        for(int j = y; j < y+num; j++) {
            if(paper[i][j] == 0) cnt++;
        }
    }
    if(cnt == num*num) whitePaper++;
    else if(cnt == 0) blackPaper++;
    else {
        func(x, y, num/2);
        func(x, y+num/2, num/2);
        func(x+num/2, y, num/2);
        func(x+num/2, y+num/2, num/2);
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
    cout << whitePaper << "\n" << blackPaper;
}