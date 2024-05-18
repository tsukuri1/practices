#include <iostream>
#include <sstream>
#include <cmath>

class RightTriangle {
private:
	double side1;
	double side2;

public:
	RightTriangle(double s1, double s2) : side1(s1), side2(s2) {}

	std::string getInfo() {
		std::stringstream ss;
		ss << "Катет1: " << side1 << ", Катет2: " << side2;
		return ss.str();
	}

	double computeArea() {
		return 0.5 * side1 * side2;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	double side1, side2;

	std::cout << "Катет1: ";
	std::cin >> side1;
	std::cout << "Катет2: ";
	std::cin >> side2;

	RightTriangle triangle(side1, side2);

	std::cout << "Информация: " << triangle.getInfo() << std::endl;

	std::cout << "Площадь: " << triangle.computeArea() << std::endl;

	return 0;
}