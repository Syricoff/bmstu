#include <iostream>
#include <fstream>
using namespace std;

void setFile() {
    ofstream fout("file.bin", ios::binary);
    int mas[50]{};
    for (int i = 0; i < 50; i++) {
        int num{};
        num = rand() % (20 - 1 + 1) + 1;
        mas[i] = num;
    }
    fout.write((char*)&mas, sizeof(mas));
    fout.close();
}

void countNum() {
    ifstream fin("file.bin", ios::binary);
    setlocale(0, "rus");
    int mas[50]{};
    fin.read((char*)&mas, sizeof(mas));
    int counter{};
    int numbers[50]{};
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if (mas[i] == mas[j]) {
                numbers[i]++;
            }
        }
    }
    for (int i = 0; i < 50; i++) {
        cout << mas[i] << "\t" << numbers[i] << endl; //для удобства
        if (numbers[i] == 1) {
            counter++;
        }
    }
    cout <<"Количество чисел встречающихся по 1 разу: " << counter;
}

int main()
{
    setFile();
    countNum();
}