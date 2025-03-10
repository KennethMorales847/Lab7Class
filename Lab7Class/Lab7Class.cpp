#include <string>
#include <iostream>
#include<cstdlib>

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
        cout << "Su saldo inicial es Q" << saldo << endl<<
            "La cantidad a depositar es: Q"<<monto<<endl;
        saldo += monto;
        cout << "Su nuevo saldo es: Q" << saldo<<endl;
    }

    void retirar (double monto) {
        cout << "Su saldo inicial es Q" << saldo << endl <<
            "La cantidad a retirar es: Q" << monto << endl;
        saldo -= monto;
        cout << "Su nuevo saldo es: Q" << saldo << endl;
    }

    void consultar() {
        cout << "Titular: " << titular << endl <<
            "Saldo actual Q" << saldo << endl;
    }

    void mostrarInfo() {
        cout << "Nombre: " << titular << endl <<
            "Saldo: Q" << saldo << endl <<
            "Estado: ";
        if (activa == 1) {
            cout << "Activa";
        }
        else {
            cout << "Bloqueada";
        }
        cout << endl;
    }
};

int main()
{

    int opcion, ID;


    CuentasBancarias c1(1, "Kenneth", 1200, true, 0);
    CuentasBancarias c2(2, "Allison", 700, true, 0);
    CuentasBancarias c3(3, "Fleur", 26900, true, 0);

    do {
        cout << "---Menu---" << endl <<
            "1. Depositar" << endl <<
            "2. Retirar" << endl <<
            "3. Consultar Saldo" << endl <<
            "4. Ver todas las cuentas" << endl <<
            "0. Salir" << endl;

        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Escribe el ID de la cuenta a depositar: "; cin >> ID;
            switch (ID)
            {
            default:
                break;
            }

            break;

        default:
            break;

        }
    } while (opcion != 0);

    return 0;
}
