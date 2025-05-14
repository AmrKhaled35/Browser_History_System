#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
template<typename T>
class Stack {
    struct node {
        T Item;
        node *Next;
    };
    node *top;
public:
    Stack() {
        top = NULL;
    }
    void push(T newItem) {
        node *newNode = new node;
        if (newNode == NULL) {
            cout << "Stack Overflow" << endl;
        }
        else {
            newNode->Item = newItem;
            newNode->Next = top;
            top = newNode;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack IsEmpty" << endl;
        }else {
            node *temp = top;
            top = top -> Next;
            temp = temp->Next = NULL;
            delete temp;
        }
    }

};

int main() {


    return 0;
}
