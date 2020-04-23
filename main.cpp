/**
 Project : Observer Example
 Authors : Erich Gamma, Richard Helm, Ralph Johnson and John
Vlissides
 Implementer : Gabriel Nicolás González Ferreira
**/
#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
 ( std::ostringstream() << std::dec << x ) ).str()
#include <iostream>
#include <list>
#include <string>
#include "AnalogClock.h"
#include "DigitalClock.h"

using namespace std;

int main()
{
    ClockTimer* timer = new ClockTimer;
    AnalogClock* ac = new AnalogClock(timer);
    DigitalClock* dc = new DigitalClock(timer);

    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();

    delete ac;
    delete dc;
    delete timer;
    return 0;
}