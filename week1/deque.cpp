#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

struct deque
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push_front(int x){
        Node* node = new Node(x);
        if (head == NULL) tail = node;
        else head->prev = node;
        node->next = head;
        head = node;
        sz++;
    }
    void push_back(int x){
        Node* node = new Node(x);
        if (tail == NULL) head = node;
        else tail->next = node;
        node->prev = tail;
        tail = node;
        sz++;
    }
    int front(){
        if (empty()) return 0;
        return head->data;
    }
    int back(){
        if (empty()) return 0;
        return tail->data;
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
    void pop_front(){
        if (empty()) return;
        sz--;
        head = head->next;
        if (!empty()) head ->prev = NULL;
        if (empty()) tail = NULL;
    }
    void pop_back(){
        if (empty()) return;
        sz--;
        tail = tail->prev;
        if (!empty()) tail->next = NULL;
        if (empty()) head = NULL;
    }
};
