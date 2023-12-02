#include <iostream>
#include <cmath>

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

    Node* current = this->head;
    Node* tmp;
    for (int i = 0; i < this->size; i++) {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    delete current;

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
void DoubleLinkedList<T>::print() {
    Node* current = this->head->next;

    for (int i = 0; i < this->size; i++) {
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << '\n';
}

bool is_first_digit_one(int x) {
    int digit;
    while (x > 0) {
        digit = x % 10;
        x /= 10;
    }
    return (digit == 1);
}

bool is_divides_by_three_and_not_3(int x) {
    if (x == 3) {
        return false;
    }
    return !(x % 3);
}

bool is_prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    DoubleLinkedList<int> lst;

    int x, n;
    bool flag = true;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> x;

        if (is_first_digit_one(x)) {
            flag = false;
        }
        lst.push_back(x);
    }

    if (flag) {
        for (int i = 0; i < lst.get_size(); i++) {
            if (is_divides_by_three_and_not_3(lst.at(i))) {
                lst.delete_el(i);
                i--;
            } else if (is_prime(lst.at(i))) {
                lst.dublicate_el(i);
                i++;
            }
        }
    } else {
        lst.sort();
    }

    lst.print();

}