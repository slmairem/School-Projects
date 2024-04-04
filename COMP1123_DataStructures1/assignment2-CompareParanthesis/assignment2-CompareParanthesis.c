#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

int compare(char par1, char par2)
{
    if (par1 == '{' && par2 == '}')
    {
        return 1;
    }
    if (par1 == '(' && par2 == ')')
    {
        return 1;
    }
    if (par1 == '[' && par2 == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesis(char *arr)
{
    LINKED_STACK stack;
    stack = linked_stack_init();

    int i, result;
    char *temp;

    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
            linked_stack_push(stack, &(arr[i]));
        }

        else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            if (linked_stack_is_empty(stack))
            {
                result = 0;
                break;
            }

            temp = linked_stack_top(stack);
            if (compare(*temp, arr[i])==0)
            {
                result = 0;
                break;
            }

            linked_stack_pop(stack);
        }

        if (linked_stack_is_empty(stack))
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

int main()
{
    char *arr = "while(c[i]==pow(a,b)){i++;}";

    if (parenthesis(arr))
    {
        printf("The parenthesis is balanced");
    }

    else
    {
        printf("The parenthesis is not balanced");
    }

    return 0;
}
