#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(esResunionValidaTEST, reunionValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, reunionHablantesInvalidos){
    senial hablante3 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante4 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante3, 3), make_pair(hablante4, 4)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, reunionHablantesRepetidos){
    senial hablante3 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante4 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante3, 0), make_pair(hablante4, 0)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, noMatriz){
    senial hablante3 = {1, 3, -3, 4, 6, 0, -2, -8, 7};
    senial hablante4 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante3, 0), make_pair(hablante4, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}