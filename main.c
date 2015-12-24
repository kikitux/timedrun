#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include "timedrun.h"


int main(int argc, char *argv[]){

    struct thetimes rettime = { .min = 0 , .avg = 0 , .max = 0, .sum = 0};
    long int num = 0; // num iterations
    char newargv[500] = "";
    char *p = NULL;
    int errno = 0;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num_run> <file-to-exec> [args .. args]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argv[1]) {
        num = strtol(argv[1], &p, 10);
        // Check for errors: e.g., the string does not represent an integer
        // or the integer is larger than int
        if (errno != 0 || *p != '\0' || num > INT_MAX) {
            // Put here the handling of the error, like exiting the program with
            // an error message
            exit(EXIT_FAILURE);
        } else {
            // No error
        }
    }

    if (num < 1) {
        fprintf(stderr, "Usage: %s <file-to-exec> <num_run>\n", argv[0]);
        return EXIT_FAILURE ;
    } else {
        for (int s = 2; s < argc; s++) {
            strcat(newargv, " ");
            strcat(newargv, argv[s]);
        } // enf of for

        rettime = timedrun(num, newargv);
        printf("min %f, avg %f, max %f, sum %f\n", rettime.min, rettime.avg, rettime.max, rettime.sum);

        if (rettime.ret == 0) {
            return EXIT_SUCCESS;
        } else {
            return EXIT_FAILURE ;
        }
    } // enf of if
} // end of main
