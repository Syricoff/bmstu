#include <iostream>

// Структура для описания комплексного числа
struct ComplexNumber {
  double real;    // действительная часть
  double imag;    // мнимая часть
};

// Функция для умножения комплексных чисел
ComplexNumber multiplyComplex(ComplexNumber num1, ComplexNumber num2) {
  ComplexNumber result;
  result.real = num1.real * num2.real - num1.imag * num2.imag;
  result.imag = num1.real * num2.imag + num1.imag * num2.real;
  return result;
}

int main() {
  // Создание двух комплексных чисел
  ComplexNumber num1, num2;
  num1.real = 2.5;
  num1.imag = 3.7;
  num2.real = -1.8;
  num2.imag = 4.2;

  // Умножение комплексных чисел
  ComplexNumber result = multiplyComplex(num1, num2);

  // Вывод результата
  std::cout << "Результат умножения: " << result.real << " + " << result.imag << "i" << std::endl;

  return 0;
}