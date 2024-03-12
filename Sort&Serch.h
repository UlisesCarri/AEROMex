/*
 * Sort&Serch.h
 *
 *  Created on: 18/09/2022
 *      Author: Ulises Orlando Carrizalez Lerín
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>
#include "Vuelos.h"
#include "list.h"

using namespace std;

template <class T>
class Sorts {
private:
	vector<T> swap(vector<T>, int, int);
public:
	vector<T> ordenaBurbuja(vector<T>, int);
	int cont(vector<T> Des) {return Des.size();};
};

template <class T>
vector<T> Sorts<T> :: swap(vector<T> v, int i, int j) {
	T aux = v[i];
	v[i]  = v[j];
	v[j]  = aux;
	return v;
}

template <class T>
vector<T> Sorts<T> :: ordenaBurbuja(vector<T> v, int n) {
	Vuelo MX;
	for (int i = v.size()-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j].get_HoraN() > v[j + 1].get_HoraN() && n == 1) {
				v= swap(v, j, j + 1);
			}
			else if (v[j].get_AerolineaN() > v[j + 1].get_AerolineaN() && n == 2) {
				v= swap(v, j, j + 1);
			}
		}
	}
	return v;
}

#endif 