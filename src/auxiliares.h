#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <iostream>

senial leerSenial(string nombreArchivo);
void escribirSenial(senial  s, string nombreArchivo);
float duracion(senial s, int freq);
bool enRango(int muestra, int prof);
float tono(senial s);
float tonoRango(senial s, int desde, int hasta);
float duracion (intervalo interv, int freq);
void burbujeoReuniones (reunion &r, int i);
void swapReuniones (reunion &r, int i, int j);
void ASSERT_SENIAL_EQ(senial s1, senial s2);
void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2);
void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2);
void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2);

#endif //REUNIONESREMOTAS_AUXILIARES_H
