/*

Билет 4. 
1. Описать существующие директивы препроцессора. 
2. Описать способы создания одномерного динамического массива.
3. Дан бинарный файл, в котором записаны структуры. 
В структуре - коэффициенты квадратного уравнения. 
С помощью подпрограммы обработать исходный файл, решив квадратные уравнения со всеми данными.

*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Cof {
  double a{};
  double b{};
  double c{};
};

void writeToFileZ() {
  int n{};
  cin >> n;
  ofstream file("binary.bin", ios::binary);
  for (int i = 0; i < n; i++) {
    Cof obj{};
    obj.a = rand() % (100 - (-100) + 1) + (-100);
    obj.b = rand() % (100 - (-100) + 1) + (-100);
    obj.c = rand() % (100 - (-100) + 1) + (-100);
    file.write((char*)&obj, sizeof(obj));
    
  }
  file.close();
  
}

void readAndCalk() {
  ifstream fin("binary.bin", ios::binary);
  cout << "Answers" << endl;
  int op = 1;
  while (!fin.eof()) {
    Cof obj{};
    cout << "Yravnenie: " << op << endl;
    fin.read((char*)&obj, sizeof(obj));
    double d{};
    d = pow(obj.b, 2) - 4 * obj.a * obj.c;
    if (d < 0) {
      cout << "No answer" << endl;
    }
    else {
      double x1 = (-obj.b + sqrt(d)) / 2 * obj.a;
      double x2 = (-obj.b - sqrt(d)) / 2 * obj.a;
      cout << x1 << "\t" << x2 << "\n";
    }
    op++;
  }
}