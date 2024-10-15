#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
        Node<int>* current = head;

        while (current != nullptr) {
            Node<int>* next = current->getNext();

            if (current->getItem() % 2 == 0) {
                evensList.insertLast(current->getItem());
            } else {
                oddsList.insertLast(current->getItem());
            }

            current = next;
        }

        head = nullptr;
    }
};

int main() {
    intLinkedList list;
    intLinkedList evensList;
    intLinkedList oddsList;
    int data;

    cout << "Enter integers ending with -999: ";
    while (true) {
        cin >> data;
        if (data == -999) {
            break;
        }
        list.insertLast(data);
    }

    cout << "List: ";
    list.display();

    list.splitEvensOddsList(evensList, oddsList);

    cout << "Evens List: ";
    evensList.display();

    cout << "Odds List: ";
    oddsList.display();

    return 0;
}