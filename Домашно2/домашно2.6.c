#include <stdio.h>
#define SWAP(A, B, TYPE) \
    do { \
        TYPE temp = A; \
        A = B; \
        B = temp; \
    }  while ()


#define SORT(ARRAY, SIZE, TYPE, COM) \
    do { \
        for (int i = 0; i < SIZE - 1; i++) { \
            for (int j = i + 1; j < SIZE; j++) { \
                if (ARRAY[i] COM ARRAY[j]) { \
                    SWAP(ARRAY[i], ARRAY[j], TYPE); \
                } \
            } \
        } \
    } while ()
