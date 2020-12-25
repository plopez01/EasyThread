#ifndef EasyThread_h
#define EasyThread_h

#include "Arduino.h"

class EasyThread {
    public:
        EZThread(int threads);
        void setInterval(void (*f)(void), int interval);
    private:
        unsigned long *_schedules;
        int _schnum;
}