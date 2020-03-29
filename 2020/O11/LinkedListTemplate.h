#pragma once

#include <memory>
#include <ostream>


// test code 
void testLinkedList();


namespace LinkedList {
template<typename T>
class Node {
private:
    const T value;    // The data held by the LinkedList
    std::unique_ptr<Node<T>> next; // unique_ptr to the next node
    Node<T>* prev;                 // raw (non-owning) ptr to the previous node
public:
    Node<T>() : value(), next(nullptr), prev(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node<T>(const T& value, std::unique_ptr<Node<T>> next, Node<T>* prev)
        : value(value)
        , next(std::move(next))
        , prev(prev)
    {}
    // We can use the default destructor, since unique_ptr takes care of deleting memory
    ~Node<T>() = default;
    // return the value of the node
    T getValue() const { return value; }

    // return a raw (non-owning) pointer to the next node
    Node<T>* getNext() const { return next.get(); }
    // return a raw (non-owning) pointer to the previous node
    Node<T>* getPrev() const { return prev; }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream& os, const Node<T>& node);

    friend class LinkedList;
};

template <typename T>
class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node<T>> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node<T>, so that tail never can
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
    // node pointed to by pos. Returns a pointer to the new Node<T>
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
    friend std::ostream& operator<<(std::ostream & os, const LinkedList<T>& list);
};

template<typename T>
Node<T>* LinkedList<T>::insert(Node<T>* pos, const T& value) {
    //Three cases: pos nullptr (invalid), pos points at head, pos points at not head
    if(pos == nullptr) {
        exit(1);
    }

    if(pos == begin()) {
        head = std::make_unique<Node<T>>(value, std::move(head), nullptr);
        pos->prev = begin();
    }
    else {
        Node<T>* p_prev = pos->prev;
        p_prev->next = std::make_unique<Node<T>>(value, std::move(p_prev->next), p_prev);
        pos->prev = p_prev->getNext();
    }

    //pos->prev is now inserted node, as we insert before pos
    return pos->prev;
}

template<typename T>
Node<T>* LinkedList<T>::find(const T& value) {
    for(Node<T>* n = begin(); n != end(); n = n->getNext()) 
        if(n->value == value)
            return n;

    return end();
}

template <typename T>
Node<T>* LinkedList<T>::remove(Node<T>* pos) {
    if(pos == nullptr || pos == end())
        exit(1);
    
    Node<T>* next;
    if(pos == begin()) {    
        head = std::move(pos->next);
        head->prev = nullptr;
        next = begin();
    }
    else {
        next = pos->getNext();
        pos->next->prev = pos->prev;
        pos->prev->next = std::move(pos->next);
    }
    return next;
}

template<typename T>
void LinkedList<T>::remove(const T& value) {
    Node<T>* node = find(value);
    if(node != end())
        remove(node);
}

template<typename T>
std::ostream& operator<<(std::ostream & os, const Node<T>& node) {
    return os << node.value;
}

template<typename T>
std::ostream& operator<<(std::ostream & os, const LinkedList<T>& list) {
    os << "{ ";
    for(Node<T>* n = list.begin(); n != list.end(); n = n->getNext()) {
        os << *n << " ";
    }
    os << "}";

    return os;
}

} //namespace LinkedList



