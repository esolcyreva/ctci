#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int **a;
    int curr_stack_index;
    int curr_stack_len;
    int max_stack_len;
    int global_stack_len;
} SetOfStacks;

SetOfStacks *head = NULL;

void
set_of_stacks_init(int max_len, int max_stacks)
{
    if (head == NULL) {
        SetOfStacks *new = malloc(sizeof(SetOfStacks));
        head = new;
        head->max_stack_len = max_len;
        head->curr_stack_index = 0;
        head->curr_stack_len = 0;
        head->global_stack_len = 0;
        head->a = malloc(sizeof(int) * max_stacks);
        printf("\nInitiated max set of stacks = %d of len = %d\n",max_stacks, max_len);
    }
}

void push(int data)
{
    if (head->global_stack_len == 0) {
        head->a[head->curr_stack_index] = malloc(head->max_stack_len * sizeof(int));
        head->a[head->curr_stack_index][head->curr_stack_len] = data;
        head->curr_stack_len++;
        head->global_stack_len++;
        return;
    }
    else if (head->curr_stack_len == (head->max_stack_len)) {
        head->curr_stack_index++;
        head->curr_stack_len = 0;
        head->a[head->curr_stack_index] = malloc(head->max_stack_len * sizeof(int));
        head->a[head->curr_stack_index][head->curr_stack_len] = data;
        head->curr_stack_len++;
        head->global_stack_len++;
        return;
    } else {
        head->a[head->curr_stack_index][head->curr_stack_len] = data;
        head->curr_stack_len++;
        head->global_stack_len++;
        return;
    }
}

void get_size()
{
    printf("\nSize of stack = %d\n",(head->global_stack_len));
    return;
}

void pop()
{
    if (head->global_stack_len <= 0) {
        return;
    }
    if (head->curr_stack_len > 1) {
        head->a[head->curr_stack_len] = 0;
        head->curr_stack_len--;
    } else {
        head->a[head->curr_stack_len] = 0;
        if (head->curr_stack_index > 0) {
            head->curr_stack_len = head->max_stack_len;
        } else {
            head->curr_stack_len = 0;
        }
        head->curr_stack_index--;
        free(head->a[head->curr_stack_index + 1]);
        if (head->curr_stack_index < 0) {
            head->curr_stack_index = 0;
        }
    }
    head->global_stack_len--;
}

void peek()
{
    printf("\nStack top = %d\n", head->a[head->curr_stack_index][head->curr_stack_len - 1]);
}

void num_of_stacks()
{
    printf("\nNumber of Stacks = %d\n", head->curr_stack_index+1);
}

int main()
{
    set_of_stacks_init(3,10);
    push(1);
    push(3);
    push(44);
    num_of_stacks();
    push(27);
    push(38);
    push(9);
    num_of_stacks();
    push(7);
    push(50);
    push(8);
    push(49);
    num_of_stacks();
    peek();
    get_size();
    pop();
    peek();
    pop();
    peek();
    num_of_stacks();;
    get_size();
    return 0;
}
