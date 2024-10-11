# include <stdio.h>
# include <time.h>
# include <string.h>
# include "chacha20_functions.h"

void calculate_throughput(test_vector_t *test)
{
    // Calculate the time taken to encrypt the plaintext
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    run_test(test);
    end = clock();

    cpu_time_used = ((double) (end - start));

    // Calculate the length in bytes of the plaintext
    int length = 0;
    length = strlen(test->plaintext);

    // Output results
    printf("Time taken: %.2f seconds.\n", cpu_time_used);
    printf("Length: %i bytes.\n", length);
    if (length == 0)
    {
        printf("Test contained all 0's as plaintext.\n");
        return;
    }
    else{
        printf("Throughput: %.2f bytes per second.\n", length / cpu_time_used);
    }
}
