# include <stdio.h>
#include <windows.h>
# include <time.h>
# include <string.h>
# include "chacha20_functions.h"

/*

    This function will allow us to calculate the throughput of the encryption algorithm. 
    Its output is the throughput in bytes per second.

    We use windows.h for more exactitude when measuring time, since this library directly interacts with the OS.

    We will do so by counting the number of counts (ticks) produced by the high-resolution timer in a given time interval, so that we can break a second into smaller pieces.

*/

void calculate_throughput(test_vector_t *test)
{
    // Calculate the time taken to encrypt the plaintext

    LARGE_INTEGER frequency, start, end; // Frequency stores a 64-bit integer value representing the number of counts per second.
    double time_taken;                   //  This frequency will allow us to be more exact when measuring time.

    QueryPerformanceFrequency(&frequency); // Retrieves the number of counts produces per second.

    QueryPerformanceCounter(&start); // Provides the current count from the timer.
    run_test(test);
    QueryPerformanceCounter(&end); // Call it again to get the ending number of counts.

    time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; // QuadPart to access the number of counts and convert from ticks to seconds.

    // Calculate the length in bytes of the plaintext
    
    int length = strlen(test->plaintext);

    // Output results
    printf("Time taken: %.6f seconds.\n", time_taken);
    printf("Length: %i bytes.\n", length);
    if (length == 0)
    {
        printf("Test contained all 0's as plaintext.\n");
        return;
    }
    else{
        printf("Throughput: %.2f bytes per second.\n", length / time_taken);
    }
}
