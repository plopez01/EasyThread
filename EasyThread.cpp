#include "Arduino.h"
#include "EasyThread.h"

// Constructor declaration
EZThread::EZThread(int threads){
    // We create the unsigned long array that will store timers for the threads
    unsigned long schedules[threads];

    // We create the int array that will store the intervals at which every thread should execute
    int intervals[threads];

    // We create the function pointer array that will point to the callback for every thread.
    void (*f[threads])();

    //We assign the globals defined in EasyThread.h
    _f = f;
    _schedules = schedules;
    _intervals = intervals;
    _schid = 0;
}

// newThread declaration
// This function creates a new Thread
void EZThread::newThread(void (*f)(), int time){
    // We store the callback function adress to the function pointer array
    *(_f + _schid) = f;
    
    // We store the time interval at which the thread should execute
    *(_intervals + _schid) = time;

    // We initialize the timer for this thread to 0
    *(_schedules + _schid) = (unsigned long) 0;

    // We increase the number of threads
    _schid++;
}

void EZThread::schedule(){
    // We store the current time in which we are scheduling
    unsigned long now = millis();

    // For every thread
    for(int i = 0; i < _schid; i++){
        // If the scheduling time - the last time  that thread executed >= interval at it should execute
        if(now - *(_schedules + i) >= *(_intervals + i)){
            // We call to the callback function stored in the function pointer array
            (*(_f + i))();

            // We set the internal timer to the time we started scheduling
            *(_schedules + i) = now;
        }
    }
}