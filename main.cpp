#include "InMemoryDB.h"
#include <iostream>


int main() 
{
	InMemoryDB inmemoryDB;
	
	// should return null, because A doesn’t exist in the DB yet
	auto returnVal = inmemoryDB.get("A");
	if (!returnVal.has_value())
		std::cout << "Get A: NULL" << std::endl;
	else
		std::cout << "Get A: " << returnVal.value() << std::endl;

	// should throw an error because a transaction is not in progress
	inmemoryDB.put("A", 5);

	// starts a new transaction
	inmemoryDB.begin_transaction();

	// set’s value of A to 5, but its not committed yet
	inmemoryDB.put("A", 5);

	if (!returnVal.has_value())
		std::cout << "Get A: NULL" << std::endl;
	else
		std::cout << "Get A: " << returnVal.value() << std::endl;

	// try to start a new transaction (throw an error)
	inmemoryDB.begin_transaction();

	// update A’s value to 6 within the transaction
	inmemoryDB.put("A", 6);


	// commits the open transaction
	inmemoryDB.commit();

	returnVal = inmemoryDB.get("A");
	// should return 6, that was the last value of A to be committed
	if (!returnVal.has_value())
		std::cout << "Get A: NULL" << std::endl;
	else
		std::cout << "Get A: " << returnVal.value() << std::endl;

	// throws an error, because there is no open transaction
	inmemoryDB.commit();

	// throws an error because there is no ongoing transaction
	inmemoryDB.rollback();

	returnVal = inmemoryDB.get("B");
	// should return null because B does not exist in the database
	if (!returnVal.has_value())
		std::cout << "Get B: NULL" << std::endl;
	else
		std::cout << "Get B: " << returnVal.value() << std::endl;

	// starts a new transaction
	inmemoryDB.begin_transaction();

	// Set key B’s value to 10 within the transaction
	inmemoryDB.put("B", 10);

	// Rollback the transaction - revert any changes made to B
	inmemoryDB.rollback();

	returnVal = inmemoryDB.get("B");
	// Should return null because changes to B were rolled back
	if (!returnVal.has_value())
		std::cout << "Get B: NULL" << std::endl;
	else
		std::cout << "Get B: " << returnVal.value() << std::endl;

    return 0;
}
