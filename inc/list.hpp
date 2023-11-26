#pragma once


namespace lst {

    template<typename T>
    class List {

    public:

        template<typename T>
        List(T data, Node<T>* next);

        ~List();

        void push_back(T data);

        void insert();

        void print();

        void delete_el();

        void dublicate_el();

        void swap_elems();

    private:

        template<T>
        class Node {

        public:
            Node* next;
            T data;

            Node(T data, Node* next);

        };

        int size;
        Node<T>* head;
    };

}