#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void color(int c);
void reset_color();
void print_complexity(int w, int a, int b);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);
void quick_sort(int a[], int l, int h);
void merge_sort(int a[], int l, int h);

int main(void)
{
    color(7);
    printf("        _            _            _         _\n       / /\\         /\\ \\         /\\ \\      /\\ \\\n      / /  \\       /  \\ \\       /  \\ \\     \\_\\ \\\n     / / /\\ \\__   / /\\ \\ \\     / /\\ \\ \\    /\\__ \\\n    / / /\\ \\___\\ / / /\\ \\ \\   / / /\\ \\_\\  / /_ \\ \\\n    \\ \\ \\ \\/___// / /  \\ \\_\\ / / /_/ / / / / /\\ \\ \\\n     \\ \\ \\     / / /   / / // / /__\\/ / / / /  \\/_/\n _    \\ \\ \\   / / /   / / // / /_____/ / / /\n/_/\\__/ / /  / / /___/ / // / /\\ \\ \\  / / /\n\\ \\/___/ /  / / /____\\/ // / /  \\ \\ \\/_/ /\n \\_____\\/   \\/_________/ \\/_/    \\_\\/\\_\\/\n");
    reset_color();

    // REVIEW
    short int type;
    do
    {
        printf("\n----------------\n");
        color(3);
        printf("Press 1: Random\n");
        color(2);
        printf("Press 2: Custom\n");
        color(1);
        printf("Press 0: Exit\n");
        reset_color();
        printf("----------------\n");
        printf("Choose array type: ");
        scanf("%hd", &type);
    }
    while (type < 0 || type > 2);

    if (type == 0)
    {
        return 1;
    }

    int n;
    printf("Size: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (type == 1)
    {
        int range;
        printf("Range: ");
        scanf("%d", &range);
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % range + 1;
        }

        color(7);
        printf("\nArray:");
        reset_color();
        for (int i = 0; i < n; i++)
        {
            printf(" %d", arr[i]);
        }
        printf("\n");    
    }
    else
    {
        color(7);
        printf("\nArray: ");
        reset_color();
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    short int sort_algorithm;
    do
    {
        printf("\n-----------------------\n");
        color(3);
        printf("Press 1: Insertion Sort\n");
        color(2);
        printf("Press 2: Selection Sort\n");
        color(6);
        printf("Press 3: Bubble Sort\n");
        color(4);
        printf("Press 4: Quick Sort\n");
        color(5);
        printf("Press 5: Merge Sort\n");
        color(1);
        printf("Press 6: Heap Sort\n");
        reset_color();
        printf("-----------------------\n");
        printf("Choose sorting algorithm: ");
        scanf("%hd", &sort_algorithm);
    }
    while (sort_algorithm < 0 || sort_algorithm > 6);

    switch (sort_algorithm)
    {
        case 1: print_complexity(6, 4, 0);
            insertion_sort(arr, n);
            break;
        case 2: print_complexity(6, 4, 2);
            selection_sort(arr, n);
            break;
        case 3: print_complexity(6, 4, 0);
            bubble_sort(arr, n);
            break;
        case 4: print_complexity(6, 3, 1);
            quick_sort(arr, 0, n - 1);
            break;
        case 5: print_complexity(5, 3, 1);
            merge_sort(arr, 0, n - 1);
            break;
        case 6: printf("Heap Sort\n");
            break;
        default: printf("Something unexpected happened\n");
            break;
    }

    color(7);
    printf("\nSorted Array:");
    reset_color();
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");

    free(arr);
    return 0;
}

void color(int c)
{
    printf("\033[1;3%dm", c);
}

void reset_color()
{
    printf("\033[0m");
}

void print_complexity(int w, int a, int b)
{
    char complexity[][10] = {"Ω(n)", "Ω(nlogn)", "Ω(n^2)", "Θ(nlogn)", "Θ(n^2)", "O(nlogn)", "O(n^2)"};

    color(7);
    printf("\nWorst Case: ");
    reset_color();
    printf("%s    ", complexity[w]);
    color(7);
    printf("Average Case: ");
    reset_color();
    printf("%s    ", complexity[a]);
    color(7);
    printf("Best Case: ");
    reset_color();
    printf("%s    \n", complexity[b]);
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (a[j] < a[j - 1])
        {
            swap(&a[j], &a[j - 1]);
            j--;
        }
    }
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = a[i], index;
        for (int j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                index = j;
            }
        }
        if (a[i] != min)
        {
            swap(&a[i], &a[index]);
        }
    }
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int partition(int a[], int l, int h)
{
    int i = l, j = l, p = h;

    while (i < h)
    {
        if (a[i] < a[p])
        {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }

    swap(&a[p], &a[j]);

    return j;
}

void quick_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }
}

void merge(int a[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int L[n1], H[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        H[j] = a[m + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= H[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = H[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = H[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}