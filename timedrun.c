#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>

struct thetimes {
    double min;
    double avg;
    double max ;
    double sum;
    int ret;
};


struct thetimes timedrun(long int num, char *list){
  struct timeval tv_start;
  gettimeofday(&tv_start, NULL);

  struct thetimes rettimes = { .min = 0 , .avg = 0 , .max = 0, .sum = 0, .ret = 0 };

  double run = 0; // current run
  int ret = -1;
  int i = 0;
  for ( i = 0 ; i < num ; i++){
    printf("run: %d\n",i+1);

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    ret = system(list);
    gettimeofday(&tv2, NULL);
    printf("ret: %d\n",ret);
    run = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
          (double) (tv2.tv_sec - tv1.tv_sec);
    rettimes.sum += run;

    if (rettimes.min == 0){
      rettimes.min = run;
    }
    if (rettimes.min > run){
      rettimes.min = run;
    }
    if (rettimes.max < run){
      rettimes.max = run;
    }
  } // end of for

  rettimes.avg = rettimes.sum/num;

  printf("\n");
  printf("New argv: %s\n",list);
  printf("Number of run: %ld\n",num);

  if (ret == 0 ) {
    rettimes.ret = ret ;
    return rettimes;
  } else {
    exit(EXIT_FAILURE);
  }
}
