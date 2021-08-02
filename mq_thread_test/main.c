#include <stdio.h>
#include <unistd.h>
#include "calculate.h"

static int test_add_handle(const int iLeftValue, const int iRightValue)
{
    printf("[%s] [%s] [%s]\n", __FILE__, __FUNCTION__, __TIME__);
    printf("[%d + %d = %d]\n", iLeftValue, iRightValue, iLeftValue + iRightValue);
}

static int test_sub_handle(const int iLeftValue, const int iRightValue)
{
    printf("[%s] [%s] [%s]\n", __FILE__, __FUNCTION__, __TIME__);
    printf("[%d - %d = %d]\n", iLeftValue, iRightValue, iLeftValue - iRightValue);
}

static int test_mul_handle(const int iLeftValue, const int iRightValue)
{
    printf("[%s] [%s] [%s]\n", __FILE__, __FUNCTION__, __TIME__);
    printf("[%d * %d = %d]\n", iLeftValue, iRightValue, iLeftValue * iRightValue);
}

static int test_div_handle(const int iLeftValue, const int iRightValue)
{
    printf("[%s] [%s] [%s]\n", __FILE__, __FUNCTION__, __TIME__);
    printf("[%d / %d = %d]\n", iLeftValue, iRightValue, iLeftValue / iRightValue);
}

int main(int argv, char **argc)
{
    calculate_cb_t test_cb_t;
    test_cb_t.add_cb = test_add_handle;
    test_cb_t.sub_cb = test_sub_handle;
    test_cb_t.mul_cb = test_mul_handle;
    test_cb_t.div_cb = test_div_handle;

    test_cb_init(&test_cb_t);
    test_start();

    for (;;)
        ;

    return 0;
}
