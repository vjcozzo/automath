/* Vincent Cozzo
 * 
 * Program to find, experimentally, 
 * a relationship between factorial numbers 
 * and composites
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "factorial-composites.h"
#define MAX 11

/* Postcondition: Returns 1 for any prime number
 * 0 for any composite */
int isPrime(int k) {
    int upper_bound = (int)(1+sqrt(((double) (k))));
    int div=2;
    for (div=2; div < upper_bound; div ++) {
       /* *
        * Check if this next integer is a 
        * divisor of k.
        ***/
        if ((k % div) == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    int factorials[MAX];
    int numCompositesArr[MAX];
    int ind = 1;
    factorials[0] = 1;
    printf("[");
    while ((ind < MAX)) {
        factorials[ind] = factorials[ind-1]*ind;
        printf("%d    ", factorials[ind]);
        ind ++;
    }
    printf("]\n");
    for (ind = 1; ind < MAX; ind ++) {
        int numComposites = 0;
        int candidate = (2+factorials[ind]);
        while (! isPrime(candidate)) {
/*
            printf("\t%d is apparently composite\n", candidate);
*/
            candidate ++;
            numComposites ++;
        }
        numCompositesArr[ind] = numComposites;
    }
    printf(" n  |  # composite\n");
    printf("--------------------\n");
    for (ind = 0; ind < MAX; ind ++) {
        printf("%3d | %3d\n", ind, numCompositesArr[ind]);
    }
   /* Code used to test the isPrime function
    ***/
    /*
    for (ind = 1; ind < MAX; ind ++) {
        if (isPrime(ind)) {
            printf("%d identified as prime\n", ind);
	} else {
            printf("%d identified as composite\n", ind);
	}
    }
    */
    return 0;
}
