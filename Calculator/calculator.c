#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MaxSize 100

int prec(char c) {
    if(c == '/' || c == '*') {
        return 2;
    }else if(c == '+' || c == '-') {
        return 1;
    }else {
        return 0;
    }
}

int evaluate(int num1, int num2, char op) {
    if(op == '/') {
        if(num2 == 0) {
        printf("Error: Division by zero");
        exit(0);
        }
        return num1/num2;
    }else if(op == '*') {
        return num1*num2;
    }else if(op == '+') {
        return num1+num2;
    }else if(op == '-') {
        return num1-num2;
    }else {
        return -1;
    }
}

int calculator(char *str) {
    int n = strlen(str) - 1;
    int nums[n];
    char ops[n];
    int top1=-1,top2=-1;

    for (int i = 0; i < n; i++)
    {
        if(str[i] == ' ') {
            continue;
        }else if(isdigit(str[i])) {
            int val = 0;

            while (i < n && isdigit(str[i]))
            {
                val = (val * 10) + (str[i] - '0');
                i++;
            }
            top1++;
            nums[top1] = val;
            i--;
        }else if(str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-') {
            while (top2 != -1 && prec(str[i]) <= prec(ops[top2]))
            {
                int val2 = nums[top1];
                top1--;
                int val1 = nums[top1];
                top1--;
                char op = ops[top2];
                top2--;

                top1++;
                nums[top1] = evaluate(val1,val2,op);
            }
            top2++;
            ops[top2] = str[i];
        }else{
            printf("Invalid Expression");
            return 0;
            break;
        }
    }
    while (top2 != -1)
    {
        int val2 = nums[top1];
        top1--;
        int val1 = nums[top1];
        top1--;

        char op = ops[top2];
        top2--;

        top1++;
        nums[top1] = evaluate(val1,val2,op);
    }
    return nums[top1];
}

int main() {
    char str[MaxSize];
    fgets(str, MaxSize, stdin);

    printf("%d",calculator(str));
}