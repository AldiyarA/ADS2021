#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string data;
    Node* next;
    int cnt;
    Node(string data){
        this -> data = data;
        this -> next = NULL;
        cnt = 1;
    }
};
ofstream out;
struct LinkedList
{
    Node* head;
    LinkedList (){
        this -> head = NULL;
    }
    void add(string data){
        if (this -> head == NULL){
            this -> head = new Node(data);
            return;
        }
        if (this -> head -> data > data){
            Node * node = new Node(data);
            node->next = head;
            this->head = node;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL)
        {
            if (curr -> data == data){
                curr -> cnt ++;
                return;
            }
            if (curr -> data > data){
                Node* node = new Node(data);
                prev -> next = node;
                node -> next = curr;
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
        Node* node = new Node(data);
        prev -> next = node;
        
    }
    void print(){
        Node* curr = head;
        while (curr != NULL)
        {
            out << curr -> data <<" " << curr -> cnt<<"\n";
            curr = curr -> next;
        }

    }
};


int main(){
    ifstream in("input.txt");
    out.open("output.txt");
    LinkedList* L = new LinkedList();
    while (!in.eof())
    {
        string s;
        in >> s;
        if (s == "") continue;
        L->add(s);
    }
    L->print();
    in.close();
    out.close();
    return 0;
}