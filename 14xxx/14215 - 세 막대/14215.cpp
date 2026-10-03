#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 3, triangle[3];
    for(int i = 0; i < n; i++) cin >> triangle[i];
    sort(triangle, triangle+3);
    if(triangle[0]+triangle[1] <= triangle[2]) cout << (triangle[0]+triangle[1])*2-1;
    else cout << triangle[0]+triangle[1]+triangle[2];
}