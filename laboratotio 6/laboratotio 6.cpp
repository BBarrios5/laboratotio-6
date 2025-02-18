#include <iostream>
#include <string>

using namespace std;

// Clase base que representa un Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    double precio;

public:
    // Constructor de la clase Vehiculo
    Vehiculo(string m, string mod, double p) : marca(m), modelo(mod), precio(p) {}

    // Metodo virtual para mostrar la informacion del vehiculo
    virtual void mostrarInfo() {
        cout << "Vehiculo: " << marca << " modelo " << modelo << ", precio: Q" << precio;
    }

    // Metodos para obtener los atributos privados
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    double getprecio() { return precio; }
};

// Clase Automovil que hereda de Vehiculo
class Automovil : public Vehiculo {
    int numPuertas;
public:
    // Constructor de Automovil, inicializa la cantidad de puertas
    Automovil(string m, string mod, double p, int puertas) : Vehiculo(m, mod, p), numPuertas(puertas) {}

    // Sobrescribe el metodo mostrarInfo para incluir las puertas
    void mostrarInfo() override {
        cout << "Vehiculo: " << marca << " modelo " << modelo << ", precio: Q" << precio << ", numero de puertas: " << numPuertas << endl;
    }
};

// Clase Motocicleta que hereda de Vehiculo
class Motocicleta : public Vehiculo {
    int cilindraje;
public:
    // Constructor de Motocicleta, inicializa el cilindraje
    Motocicleta(string m, string mod, double p, int cc) : Vehiculo(m, mod, p), cilindraje(cc) {}

    // Sobrescribe el metodo mostrarInfo para incluir el cilindraje
    void mostrarInfo() override {
        cout << "Motocicleta: " << marca << " modelo " << modelo << ", precio: Q" << precio << ", cilindraje: " << cilindraje << "cc" << endl;
    }
};

// Clase Camioneta que hereda de Vehiculo
class Camioneta : public Vehiculo {
    double capacidadCarga;
public:
    // Constructor de Camioneta, inicializa la capacidad de carga
    Camioneta(string m, string mod, double p, double carga) : Vehiculo(m, mod, p), capacidadCarga(carga) {}

    // Sobrescribe el metodo mostrarInfo para incluir la capacidad de carga
    void mostrarInfo() override {
        cout << "Camioneta: " << marca << " modelo " << modelo << ", precio: Q" << precio << ", capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

// Clase Cliente que representa a una persona que compra vehiculos
class Cliente {
    string nombre;
    int edad;
public:
    // Constructor que inicializa el nombre y edad del cliente
    Cliente(string n, int e) : nombre(n), edad(e) {}

    // Metodo que simula la compra de un vehiculo
    void comprarVehiculo(Vehiculo& v) {
        cout << nombre << " compro un " << v.getMarca() << " " << v.getModelo() << " en Q" << v.getprecio() << "!" << endl;
    }

    // Metodo para obtener el nombre del cliente
    string getnombre() { return nombre; }
};

// Clase Vendedor que representa a una persona que vende vehiculos
class Vendedor {
    string nombre;
public:
    // Constructor que inicializa el nombre del vendedor
    Vendedor(string n) : nombre(n) {}

    // Metodo que simula la venta de un vehiculo a un cliente
    void venderVehiculo(Vehiculo& v, Cliente& c) {
        cout << "Vendedor " << nombre << " vendio un " << v.getMarca() << " " << v.getModelo() << " a " << c.getnombre() << "!" << endl;
    }
};

int main() {
    // Creacion de varios vehiculos
    Automovil auto1("Lamborghini", "Aventador", 800000, 2);
    Automovil auto2("Ferrari", "Spider", 500000, 2);
    Automovil auto3("Ford", "Mustang GT40", 300000, 2);
    Motocicleta moto1("Ford", "Ranger", 100000, 250);
    Motocicleta moto2("Kawasaki", "Ninja", 50000, 600);
    Motocicleta moto3("Suzuki", "GSX", 30000, 750);
    Camioneta camioneta1("Kia", "Sportage", 200000, 1);
    Camioneta camioneta2("Chevrolet", "Tracker", 150000, 2);
    Camioneta camioneta3("Hyundai", "Tucson", 180000, 1.5);

    // Creacion de clientes
    Cliente cliente1("Fren", 20);
    Cliente cliente2("Fredy", 25);
    Cliente cliente3("Daniela", 20);

    // Creacion de vendedores
    Vendedor vendedor1("Gabriela");
    Vendedor vendedor2("Antonio");
    Vendedor vendedor3("Brayan");

    // Mostrar el inventario de vehiculos
    cout << "--- Inventario de Vehiculos ---" << endl;
    auto1.mostrarInfo();
    auto2.mostrarInfo();
    auto3.mostrarInfo();
    moto1.mostrarInfo();
    moto2.mostrarInfo();
    moto3.mostrarInfo();
    camioneta1.mostrarInfo();
    camioneta2.mostrarInfo();
    camioneta3.mostrarInfo();

    // Simulacion de ventas
    cout << "--- Ventas de Vehiculos ---" << endl;
    cliente1.comprarVehiculo(auto1);
    vendedor1.venderVehiculo(auto1, cliente1);

    cliente2.comprarVehiculo(moto2);
    vendedor2.venderVehiculo(moto2, cliente2);

    cliente3.comprarVehiculo(camioneta3);
    vendedor3.venderVehiculo(camioneta3, cliente3);

    return 0;
}
