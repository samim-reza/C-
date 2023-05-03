#include<bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
};
class Linked_List{
    private:
        Node* head;
    public:
        Linked_List()
        {
            head = NULL;
        }
        void add_node_at_front(int val)
        {
            Node *n = new Node;
            n -> value = val;
            n -> next = head;
            head = n;
        }
        void append_node(int val)
        {
            Node* n = new Node;
            n -> value = val;
            n -> next = NULL;
            if(head == NULL)
            {
                head = n;
                return;
            }
            Node* current = head;
            while(current -> next != NULL)
            {
                current = current -> next;
            }
            current -> next = n;
        }

        void print_Node()
        {
            Node *current = head;
            cout << "Head -> ";
            while(current != NULL)
            {
                cout << current -> value << " -> ";
                current = current -> next;
            }
            cout << endl;
        }
};

int main()
{
    Linked_List L;

    L.print_Node();
    L.add_node_at_front(5);
    L.add_node_at_front(6);
    L.append_node(8);
    L.print_Node();
}
