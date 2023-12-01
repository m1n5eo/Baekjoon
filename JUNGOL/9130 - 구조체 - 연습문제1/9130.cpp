#include <iostream>
#include <string>
using namespace std;

struct human {
    string name;
    int age;
}a;

int main() {
    cout << "당신의 이름은 무엇입니까? ";
    cin >> a.name;

    cout << "당신의 나이는 몇 살입니까? ";
    cin >> a.age;

    cout << "당신의 이름은 " << a.name << "이고 나이는 " << a.age << "세이군요.";
}