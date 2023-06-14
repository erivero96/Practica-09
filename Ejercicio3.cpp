#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Recipiente {
private:
    vector<T> elementos;

public:
    void agregarElemento(const T& elemento) {
        elementos.push_back(elemento);
    }

    void mostrarElementos() {
        for (T& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
};

int main() {
    Recipiente<int> recipienteInt;
    recipienteInt.agregarElemento(1);
    recipienteInt.agregarElemento(2);
    cout << "Enteros: ";
    recipienteInt.mostrarElementos();

    Recipiente<string> recipienteString;
    recipienteString.agregarElemento("Makanaky");
    recipienteString.agregarElemento("Chupetin");
    cout << "Cadenas: ";
    recipienteString.mostrarElementos();

    Recipiente<double> recipienteDouble;
    recipienteDouble.agregarElemento(3.14);
    recipienteDouble.agregarElemento(2.71);
    cout << "Flotantes: ";
    recipienteDouble.mostrarElementos();

    return 0;
}
