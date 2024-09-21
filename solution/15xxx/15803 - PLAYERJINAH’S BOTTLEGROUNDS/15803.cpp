#include <iostream>
using namespace std;

double x[3], y[3];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    if((x[0]-x[1])*(y[1]-y[2]) == (x[1]-x[2])*(y[0]-y[1])) cout << "WHERE IS MY CHICKEN?";
    else cout << "WINNER WINNER CHICKEN DINNER!";

    return 0;
}