#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(float arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }
}

float findMinPairwise(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        int isMin = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j] < arr[i]) {
                isMin = 0;
                break;
            }
        }
        if (isMin) return arr[i];
    }
    return arr[0]; 
}

float findMaxPairwise(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        int isMax = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i]) {
                isMax = 0;
                break;
            }
        }
        if (isMax) return arr[i];
    }
    return arr[0]; 
}

int main() {
    int n = 100; 
    float temperature[n], pressure[n];

    srand(time(NULL));
    generateData(temperature, n, -20, 50);
    generateData(pressure, n, 950, 1050);

    // Print first 10 values
     printf("First 10 Temperature Values:\n");
     for (int i = 0; i < 10 && i < n; i++) {
        printf("%.2f°C  ", temperature[i]);
    }
    printf("\n");

    printf("First 10 Pressure Values:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%.2f hPa  ", pressure[i]);
    }
    printf("\n");

    clock_t start, end;
    double duration_s, duration_ms;

    // Minimum Temperature (Pairwise)
     start = clock();
    float minTemp = findMinPairwise(temperature, n);
    end = clock();
    duration_s = (double)(end - start) / CLOCKS_PER_SEC;
    duration_ms = duration_s * 1000;
    printf("\nMinimum Temperature (Pairwise) = %.2f°C\n", minTemp);
    printf("Time for Pairwise Comparison (Temperature, n=%d): %.8f seconds (%.4f ms)\n", n, duration_s, duration_ms);

    // Maximum Pressure (Pairwise)
    start = clock();
    float maxPressure = findMaxPairwise(pressure, n);
    end = clock();
    duration_s = (double)(end - start) / CLOCKS_PER_SEC;
    duration_ms = duration_s * 1000;
    printf("Maximum Pressure (Pairwise) = %.2f hPa\n", maxPressure);
    printf("Time for Pairwise Comparison (Pressure, n=%d): %.8f seconds (%.4f ms)\n", n, duration_s, duration_ms);

    return 0;
}
