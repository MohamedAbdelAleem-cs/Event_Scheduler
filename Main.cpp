#include <iostream>
#include "LinkedList.cpp"
using namespace std;

LinkedList<Event> SortStartDate(LinkedList<Event> E);
LinkedList<Event> SortEndDate(LinkedList<Event> E);
LinkedList<Event> SortReminderDate(LinkedList<Event> E);

int main()
{
    LinkedList<Event> Events;
    Event E("Hello", {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Event E1("Hello", {1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Event E2("Hello", {3, 3, 3, 3, 3}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Event E3("Hello", {4, 4, 4, 4, 4}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Event E4("Hello", {5, 5, 5, 5, 5}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Events.Append(E);
    Events.Append(E1);
    Events.Append(E2);
    Events.Append(E3);
    Events.Append(E4);
    /*cout << "Update: ";
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }
    int updateIndex;
    cin >> updateIndex;
    Event E1;
    Event E2 = E1.Update();
    Events.Append(E);
    Events.Update(updateIndex, E2);
    cout << "----------------------------------" << endl;*/
    cout
        << "Display:   ";
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }
    cout << "----------------------------------" << endl;
    /*cout << "Delete:   ";
    Events.DeleteAt(1);
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }*/
    cout << "Sort  " << endl;
    Events = SortStartDate(Events);
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }
}

LinkedList<Event> SortStartDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event lastEvent;
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
LinkedList<Event> SortEndDate(LinkedList<Event> E)
{
    LinkedList<Event> Esorted;
    Event lastEvent;
    Event *Es = new Event[E.Length()];
    for (int i = 0; i < E.Length(); i++)
    {
        Es[i] = E.At(i);
    }
    for (int i = 0; i < E.Length(); i++)
    {
        for (int j = i + 1; j < E.Length(); j++)
        {
            if (E.At(i).endDate.year > E.At(j).endDate.year)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).endDate.year == E.At(j).endDate.year && E.At(i).endDate.month > E.At(j).endDate.month)
            {
                Event etmp = Es[i];
                Es[i] = Es[j];
                Es[j] = etmp;
            }
            else if (E.At(i).endDate.year == E.At(j).endDate.year && E.At(i).endDate.month == E.At(j).endDate.month && E.At(i).endDate.day > E.At(j).endDate.day)
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
    Event lastEvent;
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