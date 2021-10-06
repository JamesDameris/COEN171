#include <stdio.h>
#include <math.h>

#define HIGH 8


typedef int numbers[HIGH];


void readarray (numbers arr) {
    int i;
    for (i = 0; i < HIGH; ++i) {
        printf("%d ",arr[i]);
    }
}
void writearray (numbers arr) {
    int i;
    for (i = 0; i < HIGH; ++i) {
        scanf("%d",&(arr[i]));
    }
}
void exchange (int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (numbers a, int y, int z) {
    int i, j, x;
    x = a[y];
    i = y - 1;
    j = z + 1;
    while (i < j) {
        do {
            --j;
        } while (a[j] > x);

        do {
            ++i; 
        } while (a[i] < x);

        if (i < j) {
            exchange(a + i, a + j);
        }
    }
    return j;
}

void quicksort (numbers a, int m, int n) {
    int i;
    if (n > m) {
        i = partition(a, m, n);
        quicksort(a, m, i);
        quicksort(a, i + 1, n);
    }
}

int main(void) {
    numbers a;
    writearray(a);
    quicksort(a , 1, HIGH);
    readarray(a);
}

