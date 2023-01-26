#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

Book::Book(string t, string a)
{
  id     = getNextId();
  title  = t;
  author = a;
}

Book::Book(Book& orig)
{
  id     = orig.id;
  title  = orig.title;
  author = orig.author;
}

Book::~Book() {}

bool Book::lessThan(Book *b){
  if(author == b->author)
    if(title==b->title)
      return id < b->id;
    else return title < b->title;
  return author < b->author;

}

bool Book::isDuplicate(Book* b){
  if(title==b->title && author==b->author)
    return true;
  return false;
}

int Book::getId() { return id; }

string Book::getTitle() { return title; }

string Book::getAuthor() { return author; }

void Book::print() const
{
  cout<<"Id: " << id << "** "<< title <<" by "<<author<<endl;
}
