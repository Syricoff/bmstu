#include <iostream>
#include <cstdlib>

const int MATRIX_SIZE = 17;

int matrix[MATRIX_SIZE][MATRIX_SIZE];
int numberOfRow = 0;
bool tempOfNegative, flag = true;

void generateRandomMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % 25 - 12;
        }
    }
}

void printMatrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int calculateDigitSum(int number)
{
    return abs(number / 10 + number % 10);
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
    std::cin >> numberOfRow;
    for (int j = 1; j < MATRIX_SIZE; j++)
    {
        if (isNegative(matrix[numberOfRow][j]) == isNegative(matrix[numberOfRow][j - 1]))
        {
            flag = false;
            break;
        }
    }
    std::cout << flag << std::endl;
}

void findFirstZeroElement()
{
    flag = true;
    for (int i = MATRIX_SIZE / 3; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                std::cout << i << " " << j << std::endl;
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main()
{
    generateRandomMatrix();
    modifyMatrix();
    checkRowForAlternatingSigns();
    findFirstZeroElement();
    return 0;
}