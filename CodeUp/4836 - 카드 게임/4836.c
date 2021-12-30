#include <stdio.h>

int main() {
    int A_card[11], B_card[11], A_win = 0, B_win = 0;
    for(int i = 0; i < 10; i++) scanf("%d", &A_card[i]);
    for(int i = 0; i < 10; i++) scanf("%d", &B_card[i]);
    
    for(int i = 0; i < 10; i++) {
        if(A_card[i] > B_card[i]) A_win++;
        else if(A_card[i] < B_card[i]) B_win++;
    }
    
    if(A_win > B_win) printf("A");
    else if(A_win < B_win) printf("B");
    else printf("D");
}