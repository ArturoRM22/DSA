#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int formateaFecha(string fecha){
    istringstream c(fecha);
    string mesS, diaS, horaS, minS, secS;
    c >> mesS >> diaS;
    getline(c, horaS, ':');
    getline(c, minS, ':');
    getline(c, secS);
    int mes_int = stoi(mesS);
    int dia_int = stoi(diaS);
    int hora_int = stoi(horaS);
    int min_int = stoi(minS);
    int sec_int = stoi(secS);
    return (mes_int * 100000000) + (dia_int * 1000000) + (hora_int * 10000) + (min_int * 100) + sec_int;
}

int main() {
    cout<<"Elige una fecha de inicio y final (mes dia hora) con numeros"<<endl;
    cout<<"Ejemplo: 12 de Octubre a las 16:58:01 --> 10 12 16:58:01"<<endl;
    cout << formateaFecha("10 2 02:20:10") <<endl;
    cout << formateaFecha("10 2 20:20:10") <<endl;
    return 0;
}
