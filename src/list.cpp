#include "list.hpp"


namespace lst {

    template<typename T>
    class List {

    public:

        List(T data, Node* next);

        ~List();

        void push_back(T data);

        void insert();

        void print();

        void delete_el();

        void dublicate_el();

        void swap_elems();

    private:

        template<typename T>
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
        Node<T>* head;

    };

    template<typename T>
    List<T>::List(T data = T(), Node* next = nullptr) {

    }

    template<typename T>
    List<T>::~List() {

    }

    template<typename T>
    void List<T>::push_back(T data) {

        if (head == nullptr) {

            head = new Node<T>(data);

        } else {
            
            Node<T>* current = this->head;
            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = new Node<T>(data);

        }
    }

    template<typename T>
    void List<T>::insert() {

    }

    template<typename T>
    void List<T>::print() {

    }

    template<typename T>
    void List<T>::delete_el() {

    }

    template<typename T>
    void List<T>::dublicate_el() {

    }

    template<typename T>
    void List<T>::swap_elems() {

    }

}
