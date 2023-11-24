#include <iostream>
#include <cstring>

// Структура для описания важнейших исторических дат
struct HistoricalDate
{
    int year;        // год
    char event[100]; // событие
};

// Функция для сортировки структур по году
void sortByYear(HistoricalDate dates[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (dates[i].year > dates[j].year)
            {
                HistoricalDate temp = dates[i];
                dates[i] = dates[j];
                dates[j] = temp;
            }
        }
    }
}

// Функция для сортировки структур по событию
void sortByEvent(HistoricalDate dates[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (std::strcmp(dates[i].event, dates[j].event) > 0)
            {
                HistoricalDate temp = dates[i];
                dates[i] = dates[j];
                dates[j] = temp;
            }
        }
    }
}

// Функция для подсчета среднего интервала между датами
float averageInterval(HistoricalDate dates[], int N)
{
    int totalYears = 0;

    for (int i = 0; i < N - 1; i++)
    {
        totalYears += dates[i + 1].year - dates[i].year;
    }

    return (float)totalYears / (N - 1);
}

// Функция для определения наиболее часто встречающейся первой буквы в названии события
char mostFrequentFirstLetter(HistoricalDate dates[], int N)
{
    int letterCount[33] = {0};

    for (int i = 0; i < N; i++)
    {
        char firstLetter = std::tolower(dates[i].event[0]);
        if (std::isalpha(firstLetter))
        {
            letterCount[firstLetter - 'a']++;
        }
    }

    char mostFrequentLetter = 'a';
    int maxCount = letterCount[0];

    for (int i = 1; i < 33; i++)
    {
        if (letterCount[i] > maxCount)
        {
            mostFrequentLetter = 'a' + i;
            maxCount = letterCount[i];
        }
    }

    return mostFrequentLetter;
}

int main()
{
    // // Создание массива важнейших исторических дат
    // HistoricalDate dates[] = {
    //     {1776, "Declaration of Independence of the United States"},
    //     {1865, "Abolition of slavery in the United States"},
    //     {1945, "Victory over fascism in World War II"},
    //     {1917, "October Revolution"},
    //     {1969, "Moon landing"}};

    std::cout << "Введите количество дат" << std::endl;
    int n{};
    std::cin >> n;

    HistoricalDate dates[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Введите дату: ";
        std::cin >> dates[i].year;

        std::cout << "Введите описание: ";
        std::cin >> dates[i].event;
    }

    int size = sizeof(dates) / sizeof(dates[0]);

    // Тестирование функции sortByYear
    sortByYear(dates, size);
    std::cout << "Структуры, отсортированные по году:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << dates[i].year << " - " << dates[i].event << "\n";
    }

    // Тестирование функции sortByEvent
    sortByEvent(dates, size);
    std::cout << "\nСтруктуры, отсортированные по событию:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << dates[i].year << " - " << dates[i].event << "\n";
    }

    // Тестирование функции averageInterval
    float averageInt = averageInterval(dates, size);
    std::cout << "\nСредний интервал между датами: " << averageInt << " лет\n";

    // Тестирование функции mostFrequentFirstLetter
    char mostFreqLetter = mostFrequentFirstLetter(dates, size);
    std::cout << "\nНаиболее часто встречающаяся первая буква в названии события: " << mostFreqLetter << "\n";

    return 0;
}