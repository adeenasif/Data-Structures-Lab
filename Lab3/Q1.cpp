#include<iostream>
using namespace std;

class Node {  // node class
    public:
        int val;  // stores data
        Node* next;  // pointer that holds the address of next node

        Node(int val) {  // constructor
            this->val = val;  // to initialize data
            next = NULL;  // current node points to null
        }
};

class LinkedList {  // single linked list
    public:
        Node* head;  // a head ptr that will point to the first node of list
        Node* tail;  // a tail ptr that will point to the last node of list

        LinkedList() {  // constructor to initialize head/tail to NULL (no nodes in list)
            head = NULL;
            tail = NULL;
        }

        void firstNode (int val) {  // function to insert first node
            Node* newNode = new Node(val);  // creates a new node
            if (head == NULL) {  // checks if there is no current node
                head = newNode;  // updates the head from null to new node pointer
                return;
            } else {  // inserts at first, if there is data alr present in the list
                newNode->next = head; // next was pointing to Null, now pointing to head
                head = newNode;
            }
        }

        void insertNode(int val) {  // at the end of the list
            Node* newNode = new Node(val);  // creates a new node
            Node* temp = head;  // a temp ptr used for traversing
            while (temp->next != tail) {  // traverses until it finds last node
                temp = temp->next;  // moves ptr to next node of the current one
            }
            temp->next = newNode;  // the next of last node now points to new node added
            newNode->next = tail;  // tail points to null of the last node
        }

        void display() {  // function to display the nodes of list
            Node* temp = head;  // temp pointer required for traversing
            while (temp != NULL) {  // keeps traversing untill the end of list
                cout << temp->val << " -> ";  // prints the data of current node 
                temp = temp->next;  // moves the pointer to next node
            }
            cout << "NULL" << endl;
        }

        // function to modify list such that all even nums appear before all odd nums.
        void modify () {  
            if (!head || !head->next) {
                return;  // if the list is empty or has only one node, it returns without perfoming anything
            }

            Node* prev = NULL;  // a temp pointer to point at previous node
            Node* curr = head;  // a temp pointer to point at current node (starts from head)
            Node* evenTail = NULL; // a temp pointer that points to last even node 

            while (curr != NULL) {  // to traverse thru entire list
                if (curr->val % 2 == 0) { // checks if value at current node is even
                    if (evenTail == NULL) {  // means no even value found yet
                        // first even node found
                        if (curr != head) {
                            prev->next = curr->next; // to remove link of curr from its current position
                            curr->next = head;  // move curr to start of list(head)
                            head = curr;  // update head for it to point at the first node
                        }
                        evenTail = head;  // now head is the first and most recent even node so eventail also points to it
                        if (prev == NULL) {
                            curr = head->next;   // move curr to the node after head
                        } else {
                            curr = prev->next;   // move curr to the node after prev
                        }

                    } else {  // if theres already an even num found at start
                        if (evenTail->next == curr) { // already in correct position
                            evenTail = curr;  // first even node found so evenTail now points to curr
                            prev = curr;  //  move the previous ptr to current
                            curr = curr->next;  // moves current to next node
                        } else {  // if its not the first node that is even
                            prev->next = curr->next; // remove curr from its place

                            // insert after evenTail so that even nodes are together
                            curr->next = evenTail->next;  // curr points to the node after the last even node
                            evenTail->next = curr;  // link evenTail node to curr, to insert curr right after the last even node
                            evenTail = curr;  // evenTail pointer now points to the new last even node (which is now curr)
                            curr = prev->next;  // move curr forward in the list 
                        }
                    }
                } else { // odd node (we ignore the odd nodes and change them only when an even one is found)
                    prev = curr;  // moves prev ptr forward (to curr)
                    curr = curr->next;  // moves curr ptr forward to its next
                }
            }
        }

        ~LinkedList() {  // destructor
            Node* current = head;  // a temp ptr holding current node
            while (current != NULL) {  // traverses thru entire list
                Node* nextNode = current->next;  // creates a temp pointer for next node
                delete current;  // deletes the node of current pointer
                current = nextNode;  // assigns current to the next node
            }
        }
};

int main() {
    LinkedList list;  // create a list
    
    /*  a menu could be created instead with the choice of where the user wants to insert data 
        but here i have assumed the data is positive and user can enter -1 to stop
    */
    cout << "Enter data in the list (enter -1 to stop): " << endl;  
    int val;
    cin >> val;  // takes input for the data on the first node
    list.firstNode(val);  // inserts data on the first node of list

    while (val != -1) {  // loops takes input until it gets -1
        cin >> val;
        if (val != -1) 
            list.insertNode(val);  // inserts from end if the val is not -1
    } 
    cout << "\nOriginal List: " << endl;
    list.display();  // displays the original linked list

    list.modify();
    cout << "\n\nModified List: " << endl;
    list.display();  // displays the list after modification (if any)

    return 0;
}