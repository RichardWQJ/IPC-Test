#ifndef _CALCULATE_H_
#define _CALCULATE_H_

typedef int (*test_add_cb)(const int iLeftValue, const int iRightValue);
typedef int (*test_sub_cb)(const int iLeftValue, const int iRightValue);
typedef int (*test_mul_cb)(const int iLeftValue, const int iRightValue);
typedef int (*test_div_cb)(const int iLeftValue, const int iRightValue);

typedef struct
{
    /* callbacks */
    test_add_cb add_cb;
    test_sub_cb sub_cb;
    test_mul_cb mul_cb;
    test_div_cb div_cb;
} calculate_cb_t;

void test_cb_init(calculate_cb_t *cb_t);
void test_start();

#endif