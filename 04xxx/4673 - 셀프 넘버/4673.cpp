#include <bits/stdc++.h>
using namespace std;

int arr[10001]; /// 0.셀프넘버아님 1.셀프넘버임

void SelfNumber(int num) {
    int imsi = num, k = num;
    while(imsi) {
        k += imsi%10;
        imsi /= 10;
    }
    arr[k] = 1;
}

int main() {
    for(int i = 1; i <= 10000; i++) {
        SelfNumber(i);
    }
    for(int i = 1; i <= 10000; i++) {
        if(arr[i] == 0) printf("%d\n", i);
    }
}
