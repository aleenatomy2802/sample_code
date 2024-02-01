#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position <= 0) {
            std::cerr << "Invalid position\n";
            return;
        }

        if (!head && position > 1) {
            std::cerr << "Invalid position\n";
            return;
        }

        if (position == 1) {
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            Node* temp = head;
            int i = 1;
            while (i < position - 1 && temp) {
                temp = temp->next;
                ++i;
            }

            if (!temp) {
                std::cerr << "Invalid position\n";
                return;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList myList;

    std::cout << "Doubly Linked List before insert: ";
    myList.display();

    myList.insertAtBeginning(1);
    myList.insertAtBeginning(2);
    myList.insertAtEnd(4);

    std::cout << "Doubly Linked List after insertion: ";
    myList.display();

    myList.insertAtPosition(3, 3);
    std::cout << "Doubly Linked List after insertion at position 3: ";
    myList.display();

    return 0;
}
