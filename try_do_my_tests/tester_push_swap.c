#include "minunit.h"
#include "../includes/push_swap.h"

MU_TEST(funtion_should_test_operation_ra)
{
    t_stack	a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
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
    if (!b.items)
    {
        mu_fail("calloc failed");
        return ;
    }
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

MU_TEST(function_should_test_operation_rr)
{
    t_stack a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    t_stack b;
    b.size_max = 3;
    b.top = 3;
    b.items = malloc(3 * sizeof(int));
    if (!b.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    b.items[0] = 1;
    b.items[1] = 2;
    b.items[2] = 3;
    int expected_a[] = {3, 1, 2};
    int expected_b[] = {3, 1, 2};

    printf("\n------------------------\n");
    printf(" TEST 3: rotate both stacks");
    printf("\n------------------------\n");

    rotate_both(&a, &b);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected_a[0], a.items[0]);

    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected_a[1], a.items[1]);

    ft_printf("a[2] = %d\n\n", a.items[2]);
    mu_assert_int_eq(expected_a[2], a.items[2]);

    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected_b[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected_b[1], b.items[1]);

    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected_b[2], b.items[2]);

    free(a.items);
    free(b.items);
}

MU_TEST(funtion_should_test_operation_sa)
{
    t_stack	a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    int	expected[] = {1, 3, 2};

    printf("\n------------------------\n");
    printf(" TEST 1: swap stack a");
    printf("\n------------------------\n");

    swap_stack_a(&a);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected[0], a.items[0]);

    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected[1], a.items[1]);

    ft_printf("a[2] = %d\n", a.items[2]);
    mu_assert_int_eq(expected[2], a.items[2]);

    free(a.items);
}

MU_TEST(function_should_test_operation_sa_empty)
{
    t_stack b;
    b.size_max = 3;
    b.top = 0;
    b.items = ft_calloc(3, sizeof(int));
    if (!b.items)
    {
        mu_fail("calloc failed");
        return ;
    }
    int expected[] = {0, 0, 0};

    printf("\n------------------------\n");
    printf(" TEST 2: swap empty stack");
    printf("\n------------------------\n");

    swap_stack_b(&b);

    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected[1], b.items[1]);

    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected[2], b.items[2]);

    free(b.items);
}

MU_TEST(function_should_test_operation_pa)
{
    t_stack a;
    a.size_max = 4;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    t_stack b;
    b.size_max = 3;
    b.top = 1;
    b.items = ft_calloc(3, sizeof(int));
    if (!b.items)
    {
        mu_fail("calloc failed");
        return ;
    }
    b.items[0] = 42;
    int expected_a[] = {1, 2, 3, 42};
    int expected_top_b = 0;

    printf("\n------------------------\n");
    printf(" TEST 3: push to stack a");
    printf("\n------------------------\n");

    push_to_stack_a(&b, &a);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected_a[0], a.items[0]);

    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected_a[1], a.items[1]);

    ft_printf("a[2] = %d\n", a.items[2]);
    mu_assert_int_eq(expected_a[2], a.items[2]);

    ft_printf("a[3] = %d\n", a.items[3]);
    mu_assert_int_eq(expected_a[3], a.items[3]);

    mu_assert_int_eq(expected_top_b, b.top);

    free(a.items);
    free(b.items);
}

MU_TEST(function_should_test_operation_pb)
{
    t_stack b;
    b.size_max = 4;
    b.top = 3;
    b.items = malloc(3 * sizeof(int));
    if (!b.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    b.items[0] = 1;
    b.items[1] = 2;
    b.items[2] = 3;
    t_stack a;
    a.size_max = 3;
    a.top = 1;
    a.items = ft_calloc(3, sizeof(int));
    if (!a.items)
    {
        mu_fail("calloc failed");
        return ;
    }
    a.items[0] = 42;
    int expected_b[] = {1, 2, 3, 42};
    int expected_top_a = 0;

    printf("\n------------------------\n");
    printf(" TEST 3: push to stack b");
    printf("\n------------------------\n");

    push_to_stack_b(&a, &b);

    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected_b[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected_b[1], b.items[1]);

    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected_b[2], b.items[2]);

    ft_printf("b[3] = %d\n", b.items[3]);
    mu_assert_int_eq(expected_b[3], b.items[3]);

    mu_assert_int_eq(expected_top_a, a.top);

    free(a.items);
    free(b.items);
}

