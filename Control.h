 /*
Purpose: To manage all operations of a bookclub
*/
#ifndef CONTROL_H
#define CONTROL_H

#include "BookClub.h"
#include "View.h"

using namespace std;

class Control
{
  public:
    Control();

    //controls all operations on the bookclub attributes
    void launch();

    //initializes clubmembers in the book club
    void initMembers(BookClub*);

    //initializes books in the book club
    void initBooks(BookClub*);
    //initializes the ratings of books by members of the club
    void initRatings(BookClub*);


  private:

    //the bookclub managed by this class
    BookClub bookclub;

    //displays main menu and reads user selection
    View view;
};

#endif
