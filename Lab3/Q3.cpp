#include<iostream>
using namespace std;

// ------ CIRCULAR DOUBLY LINKED LIST ------

class Node {  // class of node
    public:
        int data;  // holds int data
        Node* next;  // pointer to next node
        Node* prev; // ptr to prev node

        Node (int val) {  // constructor
            data = val;   // initialezes data
            next = NULL;  // new node created points to null
            prev = NULL;  // new node created points back to null
        }
};

class CDLL {
    public:
        Node* head;

        CDLL() { head = NULL; }  // constructor
        
        // head -> null
        // prev -> null

        // head -> 6 -> 7 -> head
        // head <- 6 <- 7 <- head
        void addAtStart(int val) {
            Node* newNode = new Node(val);  // create new node
            if (head == NULL) {  // if list is empty
                head = newNode;  // head points to new node
                newNode->next = head;  // circular, points to itself
            } else {  // if list already has elements
                Node* temp = head;
                while (temp->next != head) { // find last node pointing back to head
                    temp = temp->next;
                }
                temp->next = newNode;  // next of tail points to new node
                newNode->prev = temp;  // new node's prev points to tail
                newNode->next = head;  // new node’s next points to old head
                head->prev = newNode;  // old head’s prev points to new node
                head = newNode;   // update head
            }
        }
        
        // head -> 6 -> 7 -> head
        // head <- 6 <- 7 <- head

        // head -> 6 -> 7 -> 5 -> 2 -> head
        // head <- 6 <- 7 <- 5 <- 2 <- head
        void addAtEnd(int val) {
            Node* newNode = new Node(val);  // create new node

            if (head == NULL) {  // if list is empty, add at start
                head = newNode;
                head->next = head;
                head->prev = head;
                return;
            }

            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
        //         0    1    2    3
        // head -> 6 -> 7 -> 5 -> 2 -> head
        // value 4 at pos 2
        //         0    1    2    3    4
        // head -> 6 -> 7 -> 4 -> 5 -> 2 -> head

        // head <- 6 <- 7 <- 4 <- 5 <- 2 <- head
        void addInBetween(int val, int pos) {
            Node* newNode = new Node(val);  // create new node
            Node* temp = head;
            for (int i = 0; i < pos-1; i++) {  // move to node before insertion point
                temp = temp->next;
            }
            // temp -> 1 = 7
            // insert newNode between temp and temp->next
            // updated ptrs accordingly
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }

        void deleteNode(int val) {
            if (head == NULL) return;  // empty list

            Node* curr = head;  // ptr to traverse the list
            while (curr->data != val && curr->next != head) { // traverse until finds node with value to be delted or val not found (comes back to head)
                curr = curr->next;  
            }
            if (curr->data != val) return; // not found

            if (curr->next == curr) { // only one node in the list
                delete curr;  // free memory of head
                head = NULL;  // empty list
                return;
            }

            // unlink node by connecting its prev and next
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            // if node to delete was head, move head forward
            if (curr == head) head = curr->next;
            delete curr;  // delete the node
        }

        void display() {
            if (head == NULL) {
                cout << "List is empty\n";
                return;
            }
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            }while (temp != head);
        }

        ~CDLL() {  // destructor
            if (head == NULL) return;  // list is empty

            Node* curr = head->next;  // curr ptr points to next node of head
            while (curr != head) {  // until finds last node
                Node* nextNode = curr->next;  // store next of curr node
                delete curr; // delete curr node
                curr = nextNode;  // curr points to next node to be deleted
            } 
            delete head;  // delete last remaining node
            head = NULL;
        }
};

int main () {
    CDLL list;
    list.addAtStart(7);
    list.addAtStart(6);

    list.addAtEnd(5);
    list.addAtEnd(2);

    list.addInBetween(4, 2);

    list.display();

    list.deleteNode(4);
    cout << "\nList after deleting 4: ";
    list.display();

    list.deleteNode(6);
    cout << "\nList after deleting 6: ";
    list.display();

    return 0;
}