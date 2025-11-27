#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* Simple dynamic stack for long long integers */
typedef struct {
    long long *data;
    int top;
    int capacity;
} LLStack;

LLStack *create_stack(int capacity) {
    LLStack *s = (LLStack*)malloc(sizeof(LLStack));
    s->data = (long long*)malloc(sizeof(long long) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

void free_stack(LLStack *s) {
    if (!s) return;
    free(s->data);
    free(s);
}

int is_empty(LLStack *s) {
    return s->top == -1;
}

int is_full(LLStack *s) {
    return s->top == s->capacity - 1;
}

void push(LLStack *s, long long val) {
    if (is_full(s)) {
        // grow stack
        int newcap = s->capacity * 2;
        long long *tmp = (long long*)realloc(s->data, sizeof(long long) * newcap);
        if (!tmp) {
            fprintf(stderr, "Memory allocation failed while growing stack\n");
            exit(EXIT_FAILURE);
        }
        s->data = tmp;
        s->capacity = newcap;
    }
    s->data[++s->top] = val;
}

long long pop(LLStack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Pop from empty stack (malformed expression)\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

/* Trim leading/trailing spaces (in-place) */
void trim(char *s) {
    char *end;
    while (isspace((unsigned char)*s)) s++;
    if (*s == 0) return;

    end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) end--;
    *(end+1) = '\0';
}

/* Evaluate postfix expression.
   expr must be a modifiable string (we will use strtok on it).
   On error the function prints an error and exits.
*/
long long evaluate_postfix(char *expr) {
    if (!expr) {
        fprintf(stderr, "Null expression\n");
        exit(EXIT_FAILURE);
    }

    // initial stack capacity (approximate)
    LLStack *stack = create_stack(128);

    // tokenize by whitespace
    const char *delim = " \t\r\n";
    char *token = strtok(expr, delim);

    while (token != NULL) {
        // check if token is a single operator (+ - * / ^) and not a number like "-3"
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '*' || token[0] == '/' || token[0] == '^' || token[0] == '-')) {
            char op = token[0];
            // For '-' we must ensure it's an operator (not a negative number). Since token length==1, '-' is operator.
            if (stack->top < 1) {
                fprintf(stderr, "Error: insufficient operands for operator '%c'\n", op);
                free_stack(stack);
                exit(EXIT_FAILURE);
            }
            long long b = pop(stack);
            long long a = pop(stack);
            long long res = 0;

            switch (op) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                    if (b == 0) {
                        fprintf(stderr, "Error: division by zero\n");
                        free_stack(stack);
                        exit(EXIT_FAILURE);
                    }
                    res = a / b; // integer division
                    break;
                case '^': {
                    // use pow, careful with large values
                    double r = pow((double)a, (double)b);
                    res = (long long) llround(r);
                    break;
                }
                default:
                    fprintf(stderr, "Unknown operator '%c'\n", op);
                    free_stack(stack);
                    exit(EXIT_FAILURE);
            }
            push(stack, res);
        } else {
            // attempt to parse as integer (handles multi-digit and negative numbers)
            char *endptr = NULL;
            long long val = strtoll(token, &endptr, 10);
            if (endptr == token || *endptr != '\0') {
                fprintf(stderr, "Error: invalid token '%s'\n", token);
                free_stack(stack);
                exit(EXIT_FAILURE);
            }
            push(stack, val);
        }

        token = strtok(NULL, delim);
    }

    if (stack->top != 0) {
        fprintf(stderr, "Error: malformed expression (stack has %d elements remaining)\n", stack->top + 1);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    long long result = pop(stack);
    free_stack(stack);
    return result;
}

int main(void) {
    char line[4096];

    printf("Enter postfix expression (tokens space-separated):\n");
    if (!fgets(line, sizeof(line), stdin)) {
        fprintf(stderr, "No input\n");
        return 1;
    }

    trim(line);
    if (strlen(line) == 0) {
        fprintf(stderr, "Empty expression\n");
        return 1;
    }

    // strtok modifies string, so pass the buffer directly
    long long ans = evaluate_postfix(line);
    printf("Result = %lld\n", ans);
    return 0;
}

/* output
2 3 + → Result = 5

12 3 / → Result = 4 (integer division)

5 1 2 + 4 * + 3 - → evaluates 5 + ((1+2)*4) - 3 = 14 → Result = 14

-5 3 * → Result = -15

2 3 ^ → Result = 8 (2^3) */