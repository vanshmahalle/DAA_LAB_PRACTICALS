#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateData(float arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + ((float)rand() / RAND_MAX) * (max - min);
    }
}

float findMin(float arr[], int n) {
    float min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

float findMax(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    int n = 100;
    float temperature[n], pressure[n];

    srand(time(NULL));
    generateData(temperature, n, -20, 50);
    generateData(pressure, n, 950, 1050);

    printf("\nSample Generated Data (first 10 values)\n");
    printf("Temperature (°C): ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", temperature[i]);
    }
    printf("\nPressure (hPa): ");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", pressure[i]);
    }
    printf("\n\n");

    clock_t start, end;
    double duration_s, duration_ms;

    // Minimum Temperature
    start = clock();
    float minTemp = findMin(temperature, n);
    end = clock();
    duration_s = (double)(end - start) / CLOCKS_PER_SEC;
    duration_ms = duration_s * 1000;
    printf("Minimum Temperature = %.2f°C\n", minTemp);
    printf("Time for Linear Search (Temperature, n=%d): %.8f seconds (%.4f ms)\n", n, duration_s, duration_ms);

    // Maximum Pressure
    start = clock();
    float maxPressure = findMax(pressure, n);
    end = clock();
    duration_s = (double)(end - start) / CLOCKS_PER_SEC;
    duration_ms = duration_s * 1000;
    printf("Maximum Pressure = %.2f hPa\n", maxPressure);
    printf("Time for Linear Search (Pressure, n=%d): %.8f seconds (%.4f ms)\n", n, duration_s, duration_ms);

    return 0;
}