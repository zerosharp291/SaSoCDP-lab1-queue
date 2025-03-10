#include "queue.h"
#include "customer.h"
#include "cash_register.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

void test() {

	cash_register<std::string> c1("Касса 1");
	cash_register<std::string> c2("Касса 2");

	std::vector<customer<std::string>> all_customers;

	std::ifstream fin_customers("customers_list.txt", std::ios::in);
	
	if (fin_customers.is_open()) {
		std::string line;
		while (std::getline(fin_customers, line)) {
			std::istringstream iss(line);
			
			std::string elem;

			iss >> elem;

			all_customers.push_back(customer<std::string>(elem));
		}
	}
}
