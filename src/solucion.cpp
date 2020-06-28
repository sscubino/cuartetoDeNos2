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
            resp = resp || tono(s, i, j) > umbral;
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
    vector<hablante> maximos;
    // Implementacion
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
            for (int j = i; j < s.size(); j++) {
                if(abs(s[j]) < umbral && (j == s.size()-1 || abs(s[j+1]) >= umbral)){
                    intervalo interv = make_pair(i, j);
                    if(duracion(interv, freq) >= 0.2)
                        intervalos.push_back(interv);
                    i = j+1;
                    break;
                }
            }
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
    senial res = {s[0]};
    int l = 0;
    for (int r = 1; r < s.size(); r++) {
        if ( s[r] != 0 ) {
            if (!(r - l == 2 && s[l] * s[r] < 0)){
                int prom = s[l]/2 + s[r]/2;
                l++;
                while (l < r) {
                    res.push_back(prom);
                    l++;
                }
            } else {
                res.push_back(0);
                l += 2;
            }
            res.push_back(s[r]);
        }
    }
    return res;
}

void filtradoMediana(senial& s, int R, int prof, int freq){
    // Implementacion
    return;
}

