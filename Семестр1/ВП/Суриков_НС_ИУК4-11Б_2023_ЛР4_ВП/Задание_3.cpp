#include <iostream>
#include <algorithm>
using namespace std;

// Функция для нахождения НОД двух чисел
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Функция для нахождения НОК двух чисел
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int lcm_res = lcm(arr[0], arr[1]);
    int gcd_res = gcd(arr[0], arr[1]);


    for (int i = 2; i < n; i++) {
        lcm_res = lcm(lcm_res, arr[i]);
        gcd_res = gcd(gcd_res, arr[i]);

    }

    cout << "НОК: " << lcm_res << endl;
    cout << "НОД: " << gcd_res << endl;
}