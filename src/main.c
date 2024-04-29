#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int32_t top;
    int32_t array[9001];
} Stack;

Stack *create_stack() {
    Stack *new = malloc(sizeof(Stack));
    new->top = -1;
    return new;
}

void push(Stack *stack, int32_t value) { stack->array[++stack->top] = value; }

int32_t pop(Stack *stack) { return stack->array[stack->top--]; }

int32_t peek(Stack *stack) { return stack->array[stack->top]; }

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: bf {program}\n");
        return 1;
    }

    int8_t memory[30000] = {0};
    int32_t ip, dp = 0;
    Stack *loop_stack = create_stack();

    while (ip < strlen(argv[1])) {
        switch (argv[1][ip]) {
        case '>':
            dp++;
            if (dp > 29999)
                dp = 0;
            break;
        case '<':
            dp--;
            if (dp < 0)
                dp = 29999;
            break;
        case '+':
            memory[dp]++;
            break;
        case '-':
            memory[dp]--;
            break;
        case '.':
            printf("%c", memory[dp]);
            break;
        case ',':
            scanf("%c", &memory[dp]);
            break;
        case '[':
            push(loop_stack, ip);
            break;
        case ']':
            if (memory[dp] == 0) {
                pop(loop_stack);
                break;
            }
            ip = peek(loop_stack);
            break;
        }
        ip++;
    }
    printf("\n");
    return 0;
}
