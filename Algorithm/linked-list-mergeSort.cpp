#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    Node* result = nullptr;

    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}


Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* left = head;
    Node* right = slow->next;
    slow->next = nullptr; // Splitting the linked list into two halves

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    // Clean up the memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
