#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, arr[300001];
    double temp;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == 0) {
        cout << 0;
        return 0;
    }

    sort(arr, arr+n);

    int remove;

    if((n*15)%100 < 50) remove = (n*15-(n*15)%100)/100;
    else if((n*15)%100 >= 50) remove = (n*15-(n*15)%100)/100+1;

    double sum = 0;

    for(int i = remove; i < n-remove; i++) {
        sum += arr[i];
    }

    cout << round(sum/(n-remove*2));

    return 0;
}