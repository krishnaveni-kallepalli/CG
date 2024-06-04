#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~SinglyLinkedList();

    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    bool empty() const;
    size_t get_size() const;
    void print_list() const;

    // Iterator
    class Iterator;
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::push_back(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    ++size;
}

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    if (!head) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T>* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    --size;
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    if (!head) return;

    Node<T>* temp = head;
    head = head->next;
    delete temp;

    if (!head) {
        tail = nullptr;
    }
    --size;
}

template <typename T>
bool SinglyLinkedList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
size_t SinglyLinkedList<T>::get_size() const {
    return size;
}

template <typename T>
void SinglyLinkedList<T>::print_list() const {
    Node<T>* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
class SinglyLinkedList<T>::Iterator {
private:
    Node<T>* current;

public:
    Iterator(Node<T>* node) : current(node) {}

    T& operator*() { return current->data; }
    Iterator& operator++() {
        current = current->next;
        return *this;
    }
    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }
};

int main() {
    SinglyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);

    std::cout << "List contents: ";
    list.print_list();

    std::cout << "Size of list: " << list.get_size() << std::endl;

    std::cout << "Popping front and back..." << std::endl;
    list.pop_front();
    list.pop_back();

    std::cout << "List contents: ";
    list.print_list();

    std::cout << "Iterating through list: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

