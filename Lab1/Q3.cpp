#include <iostream>
using namespace std;

class Box {
    private:
        int* num;
    public:
        Box(){  // Default Constructor
            num = new int(0);
        }
        Box(int n) {  // Parameterized Constructor
            num = new int(n);
        }
        // comment from here for shallow copy
        Box (const Box& obj) {  // Copy Constructor  
            num = new int(*obj.num);
        }
        Box& operator=(const Box& other) { // Copy Assignment Operator
            if(this != &other) {
                delete num;
                num = new int(*other.num);
            }
            return *this;
        }
        // comment till here
        void printNum(){
            cout << "Number: " << *num << endl;
        }
        void minusOne () {
            *num -= 1;
        }
        ~Box() {  // destructor
            delete num;  // frees the memory of num to avoid memory leak
        }
};

int main() {
    Box box1(2);
    box1.printNum();
    
    // deep copy 
    Box box2;
    box2 = box1; // copy assignment operator (deep copy)
    box2.printNum();
    
    box2.minusOne();
    box2.printNum();
    box1.printNum();

    Box box3 = box1; // copy constructor (deep copy)
    box3.printNum();
    
    box3.minusOne();
    box3.printNum();
    box1.printNum();
    
    /* for shallow copy, we will not write the code for copy constructor or assignment operator, 
        instead it will use the default ones to create a shaallow copy.
        To test, you can comment out the code of constructors and see the result for shallow copy, 
        when the data or one object is changed, gthe other gets changed too
    */
    // Box box4
    return 0;
}
