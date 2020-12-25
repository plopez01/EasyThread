#include "Arduino.h"
#include "EasyThread.h"

EasyThread::EZThread(int threads){
    unsigned long schedules[threads];
    *_f = (*functptr[threads])();
    *_schedules = schedules;
    _schid = 0;
}

EasyThread::newThread(void (*f)(void), int time){

}

/*
unsigned long currentTime = millis();
    if(currentTime - *_schedules[_schid] >= time){
        (*f)();
        *_schedules[_schid] = currentTime;
    }*/