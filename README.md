# simple-transactiondb
A simple console based in-memory transaction database utilizing C++ v20.

## Set-up/Testing
- Make sure you're running on C++ version 20
- Clone the repository from GitHub
- Run the main.cpp file to begin the transaction menu.
- Input menu options to use the transaction database.

## InMemoryDB Functions
- **Begin Transaction:** If there is not currently a transaction, this will clear previous transactions and create a new one. (Option 1 on Menu)
- **Put:** Pushes a user's input key and value for the transaction, this is not yet committed to the actual database until 'Commit' is called. (Option 2 on Menu)
- **Get:** Searches for a user's input key value in the database, returns NULL if there is no such value. (Option 3 on Menu)
- **Commit:** Commits the current transaction's changes to the database and clears the transaction. (Option 4 on Menu)
- **Rollback:** Resets the current transaction without committing changes to the database. (Option 5 on Menu)

## Possible Assignment Improvements
In the future, this assignment could include more functions, such as a transaction trade, where a user has to input 2 keys, and key 1's value will be subtracted from itself and moved to key 2; this would be an example of a bank transfer. 

Another possible functio to be added could be withdrawal and deposit, as it currently is, this implementable with a few more steps as all it would require is a user specifying withdrawal/deposit amount and then using the get function to see current key, value and the put function to update that key. 

One more possible addition to this assigment could be a more in depth concept for the actual menu/testing process, I implemented a menu to use for the database since I felt just using testing was too basic (though I included it as well but commented it out), the menu would let the student have an easier view of how a UI might look (albeit in console form) for an actual transaction database. 

Overall although this function was fairly easy, I think the open-endedness of the actual implementation already makes it a fairly good assignment to be used for the class, with the possible addition of a few features (such as the ones before).
