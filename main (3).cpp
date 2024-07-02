#include <iostream> // Biblioteca para entrada y salida estándar.
#include <string>   // Biblioteca para trabajar con cadenas de texto.
#include <limits>   // Biblioteca que proporciona std::numeric_limits para limpiar el búfer de entrada (limpiar caracteres no deseados).
// Operador "<<", pertenece a la librería de <iostream>, se utiliza para realizar la operación de inserción en un flujo de salida. Este operador se utiliza para enviar datos a un flujo de salida, como la consola.

using namespace std;

int main() {
    // Variables para el saldo inicial y actual.
    double saldo_inicial = 632023.0; // "double" es un tipo de dato que se utiliza para representar números de punto flotante de doble precisión.
    double saldo_actual = saldo_inicial; // Variable que almacena el saldo actual, inicializada con el saldo inicial.
    // Un "punto flotante de doble precisión" es un tipo de dato numérico que se utiliza para representar números decimales con mayor precisión que los puntos flotantes de precisión simple.

    // Variable para almacenar la opción del usuario.
    int opcion = 0; // Inicializamos la opción en 0.

    // Mensaje de bienvenida inicial.
    cout << "Bienvenido al Cajero Automático" << endl;

    // Bucle principal que se ejecuta hasta que el usuario elige salir (opción 5).
    while (opcion != 5) {
        // Menú de opciones para el usuario.
        cout << "Elija una opción:" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Hacer un retiro" << endl;
        cout << "3. Hacer un depósito" << endl;
        cout << "4. Hacer una transferencia" << endl;
        cout << "5. Salir" << endl;

        // Capturamos la entrada del usuario en una cadena.
        string input;
        getline(cin, input);

        // Verificamos que la entrada sea válida.
        if (input.empty() || input.length() > 1 || !isdigit(input[0])) {
            cout << "Entrada inválida. Por favor, elija una opción válida." << endl;
            continue; // Vuelve al inicio del bucle.
        }

        // Convertimos la entrada a un número entero.
        opcion = stoi(input);

        // Switch para manejar las opciones del usuario.
        switch (opcion) {
            case 1:
                // Opción: Consultar saldo
                cout << "Su saldo actual es: $" << saldo_actual << endl;
                cout << "Recibo: Consulta de saldo realizada." << endl;
                break;

            case 2:
                // Opción: Hacer un retiro
                int monto_retiro;
                cout << "Seleccione el monto a retirar:" << endl;
                cout << "1. $20,000" << endl;
                cout << "2. $50,000" << endl;
                cout << "3. $100,000" << endl;
                cout << "4. $200,000" << endl;
                cout << "5. $500,000" << endl;
                cout << "6. Digite un valor diferente" << endl;
                cin >> monto_retiro;

                // Limpia el búfer de entrada.
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Casos para montos predefinidos.
                switch (monto_retiro) {
                    case 1:
                        monto_retiro = 20000;
                        break;
                    case 2:
                        monto_retiro = 50000;
                        break;
                    case 3:
                        monto_retiro = 100000;
                        break;
                    case 4:
                        monto_retiro = 200000;
                        break;
                    case 5:
                        monto_retiro = 500000;
                        break;
                    case 6:
                        int monto_personalizado;
                        cout << "Ingrese el monto a retirar (debe ser múltiplo de $10,000 y no mayor a $600,000): ";
                        cin >> monto_personalizado;

                        // Validación del monto personalizado.
                        if (monto_personalizado % 10000 != 0 || monto_personalizado > 600000) {
                            cout << "Monto no válido. Operación cancelada." << endl;
                            break;
                        }
                        monto_retiro = monto_personalizado;
                        break;
                    default:
                        cout << "Opción no válida. Operación cancelada." << endl;
                        break;
                }

                // Verificación del saldo antes de realizar el retiro.
                if (monto_retiro != 0) {
                    double costo_retiro = 6000.0;
                    if (monto_retiro + costo_retiro > saldo_actual) {
                        cout << "No tiene suficiente saldo para esta operación." << endl;
                    } else {
                        saldo_actual -= (monto_retiro + costo_retiro);
                        cout << "Recibo: Retiro de $" << monto_retiro << " realizado. Nuevo saldo: $" << saldo_actual << endl;
                    }
                }
                break;

            case 3:
                // Opción: Hacer un depósito
                double monto_deposito;
                cout << "Ingrese el monto a depositar (debe ser múltiplo de $10,000 y no mayor a $10,000,000): ";
                cin >> monto_deposito;

                // Limpia el búfer de entrada.
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Validación del monto de depósito.
                if (static_cast<int>(monto_deposito) % 10000 != 0 || monto_deposito > 10000000) {
                    cout << "Monto no válido. Operación cancelada." << endl;
                } else {
                    saldo_actual += monto_deposito;
                    cout << "Recibo: Depósito de $" << monto_deposito << " realizado. Nuevo saldo: $" << saldo_actual << endl;
                }
                break;

            case 4:
                // Opción: Hacer una transferencia
                double monto_transferencia;
                long long numero_cuenta_destino; // Cambiado a long long para admitir números más grandes.
                cout << "Ingrese el monto a transferir: $";
                cin >> monto_transferencia;
                cout << "Ingrese el número de cuenta de destino (debe ser de 10 dígitos): ";
                cin >> numero_cuenta_destino;

                // Limpia el búfer de entrada.
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Validación del número de cuenta antes de realizar la transferencia.
                if (numero_cuenta_destino < 1000000000ULL || numero_cuenta_destino > 9999999999ULL) {
                    cout << "Número de cuenta no válido. Operación cancelada." << endl;
                } else {
                    double costo_transferencia = monto_transferencia * 0.004;
                    // Verificación del saldo antes de realizar la transferencia.
                    if (monto_transferencia + costo_transferencia > saldo_actual) {
                        cout << "No tiene suficiente saldo para esta operación." << endl;
                    } else {
                        saldo_actual -= (monto_transferencia + costo_transferencia);
                        cout << "Recibo: Transferencia de $" << monto_transferencia << " realizada. Nuevo saldo: $" << saldo_actual << endl;
                    }
                }
                break;

            case 5:
                // Opción: Salir
                cout << "Gracias por usar nuestro servicio. Hasta pronto." << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }
    }

    return 0; // Fin del Programa.
}
