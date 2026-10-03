#include <bits/stdc++.h>
using namespace std;

int n;
int maxx = -4000, minn = 4000;
int arr[500001], arrCnt[8002];
long long int sum = 0;

void third() {
    int cnt = 0, arrSave, cntMax = -1234567890;
    for(int i = 0; i < 8001; i++) {
        if(cntMax < arrCnt[i]) cntMax = arrCnt[i];
    }
    for(int i = 0; i < 8002; i++) {
        if(cntMax == arrCnt[i]) {
            cnt++;
            arrSave = i-4000;
        }
        if(cnt == 2) {
            cout << arrSave << endl;
            return;
        }
    }
    cout << arrSave << endl;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arrCnt[arr[i]+4000]++;
        sum += arr[i];
        maxx = max(maxx, arr[i]);
        minn = min(minn, arr[i]);
    }
    sort(arr, arr+n);

    printf("%.0lf\n", (double)sum/(double)n);
    cout << arr[n/2] << endl;
    third();
    cout << maxx-minn << endl;
}