#include <iostream>
#include <cstring>

void REVERSE(char* str, int start, int end)
{
    if (start >= end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    REVERSE(str, start + 1, end - 1);
}

int main()
{
    char str[100];
    std::cin.getline(str, 100);

    REVERSE(str, 0, strlen(str) - 1);
    std::cout << str << std::endl;
    return 0;
}