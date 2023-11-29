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

    void swap(int index_a, int index_b);

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
    // fictitious element
    Node* head;
};

template<typename T>
List<T>::List() {
    this->head = new Node();
    this->size = 0;
    
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
    if (head->next == nullptr) {
        head->next = new Node(data);
        
    } else {
        Node* current = this->head->next;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }
    this->size++;
}

template<typename T>
T List<T>::at(int index) {
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }
    Node* current = head->next;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void List<T>::delete_el(int index) {
    if (this->size <= index) {
        throw std::out_of_range("Out of range");
    }
    Node* previous;
    Node* current = this->head->next;
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
    if (this->size <= index) {
        throw std::out_of_range("Out of range");
    }

    Node* current = this->head->next;

    if (this->size == index + 1) {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        T data = current->data;
        current->next = new Node(data);
    } else {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        T data = current->data;
        Node* next = current->next;

        current->next = new Node(data);
        current->next->next = next;
    }
    this->size++;
}

template<typename T>
void List<T>::swap(int index_a, int index_b) {
    T data_a;
    T data_b;
    int max_index = (index_a > index_b ? index_a : index_b);
    int min_index = (index_a < index_b ? index_a : index_b);

    Node* node_a, *node_b;
    Node* current = this->head->next;
    for (int i = 0; i < max_index; i++) {
        if (i == min_index) {
            data_a = current->data;
            node_a = current;
        }
        current = current->next;
    }
    data_b = current->data;
    node_b = current;

    node_b->data = data_a;
    node_a->data = data_b;
}


int main() {
    List<int> lst;

    lst.push_back(5);
    lst.push_back(7);
    lst.push_back(10);
    lst.push_back(18);

    lst.delete_el(2);
    lst.dublicate_el(1);
    lst.swap(0, 3);

    std::cout << lst.at(0) << ' ' << lst.at(1) << ' ' << lst.at(2) << ' ' << lst.at(3) << '\n';

}