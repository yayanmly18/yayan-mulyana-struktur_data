#include <iostream>
using namespace std;

// Mendefinisikan struktur sebuah node
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk membalik linked list
Node *reverseLinkedList(Node *head)
{
    Node *prev = nullptr; // Node sebelumnya awalnya null
    Node *curr = head; // Node saat ini adalah head
    Node *nextNode = nullptr; // Node selanjutnya awalnya null

    while (curr != nullptr) // Selama masih ada node saat ini
    {
        nextNode = curr->next; // Simpan node selanjutnya
        curr->next = prev; // Balik pointer ke node sebelumnya
        prev = curr; // Pindahkan pointer node sebelumnya ke node saat ini
        curr = nextNode; // Pindahkan pointer node saat ini ke node selanjutnya
    }

    return prev; // Kembalikan node terakhir yang sekarang menjadi head
}

// Fungsi untuk mencetak linked list
void printLinkedList(Node *head)
{
    while (head != nullptr) // Selama masih ada node
    {
        cout << head->data << " "; // Cetak data node saat ini
        head = head->next; // Pindahkan pointer ke node selanjutnya
    }
    cout << endl;
}

int main()
{
    // Membuat linked list contoh: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1); // Node pertama (head)
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
    printLinkedList(head); // Cetak linked list normal

    // Memutar balik linked list
    head = reverseLinkedList(head);

    cout << "Reverse : ";
    printLinkedList(head); // Cetak linked list yang sudah dibalik

    cout << "Nama  : Yayan Mulyana" << endl; // Cetak nama
    cout << "NPM   : 2310631170057" << endl; // Cetak NPM
    cout << "Kelas : 2C INFORMATIKA" << endl; // Cetak kelas

    return 0;
}
