#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *b = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        b[i] = rand() % 101 - 50;
    }
    int countPos = 0, countNeg = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > 0) countPos++;
        else if(b[i] < 0) countNeg++;
    }
    int *c = (int*)malloc(countPos * sizeof(int));
    int *d = (int*)malloc(countNeg * sizeof(int));
    int posIndex = 0, negIndex = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > 0) c[posIndex++] = b[i];
        else if(b[i] < 0) d[negIndex++] = b[i];
    }
    printf("Original array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
    printf("\nPositive numbers: ");
    for(int i = 0; i < countPos; i++){
        printf("%d ", c[i]);
    }
    printf("\nNegative numbers: ");
    for(int i = 0; i < countNeg; i++){
        printf("%d ", d[i]);
    }
    free(b);
    free(c);
    free(d);
    return 0;
}
