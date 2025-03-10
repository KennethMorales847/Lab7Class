#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class CuentasBancarias {
private:
    int id;
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
public:

    CuentasBancarias(int _id,string _titular, double _saldo, bool _activa, int _intentosFallidos):
        id(_id), titular(_titular), saldo(_saldo), activa(_activa), intentosFallidos() { }

    void depositar(double monto) {
        //Condicion: No se pueden hacer depositos si la cuenta está bloqueada.

        if (activa != true) {
            cout << "La cuenta esta bloqueada. Contacta a un representante para desbloquearla." << endl;
        }
        else {
            cout << "Su saldo inicial es Q" << fixed << setprecision(2) << saldo << endl <<
                "La cantidad a depositar es: Q"  << monto << endl;
            saldo += monto;
            cout << "Su nuevo saldo es: Q"  << saldo << endl;
        }
        
    }

    void retirar (double monto) {
        

       //Condicion: No se pueden hacer retiros si la cuenta está bloqueada.
        if (activa != true) {
            cout << "La cuenta esta bloqueada. Contacta a un representante para desbloquearla." << endl;
        }
        //Condicion: No se puede retirar más dinero del saldo disponible
        //Condicion: No se pueden hacer transacciones con montos negativos o cero.
        else if (monto > saldo || monto<= 0) {
            intentosFallidos += 1;
            cout << "No puedes retirar esa cantidad, intenta de nuevo." << endl
                <<"Intentos fallidos: "<<intentosFallidos<<". Si llega a tres intentos fallidos, la cuenta sera bloqueada." << endl;
            //Condicion: Si hay 3 intentos fallidos de retiro, la cuenta se bloquea
            if (intentosFallidos >= 3) {
                activa = false;
            }
        }
        else {
            cout << "Su saldo inicial es Q" << fixed << setprecision(2) << saldo << endl <<
                "La cantidad a retirar es: Q" << monto << endl;
            saldo -= monto;
            cout << "Su nuevo saldo es: Q" << endl;
        }

        //Condicion: Si el saldo cae por debajo de 100, mostrar una advertencia.
        if (saldo < 100) {
            cout << "ADVERTENCIA: Su saldo es menor a Q100." << endl;
        }
        
    }

    void consultar() {
        cout << "Titular: " << titular << endl <<
            "Saldo actual Q" << saldo << endl;
    }

    void mostrarInfo() {
        
        if (activa == 1) {
            cout << "\033[92m";
            cout << "Nombre: " << titular << endl <<
                "Saldo: Q" << saldo << endl <<
                "Estado: "<<endl<<
                "Activa"<<endl;
            cout << "\033[0m";
        }
        else {
            cout << "\033[91m";
            cout << "Nombre: " << titular << endl <<
                "Saldo: Q" << saldo << endl <<
                "Estado: " << endl <<
                "Bloqueada" << endl;
            cout << "\033[0m";
        }
        cout << endl;
    }
};

