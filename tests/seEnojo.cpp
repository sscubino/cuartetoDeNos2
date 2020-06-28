#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(seEnojoTEST, senialMenorADosSegundos){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialSinEnojos){
    senial s = {1,3,-3,4,6,0,-2,-8,9,0,-2,4,-15,7,6,0,-2,-8,9,6,0,-7,3,4,6,0};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    std::cout<<"s.size: "<< s.size()<<"\n";

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialConEnojos){
    senial s = {1,3,-3,4,6,0,-2,-8,9,0,-2,4,-15,7,6,0,-2,-8,9,6,0,-7,3,4,6,0};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, senialConEnojoEnUnExtremo){
    senial s = {8,-5,5,7,6,-6,-10,-2,-8,9,4,-7,4,-10,3,6,10,-2,-8,2,6,0,-3,3,4,1,0,2,6,0,-3,3,4,1,0};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}
