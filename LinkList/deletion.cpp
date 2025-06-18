#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // 1. Delete node by value
    void deleteByValue(int val) {
        if (!head) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Value not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
    }

    // 2. Delete first node
    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 3. Delete last node
    void deleteLast() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // 4. Delete node at specific index (0-based)
    void deleteAtPosition(int pos) {
        if (!head || pos < 0) return;

        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    LinkedList list;
    int n, val;

    cout << "How many elements to insert? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "\nInitial Linked List:\n";
    list.display();

    int choice;
    do {
        cout << "\n--- Delete Menu ---\n";
        cout << "1. Delete by value\n";
        cout << "2. Delete first node\n";
        cout << "3. Delete last node\n";
        cout << "4. Delete at position\n";
        cout << "5. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteByValue(val);
                break;
            case 2:
                list.deleteFirst();
                break;
            case 3:
                list.deleteLast();
                break;
            case 4:
                int pos;
                cout << "Enter position to delete (0-based index): ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 5:
                list.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
