#include "LinkedList.h"

namespace LinkedList {

Node* LinkedList::insert(Node *pos, const std::string& value) {
    //Three cases: pos nullptr (invalid), pos points at head, pos points at not head
    if(pos == nullptr) {
        exit(1);
    }

    if(pos == begin()) {
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = begin();
    }
    else {
        Node* p_prev = pos->prev;
        p_prev->next = std::make_unique<Node>(value, std::move(p_prev->next), p_prev);
        pos->prev = p_prev->getNext();
    }

    //pos->prev is now inserted node, as we insert before pos
    return pos->prev;
}

Node* LinkedList::find(const std::string& value) {
    for(Node* n = begin(); n != end(); n = n->getNext()) 
        if(n->value == value)
            return n;

    return end();
}

Node* LinkedList::remove(Node* pos) {
    if(pos == nullptr || pos == end())
        exit(1);
    
    Node* next;
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


void LinkedList::remove(const std::string& value) {
    Node* node = find(value);
    if(node != end())
        remove(node);
}
std::ostream& operator<<(std::ostream & os, const Node & node) {
    return os << node.value;
}
std::ostream& operator<<(std::ostream & os, const LinkedList& list) {
    os << "{ ";
    for(Node* n = list.begin(); n != list.end(); n = n->getNext()) {
        os << *n << " ";
    }
    os << "}";

    return os;
}

} // EOF namespace LinkedList