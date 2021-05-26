#include "Event.h"

Event::Event()
{
}
Event::Event(string n, date sd, date ed, date rd, string p)
{
    name = n;
    startDate = sd;
    endDate = ed;
    reminderDate = rd;
    place = p;
    isDone = false;
}

void Event::Display()
{
    cout << name << endl;
    cout << place << endl;
}