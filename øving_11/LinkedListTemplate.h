#pragma once

#include <memory>
#include <iostream>



// test code 
void testLinkedList();

namespace TLL {
template<class T>
class Node {
private:
    const T value;    // The data held by the LinkedList
    std::unique_ptr<Node<T>> next; // unique_ptr to the next node
    Node<T>* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node() : value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node(const T& value, std::unique_ptr<Node<T>> next, Node<T>* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default constructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node<T>* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node<T>* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream & os, const Node<T> & node);ostream& LL::operator<<(ostream& os, const Node& node) {
        os << node.value;
    return os;
}

    friend class LinkedList<T>;
};

template <class T>
class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node<T>> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node, so that tail never can
    // point anywhere else
    Node<T>* const tail;
public:
    //create the dummy node, and make tail point to it
    LinkedList()
        : head(std::make_unique<Node<T>>())
        , tail(head.get())
    {}
    ~LinkedList() = default;

    //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
    bool isEmpty() const { return !head->next; }


    //return a pointer to first element
    Node<T>* begin() const { return head.get(); }
    //return a pointer to beyond-end element
    Node<T>* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos. Returns a pointer to the new Node
    Node<T>* insert(Node<T> *pos, const T& value);

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node<T>* find(const T& value);

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node<T>* remove(Node<T>* pos);

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const T& value);

    // write a string representation of the list to the ostream
    friend std::ostream & operator<<(std::ostream & os, const LinkedList<T>& list);
};
}// namespace LL

using namespace TLL;

template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* pos,const T& value) {
    if (pos == begin()) { // if pos is the first node
        // create a new head node, point to the old head node
        head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
        // and make the old head node point back to the new one
        pos->prev = begin();
    } else {
        auto prevNode = pos->prev;
        prevNode->next = make_unique<Node<T>>(value, move(prevNode->next), prevNode);
        pos->prev = prevNode->getNext();
    }
    return pos->prev;
}

template <class T>
Node<T>* LinkedList<T>::remove(Node<T>* pos) {
    assert(pos);
    assert(pos != end());
    if (pos == begin()) {
        head = move(pos->next);
        head->prev = nullptr;
        return begin();
    }
    Node<T>* nextNode = pos->getNext();
    nextNode->prev = pos->prev;
    pos->prev->next = move(pos->next);

    return nextNode;
}