#include <iostream>

// Node class represents a node in the double-linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// DoubleLinkedList class represents the double-linked list
class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Traverse the list to find the last node
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }

            // Insert the new node at the end
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to insert a node at a specified location
    void insertAtLocation(int data, int position) {
        Node* newNode = new Node(data);

        if (position <= 0) {
            // Invalid position
            std::cerr << "Invalid position\n";
            return;
        }

        if (!head && position > 1) {
            // Invalid position for an empty list
            std::cerr << "Invalid position\n";
            return;
        }

        if (position == 1) {
            // Insert at the beginning
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        } else {
            // Insert at the specified position
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp; ++i) {
                temp = temp->next;
            }

            if (!temp) {
                // Invalid position
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

    // Function to display the contents of the list
    void displayList() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage of the DoubleLinkedList class
    DoubleLinkedList dll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.displayList();  // Output: 1 2 3

    dll.insertAtLocation(4, 2);
    dll.displayList();  // Output: 1 4 2 3

    dll.insertAtLocation(5, 1);
    dll.displayList();  // Output: 5 1 4 2 3

    return 0;
}
