#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA 26

typedef struct {
    char ch;
    int freq;
} CharFreq;

char* rearrange(char* str) {
    int len = strlen(str);
    CharFreq freqMap[ALPHA] = {0};
    
    for (int i = 0; i < len; i++) {
        int idx = str[i] - 'a';
        if (idx >= 0 && idx < ALPHA) {
            freqMap[idx].ch = str[i];
            freqMap[idx].freq++;
        }
    }
    
    for (int i = 0; i < ALPHA - 1; i++) {
        for (int j = i + 1; j < ALPHA; j++) {
            if (freqMap[i].freq < freqMap[j].freq) {
                CharFreq temp = freqMap[i];
                freqMap[i] = freqMap[j];
                freqMap[j] = temp;
            }
        }
    }
    
    if (freqMap[0].freq > (len + 1) / 2) {
        return strdup("Not possible");
    }
    
    char* res = (char*)malloc((len + 1) * sizeof(char));
    if (!res) {
        return strdup("Memory allocation failed");
    }
    res[len] = '\0';
    int pos = 0;
    
    for (int i = 0; i < ALPHA && freqMap[i].freq > 0; i++) {
        while (freqMap[i].freq > 0) {
            if (pos >= len) {
                pos = 1;
            }
            res[pos] = freqMap[i].ch;
            pos += 2;
            freqMap[i].freq--;
        }
    }
    
    return res;
}

int main() {
    char *input = (char *)malloc(1024 * sizeof(char));
    if (!input) {
        return 1;
    }
    printf("Enter a string to rearrange: ");
    scanf("%s", input);
    char* output = rearrange(input);
    printf("Rearranged string: %s\n", output);
    free(output);
    free(input);
    return 0;
}
