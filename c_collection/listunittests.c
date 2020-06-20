/*
 * File:   listtests.c
 * Author: bilaleluneis
 *
 * Created on Jun 9, 2020, 12:55:52 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "list.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    printf("\ninit_suite()");
    return 0; 
}

int clean_suite(void) { 
    printf("\nclean_suite()");
    return 0; 
}

void testInit() {
    printf("testInit()\n");
    List* list = init();
    CU_ASSERT(list != NULL);
    CU_ASSERT(list->size == 0);
    discard(list);
}

void testPush() {
    printf("testPush()\n");
    List* list = init();
    CU_ASSERT(list->size == 0);
    push(3, list);
    CU_ASSERT(list->size == 1);
    discard(list);
}

void testPop() {
    printf("testPop()\n");
    List* list = init();
    // pop empty list
    pop_result result = pop(list);
    CU_ASSERT(!result.success);
    // pop non empty list
    push(10, list);
    result = pop(list);
    CU_ASSERT(result.success);
    CU_ASSERT(result.val == 10);
    discard(list);
}


int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("listtests", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testInit", testInit)) ||
        (NULL == CU_add_test(pSuite, "testPush", testPush)) ||
        (NULL == CU_add_test(pSuite, "testPop", testPop))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
