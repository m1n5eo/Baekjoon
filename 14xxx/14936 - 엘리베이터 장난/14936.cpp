#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, time, result;

int main() {
    FASTIO

    cin >> n >> time;

    int push_time[5] = {0, n, n/2, (n+1)/2, (n+2)/3};

    result += 1; // 0
    if(time >= push_time[1]) result += 1; // 1
    if(n > 1 && time >= push_time[2]) result += 1; // 2
    if(n > 1 && time >= push_time[3]) result += 1; // 3
    if(n > 2 && time >= push_time[4]) result += 1; // 4
    if(n > 2 && time >= push_time[1]+push_time[4]) result += 1; // 1+4
    if(n > 2 && time >= push_time[2]+push_time[4]) result += 1; // 2+4
    if(n > 2 && time >= push_time[3]+push_time[4]) result += 1; // 3+4
    
    cout << result;
}