/*
Purpose: To declare a linked list of books and manipulate the books in it.
*/
#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"

class BookList
{
  //declaration of a Node class that has attributes as a Book data and a Node next
  class Node
  {
    public:
      //book pointer
      Book* data;
      //node that points to the next node in the list
      Node*    next;
  };

  public:
    BookList();
    ~BookList();
    //adds given book to the list
    void add(Book*);
    /*
    returns true if a book with an id that matches the given id integer was
    found in the array and makes the given Book double pointer point to the book
    returns false if a matching book id is not found.
    */
    bool find(int,Book**);
    //deletes the book that matches the given title and makes the given double pointer point to the deleted book.
    void del(int, Book**);
    void print() const;
    //copies all elements in our list into the given booklist
    void clone(BookList*);

  private:
    //node that points to the first element in the respective list
    Node* head;
    //node that points to the last element in the respective list
    Node* tail;

};

#endif
