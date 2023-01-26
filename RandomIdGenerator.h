/*
To declare a class that generates ids for clubmembers and books in the bookclub
*/
#ifndef RANDOMIDGENERATOR_H
#define RANDOMIDGENERATOR_H
#include <string>

class RandomIdGenerator
{
  public:
    RandomIdGenerator();
    ~RandomIdGenerator();
    //generates and returns the next id to be assigned for a clubmember/book
    int getNextId();

  private:
    static int nextId;

};

#endif
