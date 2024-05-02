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

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
Node* getTail(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, * cur = head, * tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (newHead == nullptr) {
                newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (newHead == nullptr) {
        newHead = pivot;
    }

    newEnd = tail;

    return pivot;
}

Node* quickSortRec(Node* head, Node* end) {
    if (!head || head == end) {
        return head;
    }

    Node* newHead = nullptr, * newEnd = nullptr;

    Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        newHead = quickSortRec(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node*& head) {
    head = quickSortRec(head, getTail(head));
}

int main() {
    
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(4);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printList(head);

    quickSort(head);

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
