#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> arr;
    int a;
    for(int i = 0; i < n; i++) {
        scanf("%d",&a);
        arr.push_back(a);
    }

   // for(int i=0; i<n; i++)printf("%d  ",arr[i]);
    printf("%d", lower_bound(arr.begin(), arr.end(), k)-arr.begin()+1);
}