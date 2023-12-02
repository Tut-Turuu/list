#include <iostream>
#include <cmath>


template<typename T>
class List {

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

public:

    List();

    ~List();

    void push_back(T data);

    T at(int index);

    void delete_el(int index);

    void dublicate_el(int index);

    void swap(Node* a, Node* b);

    void sort();

    void print();

    int get_size() {
        return this->size;
    }
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
void List<T>::swap(Node* a, Node* b) {
    T tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

template<typename T>
void List<T>::sort() {
    Node* ptr_a = this->head->next;
    Node* ptr_b;
    for (int i = 0; i < this->size - 1; i++) {
        ptr_b = ptr_a;
        for (int j = i; j < this->size; j++) {
            if (ptr_a->data > ptr_b->data) {
                swap(ptr_a, ptr_b);
            }
            ptr_b = ptr_b->next;
        }
        ptr_a = ptr_a->next;
    }
}

template<typename T>
void List<T>::print() {
    Node* current = this->head->next;

    for (int i = 0; i < this->size; i++) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

bool is_first_digit_seven(int x) {
    int digit;
    while (x > 0) {
        digit = x % 10;
        x /= 10;
    }
    return (digit == 7);
}

bool is_prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_even(int x) {
    return (x % 2 == 0);
}


int main() {
    List<int> lst;

    int x, n;
    bool flag = false;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> x;

        if (is_first_digit_seven(x)) {
            flag = true;
        }
        lst.push_back(x);
    }

    if (flag) {
        for (int i = 0; i < lst.get_size(); i++) {
            if (is_prime(lst.at(i))) {
                lst.delete_el(i);
                i--;
            } else if (is_even(lst.at(i))) {
                lst.dublicate_el(i);
                i++;
            }
        }
    } else {
        lst.sort();
    }

    lst.print();

}