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
Event::Event(string n, date sd, date ed, date rd, string p, bool d)
{
    name = n;
    startDate = sd;
    endDate = ed;
    reminderDate = rd;
    place = p;
    isDone = d;
}

void Event::Display()
{
    cout << "the name of event is :"
         << "" << name << endl;
    cout << "the place is :"
         << " " << place << endl;
    cout << "the start date is :"
         << " " << startDate.day << "/" << startDate.month << "/" << startDate.year << " at " << startDate.hr << ":" << startDate.min << endl;
    cout << "the end date is :"
         << " " << endDate.day << "/" << endDate.month << "/" << endDate.year << " at " << endDate.hr << ":" << endDate.min << endl;
    cout << "the reminder date is :"
         << " " << reminderDate.day << "/" << reminderDate.month << "/" << reminderDate.year << " at " << reminderDate.hr << ":" << reminderDate.min << endl;
}

Event Event::Update()
{
    cout << "Enter a new value to update or enter the same values to keep it as it is " << endl;
    cout << "Enter The new name: ";
    string newName;
    cin >> newName;
    cout << "Enter the new start date: ";
    date newStartDate;
    cout << "Enter Day: ";
    cin >> newStartDate.day;
    cout << "Enter Month: ";
    cin >> newStartDate.month;
    cout << "Enter Year: ";
    cin >> newStartDate.year;
    cout << "Enter hour: ";
    cin >> newStartDate.hr;
    cout << "Enter minute: ";
    cin >> newStartDate.min;
    cout << "Enter the new end date: ";
    date newEndDate;
    cout << "Enter Day: ";
    cin >> newEndDate.day;
    cout << "Enter Month: ";
    cin >> newEndDate.month;
    cout << "Enter Year: ";
    cin >> newEndDate.year;
    cout << "Enter hour: ";
    cin >> newEndDate.hr;
    cout << "Enter minute: ";
    cin >> newEndDate.min;
    cout << "Enter the new Reminder date: ";
    date newRemDate;
    cout << "Enter Day: ";
    cin >> newRemDate.day;
    cout << "Enter Month: ";
    cin >> newRemDate.month;
    cout << "Enter Year: ";
    cin >> newRemDate.year;
    cout << "Enter hour: ";
    cin >> newRemDate.hr;
    cout << "Enter minute: ";
    cin >> newRemDate.min;
    cout << "Enter the new place: ";
    string newPlace;
    cin >> newPlace;
    cout << "Enter Y if event is done and N if not: ";
    bool done;
    char dstr;
    cin >> dstr;
    if (dstr == 'y' || dstr == 'Y')
    {
        done = true;
    }
    else
    {
        done = false;
    }

    Event Eupdate(newName, newStartDate, newEndDate, newRemDate, newPlace, done);
    return Eupdate;
}
