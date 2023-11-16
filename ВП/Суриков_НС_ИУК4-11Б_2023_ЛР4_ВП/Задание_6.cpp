#include <iostream>
using namespace std;

int main() {
    int n{};
    cin >> n;

    double a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count{};
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i-1] && a[i] < a[i+1]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}