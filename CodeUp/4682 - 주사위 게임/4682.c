#include <stdio.h>
#include <algorithm>

using namespace std;

int num[1003][5], score[1003];

int main() {
	int n, max = -1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(num[i][1] == num[i][2] && num[i][2] == num[i][3]) score[i] = 10000 + num[i][1]*1000;
		else if(num[i][1] == num[i][2]) score[i] = 1000 + num[i][1]*100;
		else if(num[i][2] == num[i][3]) score[i] = 1000 + num[i][2]*100;
		else if(num[i][1] == num[i][3]) score[i] = 1000 + num[i][3]*100;
		else {
			if(num[i][1] > num[i][2] && num[i][1] > num[i][3]) score[i] = num[i][1]*100;
			else if(num[i][2] > num[i][1] && num[i][2] > num[i][3]) score[i] = num[i][2]*100;
			else score[i] = num[i][3]*100;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(score[i] > max) {
			max = score[i];
		}
	}
	printf("%d", max);
}