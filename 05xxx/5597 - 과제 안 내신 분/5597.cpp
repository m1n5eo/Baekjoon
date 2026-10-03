#include <bits/stdc++.h>
using namespace std;

int a, arr[33];

int main() {
	for(int i = 1; i <= 28; i++) {
		scanf("%d", &a);
		arr[a] = 1;
	}
	for(int i = 1; i <= 30; i++) {
		if(arr[i] == 0) printf("%d\n", i);
	}
}