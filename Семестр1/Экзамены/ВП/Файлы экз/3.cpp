#include <iostream>
#include <fstream>
using namespace std;

int** setMatrix() {
    int** matrix = new int*[6];
    for (int i = 0; i < 6; i++) {
        matrix[i] = new int[6];
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            matrix[i][j] = rand();
        }
    }
    return matrix;
}

double* findSr(int** matrix) {
    double* mas = new double[6];
    
    for (int i = 0; i < 6; i++) {
        double summa{};
        for (int j = 0; j < 6; j++) {
            summa += matrix[i][j];
        }
        mas[i] = summa / 6;
    }
    return mas;
}

void writeToFile(double* mas) {
    ofstream fout("file.bin", ios::binary);
    fout.write((char*)&mas, sizeof(mas));

}

void getFromFile() {
    double* mas = new double[6];
    ifstream fin("file.bin", ios::binary);
    fin.read((char*)&mas, sizeof(mas));
    for (int i = 0; i < 6; i++) {
        cout << mas[i] << endl;
    }
}

int main()
{
    int** matrix = new int* [6];
    for (int i = 0; i < 6; i++) {
        matrix[i] = new int[6];
    }
    matrix = setMatrix();
    double* mas = new double[6];
    mas = findSr(matrix);
    writeToFile(mas);
    getFromFile();
}