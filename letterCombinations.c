#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genComb(char* in, int pos, char* temp, char** out, int* count, char* map[]) {
    if (pos == strlen(in)) {
        out[*count] = (char*)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(out[*count], temp);
        (*count)++;
        return;
    }

    int dig = in[pos] - '0';
    for (int i = 0; map[dig][i] != '\0'; i++) {
        temp[pos] = map[dig][i];
        genComb(in, pos + 1, temp, out, count, map);
    }
}

void findComb(char* in) {
    if (strlen(in) == 0) {
        printf("[]\n");
        return;
    }

    char* map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    
    int maxComb = 1;
    for (int i = 0; i < strlen(in); i++) {
        int dig = in[i] - '0';
        maxComb *= strlen(map[dig]);
    }


    char** out = (char**)malloc(maxComb * sizeof(char*));
    int count = 0;
    char temp[50] = "";

    genComb(in, 0, temp, out, &count, map);

    // Print output
    printf("[");
    for (int i = 0; i < count; i++) {
        printf("\"%s\"", out[i]);
        if (i < count - 1) {
            printf(", ");
        }
        free(out[i]);  
    }
    printf("]\n");
    free(out);  
}

int main() {
    char in[20];
    printf("Enter digits: ");
    scanf("%s", in);
    findComb(in);
    return 0;
}
