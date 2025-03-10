#pragma once

#include <string>
#include "queue.h"

// ������ ������, ����������� �������� � ����������
template<typename T>
struct cart {
	queue<T> products; // ������� � ����������

	cart() { // �����������
		products = new queue;
	}
	cart(const cart& another_cart) { // ����������� �����������
		products = another_cart.products;
	}
	~cart() { // ����������
		delete queue;
	}
};

// ������ ������ ����������� ����������
template <typename T>
class customer {
private:
	std::string name; // ���
	cart<T> _cart; // ��� �������� � ����������

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
