#include <stdio.h>

class Solution {
public:
    int oppositeOf(int n) {
        return ~n + 1;
    }

    // version 1
    /*
    int add(int i, int j) {
        if (0 == i) {
            return j;
        }
        if (0 == j) {
            return i;
        }

        int carry = (i & j) << 1;
        int sum = i ^ j;
        return add(carry, sum);
    }
    */

    // version 2
    /*
    int add(int i, int j) {
        return j ? add((i^j), ((i&j)<<1)) : i;
    }
    */

    // version 3
    int add(int i, int j) {
        int sum = 0;
        while (j != 0) {
            sum = i ^ j;
            j = (i & j) << 1;
            i = sum;
        }
        return i;
    }

    // i - j
    int sub(int i, int j) {
        int j_n = oppositeOf(j);
        return add(i, j_n);
    }
};

int main(int argc, char* argv[])
{
    Solution cSol;

    // data for test
    int numberA = 1;
    int numberA_n = -1;
    int numberB = 2;
    int numberB_n = -2;
    int numberC = 0;

    // ----------------------------------------------------------------------------
    {
        printf("opposite of (%d) is %d\n", numberA,     cSol.oppositeOf(numberA));
        printf("opposite of (%d) is %d\n", numberA_n,   cSol.oppositeOf(numberA_n));
        printf("opposite of (%d) is %d\n", numberB,     cSol.oppositeOf(numberB));
        printf("opposite of (%d) is %d\n", numberB_n,   cSol.oppositeOf(numberB_n));
    }

    // ----------------------------------------------------------------------------
    {
        printf("%d add %d is %d\n", numberA, numberA_n,     cSol.add(numberA, numberA_n));
        printf("%d add %d is %d\n", numberA, numberB,       cSol.add(numberA, numberB));
        printf("%d add %d is %d\n", numberA, numberB_n,     cSol.add(numberA, numberB_n));
        printf("%d add %d is %d\n", numberA_n, numberB,     cSol.add(numberA_n, numberB));
        printf("%d add %d is %d\n", numberA_n, numberB_n,   cSol.add(numberA_n, numberB_n));
        printf("%d add %d is %d\n", numberB, numberB_n,     cSol.add(numberB, numberB_n));
        printf("%d add %d is %d\n", numberA, numberC,       cSol.add(numberA, numberC));
        printf("%d add %d is %d\n", numberA_n, numberC,     cSol.add(numberA_n, numberC));
        printf("%d add %d is %d\n", numberB, numberC,       cSol.add(numberB, numberC));
        printf("%d add %d is %d\n", numberB_n, numberC,     cSol.add(numberB_n, numberC));

        printf("%d add %d is %d\n", 0, 1,     cSol.add(0, 1));
    }

    // ----------------------------------------------------------------------------
    {
        printf("%d sub %d is %d\n", numberA, numberA_n,     cSol.sub(numberA, numberA_n));
        printf("%d sub %d is %d\n", numberA, numberB,       cSol.sub(numberA, numberB));
        printf("%d sub %d is %d\n", numberA, numberB_n,     cSol.sub(numberA, numberB_n));
        printf("%d sub %d is %d\n", numberA_n, numberB,     cSol.sub(numberA_n, numberB));
        printf("%d sub %d is %d\n", numberA_n, numberB_n,   cSol.sub(numberA_n, numberB_n));
        printf("%d sub %d is %d\n", numberB, numberB_n,     cSol.sub(numberB, numberB_n));
        printf("%d sub %d is %d\n", numberA, numberC,       cSol.sub(numberA, numberC));
        printf("%d sub %d is %d\n", numberA_n, numberC,     cSol.sub(numberA_n, numberC));
        printf("%d sub %d is %d\n", numberB, numberC,       cSol.sub(numberB, numberC));
        printf("%d sub %d is %d\n", numberB_n, numberC,     cSol.sub(numberB_n, numberC));
    }
    return 0;
}

