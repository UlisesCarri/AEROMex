/*
 * Vuelos.h
 *
 *  Created on: 18/09/2022
 *      Author: Ulises Orlando Carrizalez Lerín
 */

#ifndef Vuelos_h
#define Vuelos_h

#include <iostream> 
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <stdio.h>
#include "list.h"

using namespace std;

class Vuelo {
private:
    string Destino;
    vector<int> DestinoN;
    string Aerolinea;
    int AerolineaN;
    string Matricula;
    string Hora;
    int HoraN;
    string Puerta;
    string Terminal;
    string Estado;

public:
	Vuelo ();                                               //Metodos Constructores
    Vuelo (string Des, string Aero, string Mat, string Hor, string Pue, string Ter, string Es);

    std::vector<int> ASCII (string letter);            //Metodos de calculo o traduccion
    int Primer(vector<int> v);
    int SHoraN(string letter);

    std::vector<string> NDestinoN (vector<Vuelo> arr); //Metodos de revision
    std::vector<int> NAeroLineaN (vector<Vuelo> arr);
    std::vector<int> NHoraN (vector<Vuelo> arr);

    void imprime_info();                                    //Metodos de impresion
    void imprime_info(vector<Vuelo> arr);
    void imprime_avion();
    void imprime_menu();
    void imprime_orden();
    void imprime_error(int);

    string get_Destino(){return Destino;}                  //Metodos Geter
    string get_Aerolinea(){return Aerolinea;};
    string get_Matricula(){return Matricula;};
    string get_Hora(){return Hora;};
    string get_Puerta(){return Puerta;};
    string get_Terminal(){return Terminal;};
    string get_Estado(){return Estado;};
    int get_AerolineaN(){return AerolineaN;}
    int get_HoraN(){return HoraN;}

    void set_AerolineaN(string Aero){AerolineaN= Primer(ASCII(Aero));}; //Metodos Seter
    void set_DestinoN(string Des){DestinoN= ASCII(Des);};
    void set_HoraN(string Hor){HoraN= SHoraN(Hor);};

};

Vuelo::Vuelo (){
    Destino=" ";
    DestinoN= {0};
    Aerolinea=" ";
    AerolineaN=0;
    Matricula=" ";
    Hora=" ";
    HoraN=0;
    Puerta=" ";
    Terminal=" ";   
}

Vuelo::Vuelo (string Des, string Aero, string Mat, string Hor, string Pue, string Ter, string Es){
    Destino    = Des;
    DestinoN   = ASCII(Des);
    Aerolinea  = Aero;
    AerolineaN = Primer(ASCII(Mat));
    Matricula  = Mat;
    Hora       = Hor;
    HoraN      = SHoraN(Hor);
    Puerta     = Pue;
    Terminal   = Ter;
    Estado     = Es;
}

std::vector<int> Vuelo :: ASCII(string letter){
    int L= letter.length();
    std::vector<int> vec;
    for (int i = 0; i < L; i++){
        int x = letter.at(i);
        vec.push_back(x);
    }
    return vec;
}

int Vuelo :: Primer(vector<int> v){
    int res = v[0];
    return res;
}

int Vuelo:: SHoraN(string letter){
    int Total = 1000;
    int sum,r,L;
    sum= 0;
    string nombre;
    L= letter.length();
    char* LET = new char[L + 1];
    strcpy(LET, letter.c_str());
    for (int i = 0; i < L; i++){
        nombre = LET [i];
        if (nombre != ":"){
            istringstream(nombre) >> r;
            sum = sum + (Total * r);
            Total = Total /10;
        }
    }
    return sum;
}

std::vector<string> Vuelo::NDestinoN(vector<Vuelo> arr) {
    std::vector<string> vec;
    for (int i = 0; i < arr.size(); i++) {
        vec.push_back(arr[i].get_Destino());
    }
    return vec;
}

std::vector<int> Vuelo::NAeroLineaN(vector<Vuelo> arr) {
    std::vector<int> vec;
    for (int i = 0; i < arr.size(); i++) {
        vec.push_back(arr[i].get_AerolineaN());
    }
    return vec;
}

std::vector<int> Vuelo::NHoraN(vector<Vuelo> arr) {
    std::vector<int> vec;
    for (int i = 0; i < arr.size(); i++) {
        vec.push_back(arr[i].get_HoraN());
    }
    return vec;
}

void Vuelo::imprime_info(vector<Vuelo> arr){
    for (int i = 0; i < arr.size(); i++) {
        arr[i].imprime_info();
    }
}

void Vuelo::imprime_info(){
	cout << "_______________________________________ \n" ;
    cout << "Destino: "<< Destino << endl;
	cout << "Aerolinea: "<< Aerolinea << endl;
	cout << "ID: "<< Matricula << endl;
	cout << "Hora de Salida: "<< Hora << " PM" << endl;
    cout << "Puerta: " << Puerta << endl;
    cout << "Terminal: "<< Terminal << endl;
    cout << "_______________________________________ \n\n" ;
}

void Vuelo::imprime_avion(){
cout << "                                    |"                               << endl;
cout << "                                    |"                               << endl;
cout << "                                  .-'-."                             << endl;
cout << "                                 ' ___ '"                            << endl;
cout << "                       ---------'  .-.  '---------"                  << endl;
cout << "       _________________________'  '-'  '_________________________"  << endl;
cout << "        ''''''-|---|--/      =][^',_m_,'^][==/      -|---|-''''''"   << endl;
cout << "                           /  ||/   H     |       /"                 << endl;
cout << "                       '--'   OO   O|O   OO   '--'"                  << endl;
cout << "Bienvenido al sistema de busqueda de vuelos del Aeropuerto Internacional Benito Juarez Ciudad de Mexico:" << endl;
}

void Vuelo::imprime_menu(){
    cout << "_______________________________________ \n";
    cout << "Que quieres hacer?: "<<endl;
    cout << "1. Consultar Vuelo de Salida"<<endl;
    cout << "2. Agregar Vuelo de Salida"<<endl;
    cout << "3. Salir"<<endl;
}

void Vuelo::imprime_orden(){
    cout << "_______________________________________ \n";
    cout << "Como lo quieres ordenado?" << endl;
    cout << "1. Hora" << endl;
    cout << "2. Aerolinea" << endl;
}

void Vuelo::imprime_error(int x){
    if (x == 1){cout << "ERROR RESPUESTA NO DISPONIBLE" << endl;}
    if (x == 2) {cout << "ERROR NO EXISTE NINGUN VUELO A ESE DESTINO" << endl;}
    if (x == 3) {cout << "ERROR RESPUESTA NO DISPONIBLE." << endl;}
}

#endif