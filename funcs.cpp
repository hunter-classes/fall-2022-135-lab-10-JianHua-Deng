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
std::string getMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}//end printMovie function

std::string getTimeSlot(TimeSlot ts){
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);

    std::string newstring = getMovie(ts.movie);
    newstring += " [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ", ends by " + std::to_string(endtime.h) + ":" + std::to_string(endtime.m) + "] "; 
    return newstring;
}//en printTimeSlot function


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time endtime = addMinutes(ts.startTime, ts.movie.duration);
    return {nextMovie, endtime};
}//end scheduleAfter function

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    //Checks which timeslot is earlier
    if(minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)){
        //Checks if the gaps between timeslot1's start time and timeslot2's start time are greater or equal to movie's duration
        //If yes, then they don't overlap
        //Debugging: std::cout << "Ran default condition, minutesUntil(ts1.startTime, ts2.startTime): " << minutesUntil(ts1.startTime, ts2.startTime) << ", ts1.movie.duration: " << ts1.movie.duration << "\n";
        if(minutesUntil(ts1.startTime, ts2.startTime) > ts1.movie.duration){
            return false;
        }else{
            return true;
        }//end else condition
    }else{
        //Debugging: std::cout << "Ran else condition, minutesUntil(ts2.startTime, ts1.startTime): " << minutesUntil(ts2.startTime, ts1.startTime) << ", ts2.movie.duration: " << ts2.movie.duration << "\n";
        if(minutesUntil(ts2.startTime, ts1.startTime) > ts2.movie.duration){
            return false;
        }else{
            return true;
        }//end else condition
    }//end else condition

}//end timeoverlap function
