#include <iostream>

template<typename T>
class List {

public:

    List();

    ~List();

    void push_back(T data);

    T at(int index);

    void delete_el(int index);

    void dublicate_el(int index);

private:

    class Node {
        
    public:
        Node* next;
        T data;

        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    int size;
    Node* head;
};

template<typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    Node* current = this->head;
    Node* next;
    for (int i = 0; i < size; i++) {
        next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node(data);
        
    } else {
        Node* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }
    this->size++;
}

template<typename T>
T List<T>::at(int index) {
    if (index > size) {
        throw std::out_of_range("Out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void List<T>::delete_el(int index) {
    if (this->head == nullptr) {
        throw std::out_of_range("Out of range");
    }
    Node* previous;
    Node* current = this->head;
    for (int i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
    this->size--;
}

template<typename T>
void List<T>::dublicate_el(int index) {
    
}


int main() {
    List<int> lst;

    lst.push_back(5);
    lst.push_back(7);
    lst.push_back(10);
    lst.push_back(18);

    lst.delete_el(2);

    std::cout << lst.at(0) << ' ' << lst.at(1) << ' ' << lst.at(2) << '\n';

}