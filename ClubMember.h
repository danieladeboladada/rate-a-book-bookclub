/*
Purpose: To declare clubmembers of a bookclub that have:
         id, firstname, lastname, and list of their ratedbook(s)
*/
#ifndef CLUBMEMBER_H
#define CLUBMEMBER_H
#include <string>

#include "BookList.h"

class ClubMember : public RandomIdGenerator
{
  public:
    ClubMember(string="Unknown", string="Unknown");
    ClubMember(ClubMember&);
    ~ClubMember();
    int getId();
    //returns true if our id is less than the given clubmember's id and false otherwise
    bool lessThan(ClubMember*);
    //adds the given book to the ratedBooks list
    void rateBook(Book*);
    void print() const;

  private:
    //clubmember id
    int id;
    string firstname;
    string lastname;
    //list of all clubmember's rated books
    BookList ratedBooks;
};

#endif
