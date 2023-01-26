/*
Purpose: To declare book(s) in a bookclub which have:
         an id, title and author
         and manages the book data.
*/
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "RandomIdGenerator.h"

using namespace std;

class Book: public RandomIdGenerator
{
  public:
    Book(string="Unknown", string="Unknown");
    Book(Book&);
    ~Book();
    int getId();
    string getTitle();
    string getAuthor();
    void print() const;

    //returns true if this book's author comes before the given book's author in alphabetical order and false otherwise
    //if they have the same author, it returns true if this book's title comes before the given book's title in alphabetical order and false otherwise
    //if they have the same title, it returns true if this book's id is less than the given book's id and false otherwise
    bool lessThan(Book*);
    //returns true if this book's author and title is the same as that of the given book and false otherwise
    bool isDuplicate(Book*);

  private:
    //The book ID
    int id;
    //The book title
    string title;
    //The book author
    string author;
};

#endif
