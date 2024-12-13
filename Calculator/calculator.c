#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int precedence(char operator)
{
    if (operator== '/' || operator== '*')
    {
        return 2;
    }
    else if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int evaluate(int num1, int num2, char op)
{
    if (op == '/')
    {
        if (num2 == 0)
        {
            printf("Error: Division by zero");
            exit(0);
        }
        return num1 / num2;
    }
    else if (op == '*')
    {
        return num1 * num2;
    }
    else if (op == '+')
    {
        return num1 + num2;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else
    {
        return -1;
    }
}

void calculateTop(int nums[], char ops[], int *top1, int *top2)
{
    int val2 = nums[*top1];
    (*top1)--;
    int val1 = nums[*top1];
    (*top1)--;
    char op = ops[*top2];
    (*top2)--;

    (*top1)++;
    nums[*top1] = evaluate(val1, val2, op);
}

int calculator(char *str)
{
    int n = strlen(str) - 1;
    int nums[n];
    char operator[n];
    int top1 = -1, top2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            int val = 0;

            while (i < n && (str[i] >= '0' && str[i] <= '9'))
            {
                val = (val * 10) + (str[i] - '0');
                i++;
            }
            top1++;
            nums[top1] = val;
            i--;
        }
        else if (str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-')
        {
            while (top2 != -1 && precedence(str[i]) <= precedence(operator[top2]))
            {
                calculateTop(nums, operator, & top1, &top2);
            }
            top2++;
            operator[top2] = str[i];
        }
        else
        {
            printf("Invalid Expression");
            return 0;
        }
    }
    while (top2 != -1)
    {
        calculateTop(nums, operator, & top1, &top2);
    }
    return nums[top1];
}

int main()
{
    char *str, c;
    int i = 0, j = 1;

    str = (char *)malloc(sizeof(char));
    printf("Enter String : ");

    while (c != '\n')
    {
        c = getc(stdin);

        str = (char *)realloc(str, j * sizeof(char));
        str[i] = c;

        i++;
        j++;
    }
    str[i] = '\0';

    printf("%d", calculator(str));
    return 0;
}