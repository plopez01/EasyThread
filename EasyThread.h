#ifndef EasyThread_h
    #define EasyThread_h
    #include "Arduino.h"
#endif

class EZThread {
    public:
        EZThread(int threads);
        void newThread(void (*f)(void), int time);
        void schedule();
    private:
        unsigned long *_schedules;
        int *_intervals;
        void (**_f)();
        int _schid;
};