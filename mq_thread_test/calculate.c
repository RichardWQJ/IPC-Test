#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "calculate.h"

static calculate_cb_t test_cb_t;

void test_cb_init(calculate_cb_t *cb_t)
{
    test_cb_t.add_cb = cb_t->add_cb;
    test_cb_t.sub_cb = cb_t->sub_cb;
    test_cb_t.mul_cb = cb_t->mul_cb;
    test_cb_t.div_cb = cb_t->div_cb;
}

void *thread_test_fun(void *arg)
{
    printf("[%s] [%s] [%s]\n", __FILE__, __FUNCTION__, __TIME__);
    while (1)
    {
        if (test_cb_t.add_cb != NULL)
        {
            test_cb_t.add_cb(1, 1);
        }
        usleep(2000000);

        if (test_cb_t.sub_cb != NULL)
        {
            test_cb_t.sub_cb(2, 1);
        }
        usleep(2000000);

        if (test_cb_t.mul_cb != NULL)
        {
            test_cb_t.mul_cb(3, 1);
        }
        usleep(2000000);

        if (test_cb_t.div_cb != NULL)
        {
            test_cb_t.div_cb(4, 1);
        }
        usleep(2000000);
    }
}

void test_start()
{
    pthread_t test_tid;
    pthread_create(&test_tid, NULL, thread_test_fun, NULL);
    pthread_join(test_tid, NULL);
}
