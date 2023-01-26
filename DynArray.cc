#include <iostream>
using namespace std;

#include "DynArray.h"


DynArray::DynArray()
{
  members = new ClubMember*[MAX_ARR];
  size = 0;

}

DynArray::~DynArray()
{
  for (int i=0; i<size; ++i)
    delete members[i];
  delete [] members;
}

void DynArray::add(ClubMember* c)
{
  int i=0,j;
  if (size >= MAX_ARR)
    return;

  while(i<size){
    if(members[i]->getId()==c->getId()){
      return;
    }
    if(members[i]->lessThan(c)){
      i++;
    }
    else break;
  }

  for(j=size;j>i;j--){
    members[j]=members[j-1];
  }

  members[i] = c;
  ++size;
}

void DynArray::print()
{
  for (int i=0; i<size; ++i)
    members[i]->print();

}

bool DynArray::find(int id,ClubMember** cm){
  for(int i=0;i<size;i++){
    if(members[i]->getId()==id){
      *cm=members[i];
      return true;
    }
  }

  *cm=NULL;
  return false;
}
