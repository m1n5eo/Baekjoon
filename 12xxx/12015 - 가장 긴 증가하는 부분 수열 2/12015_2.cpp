#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int n;
vector<int> v;

int main() {
    FASTIO

    v.push_back(-1);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(v.back() < temp) v.push_back(temp);
        else *lower_bound(v.begin(), v.end(), temp) = temp;
    }
    
    cout << v.size()-1;
}