#include "minunit.h"
#include "../includes/push_swap.h"

MU_TEST(funtion_should_test_operation_ra)
{
    t_stack	a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    int	expected[] = {3, 1, 2};

    printf("\n------------------------\n");
    printf(" TEST 1: rotate stack a");
    printf("\n------------------------\n");

    rotate_stack_a(&a);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected[0], a.items[0]);

    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected[1], a.items[1]);

    ft_printf("a[2] = %d\n", a.items[2]);
    mu_assert_int_eq(expected[2], a.items[2]);

    free(a.items);
}

MU_TEST(function_should_test_operation_rb_empty)
{
    t_stack b;
    b.size_max = 3;
    b.top = 0;
    b.items = ft_calloc(3, sizeof(int));
    int expected[] = {0, 0, 0};

    printf("\n------------------------\n");
    printf(" TEST 2: rotate empty stack");
    printf("\n------------------------\n");

    rotate_stack_b(&b);
    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected[1], b.items[1]);

    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected[2], b.items[2]);

    free(b.items);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(funtion_should_test_operation_ra);
    MU_RUN_TEST(function_should_test_operation_rb_empty);
}

int    main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return (MU_EXIT_CODE);
}