#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(reconstruirTEST, reconstruirValidos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, 0, -8, 9, -15};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, 3, -3, 4, 6, -1, -1, -8, 9, -15};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, pasajePorCero){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -8, 9, -15, 10};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, 3, -3, 4, 6, 0, -8, 9, -15, 10};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, casoBorde){
    senial hablante1 = {1, 0, -3, 4, 7, 0, 0, 0, 0, 10};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, 0, -3, 4, 7, 8, 8, 8, 8, 10};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

