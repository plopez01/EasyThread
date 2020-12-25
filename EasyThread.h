#ifndef EasyThread_h
#define EasyThread_h

#include "Arduino.h"

class EasyThread {
    public:
        EZThread(int threads);
        void newThread(void (*f)(void), int time);
    private:
        unsigned long *_schedules;
        void *_f;
        int _schid;
}