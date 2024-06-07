#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    double price;

public:
    Book(const std::string& title, const std::string& author, int year, double price)
        : title(title), author(author), year(year), price(price) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }

    bool operator>(const Book& other) const { return price > other.price; }
    bool operator<(const Book& other) const { return price < other.price; }

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author: " << book.author << ", Year: " << book.year << ", Price: " << book.price;
    return os;
}

int main() {
    // 1. Создать multiset, содержащий объекты пользовательского типа.
    std::multiset<Book, std::greater<Book>> bookSet = {
        Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, 12.99),
        Book("To Kill a Mockingbird", "Harper Lee", 1960, 9.99),
        Book("1984", "George Orwell", 1949, 7.99),
        Book("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 1997, 14.99)
    };

    // 2. Отсортировать его по убыванию элементов.
    // Сортировка по убыванию происходит благодаря использованию std::greater<Book> в качестве сравнивающего предиката.

    // 3. Просмотреть контейнер.
    std::cout << "Содержимое контейнера (отсортировано по убыванию):" << std::endl;
    for (const auto& book : bookSet) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // 4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
    auto it = std::find_if(bookSet.begin(), bookSet.end(), [](const Book& book) {
        return book.getYear() >= 1950;
    });
    if (it != bookSet.end()) {
        std::cout << "Найдена книга, соответствующая условию: " << *it << std::endl;
    } else {
        std::cout << "Книга, соответствующая условию, не найдена." << std::endl;
    }
    std::cout << std::endl;

    // 5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер. Тип второго контейнера vector.
    std::vector<Book> booksToMove;
    std::copy_if(bookSet.begin(), bookSet.end(), std::back_inserter(booksToMove), [](const Book& book) {
        return book.getPrice() > 10.0;
    });

    // 6. Просмотреть второй контейнер.
    std::cout << "Содержимое второго контейнера (booksToMove):" << std::endl;
    for (const auto& book : booksToMove) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // 7. Отсортировать первый и второй контейнеры по возрастанию элементов.
    std::sort(booksToMove.begin(), booksToMove.end());

    // 8. Просмотреть их.
    std::cout << "Содержимое первого контейнера (bookSet), отсортированного по возрастанию:" << std::endl;
    for (const auto& book : bookSet) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Содержимое второго контейнера (booksToMove), отсортированного по возрастанию:" << std::endl;
    for (const auto& book : booksToMove) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // 9. Получить третий контейнер путем слияния первых двух.
    std::multiset<Book> mergedSet;
    mergedSet.insert(bookSet.begin(), bookSet.end());
    mergedSet.insert(booksToMove.begin(), booksToMove.end());

    // 10. Просмотреть третий контейнер.
    std::cout << "Содержимое третьего контейнера (mergedSet):" << std::endl;
    for (const auto& book : mergedSet) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // 11. Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
    int count = std::count_if(mergedSet.begin(), mergedSet.end(), [](const Book& book) {
        return book.getYear() >= 1950;
    });
    std::cout << "Количество элементов, удовлетворяющих условию (год >= 1950): " << count << std::endl;

    // 12. Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.
    auto found = std::find_if(mergedSet.begin(), mergedSet.end(), [](const Book& book) {
        return book.getAuthor() == "J.K. Rowling";
    });
    if (found != mergedSet.end()) {
        std::cout << "Элемент, удовлетворяющий условию (автор 'J.K. Rowling'), найден." << std::endl;
    } else {
        std::cout << "Элемент, удовлетворяющий условию (автор 'J.K. Rowling'), не найден." << std::endl;
    }

    return 0;
}
