#include <SFML/Graphics.hpp>
#include <random>

// Функция для генерации случайных координат окружности
std::pair<int, int> generateRandomCirclePosition(const sf::RenderWindow &window, int circleRadius)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(circleRadius, window.getSize().x - 3 * circleRadius);
    std::uniform_int_distribution<> distY(circleRadius, window.getSize().y - 3 * circleRadius);

    return std::make_pair(distX(gen), distY(gen));
}

// Функция для отрисовки квадратов по периметру экрана
void drawSquares(sf::RenderWindow &window, int squareSize)
{
    for (int i = 0; i < (window.getSize().x - squareSize) / squareSize; ++i)
    {
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        square.setPosition(i * squareSize, 0);
        square.setFillColor(sf::Color(i * 255 / ((window.getSize().x - squareSize) / squareSize), 0, 0));
        window.draw(square);

        square.setPosition(i * squareSize, window.getSize().y - squareSize);
        square.setFillColor(sf::Color(i * 255 / ((window.getSize().x - squareSize) / squareSize), i * 255 / ((window.getSize().x - squareSize) / squareSize), 0));
        window.draw(square);
    }

    for (int j = 0; j < (window.getSize().y - squareSize) / squareSize; ++j)
    {
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        square.setPosition(0, j * squareSize);
        square.setFillColor(sf::Color(0, j * 255 / ((window.getSize().y - squareSize) / squareSize), 0));
        window.draw(square);

        square.setPosition(window.getSize().x - squareSize, j * squareSize);
        square.setFillColor(sf::Color(0, j * 255 / ((window.getSize().y - squareSize) / squareSize), j * 255 / ((window.getSize().y - squareSize) / squareSize)));
        window.draw(square);
    }
}

// Функция для отрисовки окружности
void drawCircle(sf::RenderWindow &window, int circleX, int circleY, int circleRadius)
{
    sf::CircleShape circle(circleRadius);
    circle.setPosition(circleX, circleY);
    circle.setFillColor(sf::Color::Red);
    window.draw(circle);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    const int squareSize = 50;                       // Размеры квадратов
    const int circleRadius = 50;                     // Радиус окружности
    const sf::Time visibilityTime(sf::seconds(1)); // Время видимости окружности
    int circleX{50}, circleY{50};                    // Координаты окружности
    sf::Clock visibilityClock;                       // Время последнего изменения видимости
    bool isCircleVisible = true;                     // Флаг видимости окружности

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        drawSquares(window, squareSize);
        // Изменение видимости окружности
        if (visibilityClock.getElapsedTime() >= visibilityTime)
        {
            isCircleVisible = !isCircleVisible;
            visibilityClock.restart();

            // Изменение положения окружности при появлении
            if (isCircleVisible)
            {
                std::tie(circleX, circleY) = generateRandomCirclePosition(window, circleRadius);
            }
        }
        if (isCircleVisible)
        {
            drawCircle(window, circleX, circleY, circleRadius);
        }
        window.display();
    }

    return 0;
}
