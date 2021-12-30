#include <stdio.h>

int main() {
    int br[10][10];

    for(int j = 0; j < 10; j++) {
        for(int i = 0; i < 10; i++) {
            scanf("%d", &br[j][i]);
        }
    }
    int i = 1, j = 1;

    while(i < 10 && j < 10) {
        if(br[j][i] == 2) {
            br[j][i] = 9;
            break;
        }
        else if(br[j][i+1] == 0 || br[j][i+1] == 2) {
            br[j][i] = 9;
            i++;
        }
        else if(br[j][i+1] == 1 && (br[j+1][i] == 0 || br[j+1][i] == 2)) {
            br[j][i] = 9;
            j++;
        }
        else {
            br[j][i] = 9;
            break;
        }
    }

    for(int j = 0; j < 10; j++) {
        for(int i = 0; i < 10; i++) {
            printf("%d ", br[j][i]);
        }
        printf("\n");
    }
}