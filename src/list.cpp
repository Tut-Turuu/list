#include "list.hpp"


namespace list {

    template<typename T>
    struct Node {
        T data;
        Node* next;

        Node() {
            data = T();
            next = nullptr;
        }

        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };



    template<typename T>
    class List {

        Node<T>* head;

    public:

        List() {
            head = Node<T>();
        }

        void push_back();

        void insert();

        void print();

        void delete_el();

        void dublicate_el();

        void swap_elems();

    };

        void push_back();

        void insert();

        void print();

        void delete_el();

        void dublicate_el();

        void swap_elems();

}
