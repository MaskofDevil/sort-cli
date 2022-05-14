#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define VSIZE 20
#define VMAX_HEIGHT 20
#define VDELAY 100000
 
void color(int c);
void reset_color();
void print_complexity(int w, int a, int b);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);
void quick_sort(int a[], int l, int h);
void merge_sort(int a[], int l, int h);
void heap_sort(int a[], int n);
void visual_sort_menu(int arr[], int n);

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
        color(7);
        printf("Press 7: Visual Sort\n"); // <-- Add this line
        reset_color();
        printf("-----------------------\n");
        printf("Choose sorting algorithm: ");
        scanf("%hd", &sort_algorithm);
    }
    while (sort_algorithm < 0 || sort_algorithm > 7);

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
        case 6: print_complexity(5, 3, 1);
            heap_sort(arr, n);
            break;
        case 7:
            visual_sort_menu(arr, n); // Pass arr and n
            free(arr);
            return 0;
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

void heapify(int a[], int n, int p)
{
    int large = p, l = 2 * p + 1, r = 2 * p + 2;

    if (l < n && a[l] > a[large])
    {
        large = l;
    }

    if (r < n && a[r] > a[large])
    {
        large = r;
    }

    if (large != p)
    {
        swap(&a[p], &a[large]);
        heapify(a, n, large);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void v_clear_screen() {
    printf("\033[H\033[J");
}

void v_draw_vertical_bars(int arr[], int n, int highlight1, int highlight2) {
    v_clear_screen();

    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max) max = arr[i];

    for (int row = max; row >= 1; row--) {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= row) {
                if (i == highlight1 || i == highlight2)
                    printf("\033[31m\u2588\033[0m ");
                else
                    printf("\u2588 ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%2d", arr[i]);
    }
    printf("\n");

    usleep(VDELAY);
}

void v_bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            v_draw_vertical_bars(arr, n, j, j + 1);
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                v_draw_vertical_bars(arr, n, j, j + 1);
            }
        }
    }
    v_draw_vertical_bars(arr, n, -1, -1);
}

void v_insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            v_draw_vertical_bars(arr, n, j, j + 1);
            j--;
        }
        arr[j + 1] = key;
        v_draw_vertical_bars(arr, n, j + 1, i);
    }
    v_draw_vertical_bars(arr, n, -1, -1);
}

void v_selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            v_draw_vertical_bars(arr, n, min_idx, j);
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            v_draw_vertical_bars(arr, n, i, min_idx);
        }
    }
    v_draw_vertical_bars(arr, n, -1, -1);
}

void v_quick_sort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            v_draw_vertical_bars(arr, n, j, high);
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                v_draw_vertical_bars(arr, n, i, j);
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        v_draw_vertical_bars(arr, n, i + 1, high);

        v_quick_sort(arr, low, i, n);
        v_quick_sort(arr, i + 2, high, n);
    }
}

void v_merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        v_draw_vertical_bars(arr, n, k - 1, -1);
    }
    while (i < n1) arr[k++] = L[i++], v_draw_vertical_bars(arr, n, k - 1, -1);
    while (j < n2) arr[k++] = R[j++], v_draw_vertical_bars(arr, n, k - 1, -1);
}

void v_merge_sort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;
        v_merge_sort(arr, l, m, n);
        v_merge_sort(arr, m + 1, r, n);
        v_merge(arr, l, m, r, n);
    }
}

void v_shuffle_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % VMAX_HEIGHT + 1;
    }
}

void visual_sort_menu(int arr[], int n) {
    int vis_arr[VSIZE];
    int vis_n = n > VSIZE ? VSIZE : n; // Limit to VSIZE for visualization

    // Copy user's array (up to VSIZE elements)
    for (int i = 0; i < vis_n; i++) {
        vis_arr[i] = arr[i];
    }

    printf("\nVisual Sort Algorithms:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("Choice: ");

    int choice;
    scanf("%d", &choice);

    v_draw_vertical_bars(vis_arr, vis_n, -1, -1);

    switch (choice) {
        case 1:
            v_bubble_sort(vis_arr, vis_n);
            break;
        case 2:
            v_insertion_sort(vis_arr, vis_n);
            break;
        case 3:
            v_selection_sort(vis_arr, vis_n);
            break;
        case 4:
            v_quick_sort(vis_arr, 0, vis_n - 1, vis_n);
            v_draw_vertical_bars(vis_arr, vis_n, -1, -1);
            break;
        case 5:
            v_merge_sort(vis_arr, 0, vis_n - 1, vis_n);
            v_draw_vertical_bars(vis_arr, vis_n, -1, -1);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    color(7);
    printf("\nSorted Array:");
    reset_color();
    for (int i = 0; i < vis_n; i++) {
        printf(" %d", vis_arr[i]);
    }
    printf("\n\n");

    // Print time complexity AFTER the sorted array
    switch (choice) {
        case 1:
            print_complexity(6, 4, 0); // Bubble Sort
            break;
        case 2:
            print_complexity(6, 4, 0); // Insertion Sort
            break;
        case 3:
            print_complexity(6, 4, 2); // Selection Sort
            break;
        case 4:
            print_complexity(6, 3, 1); // Quick Sort
            break;
        case 5:
            print_complexity(5, 3, 1); // Merge Sort
            break;
    }
}