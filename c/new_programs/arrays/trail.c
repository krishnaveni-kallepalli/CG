#include <stdio.h>
#include <limits.h>

void smallest(int a[], int n)
{
    int k, ksmall, high;
    printf("Enter k:");
    scanf("%d", &k);
    
    ksmall = INT_MIN;  // Initialize ksmall to smallest possible value
    high = INT_MAX;    // Initialize high to largest possible value
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] < high)
        {
            high = a[i];  // Update high to the current smallest element
        }
        
        if (a[i] > ksmall && a[i] < high)
        {
            ksmall = a[i];  // Update ksmall if a[i] is greater than ksmall and less than high
            k--;  // Decrease k as we found one of the k smallest elements
        }
        
        // If we found the k-th smallest element, print it and exit
        if (k == 0)
        {
            printf("%d\n", ksmall);
            return;
        }
    }
    
    // If k-th smallest element is not found, k should have reached 0
    // and ksmall should contain the k-th smallest element
    printf("%d\n", ksmall);
}

int main()
{
    int a[100], n;
    printf("Enter size:");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    smallest(a, n);

    return 0;
}

