#include <iostream>
using namespace std;

// Analytical Minds Group
// Osasumwen Osazuwa: 
// Daniel Igwe:
// Emmanuella:
// Joseph Inaku:
// Emmanuel: 

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Add a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Add a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // Add a node at a specific position (middle)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position should be >= 1." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }

        Node* temp = head;

        if (head->data == value) {
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Delete a node by position
    void deleteByPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }

        Node* temp = head;

        if (position == 1) {
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        for (int i = 1; temp != nullptr && i < position; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function for testing
int main() {
    LinkedList list;

    cout << "=== Test 1 ===\n";
    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtPosition(15, 2);
    list.display();
    list.deleteByValue(15);
    list.display();

    cout << "\n=== Test 2 ===\n";
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display();
    list.deleteByPosition(2);
    list.display();

    cout << "\n=== Test 3 ===\n";
    LinkedList list2;
    list2.deleteByPosition(1); // Empty list error handling
    list2.insertAtBeginning(50);
    list2.insertAtEnd(60);
    list2.insertAtPosition(70, 2);
    list2.display();
    list2.deleteByValue(60);
    list2.display();

    return 0;
}

