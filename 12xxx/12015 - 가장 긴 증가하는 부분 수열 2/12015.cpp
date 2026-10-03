#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    vector <int> v;
    v.push_back(-1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(v.back() < a) v.push_back(a);
        else {
            *lower_bound(v.begin(), v.end(), a)=a;
        }
    }
    printf("%d", v.size()-1);
}
