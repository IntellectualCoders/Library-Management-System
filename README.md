# Library-Management-System
This software project is a library management software system with all the basic as well as some innovative features for managing a library. It consists of a large database of various books available in the library. It also lists various books issued to respective readers. The system keeps track of all the books readily available and also the books that have been issued to various readers for the time period for which the books have been issued. The system also handles the books database. Readers usually tend to forget the date to return their library books, so this system even calculates fine depending on the expiry date. Thus this innovative library management system provides enhanced library functionality for this modern world.

Features of the System:-
• ADMIN LOGIN:
The system will be under the sole control of the admin. Admin can add or remove books from the system and also maintains records of the book available and issued in the library. The admin can even update the books if required.
• USER SECTION: 
User can search and explore the books that he/she wants.
Advantages:-
• The system excludes the use of paperwork by managing all the book information electrically
• Admin can keep updating the system by providing the new books arrival in the system and their availability the students need not go to the library for issuing purpose.
• The system has books well organized and systematically arranged in different categories in the system so that user can easily search and in the book
FUNCTIONS USED IN THE PROJECT
•	void mainmenu(void);
•	void addbooks(void);
•	void deletebooks(void);
•	void editbooks(void);
•	void searchbooks(void);
•	void issuebooks(void);
•	void returnbooks(void);
•	void viewbooks(void);
•	void Password();
•	void issuerecord();
•	int rent(int Id);

 
IMPORTANT FUNCTIONS AND THEIR ALGORITHM

• ADD BOOKS: 
This function allows the admin to add books into file lib.dat by entering the details of the book.
ALGORITHM:
1. Start
2. Select category of the book(computer, electrical, electrical civil, mechanical)
3. Fetching details
4. Write to file(lib.dat)
5. Link to the main menu
6. End

• DELETE BOOKS:
This function accepts book id from the admin and deletes the required book from the file lib.dat.
ALGORITHM:
1. Start
2. Fetching book ID from admin
3. If book id exists in the file(lib.dat) goto 4, else got 7
4. Write all the book details into a new file(temp.dat) except particular book ID entered by Admin
5. Remove the File lib.dat
6. Rename File temp.dat as lib.dat
7. Ask to delete more if "Y" goto 1, else go to the main menu
8. End

• SEARCH BOOKS:
This Function helps the Admin Search for a given book in the file Lib.dat
ALGORITHM:
1. Start
2. Ask an admin to search the book by ID or name.
3. If book Id, then fetch book ID from the admin, else fetch book name
4. Search the file lib.dat till EOF
5. If the book ID/ name exists in file lib.dat, print the details of the book, 
else go to step 6
6. Do you want to search for more books. If "Y" goto 1, else go to the main menu
7. End

• ISSUE BOOKS:
This function allows the admin to issue books to the user 
ALGORITHM:
1. Start
2. Ask an admin to choose whether to
           -Issue a book
           -View issued book
           -Search issued book
3. If Issue book goto 4
      else if view issued book goto 9
      else call the search function
 4. Fetch all details from the file lib.dat and display all details
 5. Fetch the book ID to be issued
 6. Check whether the book exists or not in the file lib.dat
 7.  If exists, fetch details of the user else goto 10
 8.  Write the details of the user in the file(issue.dat) and goto 10
 9.  Display all details of the user from file issue.dat
10. Want to issue more, if "Y", goto 4
11. Else go to the main menu
12. End


• EDIT BOOKS:
 This function allows the admin to edit the details of a particular book Id.
ALGORITHM:
1. Start
2. Fetch the book ID which has to be edited
3. If book ID exists in the file (lib.dat) goto 4,  Else goto 9
4. Now fetch all the new details of the book from the admin
5. Write all the details in the file (temp.dat) with exchanging the particular ID details
6. Remove the file lib.dat
7. Rename the file temp.dat as lib.dat
8. Want to edit another book. If “Y” goto 1, Else go to the main menu
9. End

• RETURN BOOKS:
This function allows the admin to return the book issued by a user.
ALGORITHM:
1.	Start
2.	Fetch the book ID of the user from the admin
3.	If the book ID exists in the file(issue.dat) goto 4, else goto 10
4.	Fetch details of the user from the admin
5.	Call the rent function to get the rent of the user
6.	Re confirm admin to return a book or not, if “yes” goto 7, else goto 10
7.	Copy all the details of the file (test.dat) except the particular book id in the (test.dat) file
8.	Remove issue.dat
9.	Rename test.dat as isssue.dat
10.	Ask the admin to return any more books if yes goto 2, else goto main menu
11.	End

• RENT: 
This function calculates the rent/time of the book.
ALGORITHM:
1.	Start
2.	Open the file(issue.dat)
3.	Fetch the returning date of the book issue by the user from the admin
4.	Check if the book id exists or not. If exists goto 5
5.	Calculate the rent of the book
6.	Return rent
7.	Close the file(issue.dat)
8.	End

• VIEW BOOKS:
 This function displays the booklist along with book details
ALGORITHM:
1.	Start
2.	Open file (lib.dat) in reading in library mode only
3.	Read details from file(lib.dat) till EOF
4.	Display the details
5.	Display total books by adding the quantity of each entry in the file
6.	Close file
7.	End

•	MAIN:
 
ALGORITHM:
1.	Start
2.	Display ‘DATAMATE’
3.	Ask user if he/she wants to access: 
                                                         A. Librarian
                                                         B. User section
4.	If librarian goto 5, else goto 6
5.	Call password. function
6.	Ask user if he\she wants to
                                             A. search a record
                                             B. EXIT
7.	If search  a record goto 8, else 12
8.	Fetch the student id
9.	If student id exists, goto 10, else goto 11
10.	Fetch details from the file(issue.dat) and display them on the screen.
11.	Ask user if he\she wants to search again
If yes goto 8 else goto 12
12.	Ask user if he/she wants to exit or not if yes exit the application, else goto 3

