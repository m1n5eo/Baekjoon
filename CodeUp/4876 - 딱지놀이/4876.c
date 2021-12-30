#include <stdio.h>
#include <algorithm>

using namespace std;

int AEkrwl[5], BEkrwl[5];

int main() {
	int n, Aghlttn, Bghlttn, a[103], b[103];
	scanf("%d", &n);
	for(int aucqjs = 0; aucqjs < n; aucqjs++) {
		scanf("%d", &Aghlttn);
		for(int j = 0; j < Aghlttn; j++) {
			scanf("%d", &a[j]);
			AEkrwl[a[j]] = AEkrwl[a[j]] + 1;
		}
		scanf("%d", &Bghlttn);
		for(int j = 0; j < Bghlttn; j++) {
			scanf("%d", &b[j]);
			BEkrwl[b[j]] = BEkrwl[b[j]] + 1;
		}
		
		for(int i = 4; i >= 1; i--) {
			if(AEkrwl[i] > BEkrwl[i]) {
				printf("A\n");
				break;
			}
			else if(AEkrwl[i] < BEkrwl[i]) {
				printf("B\n");
				break;
			}
			else if(i == 1) {
				printf("D\n");
			}
		}
		
		for(int i = 0; i < 5; i++) AEkrwl[i] = 0;
		for(int i = 0; i < 5; i++) BEkrwl[i] = 0; 
	}
}