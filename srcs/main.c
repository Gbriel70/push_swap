#include <stdio.h>
#include "../includes/push_swap.h"
#define MAX_STACK_SIZE 100


void print_stack(const char *name, t_stack *stack) {
    printf("Pilha %s:\n", name);
    for (int i = 0; i < stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n--------------------\n\n");
}

void init_stack_a(t_stack *a, int values[], int size) {
    a->items = malloc(size * sizeof(int)); // Aloca memória
    if (!a->items) {
        perror("Falha ao alocar memória");
        exit(EXIT_FAILURE);
    }

    a->top = size;
    for (int i = 0; i < size; i++) {
        a->items[i] = values[i];
    }
}

void init_stack_b(t_stack *b) {
    b->items = malloc(MAX_STACK_SIZE * sizeof(int)); // Aloca memória para a pilha vazia
    if (!b->items) {
        perror("Falha ao alocar memória");
        exit(EXIT_FAILURE);
    }

    b->top = 0; // Pilha vazia
}

int main() {
    t_stack a, b;

    // Valores para a pilha a
    int values[] = {5, 4, 3, 2, 1};
    int size = sizeof(values) / sizeof(values[0]);

    // Inicializa as pilhas
    init_stack_a(&a, values, size);
    init_stack_b(&b);

    // Exibe as pilhas para confirmar
    ft_printf("Pilha A inicializada:\n");
    for (int i = 0; i < a.top; i++) {
        ft_printf("%d ", a.items[i]);
    }
    ft_printf("\n");

    ft_printf("Pilha B inicializada (vazia):\n");
    for (int i = 0; i < b.top; i++) {
        ft_printf("%d ", b.items[i]);
    }
    ft_printf("\n\n");
    ft_printf("--------------------\n\n");

    /*printf("Executando 1 swap_stack_a...\n");
    swap_stack_a(&a);
    printf("Pilha A após 1 swap:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");

    printf("Executando 2 swap_stack_a...\n");
    swap_stack_a(&a);
    printf("Pilha A após 2 swap:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");

    printf("Executando 3 swap_stack_a...\n");
    swap_stack_a(&a);
    printf("Pilha A após 3 swap:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");*/

    /*printf("Executando  1 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    printf("Pilha A após push:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");
    printf("Pilha B após push:\n");
    for (int i = 0; i < b.top; i++) {
        printf("%d ", b.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");

    printf("Executando  2 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    printf("Pilha A após push:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");
    printf("Pilha B após push:\n");
    for (int i = 0; i < b.top; i++) {
        printf("%d ", b.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");

    printf("Executando  3 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    printf("Pilha A após push:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");
    printf("Pilha B após push:\n");
    for (int i = 0; i < b.top; i++) {
        printf("%d ", b.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");

    printf("Executando  4 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    printf("Pilha A após push:\n");
    for (int i = 0; i < a.top; i++) {
        printf("%d ", a.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");
    printf("Pilha B após push:\n");
    for (int i = 0; i < b.top; i++) {
        printf("%d ", b.items[i]);
    }
    printf("\n");
    ft_printf("--------------------\n\n");*/



     // Teste de rotação
    /*printf("Executando rotate_stack na Pilha A...\n");
    rotate_stack(&a);
    print_stack("A", &a);

    // Teste de reverse
    printf("Executando reverse_stacks na Pilha A...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    // Movendo elementos para a Pilha B
    printf("Executando 1 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    print_stack("A", &a);
    print_stack("B", &b);

    printf("Executando 2 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    print_stack("A", &a);
    print_stack("B", &b);

    printf("Executando 3 push_to_stack_b...\n");
    push_to_stack_b(&a, &b);
    print_stack("A", &a);
    print_stack("B", &b);*/

    /*printf("Executando rotate_stack na Pilha B...\n");
    rotate_stack(&a);
    print_stack("A", &a);

    printf("Executando 2 rotate_stack na Pilha B...\n");
    rotate_stack(&a);
    print_stack("A", &a);

    printf("Executando 3 rotate_stack na Pilha B...\n");
    rotate_stack(&a);
    print_stack("A", &a);

    printf("Executando 4 rotate_stack na Pilha B...\n");
    rotate_stack(&a);
    print_stack("A", &a);

    printf("Executando 5 rotate_stack na Pilha B...\n");
    rotate_stack(&a);
    print_stack("A", &a);*/

    printf("Executando 1 reverse_stacks na Pilha B...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    printf("Executando 2 reverse_stacks na Pilha B...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    printf("Executando 3 reverse_stacks na Pilha B...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    printf("Executando 4 reverse_stacks na Pilha B...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    printf("Executando 5 reverse_stacks na Pilha B...\n");
    reverse_stacks(&a);
    print_stack("A", &a);

    // Liberar memória alocada
    free(a.items);
    free(b.items);

    return 0;
}
