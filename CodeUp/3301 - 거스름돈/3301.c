#include <stdio.h>

int main() {
	int money, cnt = 0;
	scanf("%d", &money);
	cnt = cnt + money/50000;
	money = money - ((money/50000)*50000);
	
	cnt = cnt + money/10000;
	money = money - ((money/10000)*10000);
	
	cnt = cnt + money/5000;
	money = money - ((money/5000)*5000);
	
	cnt = cnt + money/1000;
	money = money - ((money/1000)*1000);
	
	cnt = cnt + money/500;
	money = money - ((money/500)*500);
	
	cnt = cnt + money/100;
	money = money - ((money/100)*100);
	
	cnt = cnt + money/50;
	money = money - ((money/50)*50);
	
	cnt = cnt + money/10;
	money = money - ((money/10)*10);
	
	printf("%d", cnt);
}