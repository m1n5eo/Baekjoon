#include <stdio.h>
#include <algorithm>

using namespace std;

int person[3];

void bg() {
    for(int i = 0; i < 2; i++) {
        for(int j = i+1; j < 3; j++) {
            if(person[i] > person[j]) {
                swap(person[i], person[j]);
            }
        }
    }

    for(int i = 0; i < 3; i++) printf("%d ", person[i]);
}

int main() {
    for(int i = 0; i < 3; i++) scanf("%d", &person[i]);

    bg();
}