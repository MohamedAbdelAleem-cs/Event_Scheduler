#include <iostream>
#include "LinkedList.cpp"
#include <fstream>
using namespace std;

LinkedList<Event> SortStartDate(LinkedList<Event> E);
LinkedList<Event> SortReminderDate(LinkedList<Event> E);
Event CreateEvent();

int main()
{
    LinkedList<Event> Events;
    Event Efile;
    ifstream theFile("file.txt");
    while (theFile >> Efile.name >> Efile.startDate.day >> Efile.startDate.month >> Efile.startDate.year >> Efile.startDate.hr >> Efile.startDate.min >> Efile.startDate.day >> Efile.endDate.month >> Efile.endDate.year >> Efile.endDate.hr >> Efile.endDate.min >> Efile.reminderDate.day >> Efile.reminderDate.month >> Efile.reminderDate.year >> Efile.reminderDate.hr >> Efile.reminderDate.min >> Efile.place >> Efile.isDone)
        Events.Append(Efile);

    while (true)
    {
        cout << "********** Event's Scheduler**********" << endl;
        cout << "(1) TO ADD EVENT " << endl;
        cout << "(2) TO UPDATE EVENT " << endl;
        cout << "(3) TO DELETE EVENT" << endl;
        cout << "(4) TO DISPLAY ALL EVENTS" << endl;
        cout << "(5) TO EXIST THE PROGRAMME" << endl;
        cout << "*****************************" << endl;
        cout << " ENTER THE NUMBER OF OPTION WHICH YOU WANT" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            Events.Append(CreateEvent());
            break;
        }
        case 2:
        {
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            cout << "Enter the number of the event you want to update: ";
            int updateOption;
            cin >> updateOption;
            Event Etmp;
            Etmp = Etmp.Update(Events.At(updateOption));
            Events.Update(updateOption, Etmp);
            break;
        }
        case 3:
        {
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            cout << "Enter the number of the event you want to delete: ";
            int deleteOption;
            cin >> deleteOption;
            Events.DeleteAt(deleteOption);
            break;
        }
        case 4:
        {
            cout << "Enter 1 to sort by starting dates and 2 to sort by reminder dates: ";
            int sortOption;
            cin >> sortOption;
            if (sortOption == 1)
                Events = SortStartDate(Events);
            else if (sortOption == 2)
                Events = SortReminderDate(Events);
            for (int i = 0; i < Events.Length(); i++)
            {
                cout << i << ": " << endl;
                Events.At(i).Display();
            }
            break;
        }
        case 5:
        {

            fstream file1;
            file1.open("file.txt");
            for (int i = 0; i < Events.Length(); i++)
            {
                file1 << Events.At(i).name << " " << Events.At(i).startDate.day << " " << Events.At(i).startDate.month << " " << Events.At(i).startDate.year << " " << Events.At(i).startDate.hr << " " << Events.At(i).startDate.min << " " << Events.At(i).startDate.day << " " << Events.At(i).endDate.month << " " << Events.At(i).endDate.year << " " << Events.At(i).endDate.hr << " " << Events.At(i).endDate.min << " " << Events.At(i).reminderDate.day << " " << Events.At(i).reminderDate.month << " " << Events.At(i).reminderDate.year << " " << Events.At(i).reminderDate.hr << " " << Events.At(i).reminderDate.min << " " << Events.At(i).place << " " << Events.At(i).isDone << endl;
            }
            file1.close();
            return 0;
            break;
        }
        default:
        {
            cout << " wrong option please try again" << endl;
            break;
        }
        }
        //cout << "*****************************************";
        // cout << "Press Enter to continue";
        // int enter;
        // cin >> enter;
        //system("CLS");
    }
}

Event CreateEvent()
{
    cout << "Enter values of event " << endl;
    cout << "Enter the name: ";
    string name;
    cin >> name;
    cout << "Enter the start date: ";
    date startDate;
    cout << "Enter Day: ";
    cin >> startDate.day;
    cout << "Enter Month: ";
    cin >> startDate.month;
    cout << "Enter Year: ";
    cin >> startDate.year;
    cout << "Enter hour: ";
    cin >> startDate.hr;
    cout << "Enter minute: ";
    cin >> startDate.min;
    cout << "Enter the end date: ";
    date endDate;
    cout << "Enter Day: ";
    cin >> endDate.day;
    cout << "Enter Month: ";
    cin >> endDate.month;
    cout << "Enter Year: ";
    cin >> endDate.year;
    cout << "Enter hour: ";
    cin >> endDate.hr;
    cout << "Enter minute: ";
    cin >> endDate.min;
    cout << "Enter the Reminder date: ";
    date remDate;
    cout << "Enter Day: ";
    cin >> remDate.day;
    cout << "Enter Month: ";
    cin >> remDate.month;
    cout << "Enter Year: ";
    cin >> remDate.year;
    cout << "Enter hour: ";
    cin >> remDate.hr;
    cout << "Enter minute: ";
    cin >> remDate.min;
    cout << "Enter the place: ";
    string place;
    cin >> place;
    Event Ecreated(name, startDate, endDate, remDate, place);
    return Ecreated;
}

LinkedList<Event> SortStartDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event *Es = new Event[E.Length()];
    for (int i = 0; i < E.Length(); i++)
    {
        Es[i] = E.At(i);
    }
    for (int i = 0; i < E.Length(); i++)
    {
        for (int j = i + 1; j < E.Length(); j++)
        {
            if (E.At(i).startDate.year > E.At(j).startDate.year)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).startDate.year == E.At(j).startDate.year && E.At(i).startDate.month > E.At(j).startDate.month)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).startDate.year == E.At(j).startDate.year && E.At(i).startDate.month == E.At(j).startDate.month && E.At(i).startDate.day > E.At(j).startDate.day)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
        }
    }
    for (int i = 0; i < E.Length(); i++)
    {
        Esorted.Append(Es[i]);
    }
    return Esorted;
}

LinkedList<Event> SortReminderDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event *Es = new Event[E.Length()];
    for (int i = 0; i < E.Length(); i++)
    {
        Es[i] = E.At(i);
    }
    for (int i = 0; i < E.Length(); i++)
    {
        for (int j = i + 1; j < E.Length(); j++)
        {
            if (E.At(i).reminderDate.year > E.At(j).reminderDate.year)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).reminderDate.year == E.At(j).reminderDate.year && E.At(i).reminderDate.month > E.At(j).reminderDate.month)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).reminderDate.year == E.At(j).reminderDate.year && E.At(i).reminderDate.month == E.At(j).reminderDate.month && E.At(i).reminderDate.day > E.At(j).reminderDate.day)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
        }
    }
    for (int i = 0; i < E.Length(); i++)
    {
        Esorted.Append(Es[i]);
    }
    return Esorted;
}