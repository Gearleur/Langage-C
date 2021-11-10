#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int count_primes(int n) {
    const int S = 10000;

    int* Tab;
    Tab = (int*)calloc(sqrt(n) + 2, sizeof(int));
    for (int i = 2; i <= sqrt(n); i++) {
        if (Tab[i]==0) {
            int j = i + i;
            for (int j = i * i; j <= sqr(n); j += i)
                Tab[j] = 1;
        }
    }

    int result = 0;
    int* block;
    block = (int*)calloc(S, sizeof(int));
    for (int k = 0; k * S <= n; k++) {
        int start = k * S;
        for (int p=0; p<sqrt(S); p++) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for ( ; j < S; j += p)
                block[j] = 1;
        }
        if (k == 0)
            block[0] = block[1] = 1;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}