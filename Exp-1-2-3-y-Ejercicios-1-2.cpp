#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

template<typename T> class Posicion{
    public:
        T x, y;

        Posicion(T x, T y)
        {
            this->x = x;
            this->y = y;
        }
};
class PosicionFloat {
public:
    float x, y;

    PosicionFloat(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};


class PosicionInt {
public:
    int x, y;

    PosicionInt(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

template <class T>
double calcularDistancia(T punto1, T punto2)
{
    double distancia = sqrt(pow(punto2.x - punto1.x, 2) + pow(punto2.y - punto1.y, 2));
    return distancia;
}

template <class T>
double tiempoEstimado(T a, T b)
{
    const float KmPorMin = 0.8;  //Suponiendo que se conduce a 50Km/H
    double distancia = calcularDistancia(a, b);
    double tiempo = KmPorMin * distancia;
    return tiempo;
}

template <typename T>
void generarInforme(T dis, T tmp)
{
    cout << "--------------Informe de entrega--------------" << endl;
    cout << "Distancia: " << dis << endl;
    cout << "Tiempo: " << tmp << endl;
}

template <typename T>
void imprimirArreglo(const vector<T>& arreglo) {
    for (const T& elemento : arreglo) {
        cout << elemento << " ";
    }
    cout << endl;
}

template <typename T>
void ordenarArreglo(vector<T>& arreglo) {
    int n = arreglo.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                swap(arreglo[j], arreglo[j + 1]);
            }
        }
    }
}

template <class T>
class Ruta {
public:
    void asignarVehiculo(T vehiculo) {
        // Código para asignar el vehículo a la ruta
        cout << "Vehículo asignado: " << vehiculo << endl;
    }

    void planificarHorarios(T horarios) {
        // Código para planificar los horarios basados en los datos de horarios proporcionados
        cout << "Horarios planificados: " << horarios << endl;
    }

    template <typename U>
    void ordenarEntregas(vector<U>& entregas) {
        ordenarArreglo(entregas);
        cout << "Entregas ordenadas: ";
        imprimirArreglo(entregas);
    }
};

template <class T>
class Entrega {
public:
    void actualizarEstado(T estado) {
        cout << "Estado actualizado: " << estado << endl;
    }
};

template <typename T>
class SistemaGestionRutas {
public:
    SistemaGestionRutas() { }
    void mostrarMenu()
    {
        char opcion;
        while (true) {
            cout << "----------Sistema de Gestión de Rutas de Entrega----------" << endl;
            cout << "1. Asignar vehículo a una ruta" << endl;
            cout << "2. Planificar horarios de una ruta" << endl;
            cout << "3. Actualizar estado de una entrega" << endl;
            cout << "4. Calcular distancia de una entrega" << endl;
            cout << "5. Ordenar entregas" << endl;
            cout << "6. Salir" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion) {
                case '1':
                    asignarVehiculo();
                    break;
                case '2':
                    planificarHorarios();
                    break;
                case '3':
                    actualizarEstadoEntrega();
                    break;
                case '4':
                    calcularDistanciaEntrega<float>();
                    break;
                case '5':
                    ordenarEntregas();
                    break;
                case '6':
                    cout << "Saliendo del sistema..." << endl;
                    return;
                default:
                    cout << "Opción inválida. Intente nuevamente." << endl;
                    break;
            }
        }
    }

private:
    void asignarVehiculo()
    {
        T vehiculo;
        cout << "Ingrese el vehículo a asignar: ";
        cin >> vehiculo;
        Ruta<T> ruta;
        ruta.asignarVehiculo(vehiculo);
    }

    void planificarHorarios()
    {
        T horarios;
        cout << "Ingrese los horarios a planificar: ";
        cin >> horarios;
        Ruta<T> ruta;
        ruta.planificarHorarios(horarios);
    }

    void actualizarEstadoEntrega()
    {
        T estado;
        cout << "Ingrese el estado de la entrega: ";
        cin >> estado;
        Entrega<T> entrega;
        entrega.actualizarEstado(estado);
    }

    template <typename Y> 
    void calcularDistanciaEntrega()
    {
        Y x1, y1, x2, y2;
        cout << "Ingrese las coordenadas de la partida (x y): ";
        cin >> x1 >> y1;
        cout << "Ingrese las coordenadas de la entrega (x y): ";
        cin >> x2 >> y2;
        Posicion<Y> puntoPartida(x1, y1);
        Posicion<Y> puntoEntrega(x2, y2);
        double distancia = calcularDistancia(puntoPartida, puntoEntrega);
        cout << "Distancia de entrega: " << distancia << endl;
    }

    void ordenarEntregas()
    {
        vector<T> entregas;
        int n;
        cout << "Ingrese el número de entregas: ";
        cin >> n;
        cout << "Ingrese las entregas: ";
        for (int i = 0; i < n; i++) {
            T entrega;
            cin >> entrega;
            entregas.push_back(entrega);
        }
        Ruta<T> ruta;
        ruta.ordenarEntregas(entregas);
    }
};


int main()
{
    PosicionFloat posa(2.0, 3.0);
    PosicionFloat posb(5.0, 1.0);

    PosicionInt posaint(2, 3);
    PosicionInt posbint(5, 1);

    double distancia = calcularDistancia(posa, posb);
    double tiempo = tiempoEstimado(posa, posb);

    int distanciaInt = calcularDistancia(posaint, posbint);
    int tiempoInt = tiempoEstimado(posaint, posbint);
    generarInforme(distanciaInt, tiempoInt);
    generarInforme(distancia, tiempo);
    return 0;

    Ruta<string> ruta1;
    ruta1.asignarVehiculo("Camión");
    ruta1.planificarHorarios("Lunes a viernes");

    Entrega<PosicionFloat> entrega1;
    PosicionFloat puntoPartida(2.0, 3.0);
    PosicionFloat puntoEntrega(5.0, 1.0);

    double distancia1 = calcularDistancia(puntoPartida, puntoEntrega);
    cout << "Distancia de entrega: " << distancia1 << endl;

    SistemaGestionRutas<string>  sistema;
    sistema.mostrarMenu();
    return 0;
}
