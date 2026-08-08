#include <stdio.h>
#include <time.h>

// Function for Linear Search
int linearSearch(int a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }

    return -1;
}

int main()
{
    int n, i, key, pos;
    clock_t start, end;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    pos = linearSearch(a, n, key);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    printf("Execution Time = %f seconds", time_taken);

    return 0;
}