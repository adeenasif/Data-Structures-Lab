#include<iostream>
using namespace std;

class Node {  // class of node
    public:
        int data;  // holds int data
        Node* next;  // pointer to next node

        Node (int val) {  // constructor
            data = val;   // initialezes data
            next = NULL;  // new node created points to null
        }
};

class CLL {  // class of CIRCULAR LINKED LIST
    public:
        Node* head;  // head ptr points to first node

        CLL() { head = NULL; } // constructor
        
        // head -> null
        // head -> 7 -> head
        // head -> 6 -> 7 -> head
        // head -> 6 -> 7 -> head
        void addAtStart(int val) {  // to insert a new node at beginning of list
            Node* newNode = new Node(val);  // create a new node
            if (head == NULL) {  // if list is empty
                head = newNode;  // head points to first node added
                newNode->next = head;  // circular, so next points back to head(itself)
            } else {  // list already exists
                Node* temp = head;  // temp ptr for traversing to end
                while (temp->next != head) { // finds the last node that points back to head
                    temp = temp->next;  // keeps moving temp forward 
                }
                temp->next = newNode;  // now next of temp points to new node created
                newNode->next = head;  // next of new node points back to head
                head = newNode; // head points to the first node
            }
        }
        
        // head -> 6 -> 7 -> head
        // head -> 6 -> 7 -> 5 -> 2 -> head
        void addAtEnd(int val) {  // to insert a new node at end of list
            Node* newNode = new Node(val); // create a new node
            Node* temp = head;  // temp ptr for traversing to end
            while (temp->next != head) { // finds the last node that points back to head
                temp = temp->next;  // keeps moving temp forward 
            }
            temp->next = newNode;  // now next of temp points to new node created
            newNode->next = head;  // next of new node points back to head
        }
        //         0    1    2    3
        // head -> 6 -> 7 -> 5 -> 2 -> head
        // value 4 at pos 2
        //         0    1    2   3    4
        // head -> 6 -> 7 -> 4-> 5 -> 2 -> head

        // to insert a new node at any given position
        void addInBetween(int val, int pos) { 
            Node* newNode = new Node(val); // create a new node
            Node* temp = head;  // temp ptr for traversing to end
            for (int i = 0; i < pos-1; i++) {  // to find the node where new node is to be inserted
                temp = temp->next; // keeps moving temp forward 
            }
            // temp -> 1 = 7
            newNode->next = temp->next;  // next of new node points back to next of temp
            temp->next = newNode;  // next of temp points to new node created
        }

        // function to delete any node
        void deleteNode(int val) {
            if (head == NULL) return;  // returns if list is empty
            // temp -> 6
            // temp -> 2
            // temp->next -> head(6)
            // temp -> 7
            // head -> 7

            // head -> 6 -> 7 -> 4-> 5 -> 2 -> head(6)
            // delete 6
            // head -> 7 -> 4-> 5 -> 2 -> head
            if (val == head->data){  //  if the node to be deleted is the head node 
                Node* temp = head;  // store head in a temp ptr
                while (temp->next != head) {  // traverse to find last that is pointing to head
                    temp = temp->next;  // move temp to its next
                }
                temp->next = head->next;  // make last node point to second node (head->next)
                head = temp;  // update head to point to its next
                delete temp;  // delete temp
                return;
            }
            // head -> 6 -> 7 -> 4 -> 5 -> 2 -> head
            // delete 4
            Node* curr = head;  // curr ptr pointing to head
            Node* prev;     // prev ptr 
            while (val != curr->data) { // loop till it finds val on the node to be deleted
                prev = curr;  //  update prev ptr to curr
                curr = curr->next;  // update curr ptr to its next
            }
            // curr -> 4
            // prev -> 7
            prev->next = curr->next;  // unlink curr by making prev->next skip curr
            // head -> 6 -> 7 -> 5 -> 2 -> head
            delete curr;  // delete curr node
        }

        // function to print complete circular link list
        void display() { 
            if (head == NULL) {
                cout << "List is empty\n";
                return;
            }
            Node* temp = head;  // temp ptr points to head
            do {  // do-while so that it prints the data on the first node(head)
                cout << temp->data << " ";  // prints data
                temp = temp->next;  // moves ptr to next
            } while (temp != head);  // until it finds the last node (which points back to head)
        }

        ~CLL() { // Destructor
            if (head == NULL) return;  // empty list

            Node* current = head->next;
            while (current != head) {  // loops till last node
                Node* nextNode = current->next;  // move to next 
                delete current;  // free memory of curr node
                current = nextNode;  // move to next node
            }
            delete head; // free memory of head pointer
        }
};

int main () {
    CLL list; 
    // add values at start of list
    list.addAtStart(7);
    list.addAtStart(6);

    // add values at end of list
    list.addAtEnd(5);
    list.addAtEnd(2);

    // add val at a certain position
    list.addInBetween(4, 2);

    // display original list
    cout << "List: ";
    list.display();

    // delete node (somewhere in between)
    list.deleteNode(4);
    cout << "\nList after deleting 4: ";
    list.display();

    // delete node (first node)
    list.deleteNode(6);
    cout << "\nList after deleting 6: ";

    // display list (after deletion)
    list.display();
    return 0;
}
