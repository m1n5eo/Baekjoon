#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check;
    check.push_back(3);
    for(int i = 1; i <= n; i++) check.push_back(1);
    for(int i = 0; i < lost.size(); i++) check[lost[i]] = 0;
    for(int i = 0; i < reserve.size(); i++) check[reserve[i]]++;
    for(int i = 0; i < lost.size(); i++) {
        if(check[lost[i]-1] == 2) {
            check[lost[i]-1] = 1;
            check[lost[i]] = 1;
        }
        else if(check[lost[i]+1] == 2) {
            check[lost[i]+1] = 1;
            check[lost[i]] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(check[i] == 1 || check[i] == 2) answer++;
    }
    return answer;
}