#include "LL.h"

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
    this->size++;
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
    this->size--;
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
    size++;
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
    this->size--;
}

void LL::AddMid(int data, int index){
    if(index == 0){
        this->AddHead(data);
    } 
    else if(index == size){
        this->AddTail(index);
    }
    else{
        Node *prev = head;
        Node *current = prev->next;

        for(int i = 1; i < index; i++){
            prev = current;
            current = current->next;
        }
        Node *newNode = new Node(data);
        prev->next = newNode;
        newNode->next = current;
        this->size++;
    }
}

void LL::DeleteMid(int index){
    if(index == 0){
        this->DeleteHead();
    }
    else if(index == size){
        this->DeleteTail();
    }
    else{
        Node *prev = head;
        Node *current = prev->next;

        for(int i = 1; i < index; i++){
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        delete current;
        this->size--;
    }
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

Node LL::FindMid(){
    Node *slow = head;
    Node *fast = head;

    while( fast->next != nullptr){
        
        if(fast->next->next == nullptr){
            fast->next = nullptr;
        }
        else{
            fast = fast->next->next;
        }
        slow = slow->next;
    }
    return *slow;
}