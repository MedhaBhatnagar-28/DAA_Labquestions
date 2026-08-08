#include <stdio.h>
#include <time.h>

// Function to sor using Bubblesort
void sort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++) //for number of passes
    {
        for(j = 0; j < n - i - 1; j++)//for comparing adjacent, 
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function for Binary Search
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;

        else if(key > a[mid])
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

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Start timer
    start = clock();

    // Sort the array
    sort(a, n);

    //  sorted array
    printf("\nSorted Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    // Perform Binary Search
    pos = binarySearch(a, n, key);

    // Stop timer
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("\nElement found at index %d", pos);
    else
        printf("\nElement not found");


    return 0;
}