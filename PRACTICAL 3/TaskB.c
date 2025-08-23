#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, finish, profit;
    char name[5];
};

int comp(const void *a, const void *b) {
      struct Activity *x = (struct Activity *)a;
      struct Activity *y = (struct Activity *)b;
    return x->finish - y->finish;
}

void activitySelection(struct Activity arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), comp);
     printf("Selected Activities:\n");
    int i = 0;
    printf("%s ", arr[i].name);
    int totalProfit = arr[i].profit;
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
         printf("%s ", arr[j].name);
            totalProfit += arr[j].profit;
            i = j;
        }
    }
    printf("\nTotal Profit = %d\n", totalProfit);
}

int main() {
    struct Activity arr[] = {
        {1,4,10,"A1"}, {3,5,15,"A2"}, {0,6,14,"A3"},
        {5,7,12,"A4"}, {3,9,20,"A5"}, {5,9,30,"A6"},
        {6,10,32,"A7"}, {8,11,28,"A8"}, {8,12,30,"A9"},
        {2,14,40,"A10"}, {12,16,45,"A11"}
    };
    int n = sizeof(arr)/sizeof(arr[0]);
    activitySelection(arr, n);
    return 0;
}
