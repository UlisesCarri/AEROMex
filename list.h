#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include <vector>
#include "Vuelos.h"

template <class T> class List;
template <class T> class ListIterator;

using namespace std;

template <class T>
class Link {
private:
	Link(T val) : value(val), next(nullptr) {};

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
class List {
public:
	List();

	void     insertion(T);
	vector<T> search(string);
	vector<T> valorT();
	string   toString() const;
	int getsize();
	T valor(int);

private:
	Link<T>  *head;
	int 	 size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
void List<T>::insertion(T valor) {
	Link<T>* newVal = new Link<T>(valor);

    if (head == nullptr) {
        head = newVal;
    }

	else {
        Link<T>* curr = head;
        while (curr -> next != nullptr) {
            curr = curr -> next;
        }
        curr -> next = newVal;
    }
	size= size + 1;
}

template <class T>
vector<T> List<T>::search(string valor) {
	Link<T> *curr = head;
	int index = 0;
	string Lec;
	T Lec1;
    vector<T> R1;


	while (curr) {
		Lec1= curr -> value;
		Lec= Lec1.get_Destino();
		if (Lec == valor) {
			R1.push_back(Lec1);
		}

		curr = curr -> next;
		index++;
	}
	return R1;
}

template <class T>
vector<T> List<T>::valorT() {
	Link<T> *curr = head;
	int index = 0;
	T Lec1;
    vector<T> R1;

	while (curr) {
		if (index==size){
			break;
		}
		Lec1= curr -> value;
		R1.push_back(Lec1);

		curr = curr -> next;
		index++;
	}
	return R1;
}

template <class T>
T List<T>::valor(int av) {
	Link<T> *curr = head;
	int index=0;
	T Lec1;

	while (curr) {
		if (index==av){
		Lec1= curr -> value;
		return Lec1;
		}
		curr = curr -> next;
		index++;
	}
}

template <class T>
int List<T>::getsize(){
	return size;
}

#endif