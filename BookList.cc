#include <iostream>
#include <string>
using namespace std;

#include "BookList.h"

BookList::BookList() : head(NULL), tail(NULL) { }

BookList::~BookList()
{
  Node* currNode;
  Node* nextNode;

  currNode = head;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }

  head=tail=NULL;
}

void BookList::add(Book* b)
{
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;
  newNode->data = b;
  newNode->next = NULL;

  if(head==NULL){
    head=tail=newNode;
    return;
  }

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if(newNode->data->isDuplicate(currNode->data)){
        cerr << "Book " << currNode->data->getId() << " already exists" <<endl;
        delete newNode->data;
        delete newNode;
        return;
    }
    if (newNode->data->lessThan(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL){
    newNode->next = head;
    head = newNode;
  }
  else if(currNode ==NULL){
    prevNode->next=newNode;
    tail=newNode;
  }
  else{
    prevNode->next = newNode;
    newNode->next = currNode;
  }

}

void BookList::del(int id, Book** goner)
{
  Node* currNode;
  Node* prevNode;


  if(head==NULL){
    *goner=NULL;
    return;
  }

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->data->getId() == id)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if(prevNode==NULL){
    *goner = head->data;
    if(head->next==NULL){
      delete head;
      head=tail=NULL;
    }
    else{
      currNode=currNode->next;
      delete head;
      head=currNode;
    }
  }
  else if (currNode == NULL) {
    *goner = NULL;
    return;
  }
  else{
    *goner=currNode->data;
    if(currNode->next == NULL){
      prevNode->next = NULL;
      delete tail;
      tail=prevNode;
    }
    else{
      prevNode->next=currNode->next;
      delete currNode;
    }
  }

}

void BookList::clone(BookList* bl){
  Node* currNode;

  currNode = head;

  while (currNode != NULL) {
    bl->add(currNode->data);
    currNode=currNode->next;
  }

}

bool BookList::find(int id,Book** b){
  Node* currNode;

  currNode = head;

  while (currNode != NULL) {
    if(id==currNode->data->getId()){
      *b=currNode->data;
      return true;
    }
    currNode=currNode->next;
  }

  *b=NULL;
  return false;

}


void BookList::print() const
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }

  // if(head != NULL){
  //   cout<<"head is : ";
  //   head->data->print();
  //   cout<<"tail is: ";
  //   tail->data->print();
  //   cout<<endl;

  // }
}
