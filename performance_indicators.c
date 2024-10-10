# include <stdio.h>
# include <time.h>
# include "chacha20_functions.h"

void time_taken(test_vector_t *test)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    run_test(test);
    end = clock();

    cpu_time_used = ((double) (end - start));

    printf("Time taken: %f\n", cpu_time_used);
}
