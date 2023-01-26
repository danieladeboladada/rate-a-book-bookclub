
#ifndef DYNARRAY_H
#define DYNARRAY_H

#define MAX_ARR 64

#include "ClubMember.h"

class DynArray
{
  public:
    DynArray();
    ~DynArray();

    //adds the given club member to the array
    void add(ClubMember*);
    void print();
    /*
    returns true if a clubmember with an id that matches the given id integer was
    found in the array and makes the given double pointer point to the clubmember
    returns false if a matching club member id is not found
    */
    bool find(int,ClubMember**);

  private:
    //dynamically allocated array containing all the members
    ClubMember** members;
    //size of the members array
    int   size;
};

#endif
