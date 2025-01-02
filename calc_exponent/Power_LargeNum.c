#include<stdio.h>

#define MAX 10000

int multiply(int x,int result[], int size) {
    int carry = 0;
    int prod;

    for (int i = 0; i < size; i++)
    {
        prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    
    while (carry)
    {
        result[size] = carry % 10;
        carry = carry/10;
        size++;
    }
    
    return size;
}

int modulo(int x, int n, int m) {
    long long resultMod = 1;
    long long baseMod = x % m;

    while (n > 0)
    {
        if(n % 2 == 1) {
            resultMod = (resultMod * baseMod) % m;
        }

        baseMod = (baseMod * baseMod) % m;
        n = n / 2;
    }
    return resultMod;
}

int power(int x, int n, int m) {
    int size = 0;
    int result[MAX];
    int temp = x;

    while (temp != 0)
    {
        result[size] = temp % 10;
        size++;
        temp = temp / 10;
    }
    
    for (int i = 2; i <= n; i++)
    {
        size = multiply(x,result, size);
    }
    
    printf("x ^ n = ");

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d",result[i]);
    }
    
    printf("\n");
    printf("x ^ n %% m = %d",modulo(x,n,m));
}

int main() {
    int x,m,n;

    printf("Enter base value : ");
    scanf("%d",&x);
    printf("Enter exponent value : ");
    scanf("%d",&n);
    printf("Enter modulo value : ");
    scanf("%d",&m);

    power(x,n,m);
}