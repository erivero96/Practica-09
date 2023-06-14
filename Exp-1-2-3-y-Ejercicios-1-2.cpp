#include <iostream>
#include <cmath>

using namespace std;

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
double  tiempoEstimado(T a, T b)
{
    const float KmPorMin = 0.8;  //Suponiendo que se conduce a 50Km/H
    double distancia = calcularDistancia(a,b);
    double tiempo = KmPorMin*distancia;
    return tiempo;
}

template <typename T> void generarInforme(T dis, T tmp)
{
    cout << "--------------Informe de entrega--------------" << endl;
    cout << "Distancia: " << dis << endl;
    cout << "Tiempo: " << tmp << endl;
}

#include <iostream>
#include <cmath>

using namespace std;

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
};

template <class T>
class Entrega {
public:
    void actualizarEstado(T estado) {
        cout << "Estado actualizado: " << estado << endl;
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

    double distancia = calcularDistancia(puntoPartida, puntoEntrega);
    cout << "Distancia de entrega: " << distancia << endl;
}
