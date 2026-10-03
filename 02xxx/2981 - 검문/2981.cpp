#include <bits/stdc++.h>
using namespace std;

int n, arrMinusMin = 1234567890;
int arr[101], arrMinus[101], print[101];

int gcd(int a, int b) {
	while(b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for(int i = 1; i < n; i++) {
        arrMinus[i-1] = arr[i]-arr[i-1];
        arrMinusMin = min(arrMinus[i-1], arrMinusMin);
    }
    int save = arrMinus[0];
    for(int i = 1; i < n-1; i++) save = gcd(save, arrMinus[i]);
    int k = 0;
    for(int i = 1; i*i <= save; i++) {
        if(save%i == 0) print[k++] = i;
    }
    for(int i = 1; i < k; i++) printf("%d ", print[i]);
    if(print[k-1]*print[k-1] != save) printf("%d ", save/print[k-1]);
    for(int i = k-2; i >= 0; i--) printf("%d ", save/print[i]);
}