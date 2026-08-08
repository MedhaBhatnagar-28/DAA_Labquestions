#include <stdio.h>
#include <time.h>

// Function for Binary Search
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
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

    printf("Enter sorted array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();

    pos = binarySearch(a, n, key);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}