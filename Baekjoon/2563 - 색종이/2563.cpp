#include <bits/stdc++.h>
using namespace std;

int paper[103][103];
int main() {
	int n, a, b, cnt = 0;
	scanf("%d", &n);
	for(int k = 0; k < n; k++) {
		scanf("%d %d", &a, &b);
		for(int i = a; i < a+10; i++) {
			for(int j = b; j < b+10; j++) {
				paper[i][j] = 1;
			}
		}
	}
	
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(paper[i][j] == 1) cnt++;
		}
	}
	
	printf("%d", cnt);
}