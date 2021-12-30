#include <algorithm>

using namespace std;

int mid(int a, int b, int c) {
    int k[3];
    k[0] = a, k[1] = b, k[2] = c;
    sort(k, k+3);
    return k[1];
}