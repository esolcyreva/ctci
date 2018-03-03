#include <stdio.h>
#include <string.h>

void is_valid(char **str1)
{
    char *str = *str1;
    int currptr = -1;
    int len = strlen(str);
    int i = 0;
    char stack[len];
    char ch;
    memset(&stack, 0, len);
    printf("\nlen of string = %d, string = %s\n", len, str);
    while ((ch=*str) != '\0') {
        printf("\nvalue of i = %d, char = %c\n", i, *str);
            if (*str == ')')
            {
                if (strcmp(&stack[currptr], "(") != 0) {
                    currptr++;
                    stack[currptr] = *str;
                } else {
                    stack[currptr] = '\0';
                    currptr--;
                }
            } else if (*str == ']')
            {
                if (strcmp(&stack[currptr], "[") != 0) {
                    currptr++;
                    stack[currptr] = *str;
                } else {
                    stack[currptr] = '\0';
                    currptr--;
                }
            } else if (*str == '}')
            {
                if (strcmp(&stack[currptr], "{") != 0) {
                    currptr++;
                    stack[currptr] = *str;
                } else {
                    stack[currptr] = '\0';
                    currptr--;
                }
            } else 
            {
                currptr++;
                stack[currptr] = *str;
            }
        printf("\nstack = %s\n", stack);
        i++;
        str++;
    }
    if (!strlen(stack)) {
        printf("\nValid Parentheses\n");
    } else {
        printf("\nInValid Parentheses\n");
    }
}

int main()
{
    char *str = {"([]){(())[]}"}; 
    is_valid(&str);
}
