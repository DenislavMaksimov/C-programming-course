#include <stdio.h>
#include <stdlib.h>

void bubblesort(void *array, size_t n, size_t size, int (*compare)(const void *, const void *), void (*swapelements)(void *, void *, size_t)) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            void *elem1 = (char *)array + j * size;
            void *elem2 = (char *)array + (j + 1) * size;
            if (compare(elem1, elem2) > 0) {
                swapelements(elem1, elem2, size);
            }
        }
    }
}
