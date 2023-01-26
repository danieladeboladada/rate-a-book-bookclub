#include <iostream>
#include <iomanip>
#include <string>
#include "BookClub.h"

using namespace std;

BookClub::BookClub(string n){
  name=n;
  numRated=0;
}

BookClub::~BookClub(){
  for (int i=0; i<numRated; ++i)
    delete pairs[i];

}

void BookClub::addMember(ClubMember* cm){
  members.add(cm);
}

void BookClub::addBook(Book* b){
  books.add(b);
}

void BookClub::addRating(int cmID,int bID,int r){
  ClubMember* cm;
  Book* b;
  char ch;

  if(numRated >= RATING_MAX){
    cerr <<endl << "Out of space" <<endl;
    return;
  }

  if(r < 1 || r > 10){
    cerr<<"Invalid rating, must be between 1 and 10"<<endl;
    return;
  }

  if(members.find(cmID,&cm) && books.find(bID,&b)){
    for(int i=0;i<numRated;i++){
      if(pairs[i]->getClubMember()->getId()==cmID &&
         pairs[i]->getBook()->getId()==bID){
        while(true){
          cout<<"Do you wish to update your rating Y/N ? ";
          cin >> ch;
          if(ch=='N' || ch=='n'){ return;}
          if(ch=='Y' || ch=='y'){
            pairs[i]->setRating(r);
            cout<<"Rating updated successfully"<<endl;
            return;
          }
        }
      }
    }

    pairs[numRated]= new Rating(cm, b, r);
    numRated++;

    Book *tempBook=new Book(*b);

    cm->rateBook(tempBook);

    cout<<endl<< "Book "<< b->getId()
        << " was successfully rated "<< r << " by " << "Member "<<cm->getId() << endl;


  }
  else{
    cerr <<endl<< "This Member/Book does not exist" << endl;
  }
}

void BookClub::printMembers(){
  cout<<endl<<"Members of bookclub "<<name<<": "<<endl;
  members.print();
}

void BookClub::printBooks(){
  cout<<endl<<"Books in bookclub "<<name<<": "<<endl;
  books.print();
}

void BookClub::bestRated(){
  if(numRated==0){
    cerr<<"No book is rated yet"<<endl;
    return;
  }

  int enumAvg=1;
  int denomAvg=1;
  int i,j;


  for (i=0; i<numRated; ++i){
    int id=pairs[i]->getBook()->getId();
    int count=0;
    int total=0;

    for(j=0;j<numRated;j++){
        if(pairs[j]->getBook()->getId()==id){
          count++;
          total+=pairs[j]->getRating();
        }

    }
    if(enumAvg*count < denomAvg*total){
      enumAvg=total;
      denomAvg=count;
    }
  }
  cout<< "Best rated book(s): "<<endl;

  for (i=0; i<numRated; ++i){
    int id=pairs[i]->getBook()->getId();
    int count=0;
    int total=0;

    for(j=0;j<numRated;j++){
        if(pairs[j]->getBook()->getId()==id){
          count++;
          total+=pairs[j]->getRating();
        }

    }
    bool sw=true;
    for(j=i-1;j>=0;j--){
      if(pairs[j]->getBook()->getId()==id){
        sw=false;
        break;
      }
    }
    if(sw && enumAvg*count == denomAvg*total){
        pairs[i]->getBook()->print();
    }
  }

}

void BookClub::mostRated(){
  if(numRated==0){
    cerr<<"No book is rated yet"<<endl;
    return;
  }

  int most=1;
  int i,j;

  for (i=0; i<numRated; ++i){
    int id=pairs[i]->getBook()->getId();
    int count=0;

    for(j=0;j<numRated;j++){
        if(pairs[j]->getBook()->getId()==id)
          count++;
    }
    if(count>most){
      most=count;
    }
  }
  cout << "Most rated book(s): "<<endl;
  for (i=0; i<numRated; ++i){
    int id=pairs[i]->getBook()->getId();
    int count=0;

    for(j=0;j<numRated;j++){
        if(pairs[j]->getBook()->getId()==id)
          count++;
    }
    bool sw=true;
    for(j=i-1;j>=0;j--){
      if(pairs[j]->getBook()->getId()==id){
        sw=false;
        break;
      }
    }
    if(sw && count==most){
      pairs[i]->getBook()->print();
    }
  }

}
