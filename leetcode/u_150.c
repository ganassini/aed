#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** items;
    int top;
    int capacity;
} Stack;

Stack* init_stack();
void push(Stack* s, char* c);
void pop(Stack* s);
int evalRPN(char** tokens, int tokensSize);

int main(void)
{
	char values[7][3] = {"4","-2","/","2","-3","-","-"};
	// -2, 2, -3

	char** tokens = (char**)malloc(7 * sizeof(char*));

	if (!tokens){
		printf("Memory allocation failed.\n");
		return 1;
	}

	for (int i =0; i < 7; i++) {
		tokens[i] = (char*)malloc(sizeof(char) * 3);

		
		if (!tokens[i]){
			printf("Memory allocation failed.\n");
			return 1;
		}

		strcpy(tokens[i], values[i]);
	}

	printf("%d\n", evalRPN(tokens, 7));

	for (int i =0; i < 7; i++) {
		free(tokens[i]);
	}
	free(tokens);

	return 0;
}

int evalRPN(char** tokens, int tokensSize) {
    int result;
    char s_result[5]; // this need a malloc
    Stack* s = init_stack();
    
    for (int i = 0; i < tokensSize; i++) {
        if (!strcmp(tokens[i], "+")) {
            result = atoi(s->items[s->top - 1]) + atoi(s->items[s->top]);
            snprintf(s_result, 5, "%d", result);
            pop(s);
            pop(s);
            push(s, s_result);
			continue;
        }
        if (!strcmp(tokens[i], "-")) {
            result = atoi(s->items[s->top - 1]) - atoi(s->items[s->top]);
            snprintf(s_result, 5, "%d", result);
            pop(s);
            pop(s);
            push(s, s_result);
			continue;
        }
        if (!strcmp(tokens[i], "*")) {
            result = atoi(s->items[s->top - 1]) * atoi(s->items[s->top]);
            snprintf(s_result, 5, "%d", result);
            pop(s);
            pop(s);
            push(s, s_result);
			continue;
        }
        if (!strcmp(tokens[i], "/")) {
            result = atoi(s->items[s->top - 1]) / atoi(s->items[s->top]);
            snprintf(s_result, 5, "%d", result);
            pop(s);
            pop(s);
            push(s, s_result);
			continue;
        }
        push(s, tokens[i]);
    }
    return atoi(s->items[s->top]);
}

Stack* init_stack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));

    s->top = -1;
    s->capacity = 50;
    s->items = (char**)malloc(sizeof(char*) * s->capacity);

    return s;
}

void push(Stack* s, char* c)
{
    if (s->top == (s->capacity - 1)) {
        s->capacity *= 2;
        s->items = realloc(s->items, s->capacity);
    }

    s->top += 1;
    s->items[s->top] = c;
}

void pop(Stack* s)
{
    if (s->top < 0) return;
	
    s->top -= 1;
}
