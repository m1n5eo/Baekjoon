#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    string str, rank;
    float score, sum = 0;
    int cnt = 0;

    for(int i = 0; i < 20; i++) {
        cin >> str >> score >> rank;

        cnt += score;

        if(rank == "A+") sum += score*4.5;
        else if(rank == "A0") sum += score*4.0;
        else if(rank == "B+") sum += score*3.5;
        else if(rank == "B0") sum += score*3.0;
        else if(rank == "C+") sum += score*2.5;
        else if(rank == "C0") sum += score*2.0;
        else if(rank == "D+") sum += score*1.5;
        else if(rank == "D0") sum += score*1.0;
        else if(rank == "F") sum += score*0.0;
        else cnt -= score;
    }

    cout << sum/cnt;
}