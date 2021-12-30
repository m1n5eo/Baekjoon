#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int human, check[11], board[11][11];
	for(int i = 1; i <= 10; i++) {
		for(int j = 1; j <= 10; j++) {
			scanf("%d", &board[i][j]);
		}
	} // crash = 1 , fall = 2 , safe = 0
	for(int i = 1; i <= 10; i++) {
		scanf("%d", &human);
		if(human == 0) continue;
		else {
			for(int j = 10; j >= 1; j--) {
				if(board[j][i] > 0) {
					printf("%d crash\n", i);
					break;
				}
				else if(board[j][i] < 0) {
					printf("%d fall\n", i);
					break;
				}
				else if(j == 1) {
					printf("%d safe\n", i);
					break;
				}
			}
		}
	}
}