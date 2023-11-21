#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            int count_7 = 0;
            int start = i;
            while (i < len && isdigit(str[i])) {
                if (str[i] == '7') {
                    count_7++;
                }
                i++;
            }
            int end = i - 1;
            if (count_7 <= 2) {
                for (int j = start; j <= end; j++) {
                    cout << str[j];
                }
                cout << endl;
            }
        }
    }

    return 0;
}