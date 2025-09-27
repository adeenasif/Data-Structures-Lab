#include <iostream>
using namespace std;

class Exam {
    private:
        string stdName;
        string examDate;
        int* score;  // to use DMA
    public:
        Exam (string name, string date, int sc) {  // parameterized constructor
            stdName = name;
            examDate = date;
            score = new int(sc);  // allocated memory using DMA
        }
        
        // Setters for each attribute
        void setName (string name) {
            stdName = name;
        }
        void setDate (string date) {
            examDate = date;
        }
        void setScore (int sc) {
            *score = sc;
        }

        void display () {  // function to display details
            cout << "Student Name: " << stdName << endl;
            cout << "Exam Date: " << examDate << endl;
            cout << "Student Score: " << *score << endl;
        }

        ~Exam() { // destructor
            delete score;  // frees memory to avoid memory leak
        }
};

int main () {
    Exam exam1("Amna", "22-08-2025", 95);
    exam1.display();

    // Shallow Copy created by using default copy constructor
    Exam exam2 = exam1;   // score pointer copied, not data 
    exam2.display();

    exam2.setScore(60); // Both exam1 and exam2 share same score pointer so both data changed

    cout << "\nAfter changing exam2's score:" << endl;
    exam1.display(); // Will also show updated score 
    exam2.display();

    // Resulting Issue: When program ends, destructor is called for both objects
    // Double deletion of score will cause runtime error
    return 0;
}
