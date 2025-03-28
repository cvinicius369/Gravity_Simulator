#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

// Constantes
const double G = 6.67430e-11;

double convertForM(double distancia, int unidade){
    switch(unidade){
        case 1: return distancia;              // metros
        case 2: return distancia * 1000;       // quilometros
        case 3: return distancia * 1.496e+11;  // unidade astronomica
        default: return distancia;
    }
}

int main(){
    double massa1, massa2, distancia, aceleracao_inicial1, aceleracao_inicial2;
    int unidade;

    cout << "Massa do objeto 1: "; cin >> massa1;
    cout << "Massa do objeto 2: "; cin >> massa2;
    cout << "Distancia entre os objetos: "; cin >> distancia;
    cout << "Unidade de medida da distancia (1-Metros, 2-Quilometros, 3-Unidade Astronomica): "; cin >> unidade;
    cout << "Aceleracao inicial do objeto 1: "; cin >> aceleracao_inicial1;
    cout << "Aceleracao inicial do objeto 2: "; cin >> aceleracao_inicial2;
    
    distancia = convertForM(distancia, unidade);
    double pos1 = 0.0;
    double pos2 = distancia;
    if (aceleracao_inicial1 < 0.01){ aceleracao_inicial1 = 0.01; }
    if (aceleracao_inicial2 < 0.01){ aceleracao_inicial2 = 0.01; }

    cout << "Iniciando simulacao . . ." << endl;
    while(true){
        double forca = (G * massa1 * massa2) / (distancia * distancia);
        double aceleracao1 = forca / massa1;
        double aceleracao2 = forca / massa2;
        pos1 += aceleracao1 * aceleracao_inicial1;
        pos2 -= aceleracao2 * aceleracao_inicial2;
        distancia = pos2 - pos1;

        cout << "Posicao 1: " << pos1 << " | Posicao 2: " << pos2 << " | distancia: " << distancia << "\r";
        cout.flush();
        
        if (distancia <= 0) { cout << "Colisao detectada!" << endl; break; }
    }
    return 0;
}
