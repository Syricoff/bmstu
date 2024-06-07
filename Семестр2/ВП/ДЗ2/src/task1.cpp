#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

int main()
{
    // 1. Создать объект multiset контейнера и заполнить его данными, тип которых int.
    std::multiset<int> mySet = {1, 2, 3, 4, 5, 2, 3, 1};

    // 2. Просмотреть контейнер.
    std::copy(mySet.begin(), mySet.end(), std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;

    // 3. Изменить контейнер, удалив из него одни элементы и заменив другие.
    mySet.erase(mySet.find(2));
    mySet.insert(6);

    // 4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
    std::cout << "Содержимое контейнера (с использованием итераторов): ";
    for (std::multiset<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
    std::multiset<int> mySet2 = {4, 5, 6, 7, 8};

    // 6. Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
    int n = 2;
    std::multiset<int>::iterator it = mySet.find(4);
    mySet.erase(++it, mySet.end());
    mySet.insert(mySet2.begin(), mySet2.end());

    // 7. Просмотреть первый и второй контейнеры.
    std::cout << "Содержимое первого контейнера: ";
    for (std::multiset<int>::iterator it = mySet.begin(); it != mySet.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Содержимое второго контейнера: ";
    for (std::multiset<int>::iterator it = mySet2.begin(); it != mySet2.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