MU_TEST(function_should_test_operation_rra)
{
    t_stack a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    int expected[] = {2, 3, 1};

    printf("\n------------------------\n");
    printf(" TEST 4: reverse rotate stack a");
    printf("\n------------------------\n");

    reverse_stack_a(&a);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected[0], a.items[0]);
    
    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected[1], a.items[1]);

    ft_printf("a[2] = %d\n", a.items[2]);
    mu_assert_int_eq(expected[2], a.items[2]);

    free(a.items);
}

MU_TEST(function_should_test_operation_rrb)
{
    t_stack b;
    b.size_max = 3;
    b.top = 3;
    b.items = malloc(3 * sizeof(int));
    if (!b.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    b.items[0] = 1;
    b.items[1] = 2;
    b.items[2] = 3;
    int expected[] = {2, 3, 1};

    printf("\n------------------------\n");
    printf(" TEST 5: reverse rotate stack b");
    printf("\n------------------------\n");

    reverse_stack_b(&b);

    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected[1], b.items[1]);
    
    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected[2], b.items[2]);

    free(b.items);
}

MU_TEST(function_should_test_operation_rrr)
{
    t_stack a;
    a.size_max = 3;
    a.top = 3;
    a.items = malloc(3 * sizeof(int));
    if (!a.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    a.items[0] = 1;
    a.items[1] = 2;
    a.items[2] = 3;
    t_stack b;
    b.size_max = 3;
    b.top = 3;
    b.items = malloc(3 * sizeof(int));
    if (!b.items)
    {
        mu_fail("malloc failed");
        return ;
    }
    b.items[0] = 1;
    b.items[1] = 2;
    b.items[2] = 3;
    int expected_a[] = {2, 3, 1};
    int expected_b[] = {2, 3, 1};

    printf("\n------------------------\n");
    printf(" TEST 6: reverse rotate both stacks");
    printf("\n------------------------\n");

    reverse_both_stacks(&a, &b);

    ft_printf("a[0] = %d\n", a.items[0]);
    mu_assert_int_eq(expected_a[0], a.items[0]);

    ft_printf("a[1] = %d\n", a.items[1]);
    mu_assert_int_eq(expected_a[1], a.items[1]);

    ft_printf("a[2] = %d\n\n", a.items[2]);
    mu_assert_int_eq(expected_a[2], a.items[2]);

    ft_printf("b[0] = %d\n", b.items[0]);
    mu_assert_int_eq(expected_b[0], b.items[0]);

    ft_printf("b[1] = %d\n", b.items[1]);
    mu_assert_int_eq(expected_b[1], b.items[1]);

    ft_printf("b[2] = %d\n", b.items[2]);
    mu_assert_int_eq(expected_b[2], b.items[2]);

    free(a.items);
    free(b.items);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(funtion_should_test_operation_ra);
    MU_RUN_TEST(function_should_test_operation_rb_empty);
    MU_RUN_TEST(function_should_test_operation_rr);
    MU_RUN_TEST(funtion_should_test_operation_sa);
    MU_RUN_TEST(function_should_test_operation_sa_empty);
    MU_RUN_TEST(function_should_test_operation_pa);
    MU_RUN_TEST(function_should_test_operation_pb);
    MU_RUN_TEST(function_should_test_operation_rra);
    MU_RUN_TEST(function_should_test_operation_rrb);
    MU_RUN_TEST(function_should_test_operation_rrr);
}

int    main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return (MU_EXIT_CODE);
}