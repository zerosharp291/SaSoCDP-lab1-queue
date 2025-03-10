#pragma once

// шаблон класса узла -- составной части очереди
template <typename T>
struct node {
	T info; // содержимое узла, произвольного типа
	node* next; // указатель на следующий узел

	// конструктор
	node(T x) {
		info = x;
		next = nullptr;
	}
};

// очередь
template<typename T>
class queue {
	queue() { // конструктор
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~queue() { // деструктор
		node* tmp = nullptr;
		while (head != nullptr) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
		tail = nullptr;
	}

	void push(T x) {
		// добавление элемента
		node* tmp = new node(x);
		if (head == nullptr) { // случай, если очередь была пустой
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		count++; // подсчет количества элементов в очереди
	}

	T pop() {
		// удаление элемента
		// !!! Перед использованием убедиться что очередь непустая !!!
		node* tmp = head;
		head = head->next;
		if (head == nullptr) {
			tail == nullptr;
		}
		T value = tmp->info();
		delete tmp;
		return value;
	}

private:
	node* head; // указатель на начальный элемент
	node* tail; // указатель на конечный элемент
	int count; // счетчик количества элементов в очереди
};

