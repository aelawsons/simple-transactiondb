# simple-transactiondb
A simple map based in-memory transaction database utilizing C++ v20.

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