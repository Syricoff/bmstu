#include "./Car/Car.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <vector>

using namespace SNS;

int main()
{
    // 1. Создать объект multiset контейнера и заполнить его данными, тип которых пользовательский.
    std::multiset<Car, std::greater<Car>> carSet = {
        SNS::Car("Tesla", 60000, 2020, "Электрический автомобиль", "Autopilot, Regenerative Braking"),
        SNS::Car("BMW", 50000, 2019, "Премиум-седан", "Turbo, Leather Seats"),
        SNS::Car("Toyota", 30000, 2018, "Надежный семейный автомобиль", "Fuel Efficient, Spacious"),
        SNS::Car("Honda", 25000, 2017, "Компактный городской автомобиль", "Reliable, Fuel Efficient")};

    // 2. Просмотреть контейнер.
    std::cout << "Содержимое контейнера: " << std::endl;
    for (const auto &car : carSet)
    {
        std::cout << car << std::endl;
    }
    std::cout << std::endl;

    // 3. Изменить контейнер, удалив из него одни элементы и заменив другие.
    auto it = carSet.find(Car("BMW", 50000, 2019, "Премиум-седан", "Turbo, Leather Seats"));
    if (it != carSet.end())
    {
        carSet.erase(it);
    }
    carSet.insert(Car("Audi", 45000, 2020, "Премиум-седан", "Quattro, LED Lights"));

    // 4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
    std::cout << "Содержимое контейнера (с использованием итераторов): " << std::endl;
    for (auto it = carSet.begin(); it != carSet.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    // 5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
    std::multiset<Car, std::greater<Car>> carSet2 = {
        Car("Hyundai", 20000, 2016, "Надежный компактный автомобиль", "Fuel Efficient, Affordable"),
        Car("Subaru", 35000, 2018, "Полноприводный автомобиль", "AWD, Boxer Engine"),
        Car("Nissan", 28000, 2017, "Городской кроссовер", "Spacious, Stylish")};

    // 6. Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
    int n = 1;
    it = carSet.find(Car("Toyota", 30000, 2018, "Надежный семейный автомобиль", "Fuel Efficient, Spacious"));
    if (it != carSet.end())
    {
        carSet.erase(++it, carSet.end());
    }
    carSet.insert(carSet2.begin(), carSet2.end());

    // 7. Просмотреть первый и второй контейнеры.
    std::cout << "Содержимое первого контейнера: " << std::endl;
    for (const auto &car : carSet)
    {
        std::cout << car << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Содержимое второго контейнера: " << std::endl;
    for (const auto &car : carSet)
    {
        std::cout << car << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
