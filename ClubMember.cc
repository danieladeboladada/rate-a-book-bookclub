#include <iostream>
using namespace std;
#include <string>
#include "ClubMember.h"

ClubMember::ClubMember(string f, string l){
    firstname=f;
    lastname=l;
    id=getNextId();
}

ClubMember::ClubMember(ClubMember& cb){
  id=getNextId();
  firstname=cb.firstname;
  lastname=cb.lastname;
  cb.ratedBooks.clone(&ratedBooks);
}

ClubMember::~ClubMember(){}

int ClubMember::getId() {return id;}

bool ClubMember::lessThan(ClubMember* cb){
  return id < cb->id;
}

void ClubMember::rateBook(Book* b){
  ratedBooks.add(b);
}

void ClubMember::print() const{
  cout<<"ID: "<<id<<" Fullname: "<<firstname<<" "<<lastname<<endl;
  cout<<firstname<<"'s rated books:"<<endl;
  ratedBooks.print();
}
