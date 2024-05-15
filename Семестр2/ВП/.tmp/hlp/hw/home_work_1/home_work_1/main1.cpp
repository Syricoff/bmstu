#include <SFML/Graphics.hpp>
int main()
{
    // создаём окно
    sf::RenderWindow app(sf::VideoMode(800, 600, 32),
                         "Hello World - SFML");
    // основной цикл
    while (app.isOpen())
    {
        // проверка события (нажатие кнопки, закрытие окна и т.д.)
        sf::Event event;
        while (app.pollEvent(event))
        {
            // если событие "закрытие окна":
            if (event.type == sf::Event::Closed)
                // закрываем окно
                app.close();
        }
        // очистка экрана и заливка его синим цветом
        app.clear(sf::Color(0, 0, 255));
        // отображаем на экран
        app.display();
    }
    return 0;
}
