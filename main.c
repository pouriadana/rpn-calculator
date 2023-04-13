#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //c99 ONLY

/*Prototype*/
bool push(int);
int pop(void);
bool is_empty(void);
void stack_underflow();
void stack_overflow();

/*External Variable*/
struct stack{
    int n;
    struct stack *next;
};
struct stack *top = NULL;

int main()
{
    int ch;
    printf("Enter mathematical expression\n" 
           "(Ex. 1 2 3 - + = evaluates to 1+(2-3))\n");
    printf("--> ");

    while((ch = getchar()) != '=')
    {
        if(ch == ' ') continue;
        else if(ch == '*' || ch == '+' || ch == '-' || ch == '/')
        {
            int temp = pop();
            switch(ch)
            {
                case '+':   {push(pop() + temp);}
                            break;
                case '-':   {push(pop() - temp);}
                            break;
                case '*':   {push(pop() * temp);}
                            break;
                case '/':   {push(pop() / temp);}
                            break;
                default:    break;
            }
        }
        else
            push(ch -= 48);
    }

    if(ch == '=')
        printf("\nSum is: %d", top->n);
    return 0;

/*  DEBUG
    while(i){
        scanf(" %d", &i);

        push(i);
    }
    while(top!= NULL)
    {
        printf("%d", top->n);
        top = top->next;
    }
    DEBUG
*/  
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

    return true;
}

int pop(void)
{
    int temp;
    struct stack *temp_node;
    if(is_empty())
        stack_underflow();
    temp_node = top;
    temp = top->n;
    top = top->next;
    free(temp_node);
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