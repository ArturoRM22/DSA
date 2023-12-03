#include "Graph.cpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <array>

struct max_fan_out
{
    int indice;
    string ip;
    int fan_out;
    max_fan_out(int indice, int fan_out, string ip){
        this->indice = indice;
        this->fan_out = fan_out;
        this->ip = ip;
    }
};

string extractIp(string &line) {
    string mes, dia, hora, ip;
    stringstream extract(line);
    extract >> mes >> dia >> hora >> ip;
    size_t dos_puntos = ip.find(':');
    if (dos_puntos != string::npos) {
        ip = ip.substr(0, dos_puntos);
    }
    return ip;
}

array<int, 4> extractSegments(string &ip) {
    array<int, 4> segments;
    for (int i = 0; i < 3; i++) {
        size_t punto = ip.find('.');
        segments[i] = stoi(ip.substr(0, punto));
        ip = ip.substr(punto + 1);
    }
    segments[3] = stoi(ip);
    return segments;
}

vector<max_fan_out> maxFanOutSegment(set<int>*& adj, int V, int num_segments) {
    list<int> top;
    vector<max_fan_out> top_segments;

    for (int i = 0; i < V; i++) {
        if (i == 0) {
            top.emplace_back(i); // es mas eficiente usar emplace que push, ya que no se crean copias para insertar el valor
        }else {
            list<int>::iterator z = top.begin(); 
            while (z != top.end() && (adj[i].size() <= adj[*z].size())) {
                ++z;
            }
            if (z != top.end()) {
                top.insert(z, i);
                if (top.size() > num_segments) {
                    top.pop_back();
                }
            }
        }
    }

    for (auto z = top.begin(); z != top.end(); z++) {
        max_fan_out* top_seg = new max_fan_out(*z, adj[*z].size(), "");
        top_segments.emplace_back(*top_seg);
    }

    return top_segments;
}

int getFanOutIp(vector<array<int, 4>>& ips, set<int>*& adj, int ip){
    int contador = 0;
    for(int i = 0; i < 4 ;i++){
        contador += (adj[ips[ip][i]].size());
    }
    return contador;
}

max_fan_out maxFanOutIp(vector<array<int, 4>>& ips, set<int>*& adj){
    int max = 0;
    string boot_master;
    for(int i = 0; i < ips.size() ;i++){
        if(getFanOutIp(ips, adj, max) < getFanOutIp(ips, adj, i)){
            max = i;
        }
    }
    for(int i = 0; i < 4 ;i++){
        if(i == 3){
            boot_master += to_string(ips[max][i]);
        }else{
        boot_master += (to_string(ips[max][i]) + ".");
        }
    }
    max_fan_out boot_master_(max, getFanOutIp(ips, adj, max), boot_master);
    return boot_master_;
}

int main() {
    ifstream bitacora;
    bitacora.open("../bitacora.txt", ios::in);
    if (bitacora.fail()) {
        cout << "Error al abrir el archivo" << endl;
    }else{
        string line, ip;
        int num_seg;
        vector<array<int, 4>> ips;
        Graph g(999);
        while (getline(bitacora, line)) {
            ip = extractIp(line);
            array<int, 4> segments = extractSegments(ip);
            ips.push_back(segments);
            for(int i = 0; i < 3; i++){
                g.addEdge(ips.back()[i], ips.back()[i+1]);
            }
        }
        cout << "Elige el número de segmentos con mayor Fan out que quieres conocer: "<< endl;
        cin >> num_seg;
        vector<max_fan_out> maxFn_segments = maxFanOutSegment(g.adj, g.V, num_seg);
        max_fan_out boot_master = maxFanOutIp(ips, g.adj); 
        cout <<num_seg<<" segmentos con más fan-out:" << endl;
        for(auto& segmento : maxFn_segments){
            cout <<segmento.indice << "-->" << segmento.fan_out << " conexiones de salida" << endl;
        }
        cout << "--------------------------------" << endl;
        cout <<"IP boot master: "<< boot_master.ip<<" con: "<<boot_master.fan_out<<" fan-outs o conexiones (sumatoria de las conexiones de sus segmentos)"<<endl;
    }
    return 0;
}