/*

1. Опишите основные приёмы ввода-вывода данных с/на консоль(и) и в/из файл(а) на языке С++.
2. Проиллюстрируйте работу пользовательской функции, возвращающей в качестве значения структуру.
3. Используя подпрограммы поиска минимального и максимального значения одномерного массива,
запишите в текстовый файл минимальный и максимальный элемент каждой последовательности
целых чисел, хранящихся в бинарном файле.

*/

#include <iostream>
#include <fstream>

void fillBinFile(int n)
{
    std::ofstream binaryFile("input.bin", std::ios::binary);
    for (int i = 0; i < n; i++)
    {
        int *buf = new int[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> buf[j];
        }
    binaryFile.write((char*)buf, sizeof(buf));
    delete[] buf;
    }
    binaryFile.close();
}


int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    fillBinFile(2);

    std::ifstream binaryFile("input.bin", std::ios::binary);
    std::ofstream textFile("output.txt");

    if (!binaryFile.is_open() || !textFile.is_open())
    {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    const int arraySize = 2;
    int buffer[arraySize];

    while (binaryFile.read(reinterpret_cast<char *>(buffer), sizeof(buffer)))
    {
        int min = findMin(buffer, arraySize);
        int max = findMax(buffer, arraySize);
        textFile << "Минимальный элемент: " << min << ", Максимальный элемент: " << max << std::endl;
    }

    binaryFile.close();
    textFile.close();

    return 0;
}
