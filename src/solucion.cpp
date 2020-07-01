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

bool esReunionValida(reunion r, int prof, int freq) {
    bool resp = false;
    // Implementacion
    return resp;
}


void acelerar(reunion& r, int prof, int freq) {
    // Implementacions
    return;
}

void ralentizar(reunion& r, int prof, int freq) {
    // Implementacions
    return;
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
    // Implementacion
    return;
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
    bool resp = false;
    // Implementacion
    return resp;
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

void filtradoMediana(senial& s, int R, int prof, int freq){
    // Implementacion
    return;
}

