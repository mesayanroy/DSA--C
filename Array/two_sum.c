#include <stdio.h>
#include <stdlib.h>
#define MAX 10 //Define the maximum number of array elements
// Function to display the matching pair
void display(int a, int b) {
    printf("The pair is (%d, %d)\n", a, b);
}
void check(int arr[], int tgt) {
    int i, j, c = 0;
    for (i = 0; i < MAX - 1; i++) {
        for (j = i + 1; j < MAX; j++) {
            if (arr[i] + arr[j] == tgt) {
                display(arr[i], arr[j]);
                c++;
                break;
            }
        }
        if (c != 0)
            break;
    }
    if (c == 0)
        printf("No pair to match the target!\n");
}
void take(int arr[]) {
    int i, tgt;
    printf("Enter %d elements:\n", MAX);
    for (i = 0; i < MAX; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target value: ");
    scanf("%d", &tgt);
    check(arr, tgt);
}
int main() {
    int inp[MAX];
    take(inp);
    return 0;
}
/*  OUTPUT
Enter 10 elements:
2 3 5 6 1 4 0 9 8 7
Enter the target value: 7
The pair is (2, 5)*/