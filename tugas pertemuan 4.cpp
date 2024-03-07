#include <iostream>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse the linked list
Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextNode = nullptr;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    cout << "Normal  : ";
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reverse : ";
    printLinkedList(head);

    cout << "Nama  : Yayan Mulyana" << endl;
    cout << "NPM   : 2310631170057" << endl;
    cout << "Kelas : 2C INFORMATIKA" << endl;

    return 0;
}
