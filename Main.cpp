#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<Event> Events;
    Event E("Hello", {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Event E5("Hello", {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Events.Append(E);
    Events.Append(E5);
    cout << "Update: ";
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
    cout << "----------------------------------" << endl;
    cout << "Display:   ";
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }
    cout << "----------------------------------" << endl;
    cout << "Delete:   ";
    Events.DeleteAt(1);
    for (int i = 0; i < Events.Length(); i++)
    {
        cout << i << ":";
        Events.At(i).Display();
    }
}