int main()
{

    int opcion, ID;
    float depos, ret;


    CuentasBancarias c1(1, "Kenneth", 1200.23, true, 0);
    CuentasBancarias c2(2, "Allison", 700, false, 0);
    CuentasBancarias c3(3, "Fleur", 26900, true, 0); 
    CuentasBancarias c4(4, "Hemlock", 1500, true, 0);
    CuentasBancarias c5(5, "Sly", 300, true, 0);
    CuentasBancarias c6(6, "Aeon", 10500, true, 0);
    CuentasBancarias c7(7, "Marta", 5800, true, 0);
    CuentasBancarias c8(8, "Eduardo", 16000, true, 0);
    CuentasBancarias c9(9, "Lucía", 950, true, 0);
    CuentasBancarias c10(10, "Juan", 2000, true, 0);
    CuentasBancarias c11(11, "Laura", 2400, true, 0);
    CuentasBancarias c12(12, "Tomás", 12000, true, 0);
    CuentasBancarias c13(13, "Raquel", 3000, true, 0);
    CuentasBancarias c14(14, "Pedro", 11000, true, 0);
    CuentasBancarias c15(15, "Verónica", 1450, true, 0);
    CuentasBancarias c16(16, "Luis", 800, false, 0);
    CuentasBancarias c17(17, "Sofía", 500, true, 0);
    CuentasBancarias c18(18, "Fernando", 2200, true, 0);
    CuentasBancarias c19(19, "Victoria", 1800, true, 0);
    CuentasBancarias c20(20, "José", 1700, true, 0);
    CuentasBancarias c21(21, "Elena", 1350, true, 0);
    CuentasBancarias c22(22, "Antonio", 15500, true, 0);
    CuentasBancarias c23(23, "Isabel", 250, true, 0);
    CuentasBancarias c24(24, "José Luis", 12500, true, 0);
    CuentasBancarias c25(25, "María", 9000, true, 0);
    CuentasBancarias c26(26, "Rosa", 7400, true, 0);
    CuentasBancarias c27(27, "Ricardo", 4200, true, 0);
    CuentasBancarias c28(28, "Antonio", 3600, true, 0);
    CuentasBancarias c29(29, "Carmen", 1500, true, 0);
    CuentasBancarias c30(30, "Héctor", 1300, true, 0);

    do {
        cout << "\033[97m" << endl;
        cout << setfill('-') << setw(30) << "-"<<endl;


        cout << setfill(' ') << setw(17) << "MENU"  << " " << endl;

        cout << setfill('-') << setw(30) << "-" << endl;

        cout << setfill(' ')
            
            <<setw(4)<< " "<< "\033[95m 1. Depositar\033[0m" << endl;
        cout << setw(4) << " " << "\033[96m 2. Retirar\033[0m" << endl;
        cout << setw(4) << " " << "\033[94m 3. Consultar Saldo\033[0m" << endl;
        cout << setw(4) << " " << "\033[92m 4. Ver todas las cuentas\033[0m" << endl;
        cout << setw(4) << " " << "\033[93m 0. Salir\033[0m" << endl;

        cout << setfill('-') << setw(30) << "-" << endl;
        
        cin >> opcion;
        cout << "\033[0m";

        switch (opcion) {
        case 1:
            cout << "\033[95m" << endl;
            ID = 0;
            cout << "Escribe el ID de la cuenta a depositar: "; cin >> ID;
            cout << "Escribe la cantidad a depositar: "; cin >> depos;
            switch (ID)
            {
            case 1: c1.depositar(depos); break;
            case 2: c2.depositar(depos); break;
            case 3: c3.depositar(depos); break;
            case 4: c4.depositar(depos); break;
            case 5: c5.depositar(depos); break;
            case 6: c6.depositar(depos); break;
            case 7: c7.depositar(depos); break;
            case 8: c8.depositar(depos); break;
            case 9: c9.depositar(depos); break;
            case 10: c10.depositar(depos); break;
            case 11: c11.depositar(depos); break;
            case 12: c12.depositar(depos); break;
            case 13: c13.depositar(depos); break;
            case 14: c14.depositar(depos); break;
            case 15: c15.depositar(depos); break;
            case 16: c16.depositar(depos); break;
            case 17: c17.depositar(depos); break;
            case 18: c18.depositar(depos); break;
            case 19: c19.depositar(depos); break;
            case 20: c20.depositar(depos); break;
            case 21: c21.depositar(depos); break;
            case 22: c22.depositar(depos); break;
            case 23: c23.depositar(depos); break;
            case 24: c24.depositar(depos); break;
            case 25: c25.depositar(depos); break;
            case 26: c26.depositar(depos); break;
            case 27: c27.depositar(depos); break;
            case 28: c28.depositar(depos); break;
            case 29: c29.depositar(depos); break;
            case 30: c30.depositar(depos); break;
            default:
                cout << "Ingresa un ID de cuenta valido" << endl;
                cout << "\033[0m";
                break;
            }

            break;
        case 2:
            cout << "\033[96m" << endl;
            ID = 0;
            cout << "Escribe el ID de la cuenta a retirar: "; cin >> ID;
            cout << "Escribe la cantidad a retirar: "; cin >> ret;
            switch (ID)
            {
            case 1: c1.retirar(ret); break;
            case 2: c2.retirar(ret); break;
            case 3: c3.retirar(ret); break;
            case 4: c4.retirar(ret); break;
            case 5: c5.retirar(ret); break;
            case 6: c6.retirar(ret); break;
            case 7: c7.retirar(ret); break;
            case 8: c8.retirar(ret); break;
            case 9: c9.retirar(ret); break;
            case 10: c10.retirar(ret); break;
            case 11: c11.retirar(ret); break;
            case 12: c12.retirar(ret); break;
            case 13: c13.retirar(ret); break;
            case 14: c14.retirar(ret); break;
            case 15: c15.retirar(ret); break;
            case 16: c16.retirar(ret); break;
            case 17: c17.retirar(ret); break;
            case 18: c18.retirar(ret); break;
            case 19: c19.retirar(ret); break;
            case 20: c20.retirar(ret); break;
            case 21: c21.retirar(ret); break;
            case 22: c22.retirar(ret); break;
            case 23: c23.retirar(ret); break;
            case 24: c24.retirar(ret); break;
            case 25: c25.retirar(ret); break;
            case 26: c26.retirar(ret); break;
            case 27: c27.retirar(ret); break;
            case 28: c28.retirar(ret); break;
            case 29: c29.retirar(ret); break;
            case 30: c30.retirar(ret); break;
            default:
                cout << "Ingresa un ID de cuenta valido" << endl;
                break;
            }
            cout << "\033[0m";
            break;

        case 3: 
            cout << "\033[94m" << endl;
            ID = 0;
            cout << "Escribe el ID de la cuenta a consultar: "; cin >> ID;
            switch (ID) {
            case 1: c1.consultar(); break;
            case 2: c2.consultar(); break;
            case 3: c3.consultar(); break;
            case 4: c4.consultar(); break;
            case 5: c5.consultar(); break;
            case 6: c6.consultar(); break;
            case 7: c7.consultar(); break;
            case 8: c8.consultar(); break;
            case 9: c9.consultar(); break;
            case 10: c10.consultar(); break;
            case 11: c11.consultar(); break;
            case 12: c12.consultar(); break;
            case 13: c13.consultar(); break;
            case 14: c14.consultar(); break;
            case 15: c15.consultar(); break;
            case 16: c16.consultar(); break;
            case 17: c17.consultar(); break;
            case 18: c18.consultar(); break;
            case 19: c19.consultar(); break;
            case 20: c20.consultar(); break;
            case 21: c21.consultar(); break;
            case 22: c22.consultar(); break;
            case 23: c23.consultar(); break;
            case 24: c24.consultar(); break;
            case 25: c25.consultar(); break;
            case 26: c26.consultar(); break;
            case 27: c27.consultar(); break;
            case 28: c28.consultar(); break;
            case 29: c29.consultar(); break;
            case 30: c30.consultar(); break;
            default:
                cout << "Ingresa un ID de cuenta valido" << endl;
                break;
            }
            cout << "\033[0m";
            break;

        case 4:
            
            c1.mostrarInfo();
            c2.mostrarInfo();
            c3.mostrarInfo();
            c4.mostrarInfo();
            c5.mostrarInfo();
            c6.mostrarInfo();
            c7.mostrarInfo();
            c8.mostrarInfo();
            c9.mostrarInfo();
            c10.mostrarInfo();
            c11.mostrarInfo();
            c12.mostrarInfo();
            c13.mostrarInfo();
            c14.mostrarInfo();
            c15.mostrarInfo();
            c16.mostrarInfo();
            c17.mostrarInfo();
            c18.mostrarInfo();
            c19.mostrarInfo();
            c20.mostrarInfo();
            c21.mostrarInfo();
            c22.mostrarInfo();
            c23.mostrarInfo();
            c24.mostrarInfo();
            c25.mostrarInfo();
            c26.mostrarInfo();
            c27.mostrarInfo();
            c28.mostrarInfo();
            c29.mostrarInfo();
            c30.mostrarInfo();
            

            break;

        default:
            break;

        }
    } while (opcion != 0);

    return 0;
}
