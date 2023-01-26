#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Control.h"

Control::Control(){}

void Control::launch()
{
  int choice;
  initMembers(&bookclub);
  initBooks(&bookclub);
  //initRatings(&bookclub);

  while (1) {
    view.showMenu(choice);
    if (choice == 0)
      break;

//  Print all members of the book club
    if (choice == 1) {
      bookclub.printMembers();
    }
//  Print all books in the book club
    if (choice == 2) {
      bookclub.printBooks();
    }
//  Rate a book
    if (choice == 3) {
      int cmID,bID,rating;
      view.printStr("Please enter the member ID: ");
      view.readInt(cmID);
      view.printStr("Please enter the book ID: ");
      view.readInt(bID);
      view.printStr("Please enter the rating: ");
      view.readInt(rating);
      bookclub.addRating(cmID,bID,rating);
    }
//  Print best rated book
    if (choice == 4) {
      bookclub.bestRated();
    }
//  Print most rated book
    if (choice == 5) {
      bookclub.mostRated();

    }
  }
}

void Control::initMembers(BookClub* bc)
{
  bc->addMember(new ClubMember("Mungo","Park"));
  bc->addMember(new ClubMember("Jeiel","Andrew"));
  bc->addMember(new ClubMember("Barack","Obama"));
  bc->addMember(new ClubMember("Donald","Trump"));
  bc->addMember(new ClubMember("Justin","Trudeau"));

}

void Control::initBooks(BookClub* bc)
{
  bc->addBook(new Book("Animal Farm","George Orwell"));//1006
  //bc->addBook(new Book("Animal Farm","George Orwell"));//1007
  bc->addBook(new Book("Absalom, Absalom","William Faulkner"));//1008
  bc->addBook(new Book("A Time To Kill","John Grisham"));
  bc->addBook(new Book("The House Of Mirth","Edith Wharton"));
  bc->addBook(new Book("Blindness","Jose Saramago"));
  bc->addBook(new Book("East of Eden","John Steinbeck"));
  bc->addBook(new Book("Alchemist","Paulo Coelho"));
  bc->addBook(new Book("Vile Bodies","Evelyn Waugh"));
  bc->addBook(new Book("Pale Fire","Vladimir Nabokov"));
  bc->addBook(new Book("News of a Kidnapping","Gabriel Garcia Marquez"));
}

void Control::initRatings(BookClub* bc)
{
  bc->addRating(1001,1009,9);
  bc->addRating(1002,1009,8);
  bc->addRating(1003,1009,7);
  bc->addRating(1004,1009,2);
  bc->addRating(1005,1009,4);
  bc->addRating(1001,1010,6);
  bc->addRating(1002,1010,3);
  bc->addRating(1003,1010,7);
  bc->addRating(1004,1010,3);
  bc->addRating(1005,1010,9);
  bc->addRating(1001,1011,4);
  bc->addRating(1002,1011,4);
  bc->addRating(1003,1011,5);
  bc->addRating(1004,1011,8);
  bc->addRating(1005,1011,3);
  bc->addRating(1001,1012,10);
  bc->addRating(1002,1012,9);
  bc->addRating(1003,1012,9);
  bc->addRating(1004,1012,3);
  bc->addRating(1005,1012,8);
  bc->addRating(1001,1013,3);

}
