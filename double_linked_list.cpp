#include <iostream>


template<typename T>
class DoubleLinkedList {
    
public:

    DoubleLinkedList();

    ~DoubleLinkedList();

    void push_back(T data);

    T at(int index);

    void delete_el(int index);

    void dublicate_el(int index);

    void swap(int index_a, int index_b);

    int get_size() {
        return this->size;
    }

    void debug() {

        Node* current = this->head->next;
        for (int i = 0; i < this->size; i++) {
            std::cout << current->prev << ' ' << current << ' ' << current->next << '\n';
            current = current->next;
        }

        std::cout << "=======\n";
    }

private:

    class Node {

    public:

        T data;
        Node* next;
        Node* prev;

        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    int size;

    // fictitious element
    Node* head;
    
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
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }

    Node* current;

    if (index < this->size / 2) {
        current = this->head->next;
        
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = this->head->prev;
        
        for (int size = this->size - 1; size > index; size--) {
            current = current->prev;
        }
    }
    return current->data;
}

template<typename T>
void DoubleLinkedList<T>::delete_el(int index) {
    if (index >= size) {
        throw std::out_of_range("Out of range");
    }

    Node* current;

    if (index < this->size / 2) {
        current = this->head->next;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = this->head->prev;
        
        for (int size = this->size - 1; size > index; size--) {
            current = current->prev;
        }
    }
    current->prev->next = current->next;
    current->prev;
    delete current;
    this->size--;
}

template<typename T>
void DoubleLinkedList<T>::dublicate_el(int index) {

}

template<typename T>
void DoubleLinkedList<T>::swap(int index_a, int index_b) {

}



int main() {

    DoubleLinkedList<int> lst;

    lst.push_back(12);
    lst.push_back(10);
    lst.push_back(111);
    lst.push_back(22);

    lst.debug();

    lst.delete_el(3);

    lst.debug();


    for (int i = 0; i < lst.get_size(); i++) {
        std::cout << lst.at(i) << ' ';
    }    

    std::cout << '\n';

}