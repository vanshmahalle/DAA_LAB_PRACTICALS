#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 20.0f
#define MAX_TEMP 50.0f
#define TARGET 30.0f

void generateData(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = MIN_TEMP + ((float)rand() / (float)(RAND_MAX)) * (MAX_TEMP - MIN_TEMP);
    }
}

// Comparator for qsort
int cmp(const void *a, const void *b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

// Linear Search: Find first index where temp >= TARGET
int linearSearch(float arr[], int n, float target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= target) return i;
    }
    return -1;
}

// Binary Search: where temp > TARGET
int binarySearch(float arr[], int n, float target) {
    int lo = 0, hi = n - 1, ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > target) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    srand((unsigned)time(NULL));

    int n = 1000000; 
    float arr[n];

    printf("Sensor Data Size (n) = %d\n\n", n);

    generateData(arr, n);
    qsort(arr, n, sizeof(float), cmp);

    // Print first 100 sorted values: 10 per line
    printf("First 100 Sorted Temperatures (10 per line):\n");
    for (int i = 0; i < 100 && i < n; i++) {
        printf("%6.2f ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    // Linear Search
    clock_t t0 = clock();
    int idx_lin = linearSearch(arr, n, TARGET);
    clock_t t1 = clock();
    double time_lin_ms = ((double)(t1 - t0) * 1000.0) / CLOCKS_PER_SEC;

    // Binary Search
    clock_t t2 = clock();
    int idx_bin = binarySearch(arr, n, TARGET);
    clock_t t3 = clock();
    double time_bin_ms = ((double)(t3 - t2) * 1000.0) / CLOCKS_PER_SEC;

    // Output
    if (idx_lin >= 0)
        printf("\nLinear Search (>= %.2f): Index = %d, Value = %.4f\n", TARGET, idx_lin, arr[idx_lin]);
    else
        printf("\nLinear Search: No temperature >= %.2f found.\n", TARGET);

    if (idx_bin >= 0)
        printf("Binary Search (> %.2f): Index = %d, Value = %.4f\n", TARGET, idx_bin, arr[idx_bin]);
    else
        printf("Binary Search: No temperature > %.2f found.\n", TARGET);

    printf("\nTime taken:\n");
    printf("  Linear Search: %.4f ms\n", time_lin_ms);
    printf("  Binary Search: %.4f ms\n", time_bin_ms);

    return 0;
}