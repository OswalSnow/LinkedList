#include <iostream>
using namespace std;

//Declaración de las clases
class Node{
public:
    int data;
    Node *next;

    Node(int data);
};

class LL{
private:
    Node *head;
    Node *tail;

public:
    LL();
    void Print();
    void AddHead(int data);
    void DeleteHead();
    void AddTail(int data);
    void DeleteTail();
    void ReverseList();
};

//Implementación de los métodos
Node::Node(int data){
    this->data = data;
    this->next = nullptr;
}

LL::LL(){
    this->head = nullptr;
    this->tail = nullptr;
}

void LL::Print(){
    Node *temp = head;

    if(temp == nullptr){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    
    while(temp != nullptr){
        cout<<"Dato ==> "<<temp->data<<endl;
        temp = temp->next;
    }
}

void LL::AddHead(int data){
    Node *temp = head;
    Node *nuevo_nodo = new Node(data);
    nuevo_nodo->next = temp;

    if(temp == nullptr)
        tail = nuevo_nodo;

    head = nuevo_nodo;
}

void LL::DeleteHead(){
    Node *temp = head;

    if(temp == nullptr){
        cout<<"La lista ya esta vacia"<<endl;
        return;
    }
    
    head = temp->next;

    if(head == nullptr)
        tail = nullptr;

    delete temp;
}

void LL::AddTail(int data){
    Node *temp = tail;
    Node *nuevo_nodo = new Node(data);

    if(tail == nullptr){
        tail = nuevo_nodo;
        head = nuevo_nodo;
        return;
    }
    
    tail->next = nuevo_nodo;
    tail = nuevo_nodo;
}

void LL::DeleteTail(){
    Node *temp = head;

    if(temp == nullptr){
        cout<<"La lista ya esta vacia"<<endl;
        return;
    }

    if(temp == tail){
        head = tail = temp->next;
        delete temp;
        return;
    }

    while(temp->next != tail )
        temp = temp->next;
    
    tail = temp;
    delete temp->next;
    tail->next = nullptr;
}

void LL::ReverseList(){
    Node *prev = nullptr;
    Node *temp = nullptr;
    Node *current = head;

    if(current == nullptr){
        cout<<"La lista esta vacia, no se puede invertir"<<endl;
        return;
    }

    while(current != nullptr){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    tail = head;
    head = prev;
}

int main(){
    LL *lista = new LL();

    lista->AddHead(5);
    lista->AddHead(4);
    lista->AddHead(3);
    lista->AddHead(2);
    lista->AddHead(1);

    lista->Print();
    lista->ReverseList();
    lista->Print();

    return 0;
}