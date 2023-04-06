#include<iostream>
#include<string>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 10;
    int b = 15;
    cout << a << " - " << b << endl;
    Swap(a, b);
    cout << a << " - " << b << endl;

    string s1 = "krishna";
    string s2 = "sriventh";
    cout << s1 << " - " << s2 << endl;
    Swap(s1, s2);
    cout << s1 << " - " << s2 << endl;

    return 0;
}