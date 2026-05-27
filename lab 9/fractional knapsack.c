#include <stdio.h>

struct Item
{
    int wt, val;
    float ratio;
};

int main()
{
    int n, i, j, cap;
    float profit = 0;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    struct Item a[n], temp;

    printf("Enter weights and values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i].wt, &a[i].val);
        a[i].ratio = (float)a[i].val / a[i].wt;
    }

    printf("Enter capacity: ");
    scanf("%d", &cap);

    // Sorting by profit/weight ratio
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i].ratio < a[j].ratio)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(cap >= a[i].wt)
        {
            profit += a[i].val;
            cap -= a[i].wt;
        }
        else
        {
            profit += a[i].ratio * cap;
            break;
        }
    }

    printf("Maximum Profit = %.2f", profit);

    return 0;
}
