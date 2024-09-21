#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", min(min(w-x, h-y), min(x, y)));
}