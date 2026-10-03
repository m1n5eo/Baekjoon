#include <stdio.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        double k;
        char str[111], ignore;
        
        scanf("%lf", &k);
        scanf("%c", &ignore);
        scanf("%[^\n]s", str);

        int len = strlen(str);

        for(int j = 0; j < len; j+=2) {
            if(str[j] == '@') {
                k = k*3;
            }
            else if(str[j] == '%') {
                k = k+5;
            }
            else if(str[j] == '#') {
                k = k-7;
            }
        }

        printf("%.2lf\n", k);
    }

    return 0;
}