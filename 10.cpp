#include "10_linked_list.h"
#include "10_bus.h"
#include <iostream>

using namespace std;

void printList(const char *title, LinkedList<Bus> *list) {
    cout << title << endl;

    Node<Bus> *c = list->start;

    while (c != nullptr) {
        cout << "Bus number = " << c->data.number << ", driver = " << c->data.driver << ", route = " << c->data.route
             << endl;
        c = c->next;
    }
    cout << endl;
}

int main() {

    auto *park = new LinkedList<Bus>;
    auto *route = new LinkedList<Bus>;

    Bus bus1 = *new Bus(1, (char *) "driver1", 11);
    Bus bus2 = *new Bus(2, (char *) "driver2", 22);
    Bus bus3 = *new Bus(3, (char *) "driver3", 33);

    park->first(1, bus1);
    park->add(2, bus2);
    park->add(3, bus3);

    printList("PARK", park);
    printList("ROUTE", route);

    Node<Bus> *removed2 = park->remove(2);
    route->add(2, removed2->data);

    printList("PARK (bus 2 removed)", park);
    printList("ROUTE (bus 2 added)", route);

    Node<Bus> *fromRoute = route->remove(2);
    park->add(2, fromRoute->data);
    printList("PARK (bus 2 added back)", park);
    printList("ROUTE (bus 2 removed)", route);

    return 0;
}