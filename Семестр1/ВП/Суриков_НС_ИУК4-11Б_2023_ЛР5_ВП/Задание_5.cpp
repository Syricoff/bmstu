#include <iostream>
#include <cstring>

int main()
{
    char str[100];
    std::cin.getline(str, 100);
    const char delimiters[] = " \t\n\r,.?!";
    char *token = std::strtok(str, delimiters);
    int count = 0;

    while (token != nullptr)
    {
        int len = std::strlen(token);
        int zCount = 0;

        for (int i = 0; i < len; i++)
        {
            if (token[i] == 'z')
            {
                zCount++;
            }
        }
        if (zCount == 2)
        {
            count++;
        }

        token = std::strtok(nullptr, delimiters);
    }

    std::cout << count << std::endl;

    return 0;
}