#include <iostream>
#include <cmath>
#include <string>

class Rectangle {
private:
    int x1, y1, x2, y2;

public:
    // Конструктор по умолчанию
    Rectangle() : x1(0), y1(0), x2(0), y2(0) {}

    // Конструктор перезагрузки с параметрами
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    // Деструктор
    ~Rectangle() {
        std::cout << "Объект уничтожен\n";
    }

    // Функции обработки данных
    double computeDiagonalLength() {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }

    std::string getInfo() {
        return "Координаты: (" + std::to_string(x1) + ", " + std::to_string(y1) + "), (" +
            std::to_string(x2) + ", " + std::to_string(y2) + ")";
    }

    // Функция для отображения прямоугольника и его диагонали на консоли
    void drawRectangle() {
        int width = std::abs(x2 - x1);
        int height = std::abs(y2 - y1);

        // Отображение прямоугольника
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }

        // Отображение диагонали
        double diagonal = computeDiagonalLength();
        int diagonalLength = static_cast<int>(diagonal);
        if (diagonalLength > 0) {
            if (width > height) {
                for (int i = 0; i < height; ++i) {
                    std::cout << std::string(i, ' ') << "*\n";
                }
            }
            else {
                for (int i = 0; i < width; ++i) {
                    std::cout << std::string(i, ' ') << "*\n";
                }
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объектов
    Rectangle rect1(2, 2, 8, 5);

    // Вывод информации о прямоугольнике
    std::cout << "Информация: " << rect1.getInfo() << std::endl;

    // Отображение прямоугольника и его диагонали на консоли
    std::cout << "Прямоугольник:\n";
    rect1.drawRectangle();

    return 0;
}