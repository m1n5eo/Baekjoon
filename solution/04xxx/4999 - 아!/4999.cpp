#include <iostream>
#include <string>
using namespace std;

int main() {
    string JaeHawn, doctor;
    cin >> JaeHawn >> doctor;
    if(JaeHawn.length() < doctor.length()) cout << "no";
    else cout << "go";
}