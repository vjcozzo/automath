#include <stdio.h>
#include <stdlib.h>


int main() {
    int numEqs = 0;
    int index;
    int *a, *m;
    long long productAll = 1;
    printf("Please enter the number of modular congruences: ");
    scanf("%d", &numEqs);

    a = malloc(numEqs*sizeof(long long));
    m = malloc(numEqs*sizeof(long long));

    for (index = 0; index < numEqs; index ++) {
        printf(" enter the value a_%d: ", index);
        scanf("%d", (a+index));
        printf(" enter the next modulus, m_%d: ", index);
        scanf("%d", (m+index));
    }

    long long *y = (long long *) (malloc(20*sizeof(long long)));
    long long *Mi = (long long *) (malloc(20*sizeof(long long)));

    for (int ind=0; ind < numEqs; ind ++) {
        productAll *= (m[ind]);
    }
    printf("%lld = the total product of all m_i's\n", productAll);

    for (int ind=1; ind < numEqs; ind ++) {
        /* Calculate M_i and y_i here */
        long long nextCoprime = m[ind];
        Mi[ind] = ((productAll) / (nextCoprime));
        long long nextMi = Mi[ind];
        long long inverseOfNextMi = 0;
 
        for (int inner=1; inner < nextCoprime; inner ++) {
            long long product = (nextMi*inner);
            int rem = (product % nextCoprime);
            if (rem == 1) {
                printf("\t%d -- the inverse of %lld modulo %lld\n", inner, nextMi, nextCoprime);
                inverseOfNextMi = (inner);
                inner = nextCoprime;
            }
        }
/*
    if (inverseOfNextMi == (-1)) {
        printf("\t*****ERR, inverse not found for " + nextMi + " modulo " + nextCoprime + "*****");
    }
*/
        y[ind] = inverseOfNextMi;
    }
    long long result = 0;
    for (int ind=1; ind < numEqs; ind ++) {
        long b = (a[ind]);
/*        printf(a + " is " + primesSquared[ind] + " - " + ind);*/
	long long prod=(b*Mi[ind]*y[ind]);
	result += prod;
    }

    if (result >= productAll) {
        printf("Now Have to reduce %lld modulo %lld\n", result, productAll);
        result = (result % productAll);
    }
    
    free(a);
    free(m);
    printf("Value of the result: %lld\n", result);
    return 0;
}
