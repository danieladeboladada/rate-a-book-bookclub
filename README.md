# rate-a-book-bookclub

Author(s): Daniel Adebola-Dada

Purpose: To manage a bookclub with book club members and books using C++ where club members can rate a book.

List of source and header files:
1. Control.cc
2. Control.h
3. View.cc
4. View.h
5. BookClub.cc
6. BookClub.h
7. Book.cc
8. Book.h
9. ClubMember.cc
10. ClubMember.h
11. Rating.cc
12. Rating.h
13. DynArray.cc
14. DynArray.h
15. BookList.cc
16. BookList.h
17. main.cc
18. RandomIdGenerator.cc
19. RandomIdGenerator.h


Launching Instructions:
1. Open the Command prompt and navigate to the directory where the files are stored
2. Compile the files using the Makefile by typing "make" in the Command prompt then press Enter
3. Run the executable created which is called "output" by typing "./output" and then press Enter

Note(s)/Assumption(s):
1. The RandomIdGenerator class was created to generate id's for club members and books.
2. While writing the del() function for the BookList class, I assumed that every book would have a distinct title.
3. The id's for the clubmembers/books start from 1001.
4. In the initRatings() function of the Control class, I made reference to the members and books initialized in the initMembers()
   and initBooks() functions.
5. I assumed that a clubmember can not revoke/delete a rating once already given; can only update it.
6. I assumed that clubmembers can not have multiple ratings of the same book.
