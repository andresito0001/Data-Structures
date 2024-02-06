#ifndef GLIST_H
#define GLIST_H 1

#include <cstddef>
#include <utility>
#include <iostream>

template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class GList {
public:
    GList();
    GList(std::initializer_list<T> list);

    void push_front(const T&& value);
    void push_back(const T&& value);
    
    void pop_back();
    void pop_front();

    const T& front() const { return head_->data; }
    T& front() { return head_->data; }

    const T& back() const { return tail_->data; }
    T& back() { return tail_->data; }

    bool isEmpty() { return size_ == 0 ? true : false; }
    std::size_t size () { return size_; }

    void printList();
private:
    Node<T>* head_;
    Node<T>* tail_;
    std::size_t size_;
};

template<class T>
GList<T>::GList() : head_(nullptr), tail_(nullptr), size_(0) { }

template<class T>
GList<T>::GList(std::initializer_list<T> list) {
    head_ = tail_ = nullptr;
    size_ = 0;
    
    for (auto const& elem : list)
        push_back(std::move(elem));
}

template<class T>
void GList<T>::push_back(const T&& value) {
    Node<T>* newElem = new Node<T>();

    newElem->data = std::move(value);

    if (head_ == nullptr)
        head_ = tail_ = newElem;
    else {
        tail_->next = newElem;
        tail_ = std::move(newElem);
    }

    ++size_;
}

template<class T>
void GList<T>::push_front(const T&& value) {
    Node<T>* newElem = new Node<T>();

    newElem->data = std::move(value);

    if (head_ == nullptr)
        head_ = tail_ = newElem;
    else {
        newElem->next = head_;
        head_ = std::move(newElem);
    }

    ++size_;
}

template<class T>
void GList<T>::pop_front() {
    if (isEmpty()) return;

    if (head_ == tail_) {
        delete head_;
        size_ = 0;
        head_ = tail_ = nullptr;
    } else {    
        Node<T>* nextNode = head_->next;
        head_ = head_->next;
        delete nextNode;
    }
    --size_;
}

template<class T>
void GList<T>::pop_back() {
    if (isEmpty()) return;

    if (head_ == tail_) {
        delete head_;
        size_ = 0;
        head_ = tail_ = nullptr;
    } else {
        Node<T>* current = head_;

        while (current->next != tail_)
            current = current->next;
        
        delete tail_;
        tail_ = current;
        tail_->next = nullptr;
       
        size_--;
    }
}

template<class T>
void GList<T>::printList() { 
    Node<T>* current = head_;

    while(current != nullptr) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    
    return;
}

#endif