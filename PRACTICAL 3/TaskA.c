#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Box {
    int weight;
    int profit;
    double ratio;
};

int compWeight(const void *a, const void *b) {
      struct Box *x = (struct Box *)a;
    struct Box *y = (struct Box *)b;
    return x->weight - y->weight;
}

int compProfit(const void *a, const void *b) {
       struct Box *x = (struct Box *)a;
    struct Box *y = (struct Box *)b;
    return y->profit - x->profit;
}

int compRatio(const void *a, const void *b) {
    struct Box *x = (struct Box *)a;
       struct Box *y = (struct Box *)b;
       if (y->ratio > x->ratio) return 1;
      if (y->ratio < x->ratio) return -1;
    return 0;
}

double knapsack(struct Box box[], int n, int capacity) {
       double totalProfit = 0.0;
      int curWeight = 0;
 
    for (int i = 0; i < n; i++) {
        if (box[i].weight == 0) continue; 
           if (curWeight + box[i].weight <= capacity) {
            curWeight += box[i].weight;
            totalProfit += box[i].profit;
        }   else {
            int remain = capacity - curWeight;
            totalProfit += box[i].profit * ((double)remain / box[i].weight);
             break;
        }
     }
    return totalProfit;
}

int main() {
      int weights[] = {7,0,30,22,80,94,11,81,70,64,59,18,0,36,3,8,15,42,9,0,42,47,52,32,26,48,55,
                     6,29,84,2,4,18,56,7,29,93,44,71,3,86,66,31,65,0,79,20,65,52,13};
      int profits[] = {360,83,59,130,431,67,230,52,93,125,670,892,600,38,48,147,78,256,63,17,120,
                     164,432,35,92,110,22,42,50,323,514,28,87,73,78,15,26,78,210,36,85,189,274,
                     43,33,10,19,389,276,312};

      int n = sizeof(weights) / sizeof(weights[0]);
      int capacity = 850;

    struct Box box[n];
    for (int i = 0; i < n; i++) {
         box[i].weight = weights[i];
        box[i].profit = profits[i];
        if (weights[i] != 0)
            box[i].ratio = (double)profits[i] / weights[i];
         else
            box[i].ratio = 0.0;
    }

    clock_t start, end;
    double profit, timeTaken;

    qsort(box, n, sizeof(box[0]), compWeight);
       start = clock();
      profit = knapsack(box, n, capacity);
      end = clock();
      timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Minimum Weight -> Profit: %.2f, Time: %f sec\n", profit, timeTaken);

    qsort(box, n, sizeof(box[0]), compProfit);
    start = clock();
    profit = knapsack(box, n, capacity);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum Profit -> Profit: %.2f, Time: %f sec\n", profit, timeTaken);

    qsort(box, n, sizeof(box[0]), compRatio);
    start = clock();
    profit = knapsack(box, n, capacity);
    end = clock();
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Profit/Weight Ratio -> Profit: %.2f, Time: %f sec\n", profit, timeTaken);

    return 0;
}
