#include "Arduino.h"
#include "EasyThread.h"

EasyThread::EZThread(int threads){
    unsigned long schedules[threads];
    *_schedules = schedules;
    _schnum = 0;
}

EasyThread::setInterval(void (*f)(void), int interval){
    *_schedules[_schnum] = millis();
}