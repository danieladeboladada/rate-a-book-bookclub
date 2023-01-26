 /*
Purpose: To declare a bookclub containing the club members, books and book rating information.
*/
#ifndef BOOKCLUB_H
#define BOOKCLUB_H

#define RATING_MAX 1000

#include "Rating.h"
#include "DynArray.h"
#include "BookList.h"

using namespace std;

class BookClub
{
  public:
    BookClub(string="Arsenal");
    ~BookClub();
    //adds the given ClubMember pointer to the members collection
    void addMember(ClubMember*);
    //adds the given Book pointer to the books collection
    void addBook(Book*);
    /*
    finds the member and book that matches the given member id and book id
    and adds the member, book and rating to the pairs array to signify that the member rated the book
    */
    void addRating(int,int,int);
    //prints all the elements in the members collection
    void printMembers();
    //prints all the elements in the books collection
    void printBooks();
    //prints information about the best rated book in the bookclub
    void bestRated();
    //prints information about the most rated book in the bookclub
    void mostRated();

  private:
    //name of the bookclub
    string name;
    //collection of all books in the book club
    BookList books;
    //collection of all book club members
    DynArray members;
    //array containing all member-book pairs with the book rating given by the member for the respective book
    Rating *pairs[RATING_MAX];
    //number of pairs in the pairs array
    int numRated;
};

#endif
