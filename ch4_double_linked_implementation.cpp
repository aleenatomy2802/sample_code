#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    // Constructor that set default value
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    /*
    Node* newNode = new Node(data);: This line creates a new node with the given data value. 
    The newNode is a pointer to the newly allocated node in the memory.

    if (!head) { ... } else { ... }: 
    This conditional statement checks whether the list is empty or not.

    If the list is empty (if (!head)), it means there are no nodes in the list. In this case, the function sets both the head and tail pointers to the new node (newNode). This is because, when the list is empty, the new node becomes both the first and the last node in the list.

    If the list is not empty (else part), it means there are already nodes in the list. In this case:

    newNode->next = head;: The next pointer of the new node is set to point to the current head of the list. This step links the new node to the existing list.
    head->prev = newNode;: The prev pointer of the current head of the list is set to point back to the new node. This step establishes the backward link from the existing head to the new node.
    head = newNode;: The head pointer is updated to point to the new node, making the new node the new head of the list.
    */
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
