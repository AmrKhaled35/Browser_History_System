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
    node *top , *curr;
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
    void getTop (T &item) {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            item = top -> Item;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            curr = top;
            cout <<" Items on Stack : " << "[";
            while (curr != NULL) {
                cout << curr -> Item;
                if (curr -> Next != NULL) {
                    cout<< " ";
                }
                curr = curr -> Next;
            }
            cout << "]" << endl;
        }
    }
};
Stack<string>backStack;
Stack<string>ForwardStack;
string curr = "";
void visit(string url) {
    if (curr !=  "") {
        backStack.push(curr);
    }
    while (ForwardStack.isEmpty()) {
         ForwardStack.pop();
    }
    curr = url;
    cout << "Visited Url : " << curr << endl;
}

int main() {
    Stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    return 0;
}
