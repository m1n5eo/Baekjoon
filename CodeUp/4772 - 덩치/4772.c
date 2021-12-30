#include <stdio.h>

int main() {
	int n, kg[55], cm[55], rank[55];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &kg[i], &cm[i]);
		rank[i] = 0;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(kg[i] < kg[j] && cm[i] < cm[j]) rank[i]++;
		}
	}
	for(int i = 0; i < n; i++) printf("%d ", rank[i]+1);
}