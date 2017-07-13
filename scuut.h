#pragma once

#include <stdio.h>

// We currently rely on __COUNTER__ being 0 to start!
// When we run tests, we use pointer arithmetic on global function pointers and this is "Undefined Behavior" according
// to the c standard

typedef void scuut_test_func_t(int*);

#define INDIR_TEST_FUNC(n) scuut_test_func_##n
#define GLOBAL_TEST_FUNC(n) INDIR_TEST_FUNC(n)

// define test functions
#define TEST(name)                                            \
     void name(int* scuut_test_failed);                       \
     scuut_test_func_t* GLOBAL_TEST_FUNC(__COUNTER__) = name; \
     void name(int* scuut_test_failed)

// pass conditionals that will cause the test to fail if they evaluate to false
#define EXPECT(cond)                                                                             \
     if(!(cond)){                                                                                \
          printf("%s:%d '%s' FAILED expecting (%s)\n", __FILE__, __LINE__, __FUNCTION__, #cond); \
          *scuut_test_failed = 1;                                                                \
     }

// call this in main after any setup you need to do
#define RUN_TESTS()                                                 \
     int scuut_test_failed_count = 0;                               \
     int scuut_test_count = __COUNTER__;                            \
     printf("executing %d test(s)\n\n", scuut_test_count);          \
     for(int i = 0; i < scuut_test_count; ++i){                     \
          int scuut_test_failed = 0;                                \
          (*(&scuut_test_func_0 + i))(&scuut_test_failed);          \
          if(scuut_test_failed) scuut_test_failed_count++;          \
     }                                                              \
     if(scuut_test_failed_count > 0){                               \
          printf("\n%d test(s) failed\n", scuut_test_failed_count); \
          return 1;                                                 \
     }                                                              \
     printf("all test(s) passed\n");                                \
     return 0;
