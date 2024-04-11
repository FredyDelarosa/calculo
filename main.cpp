#include <iostream>
#include <cmath>
#include <string>

class Expresion {
public:
    virtual ~Expresion() {}
    virtual double evaluar(double x) const = 0;
    virtual Expresion* derivar() const = 0;
};

class DerivadaLogaritmoNaturalPotencia : public Expresion {
    double u;
public:
    DerivadaLogaritmoNaturalPotencia(double u) : u(u) {}

    double evaluar(double x) const override {
        // La derivada de ln(u^x) respecto a x.
        return log(u);
    }

    Expresion* derivar() const override {
        return 0;
    }
};

class DerivadaLogaritmoBaseAPotencia : public Expresion {
    double base, u;
public:
    DerivadaLogaritmoBaseAPotencia(double base, double u) : base(base), u(u) {}

    double evaluar(double x) const override {
        // La derivada de log_base(u^x) respecto a x.
        return (log(u)  / log (base));
    }

    Expresion* derivar() const override {
        return 0;
    }
};

class LogaritmoNaturalPotencia : public Expresion {
    double u;
public:
    LogaritmoNaturalPotencia(double u) : u(u) {}

    double evaluar(double x) const {
        return log(pow(u, x));
    }

    Expresion* derivar() const {
        return new DerivadaLogaritmoNaturalPotencia(u);
    }
};

class LogaritmoBaseAPotencia : public Expresion {
    double base, u;
public:
    LogaritmoBaseAPotencia(double base, double u) : base(base), u(u) {}

    double evaluar(double x) const {
        return log(pow(u, x)) / log(base);
    }

    Expresion* derivar() const {
        return new DerivadaLogaritmoBaseAPotencia(base, u);
    }
};

int main() {
    std::string tipoLogaritmo;
    double base, u, x;

    std::cout << "Ingrese el tipo de logaritmo ('ln' para logaritmo natural, 'log' para logaritmo en base a): ";
    std::cin >> tipoLogaritmo;

    if (tipoLogaritmo == "log") {
        std::cout << "Ingrese la base del logaritmo: ";
        std::cin >> base;
    }
    std::cout << "Ingrese el valor de u (base del exponente): ";
    std::cin >> u;
    std::cout << "Ingrese el valor de x (exponente): ";
    std::cin >> x;

    Expresion* expr;
    if (tipoLogaritmo == "ln") {
        expr = new LogaritmoNaturalPotencia(u);
    } else {
        expr = new LogaritmoBaseAPotencia(base, u);
    }

    double resultado = expr->evaluar(x); // Almacena el resultado

    Expresion* derivada = expr->derivar();

    std::cout << "El valor de la funcion logaritmica en x=" << x << " es " << resultado << std::endl;
    std::cout << "La derivada de la funcion logaritmica en x=" << x << " es " << derivada->evaluar(x) << std::endl;

    // Mostrar la forma exacta del logaritmo
    if (tipoLogaritmo == "ln") {
        std::cout << "Resultado en su forma exacta: ln(" << pow(u, x) << ")" << std::endl;
    } else {
        std::cout << "Resultado en su forma exacta: log_" << base << "(" << pow(u, x) << ") = "
                  << "log(" << pow(u, x) << ")/log(" << base << ")" << std::endl;
    }

    delete expr;
    delete derivada;

    return 0;
}
