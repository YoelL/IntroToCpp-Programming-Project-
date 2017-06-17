//
//  LinkedList.h
//  GenricLinkedList
//
//  Created by Yoel Lev on 1/4/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#ifndef __GenricLinkedList__LinkedList__
#define __GenricLinkedList__LinkedList__

#include <iostream>
#include <typeinfo>

using namespace std;


template<class T> class Node{
public:
    //Member functions
    
    T data;
    Node<T> * next;
    Node<T> * prev;
    
    Node<T>():next(),prev() { }
    Node<T>(const T& d):data(d), next(),prev(){}
    Node<T>(const Node<T>& copyNode) : data(copyNode.data), next(),prev() {}
    Node<T>& operator =(const Node<T>& node ){
        
        if(&node == this) return *this;
        
        
        if(typeid(node) == typeid(*this)){
            
            this->next = node.next;
            this->prev = node.prev;
            return *this;

        }
        
    return *this ;
    }

};




template <class T > class LinkedList {
    //instance variables
   
public:
    //Member functions

    Node<T> * head;
    Node<T> * tail;
    
    //Default C'tor
    LinkedList(): head(NULL),tail(NULL){ }
    
    LinkedList(Node<T> * newNode): head(newNode),tail(newNode){ }
    
    //D'tor
    ~LinkedList(){
        Node<T> * curr = head;
        while (head){
            head = head->next;
            delete curr;
            curr = head;
        }
    }
    
    //Copy C'tor
    LinkedList(const LinkedList<T>& LL):head(NULL), tail(NULL){
       
         Node<T> * curr = LL.head;
        
        if (!head && curr){
            
            head = new Node<T>(curr->data);
            tail = head;
           // curr = curr->next;
             curr->next = curr->prev = curr;
            
        }
        
        while (curr){
            Node<T> * newNode = new Node<T>(curr->data);
            tail->next = newNode;
            tail = newNode;
            curr = curr->next;
            
            
        }
    }
    
    //Equale Operator
    LinkedList<T>& operator=(const LinkedList& ll ){
        
        if(&ll == this) return *this;
        if(typeid(ll) == typeid(*this)){
            
            this->head = ll.head;
            this->tail = ll.tail;
            return *this;

        }
    }
    
    //Bigger then Operator
    bool  operator > (const LinkedList<T>& item) const{
        
        if (item > this) {
            return true;
        }
        return false;
    }
    
    //Insert item to  Tail.
    void insertTT(T val){
        
        Node<T> * newNode = new Node<T>(val);
        
        if (tail == NULL){
            newNode->next = tail;
            tail = newNode;
            head = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
        
        sort();
    }
    
    //Insert item to  Head.
    void insertTH(T val){
        Node<T> * newNode = new Node<T>(val);
        
        if (head == NULL){
            head = newNode;
            return;
        }
        
        head->prev = newNode;
        newNode->next = head;
        head= newNode;
        
        sort();
    }
    
    //returns a pointer to the first item of the list
    LinkedList<T>& first(){
        return head;
    }
    
    //returns a pointer to the last item of the list
    LinkedList<T>& last(){
        return tail;
    }
    
    //returns a pointer to the item of the list, if found (starts from Head)
    Node<T>& findForward(T& item){
        
        Node<T> * curr = head;
        
        while (curr){
            if (curr->data == item) {
                cout<<"item Found!"<<endl;
                return *curr->prev;
                
            }
            curr = curr->next;
        }
         cout<<"item does not exists!"<<endl;
       return *curr;
    }
   
    //returns a pointer to the item of the list, if found (starts from Tail)
    void findBackward(T& item){
        
        Node<T> * curr = tail;
        
        while (curr){
            if (curr->data == item) {
                cout<<"item Found!"<<endl;
                return;
            }
            curr = curr->prev;
        }
        
        cout<<"item does not exists!"<<endl;
       return;
    }
    
    //Erases a specific node with a given value.
    bool erase(T item ){
     
        Node<T> * curr = head;
        Node<T> * temp;
        int index = 0;
        int llSize = getLinkedListSize();
    
        while (curr){
            
            if (curr->data == item && index < llSize ) {
                
                temp =curr;
                
                if (curr == head) {
                    head = curr->next;
                }else{
                    curr->prev->next =curr->next;
                    curr->next = temp->prev;
                }

                delete temp;
                return true;
            }else{
                index++;
            }
            curr = curr->next;
        }
        
        return false;
    }
  
    //recursive method that clears the LL.
    void clear( ){
        Node<T> * curr = head;
        
        if (head == NULL) {
            return;
        }else{
            delete head ;
            head = curr->next;
            clear();
        }
  
    }

    //Display on console the data in the LL.
    void print(){
        
        Node<T> * curr = head;
        
        while (curr){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<"null"<<endl;
    }
 
    //returns the number of item in LL.
    int getLinkedListSize(){
        int count = 0 ;
        Node<T> * curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    //Sorts the LL by decending values
    void sort(){
        
       Node<T> *curr = head;
        Node<T> temp ;
        
        for (int i = 0 ;i < getLinkedListSize() ; i++ ) {
            
            for (int j = 0 ;j <  getLinkedListSize(); j++) {
               
                if (curr == NULL || curr->next == NULL) {
                    curr = head;
                    break;
                }
                
                if (!(curr->data > curr->next->data)) {
                    temp.data =curr->next->data ;
                    curr->next->data=curr->data;
                    curr->data=temp.data;
                }
                
                curr = curr->next;
                
            }
            
        }
    }
    
    void printHead(){
         Node<T> * curr = head;
        
        cout<<"Head->"<<curr->data<<endl;
  
    }
    
    void printtail(){
        Node<T> * curr = tail;
        
        cout<<"Tail->"<<curr->data<<endl;
        
    }
    
    const Node<T>& getItems(int i){
        Node<T> * curr = head;

        for (int index = 0 ;curr;  curr = curr->next ,index++  ) {
            
            if (index == i ) {
                return *curr;
            }
        }
        return *curr;
    }
    
};




#endif /* defined(__GenricLinkedList__LinkedList__) */
