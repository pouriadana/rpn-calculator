#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //c99

/*Prototype*/
bool push(int);
int pop(void);
bool is_empty(void);
void stack_underflow();
void stack_overflow();

struct stack{
    int n;
    struct stack *next;
};
struct stack *top = NULL;

int main()
{
    int i, ch;
    printf("--> ");
    //scanf(" %d", &i);

    while((ch = getchar()) != '=')
    {
        if(ch == '*' || ch == '+' || ch == '-' || ch == '/')
        {
            int temp = pop();
            switch(ch)
            {
                case '+':   {temp += pop(); push(temp);}
                            break;
                case '-':   {temp -= pop(); push(temp);}
                            break;
                case '*':   {temp *= pop(); push(temp);}
                            break;
                case '/':   {temp /= pop(); push(temp);}
                            break;
                default:    break;
            }
        }
        else
        {
            ch -= 48;
            push(ch);
        }
    }

    if(ch == '=')
        printf("\nSum is: %d", top->n);
/*
    while(i){
        scanf(" %d", &i);

        push(i);
    }
    while(top!= NULL)
    {
        printf("%d", top->n);
        top = top->next;
    }
*/

    return 0;
}

bool push(int n)
{
    struct stack *temp;
    temp = malloc(sizeof(struct stack));
    if (temp == NULL){
        return false;
    }
    temp->n = n;
    temp->next = top;
    top = temp;
    //free(temp);

    return true;
}

int pop(void)
{
    int temp;
    struct stack *s_temp;
    if(is_empty())
        stack_underflow();
    s_temp = top;
    temp = top->n;
    top = top->next;
    free(s_temp);
    return temp;
}

bool is_empty()
{
    return top == NULL;
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}