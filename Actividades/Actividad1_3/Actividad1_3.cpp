#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

void ordenaMerge(vector<int>&a,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        ordenaMerge(a,low,mid);
        ordenaMerge(a,mid+1,high);
        vector<int> res(high+1);
        int i=low;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=high){
            if(a[i]<=a[j]){
                res[k]=a[i];
                i+=1;
            }else{
                res[k]=a[j];
                j+=1;
            }
            k+=1;
        }
        while(i<=mid){
            res[k]=a[i];
            i+=1;
            k+=1;
        }
        while(j<=high){
            res[k]=a[j];
            j+=1;
            k+=1;
        }
        for(int h=0;h<k;h++){
            a[low+h]=res[h];
        }
    }
}

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

void leerAlmacenarOrdenar(string l, string r){
    ifstream bitacora;
    bitacora.open("C:/Users/Arturo/Desktop/Estructura de datos y algoritmos/Actividad1_3/fechas.txt", ios::in);
    if(bitacora.fail()){
        cout<< "Error al abrir el archivo" <<endl;
    }else{
        unordered_map<int, string> infoMap;
        string line;
        vector<int> Fechas_desordenadas;
        string mes, dia, hora, ip, fallo;
        while(getline(bitacora, line)){
            vector<string> Datos_sep;
            istringstream iss(line);
            iss >> mes >> dia >> hora >> ip;
            getline(iss, fallo);
            if(mes == "Jun"){
                mes = "6";
            }
            else if(mes == "Jul"){
                mes = "7";
            }
            else if(mes == "Aug"){
                mes = "8";
            }
            else if(mes == "Sep"){
                mes = "9";
            }
            else if(mes == "Oct"){
                mes = "10";
            }
            string fecha = mes+" "+dia+" "+hora;
            int key = formateaFecha(fecha);
            infoMap[key] = (line);
            Fechas_desordenadas.push_back(key);
        } 
        ordenaMerge(Fechas_desordenadas, 0, Fechas_desordenadas.size()-1);
        int fecha_inicio_int = formateaFecha(l);
        int fecha_final_int = formateaFecha(r);
        vector<int> rango_fechas;
        for(int i : Fechas_desordenadas){
            if(i > fecha_inicio_int && i< fecha_final_int){
            int key = i;
            auto it = infoMap.find(key);
            rango_fechas.push_back(it->first);
            cout<<i<<": "<<it->first<<endl;
        } 
    }
        ofstream archivo("C:/Users/Arturo/Desktop/Estructura de datos y algoritmos/Actividad1_3/rangofechas.txt");  
            if (archivo.is_open()) {
                for(int i : rango_fechas){
                    archivo <<i<<endl;
                }
                archivo.close(); 
            }else{
                cout<<"Error"<<endl;
            }
    bitacora.close();
}
}

int main(){
    cout<<"Elige una fecha de inicio y final (mes dia hora) con numeros"<<endl;
    cout<<"Ejemplo: 12 de Octubre a las 16:58:01 --> 10 12 16:58:01"<<endl;
    string inicio, final;
    getline(cin, inicio);
    getline(cin, final);
    leerAlmacenarOrdenar(inicio, final);
}