#include <stdio.h>

void selection_sort(int to_sort[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i, t;
        for (int j = i + 1; j < n; j++)
        {
            if (to_sort[j] < to_sort[k])
            {
                k = j;
            }
        }
        t = to_sort[k];
        to_sort[k] = to_sort[i];
        to_sort[i] = t;
    }
}

int main()
{
    int a[] = {79,8,29,87,4501,61,5981,601};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}

