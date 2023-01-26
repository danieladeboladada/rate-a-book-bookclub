/*
Purpose: To declare a class that records the rating that a clubmember gives
         a book.
*/
#ifndef RATING_H
#define RATING_H

#include <string>
#include "ClubMember.h"
#include "Book.h"

class Rating
{
  public:
    Rating(ClubMember* =NULL,Book* = NULL,int=0);
    ~Rating();
    void setRating(int);
    int getRating();
    //returns the clubmember data member
    ClubMember* getClubMember() const;
    //returns the book data member
    Book* getBook() const;
    //prints information about club member, book rated and the rating given to the book by the student.
    void print() const;

  private:
    //the book rating given
    int bookRating;
    //the club member that rates the book
    ClubMember *clubmember;
    //the book that was rated
    Book *book;
};

#endif
