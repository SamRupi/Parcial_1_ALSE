#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};
double calcularDistanciaMasCercana(
    Point puntos[],
    int n,
    const Point &pUsuario,
    int &indiceMasCercano
) {
    double distanciaMinima = 0;

    for (int i = 0; i < n; i++) {

        double dx = puntos[i].x - pUsuario.x;
        double dy = puntos[i].y - pUsuario.y;

        double distancia = sqrt(dx * dx + dy * dy);

        if (i == 0) {
            distanciaMinima = distancia;
            indiceMasCercano = 0;
        } else {
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                indiceMasCercano = i;
            }
        }
    }

    return distanciaMinima;
}

int main() {

    int n;

    cout << "Cuantos puntos desea ingresar? ";
    cin >> n;

    Point puntos[n];

    cout << "\nIngrese las coordenadas de los puntos:\n";

    for (int i = 0; i < n; i++) {
        cout << "Punto " << i << " (x y): ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    Point pUsuario;

    cout << "\nIngrese las coordenadas del punto de referencia (x y): ";
    cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano;

    double distanciaMinima = calcularDistanciaMasCercana(
        puntos,
        n,
        pUsuario,
        indiceMasCercano
    );

    cout << "\nRESULTADOS\n";
    cout << "El punto mas cercano es el indice: " << indiceMasCercano << endl;
    cout << "Coordenadas: ("
         << puntos[indiceMasCercano].x << ", "
         << puntos[indiceMasCercano].y << ")" << endl;

    cout << "Distancia minima: " << distanciaMinima << endl;

    return 0;

}
