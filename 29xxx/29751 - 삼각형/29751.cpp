#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    float w, h;
    cin >> w >> h;
    cout << fixed << setprecision(1) << trunc(w*h*10/2)/10;
}