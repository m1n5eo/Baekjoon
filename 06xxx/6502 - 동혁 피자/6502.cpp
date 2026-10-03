#include <iostream>
using namespace std;

int idx = 0;
double table, pizzaX, pizzaY;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true) {
        idx += 1;

        cin >> table;
        if(table == 0) break;
        cin >> pizzaX >> pizzaY;

        if(table*table >= pizzaX*pizzaX/4 + pizzaY*pizzaY/4) {
            cout << "Pizza " << idx << " fits on the table.\n";
        }
        else {
            cout << "Pizza " << idx << " does not fit on the table.\n";
        }
    }
}