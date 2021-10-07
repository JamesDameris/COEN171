#include <stdio.h>
#include <math.h>

#define HIGH 8


typedef int numbers[HIGH];


void writearray (numbers arr) {
    int i;
    for (i = 0; i < HIGH; ++i) {
        printf("%d ",arr[i]);
    }
}
void readarray (numbers arr) {
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
    //printf("\ny val:%d\n",y);
    x = a[y];
    //printf("x val:%d\n",x);
    i = y - 1;
    j = z + 1;
    while (i < j) {
        do {
            j = j - 1;
        } while (a[j] > x);

        do {
            i = i + 1; 
        } while (a[i] < x);

        if (i < j) {
            exchange(&a[i], &a[j]);
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
    readarray(a);
    quicksort(a , 1, HIGH);
    writearray(a);
}

