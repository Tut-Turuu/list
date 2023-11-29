#include <iostream>


template<typename T>
class DoubleLinkedList {

    class Node {

    public:

        Node* next;
        Node* prev;
        T data;

        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    int size;

    // fictitious element
    Node* head;

    Node* get_elem(int index){
        Node* current;

        if (index < this->size / 2) {
            current = this->head->next;
            
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = this->head->prev;
            
            for (int i = this->size - 1; i > index; i--) {
                current = current->prev;
            }
        }
        return current;
    }
    
public:

    DoubleLinkedList();

    ~DoubleLinkedList();

    void push_back(T data);

    T at(int index);

    void delete_el(int index);

    void dublicate_el(int index);

    void swap(Node* a, Node* b);

    void sort();

    int get_size() {
        return this->size;
    }

    void debug() {

        Node* current = this->head->next;

        std::cout << "=======\n";

        for (int i = 0; i < this->size; i++) {
            std::cout << current->prev << ' ' << current << ' ' << current->next << '\n';
            current = current->next;
        }

        std::cout << "=======\n";
    }

    void loop() {
        Node* current = this->head->next;
        while (true) {
            std::cout << current->data << '\n';
            current = current->next;
        }
    }

    void print();


    
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->head = new Node();
    this->size = 0;

}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {

}

template<typename T>
void DoubleLinkedList<T>::push_back(T data) {
    if (this->size == 0) {
        this->head->next = new Node(data, head, head);
        this->head->prev = this->head->next;
    } else {
        Node* last = head->prev;
        last->next = new Node(data, head, last);
        head->prev = last->next;
    }
    this->size++;
}

template<typename T>
T DoubleLinkedList<T>::at(int index) {
    if (index >= this->size) {
        throw std::out_of_range("Out of range");
    }

    Node* current = get_elem(index);

    return current->data;
}

template<typename T>
void DoubleLinkedList<T>::delete_el(int index) {
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }

    Node* current = get_elem(index);
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    this->size--;
}

template<typename T>
void DoubleLinkedList<T>::dublicate_el(int index) {
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }

    Node* current = get_elem(index);

    current->next->prev = new Node(current->data, current->next, current);
    current->next = current->next->prev;
    this->size++;
}

template<typename T>
void DoubleLinkedList<T>::swap(Node* a, Node* b) {
    T tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

template<typename T>
void DoubleLinkedList<T>::sort() {


    
}

template<typename T>
void DoubleLinkedList<T>::print() {
    Node* current = this->head->next;

    for (int i = 0; i < this->size; i++) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';

}


int main() {

    DoubleLinkedList<int> lst;

    lst.push_back(12);
    lst.push_back(10);
    lst.push_back(111);
    lst.push_back(22);
    lst.push_back(99);

    lst.print();

    lst.delete_el(3);

    lst.dublicate_el(2);


    lst.print();

}