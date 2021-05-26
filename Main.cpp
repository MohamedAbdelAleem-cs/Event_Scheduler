#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<Event> Events;
    Event E("Hello", {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, "Place");
    Events.Append(E);
    cout << Events.Length() << endl;
    Events.At(0).Display();
}