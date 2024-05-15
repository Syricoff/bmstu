#include <iostream>
#include <cstdlib>

const int MATRIX_SIZE = 17;

int matrix[MATRIX_SIZE][MATRIX_SIZE];

void generateRandomMatrix()
{
    for (auto &i : matrix)
    {
        for (int &j : i)
        {
            j = std::rand() % 25 - 12;
        }
    }
}

void printMatrix()
{
    for (auto &i : matrix)
    {
        for (int j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int calculateDigitSum(int number)
{
    number = abs(number);
    return number / 10 + number % 10;
}

void modifyMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] += calculateDigitSum(matrix[i][MATRIX_SIZE - 1 - i]);
        }
    }
}

bool isNegative(int number)
{
    return number < 0;
}

void checkRowForAlternatingSigns()
{
    int numberOfRow{};
    std::cin >> numberOfRow;
    for (int j = 1; j < MATRIX_SIZE; j++)
    {
        if (isNegative(matrix[numberOfRow][j]) == isNegative(matrix[numberOfRow][j - 1]))
        {
            std::cout << "Строка содержит знакочередующиеся элементы" << std::endl;
            break;
        }
    }
}

void findFirstZeroElement()
{
    for (int i = MATRIX_SIZE / 3; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                std::cout << i << " " << j << std::endl;
                return;
            }
        }
    }
}

int main()
{
    generateRandomMatrix();
    printMatrix();
    modifyMatrix();
    checkRowForAlternatingSigns();
    findFirstZeroElement();
    printMatrix();
    return 0;
}