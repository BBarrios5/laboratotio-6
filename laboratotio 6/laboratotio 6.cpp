#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
protected:
	string marca;
	string modelo;
	double precio;

public:
	Vehiculo(string m, string mod, double p) : marca(m), modelo(mod), precio(p) {}
	virtual void mostrarInfo() {
		cout << "vehiculo: " << marca << " modelo " << modelo << ", precio: Q" << precio;
	}
	string getMarca() { return marca; }
	string getModelo() { return modelo; }
	double getprecio() { return precio; }
};

class Automovil : public Vehiculo {
	int numPuertas;
public:
	Automovil(string m, string mod, double p, int puertas) : Vehiculo(m, mod, p), numPuertas(puertas) {}
	void mostrarInfo() override {
		cout << "vehiculo: " << marca << " modelo " << modelo << ", precio: Q" << precio << ", numero de puertas: " << numPuertas << endl;

	}
};

class Motocicleta : public Vehiculo {
	int cilindraje;
public:
	Motocicleta(string m, string mod, double p, int cc) : Vehiculo(m, mod, p), cilindraje(cc) {}
	void mostrarInfo() override {
		cout << "motocicleta: " << marca << " modelo " << modelo << ", precio: Q" << precio << ", cilindraje: " << cilindraje << "cc" << endl;

	}
};

class Camioneta : public Vehiculo {
	int capacidadCarga;
public:
	Camioneta(string m, string mod, double p, double carga) : Vehiculo(m, mod, p), capacidadCarga(carga) {}
	void mostrarInfo() override {
		cout << "Camioneta:" << marca << " modelo " << modelo << ", precio: Q" << precio << ", capacidad de carga: " << capacidadCarga << " toneladas" << endl;

	}
};

class Cliente {
	string nombre;
	int edad;
public:
	Cliente(string n, int e) : nombre(n), edad(e) {}
	void comprarVehiculo(Vehiculo& v) {
		cout << nombre << " compro un " << v.getMarca() << " " << v.getModelo() << " en Q" << v.getprecio() << "!" << endl;
	}
	string getnombre() { return nombre; }
};

class Vendedor {
	string nombre;
public:
	Vendedor(string n) : nombre(n) {}
	void venderVehiculo(Vehiculo& v, Cliente& c) {
		cout << " Vendedor " << nombre << " vendio un " << v.getMarca() << " " << v.getModelo() << " a " << c.getnombre() << " ! " << endl;
	}
};

int main() {
	Automovil auto1("lanborghini", "aventador", 800000, 2);
	Automovil auto2("ferrarri", "spider", 500000, 2);
	Automovil auto3("Fors", "mustang GT40", 300000, 2);
	Motocicleta moto1("Ford", "ranger", 100000, 250);
	Motocicleta moto2("kawasaki", "ninja", 50000, 600);
	Motocicleta moto3("suzuki", "gsx", 30000, 750);
	Camioneta camioneta1("kia", "sportage", 200000, 1);
	Camioneta camioneta2("chevrolet", "tracker", 150000, 2);
	Camioneta camioneta3("hyundai", "tucson", 180000, 1.5);

	Cliente cliente1("fren", 20);
	Cliente cliente2("Fredy", 25);
	Cliente cliente3("Daniela", 20);

	Vendedor vendedor1("Gabriela");
	Vendedor Vendedor2("Antonio");
	Vendedor vendedor3("Brayan");

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
		
	cout << "--- Ventas de Vehiculos ---" << endl;

	cliente1.comprarVehiculo(auto1);
	vendedor1.venderVehiculo(auto1, cliente1);

	cliente2.comprarVehiculo(moto2);
	Vendedor2.venderVehiculo(moto2, cliente2);

	cliente3.comprarVehiculo(camioneta3);
	vendedor3.venderVehiculo(camioneta3, cliente3);

	return 0;
}