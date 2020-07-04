#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"

// w = (-15, -8, -3, -2, 0, 1, 3, 4, 6, 9)

using namespace std;

TEST(filtradoMedianaTEST, filtradoMedianaValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};

    int prof = 8;
    int freq = 10;
    int R = 4;

    senial hablanteResultante = {1, 3, -3, 4, 1, 0, -2, -8, 9, -15};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}

