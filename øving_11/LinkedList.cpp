#include "LinkedList.h"
#include <cassert>

using namespace std;
using namespace LL;


ostream& LL::operator<<(ostream& os, const Node& node) {
    os << node.value;
    return os;
}

Node* LinkedList::insert(Node* pos, const string& value) {
    if (pos == begin()) { // if pos is the first node
        // create a new head node, point to the old head node
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        // and make the old head node point back to the new one
        pos->prev = begin();
    } else {
        auto prevNode = pos->prev;
        prevNode->next = make_unique<Node>(value, move(prevNode->next), prevNode);
        pos->prev = prevNode->getNext();
    }
    return pos->prev;
}

Node* LinkedList::remove(Node* pos) {
    assert(pos);
    assert(pos != end());
    if (pos == begin()) {
        head = move(pos->next);
        head->prev = nullptr;
        return begin();
    }
    Node* nextNode = pos->getNext();
    nextNode->prev = pos->prev;
    pos->prev->next = move(pos->next);

    return nextNode;
}

Node* LinkedList::find(const string& value) {
    auto n = begin();
    while (n != end() && n->getValue() != value) n = n->getNext();
    return n;
}

void LinkedList::remove(const string& value) {
    auto n = begin();
    while (n != end()) {
        if (n->getValue() == value) {
            remove(n);
            break;
        }
        ++n;
    }
}

ostream& LL::operator<<(ostream& os, const LinkedList& list) {
    
    for (auto n = list.begin(); n != list.end(); n = n->getNext()) {
        cout << n->getValue() << " ";
    }
    return os;
}

void testLinkedList() {
    LinkedList list;
    
    Node* n = list.insert(list.end(), "Ulrik");
    cout << *n << '\n';
    n = list.insert(list.end(), "Vilde");
    cout << list << '\n';
    n = list.insert(list.end(), "Vilja");
    cout << list << '\n';
    n = list.remove(n);
    cout << list << '\n';
    remove("Vilde");
    cout << list << '\n';
}