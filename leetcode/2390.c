typedef struct {
    char* items;
    int top;
    int capacity;
} Stack;

Stack* initStack();
void push(Stack* s, char c);
void pop(Stack* s);
int stack_is_full(Stack* s);
int stack_is_empty(Stack* s);

char* removeStars(char* s) 
{
    Stack* stack = initStack();

    while (*s != '\0') {
        if (*s != '*') {
            push(stack, *s);
        } else if (*s == '*') {
            pop(stack);
        }
		s++;
    }
    stack->items[stack->top + 1] = '\0';
    return stack->items;
}

Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    
    s->top = -1;
    s->capacity = 100;
    s->items = (char*)malloc(sizeof(char) * s->capacity);

    if (s->items == NULL) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }
    return s;
}

void push(Stack* s, char c)
{
    if (stack_is_full(s)) {
        s->capacity *= 2;
        s->items = realloc(s->items, s->capacity * sizeof(char));
    }

    (s->top)++;
    s->items[s->top] = c;
}

void pop(Stack* s)
{  
    if (!stack_is_empty(s)) (s->top)--;
}

int stack_is_empty(Stack* s)
{
    return s->top < 0;
}

int stack_is_full(Stack* s)
{
    return s->top == (s->capacity - 1);
}
