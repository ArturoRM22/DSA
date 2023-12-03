#include <iostream>
#include <sstream>
#include <fstream>
#include "binarySearchTree.cpp"


string extractIp(string line){
    string mes, dia, hora, ip;
    stringstream extract(line);
    extract >> mes >> dia >> hora >> ip;
    return ip;
}

int main(){
    ifstream bitacora("../rango.txt");
    string line, ip, puerto;
    BinarySearchTree arbolito;
    while(getline(bitacora, line)){
        ip = extractIp(line);
        size_t dos_puntos = ip.find(':');
        if (dos_puntos != string::npos) {
            puerto = ip.substr(dos_puntos+1);
            ip = ip.substr(0, dos_puntos);
            int puertito = stoi(puerto);
            arbolito.push(puertito);
        }
    }
    if(arbolito.puertos[0]->data == 1){
        cout << "Ningun puerto es accesado más de una vez" << endl;
        return 0;
    }
    for(int i = 0; i <= 4 ;i++){
        cout <<"Puerto: "<<arbolito.puertos[i]->puerto << " accesos: "<<arbolito.puertos[i]->data<< endl;
    }
    return 0;
}

