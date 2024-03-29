#include <iostream>
#include <cmath>
#include <string>
#include <functional>

// Función para derivar ln(x)
double derivarLn(double x) {
    if (x <= 0) {
        std::cerr << "Error: x debe ser mayor que 0." << std::endl;
        return NAN;
    }
    return 1 / x;
}

// Función para derivar log_b(x), donde b es la base
double derivarLogBase(double base, double x) {
    if (x <= 0 || base <= 0 || base == 1) {
        std::cerr << "Error: x y la base deben ser mayores que 0 y la base no puede ser 1." << std::endl;
        return NAN;
    }
    return 1 / (x * log(base));
}

// Función principal
int main() {
    std::string funcion;
    double base, x;

    std::cout << "Introduce la función a derivar (ln o log): ";
    std::cin >> funcion;

    std::cout << "Introduce el valor de x: ";
    std::cin >> x;

    if (funcion == "ln") {
        std::cout << "La derivada de ln(x) en x = " << x << " es " << derivarLn(x) << std::endl;
    } else if (funcion == "log") {
        std::cout << "Introduce la base del logaritmo: ";
        std::cin >> base;
        std::cout << "La derivada de log_" << base << "(x) en x = " << x << " es " << derivarLogBase(base, x) << std::endl;
    } else {
        std::cout << "Función no soportada." << std::endl;
    }

    return 0;
}

