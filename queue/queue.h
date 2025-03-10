#pragma once

// ������ ������ ���� -- ��������� ����� �������
template <typename T>
struct node {
	T info; // ���������� ����, ������������� ����
	node* next; // ��������� �� ��������� ����

	// �����������
	node(T x) {
		info = x;
		next = nullptr;
	}
};

// �������
template<typename T>
class queue {
	queue() { // �����������
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	~queue() { // ����������
		node* tmp = nullptr;
		while (head != nullptr) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
		tail = nullptr;
	}

	void push(T x) {
		// ���������� ��������
		node* tmp = new node(x);
		if (head == nullptr) { // ������, ���� ������� ���� ������
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		count++; // ������� ���������� ��������� � �������
	}

	T pop() {
		// �������� ��������
		// !!! ����� �������������� ��������� ��� ������� �������� !!!
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
	node* head; // ��������� �� ��������� �������
	node* tail; // ��������� �� �������� �������
	int count; // ������� ���������� ��������� � �������
};

