#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define str_size 100
#define result_size 20

void lowerCase(char str[]){
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
    str[i] = '\0';
}

char* pangrams(char* s) {
    int i, count = 0;
    int seen[26] = {0};
    static char result[result_size];
    lowerCase(s);
    for (i = 0; i < strlen(s); i++) {
        char currentChar = s[i];
        if (currentChar >= 'a' && currentChar <= 'z' && !seen[currentChar - 'a']) {
            count++;
            seen[currentChar - 'a'] = 1;
        }
    }
    strcpy(result, (count == 26) ? "pangram" : "not pangram");
    return result;
}

int main(){
    char str[str_size], *result;
    fgets(str, sizeof(str), stdin);
    result = pangrams(str);
    puts(result);
    return 0;
}