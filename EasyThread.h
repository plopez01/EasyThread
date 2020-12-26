#ifndef EasyThread_h
    #define EasyThread_h
    #include "Arduino.h"
#endif

class EZThread {
    public:
        // Constructor takes the number of threads
        EZThread(int threads);

        // Protoype for the new Thread function
        void newThread(void (*f)(void), int time);

        // Prototype for the schedule function
        void schedule();
    private:
        // Unsigned long pointer that will point to an array containing the timers for every thread
        unsigned long *_schedules;
        // int pointer that will point to an array containing the intervals for every thread
        int *_intervals;
        // Function double pointer that will point to an array of function pointers that point to
        // the function callback of every thread
        void (**_f)();
        // Int that stores the number of threads there are
        int _schid;
};