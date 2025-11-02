#include <iostream>
#include <unordered_set>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at a specific position (1-based index)
    void insertAtPosition(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete first node
    void popFront() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete last node
    void popBack() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete node by value
    void deleteNode(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if (temp->next == nullptr) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete node at a position
    void deleteAtPosition(int pos) {
        if (head == nullptr || pos < 1) return;

        if (pos == 1) {
            popFront();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Search for a value
    bool search(int val) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Get length
    int getLength() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Get middle element
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;  
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    // Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Remove duplicates (for sorted list)
    void removeDuplicates() {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data == temp->next->data) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
    }

    // Detect cycle (Floyd's algorithm)
    bool detectCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Remove cycle if present
    void removeCycle() {
        if (!detectCycle()) return;

        Node* slow = head;
        Node* fast = head;

        // Detect cycle point
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        // Move one pointer to head
        fast = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = nullptr;
    }

    // Sort the linked list (using Bubble sort for simplicity)
    void sort() {
        if (head == nullptr) return;

        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = head; j->next != nullptr; j = j->next) {
                if (j->data > j->next->data) {
                    swap(j->data, j->next->data);
                }
            }
        }
    }

    // Merge two sorted lists
    static Node* mergeTwoLists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* result;
        if (l1->data < l2->data) {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        } else {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        return result;
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Clear the entire list
    void clear() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = nullptr;
    }

    Node* getHead() { return head; }
};

// Main
int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Original List:\n";
    list.display();

    list.insertAtBeginning(5);
    list.insertAtPosition(4, 25);
    cout << "\nAfter insertions:\n";
    list.display();

    list.deleteNode(30);
    list.popFront();
    list.popBack();
    cout << "\nAfter deletions:\n";
    list.display();

    cout << "\nLength: " << list.getLength() << endl;
    list.findMiddle();

    cout << "\nReversed List:\n";
    list.reverse();
    list.display();

    cout << "\nSorted List:\n";
    list.sort();
    list.display();

    cout << "\nSearch for 25: " << (list.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}
