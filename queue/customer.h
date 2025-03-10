#pragma once

#include <string>
#include "queue.h"

// шаблон класса, описывающий корзинку с продуктами
template<typename T>
struct cart {
	queue<T> products; // очередь с продуктами

	cart() { // конструктор
		products = new queue;
	}
	cart(const cart& another_cart) { // конструктор копирования
		products = another_cart.products;
	}
	~cart() { // деструктор
		delete queue;
	}
};

// шаблон класса описывающий покупателя
template <typename T>
class customer {
private:
	std::string name; // имя
	cart<T> _cart; // его корзинка с продуктами

public:
	customer(std::string _name) {
		name = _name;
		_cart = new cart;
	}
	customer(std::string _name, const cart& some_cart) {
		name = _name;
		_cart = new cart(some_cart);
	}
	~customer() {
		delete _cart;
	}

	addtocart(T x) {
		_cart.products.push(x)
	}

};
