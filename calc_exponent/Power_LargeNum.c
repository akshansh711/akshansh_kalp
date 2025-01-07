#include<stdio.h>


long long modulo_func(long long base, long long exponent, long long modulo) {
    long long resultMod = 1;
    base = base % modulo;

    while (exponent > 0)
    {
        if(exponent % 2 == 1) {
            resultMod = (resultMod * base) % modulo;
        }

        base = (base * base) % modulo;
        exponent = exponent / 2;
    }
    return resultMod;
}


long long validInput(const char *sentence,long long min) {
    long long value;
    printf("%s ",sentence);
    while (scanf("%lld",&value) != 1 || value < min)
    {
        printf("Invalid input\n");
        return -1;

    }
    return value;
}

int main() {
    long long base,modulo,exponent;

    base = validInput("Enter base value : ",0);
    if(base == -1) {
        return 0;
    }

    exponent = validInput("Enter exponent value : ",0);

    if(exponent == -1) {
        return 0;
    }

    modulo = validInput("Enter modulo value : ",2);
    
    if(modulo == -1) {
        return 0;
    }
    
    long long ans = modulo_func(base,exponent,modulo);
    printf("%lld", ans);

    return 0;
}