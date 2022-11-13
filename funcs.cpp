#include <iostream>
#include "funcs.h"

//Task A
int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}//end minutesSinceMidnight function

int minutesUntil(Time earlier, Time later){
    int earlierMin = minutesSinceMidnight(earlier);
    int laterMin = minutesSinceMidnight(later);
    return laterMin - earlierMin;
}//end minutesUntill function

//Task B
Time addMinutes(Time time0, int min){
    Time newTime;
    int timeInMin = minutesSinceMidnight(time0);
    timeInMin += min;
    
    newTime.h = timeInMin / 60;
    newTime.m = timeInMin % 60;

    return newTime;
}//end addMinuites function

//Task C
void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}//end printMovie function

void printTimeSlot(TimeSlot ts){
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);

    printMovie(ts.movie);
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endtime.h << ":" << endtime.m <<"] "; 
}//en printTimeSlot function


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    return {nextMovie, endtime};
}//end scheduleAfter function

