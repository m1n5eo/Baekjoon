#include <stdio.h>

int main() {
	char name[21];
	int age;
	char code;
	float key;
	
	scanf("%s %d %c %g", &name, &age, &code, &key);
	printf("%s\n%d\n%c\n%g", name, age, code, key);
}