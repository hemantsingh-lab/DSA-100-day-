
#include <stdio.h>

int main() {
    int n, pos, x;
    int a[20];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
// read elements
        scanf("%d", &a[i]);
    }

    // read position and element to insert
    printf("Enter position to insert element: ");
    scanf("%d", &pos);

    // position is 1-based index
    printf("Enter element to insert: ");
    scanf("%d", &x);

    // shift elements
    for(int i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    // insert element
    a[pos - 1] = x;

    // print result
    for(int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}