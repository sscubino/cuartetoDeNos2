#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(esSenialTEST, frecuenciaValida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duracionCorta){
    senial s = {1,3,-3,4,6,0,-2,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, freqInvalida){
    senial s = {1,3,-3,4,6,0,-2,-15,7,2,7};
    int prof = 8;
    int freq = 11;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, muestraFueraDeRango){
    senial s = {1,3,-3,4,6,0,-2,-230,7,2,7};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

