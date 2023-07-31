#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
    }
    
    ~Node() {
        int value = this -> data;
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }
    cout << " the memory has been freed for : " << value;
    }
};

void insertNode(Node* &tail, int d, int element) {
    //empty list
    if(tail == NULL){
        Node* nodeToInsert = new Node(d);
        tail = nodeToInsert;
        nodeToInsert -> next = nodeToInsert;
    }
    else {
        Node* curr = tail;

        while(curr -> data != element) {
            curr = curr -> next;
        }
         Node* newNode = new Node(d);
         newNode -> next = curr -> next;
         curr -> next = newNode;
    }
}

void print(Node* tail) {
    Node* temp = tail;
    
    do {
        cout << tail -> data << "  ";
        tail = tail -> next;
    } while(tail != temp);
    
    cout << endl;
}

int main() {
    
    Node* tail = NULL;
    insertNode(tail, 45, 23);
    print(tail);
    
    insertNode(tail, 55, 45);
    print(tail);
    
    insertNode(tail, 65, 55);
    print(tail);
    
    return 0;
}