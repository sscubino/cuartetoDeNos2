#include "solucion.h"
#include<iostream>

// Ejercicios

bool esSenial(vector<int> s, int prof, int freq) {
    bool resp = (freq==10 && (prof==8 || prof==16 || prof==32));
    resp = resp && duracion(s, freq) >= 1;

    for (int i = 0; i < s.size(); i++) {
        resp = resp && enRango(s[i], prof);
    }

    return resp;
}

bool seEnojo(senial s, int umbral, int prof, int freq) {
    bool resp = false;

    for (int i = 0; i < s.size(); i++) {
        // Inicializar j como i+freq*2-1 me asegura que
        // subseq(s, i, j+1) tenga duracion >= 2seg
        for (int j = i+freq*2-1; j < s.size(); j++) {
            resp = resp || tonoRango(s, i, j) > umbral;
        }
    }
    
    return resp;
}


bool hablantesDeReunionesValidos(reunion r){
    bool resp = true;
    for (int i = 0; i < r.size(); ++i) {
        if ((get<1>(r[i])) >= r.size() || (get<1>(r[i])) < 0){
            resp = false;
        }
        for (int j = 0; j < r.size(); ++j) {
            // Verifica que no hayan repetidos
            if(j != i && (get<1>(r[i])) == (get<1>(r[j])))
                resp = false;
        }
    }
    return resp;
}
bool senialesValidas(reunion r, int prof, int freq) {
    bool resp = (freq==10 && (prof==8 || prof==16 || prof==32));
    for (int i = 0; i < r.size(); i++) {
        resp = resp && duracion(get<0>(r[i]), freq) >= 1;
        for (int j = 0; j < get<0>(r[i]).size(); j++) {
            resp = resp && enRango(get<0>(r[i])[j], prof);
        }
    }
    return resp;
}
bool esMatriz(reunion r) {
    bool resp = true;
    for (int i = 0; i < r.size(); ++i) {
        if (get<0>(r[0]).size() != get<0>(r[i]).size()) {
            resp = false;
        }
    }
    return resp;
}
bool esReunionValida(reunion r, int prof, int freq) {
    bool resp = false;
    if (r.size() > 0 && esMatriz(r) && senialesValidas(r, prof, freq) && hablantesDeReunionesValidos(r)) {
        resp = true;
    }
    return resp;
}


void acelerar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        senial acelerado;
        senial original = get<0>(r[i]);
        for (int j = 1; j < get<0>(r[i]).size(); j=j+2) {  //recorre los valores impares de las seniales
            acelerado.push_back(original[j]);
        }
        get<0>(r[i]) = acelerado;
    }
}


void relent(senial& s) {
    senial relentizado;
    int i = 0;
    int j = 0;
    int promedio = 0;
    while (j < (s.size()*2)-1) {
        if (j % 2 == 0) {
            relentizado.push_back(s[i]);
            i++;
            j++;
        }
        else {
            promedio = (s[i-1]+s[i])/2;
            relentizado.push_back(promedio);
            j++;
        }
    }
    s = relentizado;
}
void ralentizar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        relent (get<0>(r[i]));
    }
}

vector<hablante> tonosDeVozElevados(reunion r, int freq, int prof) {
    vector<hablante> maximos = {r[0].second};
    float maximoTono = tono(r[0].first);
    for (int i = 1; i < r.size(); i++){
        float t = tono(r[i].first);
        if (t > maximoTono){
            maximos = {r[i].second};
            maximoTono = t;
        } else if (tono(r[i].first) == maximoTono){
            maximos.push_back(r[i].second);
        };
    }
    return maximos;
}


void ordenar(reunion& r, int freq, int prof) {
    for (int i = 0; i < r.size(); i++) {
        burbujeoReuniones(r, i); 
    }
}

vector<intervalo> silencios(senial s, int prof, int freq, int umbral) {
    vector<intervalo> intervalos;
    // Obs: considero intervalos cerrados en ambos extremos
    for (int i = 0; i < s.size(); i++) {
        if(abs(s[i]) < umbral){
            int avanzarHasta = i;
            for (int j = i; j < s.size(); j++) {
                avanzarHasta = j+1;
                if(abs(s[j]) < umbral && (j == s.size()-1 || abs(s[j+1]) >= umbral)){
                    intervalo interv = make_pair(i, j);
                    if(duracion(interv, freq) >= 0.2)
                        intervalos.push_back(interv);
                    break;
                }
            }
            i = avanzarHasta;
        }
    }
    return intervalos;
}


bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral) {
    //en el siguiente vector escribiremos en cada instante de la reunion, si alguien hablaba
    vector<int> registroDeNoSilencios(r[0].first.size(), 0);

    for (int i = 0; i < r.size(); ++i) {
        //leemos la lista de intervalos de silencios de cada hablante y escribimos, en el vector antes mencionado,
        //los instantes donde cada uno habló.

        vector<intervalo> silenciosDelHablante = silencios(r[i].first, prof, freq, umbral);
        //a y b se moveran entre los limites de los intervalos de silencio, representando los intervalos de "NOsilencio"
        int a = 0;
        int b;
        //aqui leemos cada uno de los intervalos en la lista de silencios
        for (int j = 0; j < silenciosDelHablante.size(); ++j) {
            b = silenciosDelHablante[j].first;
            //escribimos el vectos de no silencios:
            for (int k = a; k < b; ++k) {
                if (registroDeNoSilencios[k] == 0) {
                    //si nadie habia hablado en ese instante, escribimos 1
                    registroDeNoSilencios[k] = 1;
                } else {
                    //si alguien ya habia hablado retornamos falso
                    return true;
                }
            }
            a = silenciosDelHablante[j].second+1;
        }
        //repetimos para lo que seria el ultimo intervalo
        b = r[i].first.size();
        for (int k = a; k < b; ++k) {
            if (registroDeNoSilencios[k] == 0) {
                registroDeNoSilencios[k] = 1;
            } else {
                return true;
            }
        }
    }

    return false;
}

senial reconstruir(senial s, int prof, int freq) {
    senial res(s.size());
    int l = -1;
    for (int r = 0; r < s.size(); r++) {
        if ( s[r] != 0 ) {
            if (!(r - l == 2 && s[l] * s[r] < 0)){
                int prom = s[l]/2 + s[r]/2;
                l++;
                while (l < r) {
                    res[l]=prom;
                    l++;
                }
            } else {
                res[l+1] = 0;
                l += 2;
            }
            res[l] = s[r];
        }
    }
    return res;
}


void swap(vector <int > &lista , int i, int j){
    int k=lista[i];
    lista[i]= lista[j];
    lista[j]=k;
}
void burbujeo(vector <int> &lista, int i) {
    for (int j=lista.size()-1; j>i; j--){
        if (lista[j] < lista[j-1]){
            swap(lista, j, j-1);
        }
    }
}
vector <int> bubbleSort(vector <int> lista) {
    for(int i=0; i<lista.size(); i++){
        burbujeo(lista ,i);
    }
    return  lista;
}
void filtradoMediana(senial& s, int R, int prof, int freq){
    senial aux = s;
    int i = R;
    while (0 <= i-R && i+R+1 < aux.size()) {
        senial w;
        for (int j = i-R; j < i+R+1; ++j) {
            w.push_back(aux[j]);
        }
        w = bubbleSort(w);
        s[i] = w[R];
        i++;
    }
}
