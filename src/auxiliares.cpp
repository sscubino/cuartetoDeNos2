#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"
#include "fstream"

void escribirSenial(senial  s, string nombreArchivo){
    ofstream fout;
    fout.open(nombreArchivo);
    for (int i = 0; i < sizeof(s); ++i) {
        fout << s[i] << " ";
    }
    fout.close();
    return;
}


senial leerSenial(string nombreArchivo){
    senial s;
    int i = 0;
    ifstream fin;
    fin.open(nombreArchivo);
    while (!fin.eof()) {
        fin >> i;
        s.push_back(i);
    }
    fin.close();
    return s;
}

bool senialesOrdenadasIguales(senial s1, senial s2){
    if(s1.size() != s2.size())
        return false;

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool reunionesIguales(reunion reunion1, reunion reunion2){
    if(reunion1.size() != reunion2.size())
        return false;

    for (int i = 0; i < reunion1.size(); ++i) {
        if(reunion1[i].second != reunion2[i].second)
            return false;

        if(reunion1[i].first.size() != reunion2[i].first.size())
            return false;

        if(!senialesOrdenadasIguales(reunion1[i].first, reunion2[i].first))
            return false;
    }

    return true;
}

bool hablantesOrdenadosIguales(vector<hablante> s1, vector<hablante> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool intervalosOrdenadosIguales(vector<intervalo> s1, vector<intervalo> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

float duracion(senial s, int freq){
    return s.size() * 1.f / freq;
}

bool enRango(int muestra, int prof){
    return (-pow(2, prof-1) <= muestra && muestra <= pow(2, prof-1)-1);
}

float tono(senial s){
    float t = 0;
    for (int i = 0; i < s.size(); i++) {
        t += abs(s[i]);
    }
    return t/s.size();
}

float tonoRango(senial s, int desde, int hasta){
    float t = 0;
    for (int i = desde; i <= hasta; i++) {
        t += abs(s[i]);
    }
    return t/(hasta-desde+1);
}

float duracion (intervalo interv, int freq){
    return (interv.second + 1 - interv.first) * 1.f / freq;
}

void ASSERT_SENIAL_EQ(senial s1, senial s2) {
    ASSERT_TRUE(senialesOrdenadasIguales(s1, s2));
}

void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2) {
    ASSERT_TRUE(reunionesIguales(reunion1, reunion2));
}

void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2) {
    ASSERT_TRUE(hablantesOrdenadosIguales(s1, s2));
}

void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2) {
    ASSERT_TRUE(intervalosOrdenadosIguales(s1, s2));
}