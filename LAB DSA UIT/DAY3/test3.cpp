
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
        }
        void printLinkedList() {
            SinglyLinkedListNode* p;
            p = head;
            while (p != NULL){
                cout<<p->data<<endl;
                p = p->next;
            }
        }
    
};
void insert_node(SinglyLinkedList* llist, int data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if (!llist->head) {         // If the list is empty
        llist->head = node;
    } else {
        llist->tail->next = node; // Append at the end
    }
    llist->tail = node;          // Update the tail to the new node
}

void reverseLinkedList(SinglyLinkedList *llist) {
    SinglyLinkedListNode* temp = llist->head;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* nexxt = nullptr;

    while (temp != nullptr) {
        nexxt = temp->next;    
        temp->next = prev;     
        prev = temp;           
        temp = nexxt;          
    }
    llist->head = prev;        
}

void printLinkedList(SinglyLinkedList* llist) {
    SinglyLinkedListNode* p = llist->head;
    while (p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}


// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
