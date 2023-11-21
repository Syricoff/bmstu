#include <iostream>
#include <cstring>

bool isOrd(char *word)
{
    int length = strlen(word);
    for (int i = 1; i < length; i++)
    {
        if (word[i] < word[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool hasRep(char *word)
{
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        int count = 0;
        for (int j = 0; j < length; j++)
        {
            if (word[j] == word[i])
            {
                count++;
            }
        }
        if (count < 2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char sentence[30];
    std::cin.getline(sentence, 30);
    const char delimiters[] = " ,.?!";          // Разделители для разделения строки на слова
    char *token = strtok(sentence, delimiters); // Разделение строки на слова

    while (token != nullptr)
    {
        if (isOrd(token) || hasRep(token))
        {
            std::cout << token << std::endl;
        }
        token = strtok(nullptr, delimiters);
        }
    return 0;
}