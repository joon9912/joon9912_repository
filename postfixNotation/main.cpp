#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char OPERATORS[] = "+-*/";
static int PRECEDENCE[] {1, 1, 2, 2};

typedef struct ArrayStack {
    int top;
    int capacity;
    int* arr;
} Stack;

Stack *operand_stack;
Stack *operator_stack;

void free_stack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

Stack *createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int peek(Stack *stack) {
    // top()
    if (isEmpty(stack))
        return -1;
    return stack->arr[stack->top];
}

void push(Stack *stack, int data) {
    if (isFull(stack))
        printf("Stack is Full\n");
    else {
        stack->arr[++stack->top] = data;
        // printf("%d pushed to stack\n", data);
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack))
        return -1;
    else
        return stack->arr[stack->top--];
}

int is_operator(char ch) {
    for (int i = 0 ; i < strlen(OPERATORS); ++i)
        if (OPERATORS[i] == ch)
            return i;
    return -1;
}

void handle_exception(const char *err_msg) {
    printf("%s\n", err_msg);
    exit(1);
}

int eval_op(char op) {
    if (isEmpty(operand_stack))
        handle_exception("Syntax Error : Stack empty in eval_op.");
    int rhs = pop(operand_stack);
    if (isEmpty(operand_stack))
        handle_exception("Syntax Error : Stack empty in eval_op.");
    int lhs = pop(operand_stack);
    int result = 0;
    switch (op) {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
    }
    return result;
}

int eval(char *expr) {
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            // operand
            int value = atoi(token);
            push(operand_stack, value);
        }
        else if (is_operator(token[0]) > -1) {
            // operator
            int result = eval_op(token[0]);
            push(operand_stack, result);
        }
        else {
            handle_exception("Syntax Error : invalid character encountered.");
        }
        token = strtok(NULL, " ");
    }
    if (isEmpty(operand_stack))
        handle_exception("Syntax Error : Stack empty in eval_op.");
    int answer = pop(operand_stack);
    if (isEmpty(operand_stack))
        return answer;
    else {
        handle_exception("Syntax Error : Stack should be empty.");
        return -1;
    }
}

int precedence(char op) {
    return PRECEDENCE[is_operator(op)];
}

char *process_op(char op, char *pos) {
    if (isEmpty(operator_stack))
        push(operator_stack, op);
    else {
        char top_op = peek(operator_stack);
        if (precedence(op) > precedence(top_op))
            push(operator_stack, op);
        else {
            while (!isEmpty(operator_stack) && precedence(op) <= precedence(top_op)) {
                pop(operator_stack);
                sprintf(pos, "%c ", top_op);
                pos += 2;
                if (!isEmpty(operator_stack))
                    top_op = (char)peek(operator_stack);
            }
            push(operator_stack, op);
        }
    }
    return pos;
}

char *convert(char *infix) {
    char *postfix = (char *)malloc(strlen(infix) + 1);
    char *pos = postfix;

    char *token = strtok(infix, " ");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            // operand
            sprintf(pos, "%s ", token);
            pos += (strlen(token) + 1);
        }
        else if (is_operator(token[0]) > -1) // operator
            pos = process_op(token[0], pos);
        else
            handle_exception("Syntax Error : Invalid character encotuntered.");
        token = strtok(NULL, " ");
    }

    while (!isEmpty(operator_stack)) {
        char op = (char)pop(operator_stack);
        sprintf(pos, "%c ", op);
        pos += 2;
    }
    *pos = '\0';
    return postfix;
}

int read_line(FILE *fp, char str[], int limit) {
    int ch, i = 0;

    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}

int main() {
    int size = 100;
    char str[size];
    operand_stack = createStack(size);
    operator_stack = createStack(size);

    // read_line(stdin, str, size);
    // printf("%d\n", eval(str));

    read_line(stdin, str, size);
    printf("%s\n", convert(str));

    free_stack(operand_stack);
    free_stack(operator_stack);

    return 0;
}