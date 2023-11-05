#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *bitset;
} BitSet;

BitSet *createBitSet(int size) {
    BitSet *bs = (BitSet *)malloc(sizeof(BitSet));
    bs->bitset = (int *)calloc(size / 32 + 1, sizeof(int));
    return bs;
}

int get(BitSet *bs, int pos) {
    int wordNumber = pos / 32;
    int bitNumber = pos % 32;
    return (bs->bitset[wordNumber] >> bitNumber) & 1;
}

void set(BitSet *bs, int pos) {
    int wordNumber = pos / 32;
    int bitNumber = pos % 32;
    bs->bitset[wordNumber] |= 1 << bitNumber;
}

void checkDuplicates(int *array, int length) {
    BitSet *bs = createBitSet(320000);
    for (int i = 0; i < length; i++) {
        int num = array[i];
        int num0 = num - 1;
        if (get(bs, num0)) {
            printf("%d\n", num);
        } else {
            set(bs, num0);
        }
    }
    free(bs->bitset);
    free(bs);
}

int main() {
    int array[] = {1, 2, 3, 4, 4, 5, 5};
    int length = sizeof(array) / sizeof(int);

    checkDuplicates(array, length);

    return 0;
}