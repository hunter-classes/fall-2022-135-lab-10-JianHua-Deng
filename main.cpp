#include <iostream>
#include "funcs.h"

int main(){
Time earlier = {10, 30};
Time later = {13, 40};
Time time0 = {8, 10};
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"Evangelion: 3.0 + 1.0 Thrice Upon a Time", ACTION, 155};
TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}}; 
TimeSlot nextSchedule = scheduleAfter(evening, movie3);


std::cout << minutesUntil(earlier, later) << "\n";

std::cout << addMinutes(time0, 75).h << ", "<< addMinutes(time0, 75).m << "\n";

printTimeSlot(morning);
std::cout << std::endl;
printTimeSlot(daytime);
std::cout << std::endl;
printTimeSlot(evening);
std::cout << std::endl;

printTimeSlot(nextSchedule);
std::cout << std::endl;

}//end main function