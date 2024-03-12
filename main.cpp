/*
 * main.h
 *
 *  Created on: 07/09/2022
 *      Author: Ulises Orlando Carrizalez Lerín
 */

#include "Vuelos.h"
#include "Sort&Serch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream> 
#include <fstream>

using namespace std;

int main(){
    Vuelo         MX;
    Sorts<Vuelo>  sorts;
    string        line, res;
    int           ord,rin;
    char          end = ','; 
    List<Vuelo>   MEX;
    vector<Vuelo> MEX1,MEX2;
    vector<int>   Aeo, Hor;

    ifstream file("AeroMEX.csv");

    while(getline(file, line)){
        stringstream stream(line);  
        string Des, Aero, Mat, Hor, Estado, Pue, Ter;

        getline(stream, Des, end);
        getline(stream, Aero, end);
        getline(stream, Mat, end);
        getline(stream, Hor, end);
        getline(stream, Estado, end);
        getline(stream, Pue, end);
        getline(stream, Ter, end);
        Vuelo Vue (Des,Aero,Mat,Hor,Pue,Ter,Estado);

        MEX.insertion(Vue); 
    }
    file.close();

    MX.imprime_avion();

    while (true){
        MX.imprime_menu();
        cin >> rin;
        cin.ignore();
        if (rin == 1){
            cout << "_______________________________________ \n";
            cout << "A donde quieres ir?: ";
            cin  >> res;
            MEX1 =  MEX.search(res);

            if (sorts.cont(MEX1) != 0){
                while (true){
                    MX.imprime_orden();
                    cin  >> ord;

                    if (ord == 1){
                        MEX2 = sorts.ordenaBurbuja(MEX1,1);
                        MX.imprime_info(MEX2);
                        break;
                    }

                    if (ord == 2){
                        MEX2 = sorts.ordenaBurbuja(MEX1,2);
                        MX.imprime_info(MEX2);
                        break;
                    }

                    else {MX.imprime_error(1);}
                }
            }
            else {MX.imprime_error(2);}
        }

        else if (rin == 2) {
        Vuelo Temp;
        vector<Vuelo> MEX3;
        ofstream arch("AeroMEX.csv",ios::app);
        MEX3= MEX.valorT();
        
        string Des, Aero, Mat, Hor, Estado, Pue, Ter;
        cout << "_______________________________________ "<<endl;
        cout<<"Favor de responder las siguientes preguntas en el formato indicado en los parentesis para agregar el vuelo a la base de datos:"<<endl;
        
        cout<<"A donde va el vuelo? (Nombre de destino)"<<endl;
        getline(cin,Des);
        cout<<"Cual es la Aerolinea que lleva a cabo el vuelo? (Nombre de la aerolinea en MAYUSCULA)"<<endl;
        getline(cin,Aero);
        cout<<"Cual es la matricula de identificacion del vuelo? (Matricula de identificacion del vuelo en MAYUSCULA)"<<endl;
        getline(cin,Mat);
        cout<<"A que hora despega el vuelo? (hh:mm)"<<endl;
        getline(cin,Hor);
        cout<<"Cual es el estado del vuelo? (TIEMPO/RETRASADO en MAYUSCULA)"<<endl;
        getline(cin,Estado);
        cout<<"Cual es la puerta de embarque? (Letra de puerta de embarque en MAYUSCULA)"<<endl;
        getline(cin,Pue);
        cout<<"Cual es la terminal de embarque? (Numero de Terminal)"<<endl;
        getline(cin,Ter);
        arch<<Des<<','<<Aero<<','<<Mat<<','<<Hor<<','<<Estado<<','<<Pue<<endl;
        arch.close();

        cout << "\n_______________________________________ \n";
        cout<<"Se a agregado el vuelo con exito"<<endl;

        Vuelo Vue (Des,Aero,Mat,Hor,Pue,Ter,Estado);
        MEX.insertion(Vue);
        }

        else if (rin == 3) {break;}

        else {MX.imprime_error(3);}
    }
}