#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void setFile() {
    setlocale(0, "rus");
    ofstream fout("file.txt");
    cout << "Введите текст" << endl;
    for (int i = 0; i < 5; i++) {
        char str[50] = "";
        cin.getline(str, 50);
        fout << str << "\n";
    }
}
void countWord() {
    ifstream fin("file.txt");
    setlocale(0, "rus");
    char** strings = new char* [50];
    for (int i = 0; i < 50; i++) {
        strings[i] = new char[50];
    }
    int counter = 0;
    while (fin.getline(strings[counter],50)) {
        counter++;
    }
    char** strings1 = new char* [50];
    for (int i = 0; i < 50; i++) {
        strings1[i] = new char[50];
    }
    int counter2 = 0;
    for (int i = 0; i < counter; i++) {
        char* ptr = strtok(strings[i], " \n");
        while (ptr != NULL) {
            strings1[counter2] = ptr;
            ptr = strtok(nullptr, " \n");
            counter2++;
        }
    }
    char userMsg[50] = "";
    cout << "Введите искомое слово" << endl;
    cin >> userMsg;
    int slova{};
    for (int i = 0; i < counter2; i++) {
        if (strcmp(strings1[i], userMsg) == 0) {
            slova++;
        }
    }
    cout <<"Слов удв. поиску: " << slova;
}

int main()
{
    setFile();
    countWord();
}