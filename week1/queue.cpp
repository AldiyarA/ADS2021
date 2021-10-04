#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

struct queue{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int x){
        sz ++;
        Node* node = new Node(x);
        if (head == NULL) head = node;
        else tail->next = node;
        tail = node;
    }
    int front(){
        if (head == NULL) return 0;
        return head->data;
    }
    void pop(){
        if (head == NULL) return;
        head = head -> next;
        sz--;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return sz == 0;
    }
    void clear(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }
};