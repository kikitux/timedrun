//
// Created by Alvaro Miranda on 24/12/15.
//

#ifndef TIMEDRUN_TIMEDRUN_H
#define TIMEDRUN_TIMEDRUN_H

struct thetimes {
    double min;
    double avg;
    double max ;
    double sum;
    int ret;
};

extern struct thetimes timedrun(long int, char *);
#endif //TIMEDRUN_TIMEDRUN_H