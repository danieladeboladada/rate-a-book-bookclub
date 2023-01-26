#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Rating.h"

Rating::Rating(ClubMember *cm,Book *b,int br){
  clubmember=cm;
  book=b;
  bookRating=br;
}

Rating::~Rating(){}

void Rating::setRating(int r) { bookRating=r; }

int Rating::getRating() { return bookRating; }

ClubMember* Rating::getClubMember() const { return clubmember; }

Book* Rating::getBook() const { return book; }

void Rating::print() const{
  cout<<"CLUBMEMBER: "<<endl;
  cout<<"---------------------------------------"<<endl;
  clubmember->print();
  cout<<"---------------------------------------"<<endl;
  cout<<"GAVE THIS BOOK: "<<endl;
  cout<<"---------------------------------------"<<endl;
  book->print();
  cout<<"---------------------------------------"<<endl;
  cout<<" A RATING OF "<<bookRating<<endl;

}
