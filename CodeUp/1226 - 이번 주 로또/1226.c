#include <stdio.h>

int main() {
	int answer[7], lotto[7], bonus, c = 0, count = 0;
	for(int i = 1; i <= 6; i++) scanf("%d", &answer[i]);
	scanf("%d", &bonus);
	for(int i = 1; i <= 6; i++) scanf("%d", &lotto[i]);
	
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 6; j++) {
			if(answer[i] == lotto[j]) c++;
		}
		if (lotto[i] == bonus) count++;
	}
	if(c == 6) printf("1");
	else if(c == 5 && count == 1) printf("2");
	else if(c == 5) printf("3");
	else if(c == 4) printf("4");
	else if(c == 3) printf("5");
	else printf("0");
}