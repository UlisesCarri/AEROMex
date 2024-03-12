/*
 * AutoMain.h
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
#include "list.h"

using namespace std;


int main(){
    Vuelo         MX;                                       //Declaracion de variables.
    Sorts<Vuelo>  sorts;
    string        line, res;
    int           ord,rin;
    char          end = ','; 
    List<Vuelo>   MEX;                                      
    vector<Vuelo> MEX1,MEX2;                                
    List<int>     Aeo, Hor;

    ifstream file("AeroMex.csv"); //Seleccion de la ubicacion de AeroMEX.csv

    while(getline(file, line)){                            //Lectura de AeroMEX.csv
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

        MEX.insertion(Vue);                                //Guardamos la infromacion de los vuelos como objetos en un linked list.
    }

    MX.imprime_avion();

    MX.imprime_menu();
    cout << "1" << endl;
    rin = 1;
    if (rin == 1){
        cout << "_______________________________________ \n";
        cout << "A donde quieres ir?: ";
        cout << "OAXACA" << endl;
        res = "OAXACA";
        MEX1 =  MEX.search(res);                          //Utilizamos la funcion search de "list.h" para que nos regrese los valores del linked list en un vector.

        if (sorts.cont(MEX1) != 0){                      // Si el vector tiene contenido nos permite ordenar la informacion.
            MX.imprime_orden();
            cout << "1" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,1);          //Para ordenar los valores usamos un Bubble Sort que dependiendo de lo que pida el usuario es lo que busca.
            MX.imprime_info(MEX2);

            MX.imprime_orden();
            cout << "2" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,2);
            MX.imprime_info(MEX2);
        }

        else{
            cout<<"error"<<endl;
        }
    }
    MX.imprime_menu();
    cout << "1" << endl;
    rin = 1;
    if (rin == 1){
        cout << "_______________________________________ \n";
        cout << "A donde quieres ir?: ";
        cout << "QUERETARO" << endl;
        res = "QUERETARO";
        MEX1 =  MEX.search(res);

        if (sorts.cont(MEX1) != 0){
            MX.imprime_orden();
            cout << "1" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,1);
            MX.imprime_info(MEX2);

            MX.imprime_orden();
            cout << "2" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,2);
            MX.imprime_info(MEX2);
        }
    }
    MX.imprime_menu();
    cout << "2" << endl;
    rin = 2;
    if (rin == 2) {                                                                  // funcion para agregar nuevo vuelo
        Vuelo Temp;
        ofstream arch("AeroMEX.csv",ios::app);

        string Des, Aero, Mat, Hor, Estado, Pue, Ter;
        cout << "_______________________________________ "<<endl;                    //realizamos preguntas para saber los datos del vuelo
        cout<<"Favor de responder las siguientes preguntas en el formato indicado en los parentesis para agregar el vuelo a la base de datos:"<<endl;
        cout<<"A donde va el vuelo? (Nombre de destino en MAYUSCULA)"<<endl;
        Des="QUERETARO";
        cout<<Des<<endl;
        cout<<"Cual es la Aerolinea que lleva a cabo el vuelo? (Nombre de la aerolinea en MAYUSCULA)"<<endl;
        Aero="AEROMEXICO";
        cout<<Aero<<endl;
        cout<<"Cual es la matricula de identificacion del vuelo? (Matricula de identificacion del vuelo en MAYUSCULA)"<<endl;
        Mat="AM 2531";
        cout<<Mat<<endl;
        cout<<"A que hora despega el vuelo? (hh:mm)"<<endl;
        Hor="12:55";
        cout<<Hor<<endl;
        cout<<"Cual es el estado del vuelo? (TIEMPO/RETRASADO)"<<endl;
        Estado="RETRASADO";
        cout<<Estado<<endl;
        cout<<"Cual es la puerta de embarque? (Letra de puerta de embarque en MAYUSCULA)"<<endl;
        Pue="A";
        cout<<Pue<<endl;
        cout<<"Cual es la terminal de embarque? (Numero de Terminal)"<<endl;
        Ter="1";
        cout<<Ter<<endl;

        arch<<Des<<','<<Aero<<','<<Mat<<','<<Hor<<','<<Estado<<','<<Pue<<endl; //agregamos el vuelo al archivo.
        arch.close();
        cout << "\n\n_______________________________________ \n";
        cout<<"Se a agregado el vuelo con exito"<<endl;

        Vuelo Vue (Des,Aero,Mat,Hor,Pue,Ter,Estado);                                 
        MEX.insertion(Vue);                                                    //agregamos el valor a la linked list.
        
    }
    MX.imprime_menu();                                   
    cout << "1" << endl;
    rin = 1;
    if (rin == 1){                                       // Realizamos la busqueda del destino para confirmar la existencia del nuevo valor.                            
        cout << "_______________________________________ \n";
        cout << "A donde quieres ir?: ";
        cout << "QUERETARO" << endl;
        res = "QUERETARO";
        MEX1 =  MEX.search(res);

        if (sorts.cont(MEX1) != 0){
            MX.imprime_orden();
            cout << "1" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,1);
            MX.imprime_info(MEX2);

            MX.imprime_orden();
            cout << "2" << endl;
            MEX2 = sorts.ordenaBurbuja(MEX1,2);
            MX.imprime_info(MEX2);
        }
    }
    MX.imprime_menu();
    cout << "3" << endl;
    file.close();
}

/*
Este programa es uno relativamente sencillo, únicamente lee un archivo csv. los datos recopilados los convierte en objetos
"Vuelos" y los agrega a una linked list, después despliega una interfaz con 2 opciones, una busca los vuelos en la
linked list, primero los busca por destino y luego los ordena por hora o por aerolínea.
la otra opción es agregar otro vuelo, este despliega una serie de preguntas para conseguir los datos del vuelo, 
rescribe el .csv con los vuelode de la linked list, agrega los datos del nuevo vuelo al archivo .csv y crea un objeto 
que agrega a la linked list, de esta manera mantenemos tanto el archivo actualizado con el nuevo vuelo y la lista para 
futuras busqueda y nos evitamos otra lectura de todo el .csv.
*/