#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Конструктор
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    // Сложение комплексных чисел
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Вычитание комплексных чисел
    ComplexNumber operator-(const ComplexNumber& other) {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Умножение комплексных чисел
    ComplexNumber operator*(const ComplexNumber& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return ComplexNumber(r, i);
    }

    // Деление комплексных чисел
    ComplexNumber operator/(const ComplexNumber& other) {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return ComplexNumber(r, i);
    }

    // Модуль комплексного числа
    double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    // Аргумент (угол) комплексного числа
    double argument() const {
        return atan2(imag, real);
    }

    // Конъюгат комплексного числа
    ComplexNumber conjugate() const {
        return ComplexNumber(real, -imag);
    }

    // Возведение в степень
    ComplexNumber power(int n) const {
        double mod = modulus();
        double arg = argument();
        double r = pow(mod, n);
        double i = n * arg;
        return ComplexNumber(r * cos(i), r * sin(i));
    }

    // Извлечение квадратного корня
    ComplexNumber sqrt() const {
        double mod = sqrt(modulus());
        double arg = argument() / 2;
        return ComplexNumber(mod * cos(arg), mod * sin(arg));
    }

    // Сравнение комплексных чисел
    bool operator==(const ComplexNumber& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator!=(const ComplexNumber& other) const {
        return !(*this == other);
    }

    bool operator<(const ComplexNumber& other) const {
        return modulus() < other.modulus();
    }

    bool operator>(const ComplexNumber& other) const {
        return modulus() > other.modulus();
    }

    // Вывод комплексного числа
    std::string str() const {
        std::ostringstream oss;
        if (imag >= 0)
            oss << real << " + " << imag << "i";
        else
            oss << real << " - " << -imag << "i";
        return oss.str();
    }

    // Вывод в полярной форме
    void displayPolar() const {
        double r = modulus();
        double theta = argument();
        std::cout << "Полярная форма: " << r << "(cos(" << theta << ") + i sin(" << theta << "))" << std::endl;
    }
};

int main() {
    ComplexNumber a(3, 4);  // Комплексное число 3 + 4i
    ComplexNumber b(1, -2); // Комплексное число 1 - 2i

    std::cout << "Комплексное число a: " << a.str() << std::endl;
    std::cout << "Комплексное число b: " << b.str() << std::endl;

    // Операции
    std::cout << "Сложение: " << (a + b).str() << std::endl;
    std::cout << "Вычитание: " << (a - b).str() << std::endl;
    std::cout << "Умножение: " << (a * b).str() << std::endl;
    std::cout << "Деление: " << (a / b).str() << std::endl;

    // Модуль и аргумент
    std::cout << "Модуль a: " << a.modulus() << std::endl;
    std::cout << "Аргумент a: " << a.argument() << std::endl;

    // Конъюгат
    std::cout << "Конъюгат a: " << a.conjugate().str() << std::endl;

    // Полярная форма
    a.displayPolar();

    // Сравнение
    std::cout << "a == b? " << (a == b ? "Да" : "Нет") << std::endl;
    std::cout << "a > b? " << (a > b ? "Да" : "Нет") << std::endl;

    // Возведение в степень
    int n = 2;
    std::cout << "a в степени " << n << ": " << a.power(n).str() << std::endl;

    // Извлечение квадратного корня
    std::cout << "Квадратный корень из a: " << a.sqrt().str() << std::endl;

    return 0;
}
