#pragma once

#include "queue.h"
#include "customer.h"
#include <string>

template <typename T>
struct cash_register {
	queue<customer<T> customer_queue;
	std::string name;

	cash_register(std::string _name){
		customer_queue = new queue<customer<T>>; 
		name = _name;
	}

	~cash_register() {
		delete customer_queue;
	}

	void add_customer(customer C) {
		customer_queue.push(C);
	}

	void release_customer(customer C) {
		customer_queue.pop();
	}
};
