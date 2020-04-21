#pragma once
#include<iostream>
using namespace  std;

class Book {
	int id;
	char* title;
	char* author;
public:
	Book() { id = 0; title = NULL; author = NULL; };
	Book(int i, char t[], char a[]) {
		id = i;
		title = new char[strlen(t)];
		strcpy(title, t);
		author = new char[strlen(a)];
		strcpy(author, a);
	}
	Book(const Book& book) {
		id = book.id;
		title = new char[strlen(book.title)];
		strcpy(title, book.title);
		author = new char[strlen(book.author)];
		strcpy(author, book.author);
	}

	const Book& operator = (const Book& book) {
		id = book.id;
		title = new char[strlen(book.title)];
		strcpy(title, book.title);
		author = new char[strlen(book.author)];
		strcpy(author, book.author);
		return *this;
	}
	bool operator == (const Book& book) {
		return id == book.id
			&& strcmp(title, book.title) == 0
			&& strcmp(author, book.author) == 0;
	}
	void print() {
		cout << id << " | " << title
			<< " | " << author << endl;
	}
};



