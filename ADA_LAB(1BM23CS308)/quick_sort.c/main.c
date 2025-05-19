#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while(ch) {
        printf("\nEnter the number of elements (max %d): ", MAX);
        scanf("%d", &n);
        if(n > MAX) {
            printf("Exceeded max array size of %d\n", MAX);
            continue;
        }

        for(i = 0; i < n; i++) {
            a[i] = rand() % 200;
        }

        printf("The randomly generated array is:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\nThe sorted array elements are:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken = %f seconds\n", time_taken);

        printf("\nDo you wish to continue (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int key = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {
        while (i <= high && a[i] <= key) i++;
        while (a[j] > key) j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
