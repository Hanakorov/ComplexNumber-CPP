#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Конструкторы
    ComplexNumber() : real(0), imag(0) {}
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    // Фабричный метод для полярной формы
    static ComplexNumber fromPolar(double r, double theta) {
        return ComplexNumber(r * cos(theta), r * sin(theta));
    }

    // Сложение комплексных чисел
    inline ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imag + other.imag);
    }

    // Вычитание комплексных чисел
    inline ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imag - other.imag);
    }

    // Умножение комплексных чисел
    inline ComplexNumber operator*(const ComplexNumber& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return ComplexNumber(r, i);
    }

    // Деление комплексных чисел
    inline ComplexNumber operator/(const ComplexNumber& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) {
            throw std::runtime_error("Деление на ноль невозможно");
        }
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return ComplexNumber(r, i);
    }

    // Модуль комплексного числа
    inline double modulus() const {
        return sqrt(real * real + imag * imag);
    }

    // Аргумент (угол) комплексного числа
    inline double argument() const {
        return atan2(imag, real);
    }

    // Конъюгат комплексного числа
    inline ComplexNumber conjugate() const {
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
    inline bool operator==(const ComplexNumber& other) const {
        return real == other.real && imag == other.imag;
    }

    inline bool operator!=(const ComplexNumber& other) const {
        return !(*this == other);
    }

    inline bool operator<(const ComplexNumber& other) const {
        return modulus() < other.modulus();
    }

    inline bool operator>(const ComplexNumber& other) const {
        return modulus() > other.modulus();
    }

    // Преобразование в строку
    std::string str() const {
        std::ostringstream oss;
        if (imag >= 0)
            oss << real << " + " << imag << "i";
        else
            oss << real << " - " << -imag << "i";
        return oss.str();
    }

    // Преобразование в полярную форму (строка)
    std::string toPolarString() const {
        std::ostringstream oss;
        oss << modulus() << "(cos(" << argument() << ") + i sin(" << argument() << "))";
        return oss.str();
    }

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.str();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ComplexNumber& c) {
        std::cout << "Введите действительную часть: ";
        is >> c.real;
        std::cout << "Введите мнимую часть: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    ComplexNumber a(3, 4);
    ComplexNumber b(1, -2);

    std::cout << "Комплексное число a: " << a << std::endl;
    std::cout << "Комплексное число b: " << b << std::endl;

    std::cout << "Сложение: " << (a + b) << std::endl;
    std::cout << "Вычитание: " << (a - b) << std::endl;
    std::cout << "Умножение: " << (a * b) << std::endl;
    try {
        std::cout << "Деление: " << (a / b) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Модуль a: " << a.modulus() << std::endl;
    std::cout << "Аргумент a: " << a.argument() << std::endl;

    std::cout << "Конъюгат a: " << a.conjugate() << std::endl;
    std::cout << "Полярная форма a: " << a.toPolarString() << std::endl;

    int n = 2;
    std::cout << "a в степени " << n << ": " << a.power(n) << std::endl;

    std::cout << "Квадратный корень из a: " << a.sqrt() << std::endl;

    ComplexNumber c;
    std::cin >> c;
    std::cout << "Введенное комплексное число: " << c << std::endl;

    return 0;
}
