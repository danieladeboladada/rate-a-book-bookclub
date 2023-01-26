output: main.o Control.o Book.o DynArray.o BookClub.o BookList.o ClubMember.o Rating.o View.o RandomIdGenerator.o
	g++ -o output main.o Control.o Book.o DynArray.o BookClub.o BookList.o ClubMember.o Rating.o View.o RandomIdGenerator.o

main.o: main.cc Control.h
	g++  -c main.cc

Control.o: Control.cc Control.h BookClub.h View.h
	g++ -c Control.cc

RandomIdGenerator.o: RandomIdGenerator.cc RandomIdGenerator.h
	g++ -c RandomIdGenerator.cc

Book.o: Book.cc Book.h RandomIdGenerator.h
	g++ -c Book.cc

DynArray.o: DynArray.cc DynArray.h ClubMember.h
	g++ -c DynArray.cc

BookClub.o: BookClub.cc BookClub.h BookList.h DynArray.h Rating.h
	g++ -c BookClub.cc

BookList.o: BookList.cc BookList.h Book.h
	g++ -c BookList.cc

ClubMember.o: ClubMember.cc ClubMember.h
	g++ -c ClubMember.cc

Rating.o: Rating.cc Rating.h Book.h ClubMember.h
	g++ -c Rating.cc

View.o: View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o output
