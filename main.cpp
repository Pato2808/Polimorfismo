#include <iostream>
using namespace std;
#include "CtaBanc.h"
#include "Chequera.h"

int main(){
    //Se crea el array de apuntadores tipo Cuenta Bancaria y un contador
    CtaBanc* arrDatos[20];
    int numCuentas = 0;
    //Se crea un do while para correr el programa por un tiempo indefinido
    int opcion = 0;
    do{
        //Se declaran las opciones para el usuario
        cout << endl << "Seleccione una opcion:" << endl;
        cout << "1) Alta cuenta" << endl;
        cout << "2) Depositar en cuenta" << endl;
        cout << "3) Retirar de cuenta" << endl;
        cout << "4) Desplegar todas la cuentas" << endl;
        cout << "5) Salir" << endl;
        cin >> opcion;
        //Se declara un switch para que el usuario pueda seleccionar una opcion del menu
        switch(opcion){
            case 1:{ //Dar de alta una cuenta bancaria
                int op = 0;
                cout << endl << "Seleccione que tipo de cuenta quiere dar de alta: " << endl;
                cout << "1) Cuenta Bancaria" << endl;
                cout << "2) Chequera" << endl;
                cin >> op;

                if(op == 1){
                    int nc;
                    double sal;
                    bool repetido = false;
                    cout << "Introduzca el numero de cuenta: " << endl;
                    cin >> nc;
                    cout << "Introduzca el saldo:" << endl;
                    cin >> sal;

                    for(int i = 0; i < numCuentas; i++){
                        if(arrDatos[i]->getNumCuenta() == nc){
                            repetido = true;
                            break;
                        }
                    }
                    if(repetido){
                        cout << "El numero de cuenta ingresado ya esta siendo utilizado" << endl;
                        break;
                    } else{
                        arrDatos[numCuentas] = new CtaBanc(nc,sal);
                        numCuentas++;
                    }
                } else if(op == 2){
                    int nc;
                    double sal;
                    double cuo;
                    bool repetido = false;
                    cout << "Introduzca el numero de cuenta: " << endl;
                    cin >> nc;
                    cout << "Introduzca el saldo en la cuenta: " << endl;
                    cin >> sal;
                    cout << "Introduzca la cuota a cobrar: " << endl;
                    cin >> cuo;

                    for(int i = 0; i < numCuentas; i++){
                        if(arrDatos[i]->getNumCuenta() == nc){
                            repetido = true;
                            break;
                        }
                    }
                    if(repetido){
                        cout << "El numero de cuenta ingresado ya esta siendo utilizado" << endl;
                        break;
                    } else{
                        arrDatos[numCuentas] = new Chequera(nc,sal,cuo);
                        numCuentas++;
                    }  
                }
                break;
            }
            case 2:{ //Depositar dinero en una cuenta existente
                int nc;
                double cant;
                bool find = false;
                cout << endl << "Introduzca el numero de cuenta al que le desea depositar: " << endl;
                cin >> nc;
                cout << "Introduzca la cantidad a depositar: " << endl;
                cin >> cant;

                for(int i = 0; i < numCuentas; i++){
                    if(arrDatos[i]->getNumCuenta() == nc){
                        arrDatos[i]->deposita(cant);
                        find = true;
                        break;
                    }
                }
                if(!find){
                    cout << "No se encontro la cuenta referida" << endl;
                }
                break;
            }
            case 3:{ //Retirar dinero de una cuenta existente
                int nc;
                double cant;
                bool find = false;

                cout << endl  << "Introduzca el numero de cuenta a la que se le desea hacer el retiro: " << endl;
                cin >> nc;
                cout << "Introduzca la cantidad a retirar: " << endl;
                cin >> cant;

                for(int i = 0; i < numCuentas; i++){
                    if(arrDatos[i]->getNumCuenta() == nc){
                        arrDatos[i]->retira(cant);
                        find = true;
                        break;
                    }
                }
                if(!find){
                    cout << "No se encontro la cuenta referida" << endl << endl;
                }
                break;
            }
            case 4:{ //Desplegar todas las cuentas guardadas
                cout << endl;
                for(int i = 0; i < numCuentas; i++){
                    arrDatos[i]->mostrar();
                }
            }
        }
    } while(opcion != 5);
    cout << endl << "Este software fue creado por Patricio Mendoza Pasapera A00830337 :)" << endl;
    return 0;
}