#include "Arduino.h"
#include "EasyThread.h"

EZThread::EZThread(int threads){
    unsigned long schedules[threads];
    int intervals[threads];
    void (*f[threads])();
    _f = f;
    _schedules = schedules;
    _intervals = intervals;
    _schid = 0;
}

void EZThread::newThread(void (*f)(), int time){
    *(_f + _schid) = f;
    *(_intervals + _schid) = time;
    *(_schedules + _schid) = (unsigned long) 0;
    _schid++;
}

void EZThread::schedule(){
    unsigned long now = millis();
    for(int i = 0; i < _schid; i++){
        if(now - *(_schedules + _schid) >= *(_intervals + _schid)){
            (*(_f + _schid))();
            *(_schedules + _schid) = now;
        }
    }
}