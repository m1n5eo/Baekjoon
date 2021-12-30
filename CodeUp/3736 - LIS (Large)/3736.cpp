#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d", &n);
    vector <int> arr;
    arr.push_back(-1);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(arr.back() < a) arr.push_back(a);
        else  {
          *lower_bound(arr.begin(), arr.end(), a)=a;
        }
    }
    printf("%d", arr.size()-1);
}