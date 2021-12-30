#include <algorithm>

using namespace std;

long long int f(long long int a, long long int b) {
    if(a < b) swap(a, b);
    return a-b;
}