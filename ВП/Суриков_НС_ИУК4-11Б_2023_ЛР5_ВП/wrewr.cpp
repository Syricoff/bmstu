#include <iostream>
#include <cstring>

const int MAX_SIZE = 100;

void encryptText(const char* text, char matrix[][MAX_SIZE], int size) {
    int row = 0, col = 0;
    int direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up

    for (int i = 0; i < strlen(text); i++) {
        matrix[row][col] = text[i];

        switch (direction) {
            case 0: // right
                if (col < size - 1 && matrix[row][col + 1] == '\0') {
                    col++;
                } else {
                    direction = 1; // change direction to down
                    row++;
                }
                break;
            case 1: // down
                if (row < size - 1 && matrix[row + 1][col] == '\0') {
                    row++;
                } else {
                    direction = 2; // change direction to left
                    col--;
                }
                break;
            case 2: // left
                if (col > 0 && matrix[row][col - 1] == '\0') {
                    col--;
                } else {
                    direction = 3; // change direction to up
                    row--;
                }
                break;
            case 3: // up
                if (row > 0 && matrix[row - 1][col] == '\0') {
                    row--;
                } else {
                    direction = 0; // change direction to right
                    col++;
                }
                break;
        }
    }
}

void decryptText(char matrix[][MAX_SIZE], int size) {
    int row = size / 2, col = size / 2;
    int direction = 0; // 0 - right, 1 - down, 2 - left, 3 - up

    for (int i = 0; i < size * size; i++) {
        std::cout << matrix[row][col];

        switch (direction) {
            case 0: // right
                if (col < size - 1 && matrix[row][col + 1] != '\0') {
                    col++;
                } else {
                    direction = 1; // change direction to down
                    row++;
                }
                break;
            case 1: // down
                if (row < size - 1 && matrix[row + 1][col] != '\0') {
                    row++;
                } else {
                    direction = 2; // change direction to left
                    col--;
                }
                break;
            case 2: // left
                if (col > 0 && matrix[row][col - 1] != '\0') {
                    col--;
                } else {
                    direction = 3; // change direction to up
                    row--;
                }
                break;
            case 3: // up
                if (row > 0 && matrix[row - 1][col] != '\0') {
                    row--;
                } else {
                    direction = 0; // change direction to right
                    col++;
                }
                break;
        }
    }
}

int main() {
    char text[MAX_SIZE];
    std::cout << "Введите текст для шифрования: ";
    std::cin.getline(text, MAX_SIZE);

    int size = strlen(text);
    char matrix[MAX_SIZE][MAX_SIZE];
    memset(matrix, '\0', sizeof(matrix));

    encryptText(text, matrix, size);
    std::cout << "Зашифрованный текст: ";
    decryptText(matrix, size);

    return 0;
}