
#ifndef PROJECT_1_TEST1_H
#define PROJECT_1_TEST1_H

#include "student1.h"
inline void Test1();

#endif //PROJECT_1_TEST1_H

void Test1(){

    printf("Base1: %d, Base2: %d, Number: 55\n",8,17);
    printf("Expected result: Bad input \n");
    printf("Actual result:   ");
    char* result = Student1Process(8,17,"55");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 18\n",1,8);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(1,8,"18");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 3.4\n",0,20);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(0,20,"3.4");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 3401\n",2,12);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,12,"3401");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1G2\n",16,9);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(16,9,"1G2");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1k3\n",13,8);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(13,8,"1k3");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 17\n",7,8);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(7,8,"17");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: .45\n",10,8);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(10,8,".45");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 16.\n",8,16);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(8,16,"16.");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 23..16\n",8,12);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(8,12,"23..16");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 2.5.13\n",16,9);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(16,9,"2.5.13");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 03\n",11,5);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(11,5,"03");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 000Ab4\n",16,12);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(16,12,"000Ab4");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 00.5\n",10,11);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(10,11,"00.5");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 023.5\n",13,4);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(13,4,"023.5");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 12345678901234\n",10,6);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(10,6,"12345678901234");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0.100101001011\n",2,14);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,14,"0.100101001011");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1231.112123134213\n",6,15);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(6,15,"1231.112123134213");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1234567890ABCDEF012\n",16,8);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(16,8,"1234567890ABCDEF012");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1001abc\n",2,10);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,10,"1001abc");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1001 10\n",2,10);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,10,"1001 10");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1001 abc\n",2,10);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,10,"1001 abc");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1001     abc\n",2,10);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(2,10,"1001     abc");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 23 45\n",8,12);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(8,12,"23 45");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 254.,/\n",8,13);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(8,13,"254.,/");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 254      ,/*!\n",8,13);
    printf("Expected result: Bad input\n");
    printf("Actual result:   ");
    result = Student1Process(8,13,"254      ,/*!");
    if (result != NULL)
        printf(" %s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0\n",8,10);
    printf("Expected result: 0\n");
    printf("Actual result:   ");
    result = Student1Process(8,10,"0");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 234123\n",5,6);
    printf("Expected result: 104035\n");
    printf("Actual result:   ");
    result = Student1Process(5,6,"234123");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1523432432142\n",7,12);
    printf("Expected result: 48a09b6a96\n");
    printf("Actual result:   ");
    result = Student1Process(7,12,"1523432432142");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: ACB53F\n",16,2);
    printf("Expected result: 101011001011010100111111\n");
    printf("Actual result:   ");
    result = Student1Process(16,2,"ACB53F");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: aCbf3710aAa10\n",16,4);
    printf("Expected result: 22302333031301002222220100\n");
    printf("Actual result:   ");
    result = Student1Process(16,4,"aCbf3710aAa10");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: acb533\n",14,2);
    printf("Expected result: 10110011001001101101001\n");
    printf("Actual result:   ");
    result = Student1Process(14,2,"acb533");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: Cb53Ea0A1\n",15,8);
    printf("Expected result: 363456114336\n");
    printf("Actual result:   ");
    result = Student1Process(15,8,"Cb53Ea0A1");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 123\n",10,10);
    printf("Expected result: 123\n");
    printf("Actual result:   ");
    result = Student1Process(10,10,"123");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 527\n",8,8);
    printf("Expected result: 527\n");
    printf("Actual result:   ");
    result = Student1Process(8,8,"527");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 7\n",12,6);
    printf("Expected result: 7\n");
    printf("Actual result:   ");
    result = Student1Process(12,8,"7");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0.0\n",2,10);
    printf("Expected result: 0\n");
    printf("Actual result:   ");
    result = Student1Process(2,10,"0.0");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0.00000000\n",3,4);
    printf("Expected result: 0\n");
    printf("Actual result:   ");
    result = Student1Process(3,4,"0.00000000");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0.7\n",10,16);
    printf("Expected result: 0.b33333333333\n");
    printf("Actual result:   ");
    result = Student1Process(10,16,"0.7");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 1.0200\n",3,4);
    printf("Expected result: 1.032032032032\n");
    printf("Actual result:   ");
    result = Student1Process(3,4,"1.0200");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: Ac.36A019\n",16,12);
    printf("Expected result: 124.26887a548809\n");
    printf("Actual result:   ");
    result = Student1Process(16,12,"Ac.36A019");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 0.16253673526\n",8,12);
    printf("Expected result: 0.283091408845\n");
    printf("Actual result:   ");
    result = Student1Process(8,12,"0.16253673526");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: 16.3\n",7,11);
    printf("Expected result: 12.479479479479\n");
    printf("Actual result:   ");
    result = Student1Process(7,11,"16.3");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    printf("Base1: %d, Base2: %d, Number: bbbbbbbbbbbbb\n",12,16);
    printf("Expected result: 614f4bffffff\n");
    printf("Actual result:   ");
    result = Student1Process(12,16,"bbbbbbbbbbbbb");
    if (result != NULL)
        printf("%s\n", result);
    puts("");

    free(result);
}

