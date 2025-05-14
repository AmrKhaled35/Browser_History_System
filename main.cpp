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
    node *top , *curr ,*count;
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
    int StackCount () {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            int counter = 0;
            count = top;
            while (count -> Next != NULL) {
                counter++;
                count = count -> Next;
            }
            return counter+1;
        }
    }
};
Stack<string>backStack;
Stack<string>forwardStack;
string curr = "";
void visit(string url) {
    if (curr !=  "") {
        backStack.push(curr);
    }
    while (!forwardStack.isEmpty()) {
         forwardStack.pop();
    }
    curr = url;
    cout << "Visited Url : " << curr << endl;
}
void goBack() {
    if (backStack.isEmpty()) {
        cout << "No previous URL" << endl;
        return;
    }
    forwardStack.push(curr);
    string c = "";
    backStack.getTop(c);
    backStack.pop();
    curr = c ;
    cout << "Current Url : " << curr << endl;
}
void goForward() {
    if (forwardStack.isEmpty()) {
        cout << "No forward URL" << endl;
        return;
    }
    backStack.push(curr);
    string c = "";
    forwardStack.getTop(c);
    forwardStack.pop();
    curr = c ;
    cout << "Current Url : " << curr << endl;
}


int main() {
    visit("google.com");
    visit("wikipedia.org");
    visit("youtube.com");
    goBack();
    goBack();
    goForward();
    visit("facebook.com");
    goBack();
    goForward();
    goForward();
    return 0;
}
