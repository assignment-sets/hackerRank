#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    int i, j, flag = 0;
    int *visited = (int *)malloc(sizeof(int) * B_count);
    char *result = (char *)malloc(sizeof(char) * 4);

    for(i=0; i<B_count; i++)
        visited[i] = 0;

    for(i=0; i<A_count; i++){
        int lookFor = k - A[i];
        for(j=0; j<B_count; j++){
            if(lookFor == B[j] && visited[j] != 1){
                visited[j] = 1;
                break;
            }
        }
    }
    
    for(i=0; i<B_count; i++){
        if(visited[i] == 0){
            flag = 1;
            break;
        }
    }

    free(visited);

    if(flag == 0){
        strcpy(result, "YES");
    }
    else{
        strcpy(result, "NO");
    }
    return result;
}

int main(){
    return 0;
}