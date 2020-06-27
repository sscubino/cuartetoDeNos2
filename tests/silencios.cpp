#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(silenciosTEST, silenciosValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = {make_pair(5,6)};

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, sinSilencios){
    senial hablante = {1, 5, -3, 8, 6, 0, -5, -8, 9, -1};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    vector<intervalo> intervalos = {};
    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, todoSilencio){
    senial hablante = {1, 5, -3, 8, 6, 0, -5, -8, 9, -1};
    int prof = 8;
    int freq = 10;
    int umbral = 10;

    vector<intervalo> intervalos = {make_pair(0, hablante.size()-1)};
    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}