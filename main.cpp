#include "InMemoryDB.h"
#include <iostream>

// Menu: to be called in the main.
static void menu()
{
	std::cout << "\nPick an option from the list:" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "1. Begin a transaction." << std::endl;
	std::cout << "2. Create new transaction key." << std::endl;
	std::cout << "3. Get value for transaction key." << std::endl;
	std::cout << "4. Commit transaction updates." << std::endl;
	std::cout << "5. Rollback transaction updates." << std::endl;
	std::cout << "6. Exit." << std::endl;
	std::cout << "-------------------------------" << std::endl;

}

int main()
{
	InMemoryDB inmemoryDB;
	bool isExit = false;

	std::cout << " Welcome to Simple Transaction" << std::endl;
	std::cout << "===============================" << std::endl;

	// While not exited out, run the menu for the transactions:
	while (!isExit)
	{
		// Run the menu:
		menu();
		
		std::string key = ""; // String key for transaction
		int val; // Value for transaction
		auto returnVal = inmemoryDB.get(key); // Used in get function
		std::string option = "";

		std::cin >> option;
		try {
			int test = stoi(option);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "\nInvalid option: Please type a number from 1-6" << std::endl;
			continue;
		}


		if (stoi(option) > 6 || stoi(option) < 1)
		{
			std::cout << "\nInvalid option: Please type a number from 1-6" << std::endl;
			option = "";
			continue;
		}
		else 
		{
			switch (stoi(option))
			{
			case 1:
				inmemoryDB.begin_transaction();
				break;
			case 2:
				std::cout << "\nInsert name for key: ";
				std::cin >> key;
				std::cout << "Insert transaction amount: ";
				std::cin >> val;
				inmemoryDB.put(key, val);
				break;
			case 3:
				std::cout << "\nInsert key to search: ";
				std::cin >> key;

				returnVal = inmemoryDB.get(key);
				if (!returnVal.has_value())
					std::cout << "\nERROR: No key exists, value = NULL" << std::endl;
				else
					std::cout << "Transaction value = " << returnVal.value() << std::endl;
				break;
			case 4:
				inmemoryDB.commit();
				break;
			case 5:
				inmemoryDB.rollback();
				break;
			case 6:
				isExit = true;
				std::cout << "\nGoodbye!" << std::endl;
				break;
			}
		}
	}

// ====================================================================== TESTING
	// // should return null, because A doesn’t exist in the DB yet
	// auto returnVal = inmemoryDB.get("A");
	// if (!returnVal.has_value())
	// 	std::cout << "Get A: NULL" << std::endl;
	// else
	// 	std::cout << "Get A: " << returnVal.value() << std::endl;

	// // should throw an error because a transaction is not in progress
	// inmemoryDB.put("A", 5);

	// // starts a new transaction
	// inmemoryDB.begin_transaction();

	// // set’s value of A to 5, but its not committed yet
	// inmemoryDB.put("A", 5);

	// if (!returnVal.has_value())
	// 	std::cout << "Get A: NULL" << std::endl;
	// else
	// 	std::cout << "Get A: " << returnVal.value() << std::endl;

	// // try to start a new transaction (throw an error)
	// inmemoryDB.begin_transaction();

	// // update A’s value to 6 within the transaction
	// inmemoryDB.put("A", 6);


	// // commits the open transaction
	// inmemoryDB.commit();

	// returnVal = inmemoryDB.get("A");
	// // should return 6, that was the last value of A to be committed
	// if (!returnVal.has_value())
	// 	std::cout << "Get A: NULL" << std::endl;
	// else
	// 	std::cout << "Get A: " << returnVal.value() << std::endl;

	// // throws an error, because there is no open transaction
	// inmemoryDB.commit();

	// // throws an error because there is no ongoing transaction
	// inmemoryDB.rollback();

	// returnVal = inmemoryDB.get("B");
	// // should return null because B does not exist in the database
	// if (!returnVal.has_value())
	// 	std::cout << "Get B: NULL" << std::endl;
	// else
	// 	std::cout << "Get B: " << returnVal.value() << std::endl;

	// // starts a new transaction
	// inmemoryDB.begin_transaction();

	// // Set key B’s value to 10 within the transaction
	// inmemoryDB.put("B", 10);

	// // Rollback the transaction - revert any changes made to B
	// inmemoryDB.rollback();

	// returnVal = inmemoryDB.get("B");
	// // Should return null because changes to B were rolled back
	// if (!returnVal.has_value())
	// 	std::cout << "Get B: NULL" << std::endl;
	// else
	// 	std::cout << "Get B: " << returnVal.value() << std::endl;
// ====================================================================== TESTING

	return 0;
}
