#include <stdio.h> // 세로읽기
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int max = -1, len[11];
	char ch[11][22];
	for(int i = 1; i <= 5; i++) {
		scanf("%s", ch[i]);
		len[i] = strlen(ch[i]);
		if(max < len[i]) max = len[i];
	}
	
	for(int i = 0; i < max; i++) {
		for(int j = 1; j <= 5; j++) {
			if(i < len[j]) printf("%c", ch[j][i]);
		}
	}
}