#include<stdio.h>
#include<string.h>

int * matchingStrings(char strings[][20], char queries[][20], int results[], int n, int q){
    int i, j, count;
    for(i=0; i<q; i++){
        count = 0;
        for(j=0; j<n; j++){
            if(strcmp(queries[i], strings[j]) == 0)
                count++;
        }
        results[i] = count;
    }
    // for(i=0; i<q; i++){
    //     printf("%d\n", results[i]);
    // }
    return results;
}

int main(){
    int n, i, q;
    scanf("%d", &n);
    getchar();
    char strings[n][20];
    for(i=0; i<n; i++){
        fgets(strings[i], sizeof(strings[i]), stdin);
    }
    scanf("%d", &q);
    getchar();
    char queries[q][20];
    int results[q], *finalAns;
    for(i=0; i<q; i++){
        fgets(queries[i], sizeof(queries[i]), stdin);
    }
    finalAns = matchingStrings(strings, queries, results, n, q);
    for(i=0; i<q; i++){
        printf("%d\n", finalAns[i]);
    }
    return 0;
}