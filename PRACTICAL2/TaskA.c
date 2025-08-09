#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <float.h> 
#define MAX 10 
#define INF 99999.0 


        void changeNear(int near[], double arr[][MAX], int used[], int nv, int n) { 

     for(int i=0; i<n; i++) { 

        if(!used[i]) { 

              if(near[i] == -1 || arr[i][nv] < arr[i][near[i]]) { 

                near[i] = nv; 

            } 

        } 

    } 

} 


void prim(double arr[][MAX], int n) { 

    int used[MAX] = {0}; 

    int near[MAX]; 

    double sum = 0.0; 


    for(int i=0; i<n; i++) near[i] = -1; 

    used[0] = 1; 

    changeNear(near, arr, used, 0, n); 

    printf("\nMST (Prim's):\n"); 

    printf("C#\t<-->\tC#\tCost\n"); 


    for(int e=1; e<n; e++) { 

        double min = DBL_MAX; 

        int v = -1; 

        for(int i=0; i<n; i++) { 

            if(!used[i] && near[i] != -1 && arr[i][near[i]] < min) { 

                min = arr[i][near[i]]; 

                v = i; 

            } 

        } 

        if(v != -1) { 

            printf("C%d\t<-->\tC%d\t%.2lf\n", near[v]+1, v+1, arr[v][near[v]]); 

            sum += arr[v][near[v]]; 

            used[v] = 1; 

            changeNear(near, arr, used, v, n); 

        } 

    } 


    printf("\nTotal Cost: %.2lf\n", sum); 

} 

  

int main() { 

    int n; 

    double arr[MAX][MAX]; 

    char inp[20]; 

  

    printf("Enter number of cities: "); 

    scanf("%d", &n); 

  

    printf("Enter cost/distance (-1 or infinity for no path):\n"); 

  

    for(int i=0; i<n; i++) { 

        for(int j=0; j<n; j++) { 

            if(i == j) arr[i][j] = 0; 

            else { 

                printf("C%d to C%d: ", i+1, j+1); 

                scanf("%s", inp); 

  

                for(int k=0; inp[k]; k++) inp[k] = tolower(inp[k]); 

  

                if(strcmp(inp,"infinity")==0 || strcmp(inp,"inf")==0 || strcmp(inp,"-1")==0) { 

                    arr[i][j] = INF; 

                } else { 

                    sscanf(inp, "%lf", &arr[i][j]); 

                } 

            } 

        } 

    } 

  

    printf("\nMatrix:\n"); 

    for(int i=0; i<n; i++) { 

        for(int j=0; j<n; j++) { 

            if(arr[i][j] == INF) printf(" INF "); 

            else printf("%5.2lf ", arr[i][j]); 

        } 

        printf("\n"); 

    } 

  

    prim(arr, n); 

    return 0; 

} 