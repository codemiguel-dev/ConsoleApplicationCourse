#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <wbemidl.h>
#include <cstdlib> // Para system()
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void console1() {
    int* ptr = new int(10);  // Crear un puntero a entero en el heap
    std::cout << "Valor almacenado: " << *ptr << std::endl;
    delete ptr;  // Liberar la memoria asignada
    return;
}

void console2() {
    // Acceso directo a un archivo en una ruta específica
    std::ofstream port("C:\\xampp\\archivo.txt");  // Ruta corregida

    if (port.is_open()) {
        port << "Datos a enviar al puerto\n";  // Escribir en el archivo
        port.close();
        std::cout << "Datos enviados al archivo.\n";
    }
    else {
        std::cerr << "No se pudo abrir el archivo\n";
    }
}

void console3() {
    std::cout << "Presiona Console 4\n";

#ifdef _WIN32
    // Comando para abrir una nueva terminal en Windows
    system("start cmd");
#elif __linux__
    // Comando para abrir una nueva terminal en Linux (GNOME o terminal predeterminada)
    system("gnome-terminal"); // Si usas GNOME
    // system("xterm"); // Alternativa para otros entornos de escritorio
#elif __APPLE__
    // Comando para abrir una nueva terminal en macOS
    system("open -a Terminal");
#else
    std::cerr << "Sistema operativo no soportado.\n";
#endif
}

void console4() {
    std::cout << "Presiona Console 4\n";

#ifdef _WIN32
    // Crear un archivo temporal para la calculadora en Windows
    std::ofstream script("calc.bat");
    script << "@echo off\n";
    script << ":start\n";
    script << "cls\n"; // Limpiar la pantalla
    script << "echo Calculadora Simple\n";
    script << "set /p num1=Introduce el primer número: \n";
    script << "set /p op=Introduce la operación (+, -, *, /): \n";
    script << "set /p num2=Introduce el segundo número: \n";
    script << "set /a result=num1 %op% num2\n";
    script << "echo El resultado es: %result%\n";
    script << "set /p choice=¿Quieres realizar otro cálculo? (s/n): \n";
    script << "if /i \"%choice%\"==\"s\" goto start\n"; // Si elige 's', reinicia el cálculo
    script << "exit\n";
    script.close();
    system("start cmd /k calc.bat"); // Ejecutar el script en una nueva terminal

#elif __linux__
    // Crear un script temporal para la calculadora en Linux
    std::ofstream script("calc.sh");
    script << "#!/bin/bash\n";
    script << "while true; do\n";
    script << "  clear\n"; // Limpiar la pantalla
    script << "  echo \"Calculadora Simple\"\n";
    script << "  read -p \"Introduce el primer número: \" num1\n";
    script << "  read -p \"Introduce la operación (+, -, *, /): \" op\n";
    script << "  read -p \"Introduce el segundo número: \" num2\n";
    script << "  result=$(echo \"$num1 $op $num2\" | bc -l)\n";
    script << "  echo \"El resultado es: $result\"\n";
    script << "  read -p \"¿Quieres realizar otro cálculo? (s/n): \" choice\n";
    script << "  if [[ \"$choice\" != \"s\" ]]; then break; fi\n";
    script << "done\n";
    script.close();
    system("gnome-terminal -- bash -c './calc.sh; rm calc.sh'"); // Ejecutar el script

#elif __APPLE__
    // Crear un script temporal para la calculadora en macOS
    std::ofstream script("calc.sh");
    script << "#!/bin/bash\n";
    script << "while true; do\n";
    script << "  clear\n"; // Limpiar la pantalla
    script << "  echo \"Calculadora Simple\"\n";
    script << "  read -p \"Introduce el primer número: \" num1\n";
    script << "  read -p \"Introduce la operación (+, -, *, /): \" op\n";
    script << "  read -p \"Introduce el segundo número: \" num2\n";
    script << "  result=$(echo \"$num1 $op $num2\" | bc -l)\n";
    script << "  echo \"El resultado es: $result\"\n";
    script << "  read -p \"¿Quieres realizar otro cálculo? (s/n): \" choice\n";
    script << "  if [[ \"$choice\" != \"s\" ]]; then break; fi\n";
    script << "done\n";
    script.close();
    system("open -a Terminal ./calc.sh; rm calc.sh"); // Ejecutar el script

#else
    std::cerr << "Sistema operativo no soportado.\n";
#endif
}

void console5() {
    srand(time(0));
    int numero = rand() % 100 + 1;
    int intento, intentos = 0;

    cout << "Adivina el número (entre 1 y 100):\n";
    do {
        cout << "Introduce tu intento: ";
        cin >> intento;
        intentos++;

        if (intento > numero)
            cout << "Es más bajo.\n";
        else if (intento < numero)
            cout << "Es más alto.\n";
        else
            cout << "¡Correcto! Lo adivinaste en " << intentos << " intentos.\n";
    } while (intento != numero);
}

void console6() {
    vector<string> tareas;
    int opcion;

    do {
        cout << "\nGestor de Tareas\n";
        cout << "1. Agregar tarea\n2. Ver tareas\n3. Eliminar tarea\n4. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string tarea;
            cout << "Introduce la tarea: ";
            cin.ignore();
            getline(cin, tarea);
            tareas.push_back(tarea);
            break;
        }
        case 2: {
            cout << "Lista de tareas:\n";
            for (size_t i = 0; i < tareas.size(); i++) {
                cout << i + 1 << ". " << tareas[i] << endl;
            }
            break;
        }
        case 3: {
            int indice;
            cout << "Introduce el número de la tarea a eliminar: ";
            cin >> indice;
            if (indice > 0 && indice <= tareas.size()) {
                tareas.erase(tareas.begin() + indice - 1);
            }
            else {
                cout << "Índice no válido.\n";
            }
            break;
        }
        case 4:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}

void console7() {
    struct Transaction {
        std::string type; // "Ingreso" o "Gasto"
        std::string description;
        double amount;
    };

    std::vector<Transaction> transactions;
    double balance = 0.0;

    // Función para cargar datos desde un archivo
    auto loadTransactions = [&]() {
        std::ifstream file("finanzas.txt");
        if (file.is_open()) {
            Transaction transaction;
            while (file >> transaction.type >> std::ws) {
                std::getline(file, transaction.description, ';');
                file >> transaction.amount;
                transactions.push_back(transaction);
                if (transaction.type == "Ingreso") {
                    balance += transaction.amount;
                }
                else if (transaction.type == "Gasto") {
                    balance -= transaction.amount;
                }
            }
            file.close();
        }
        };

    // Función para guardar datos en un archivo
    auto saveTransactions = [&]() {
        std::ofstream file("finanzas.txt");
        if (file.is_open()) {
            for (const auto& transaction : transactions) {
                file << transaction.type << " "
                    << transaction.description << ";"
                    << transaction.amount << "\n";
            }
            file.close();
        }
        };

    // Función para añadir una transacción
    auto addTransaction = [&]() {
        Transaction transaction;
        std::cout << "Ingrese el tipo de transacción (Ingreso/Gasto): ";
        std::cin >> transaction.type;
        std::cin.ignore();
        if (transaction.type != "Ingreso" && transaction.type != "Gasto") {
            std::cout << "Tipo de transacción inválido.\n";
            return;
        }
        std::cout << "Ingrese una descripción: ";
        std::getline(std::cin, transaction.description);
        std::cout << "Ingrese el monto: ";
        std::cin >> transaction.amount;

        if (transaction.type == "Ingreso") {
            balance += transaction.amount;
        }
        else if (transaction.type == "Gasto") {
            balance -= transaction.amount;
        }

        transactions.push_back(transaction);
        saveTransactions();
        std::cout << "Transacción añadida exitosamente.\n";
        };

    // Función para mostrar el resumen de finanzas
    auto viewSummary = [&]() {
        std::cout << "\nResumen de Finanzas\n";
        std::cout << "--------------------------\n";
        std::cout << std::left << std::setw(10) << "Tipo"
            << std::setw(20) << "Descripción"
            << std::setw(10) << "Monto\n";
        std::cout << "--------------------------\n";
        for (const auto& transaction : transactions) {
            std::cout << std::left << std::setw(10) << transaction.type
                << std::setw(20) << transaction.description
                << std::setw(10) << transaction.amount << "\n";
        }
        std::cout << "--------------------------\n";
        std::cout << "Saldo actual: " << balance << " USD\n";
        };

    // Menú principal
    auto menu = [&]() {
        int choice;
        do {
            std::cout << "\nGestor de Finanzas\n";
            std::cout << "1. Añadir transacción\n";
            std::cout << "2. Ver resumen de finanzas\n";
            std::cout << "3. Salir\n";
            std::cout << "Seleccione una opción: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewSummary();
                break;
            case 3:
                std::cout << "Saliendo del gestor de finanzas.\n";
                break;
            default:
                std::cout << "Opción inválida. Inténtelo de nuevo.\n";
            }
        } while (choice != 3);
        };

    // Cargar transacciones iniciales
    loadTransactions();

    // Mostrar el menú
    menu();
}

void console8() {
    // Estructura para representar una cuenta bancaria
    struct Account {
        std::string username;
        std::string password;
        double balance = 0.0;
    };

    // Base de datos de cuentas
    std::unordered_map<std::string, Account> accounts;

    // Función para cargar cuentas desde un archivo
    auto loadAccounts = [&accounts]() {
        std::ifstream file("accounts.txt");
        if (file.is_open()) {
            Account account;
            while (file >> account.username >> account.password >> account.balance) {
                accounts[account.username] = account;
            }
            file.close();
        }
        else {
            std::cout << "No se encontró el archivo de cuentas. Se creará uno nuevo.\n";
        }
        };

    // Función para guardar cuentas en un archivo
    auto saveAccounts = [&accounts]() {
        std::ofstream file("accounts.txt");
        if (file.is_open()) {
            for (const auto& pair : accounts) {
                const Account& account = pair.second;
                file << account.username << " " << account.password << " " << account.balance << "\n";
            }
            file.close();
        }
        };

    // Función para registrarse
    auto registerAccount = [&accounts, &saveAccounts]() {
        Account newAccount;
        std::cout << "Ingrese un nombre de usuario: ";
        std::cin >> newAccount.username;

        if (accounts.find(newAccount.username) != accounts.end()) {
            std::cout << "El nombre de usuario ya existe. Intente con otro.\n";
            return;
        }

        std::cout << "Ingrese una contraseña: ";
        std::cin >> newAccount.password;
        newAccount.balance = 0.0;

        accounts[newAccount.username] = newAccount;
        saveAccounts();
        std::cout << "Cuenta registrada exitosamente.\n";
        };

    // Función para iniciar sesión
    auto login = [&accounts]() -> Account* {
        std::string username, password;
        std::cout << "Ingrese su nombre de usuario: ";
        std::cin >> username;
        std::cout << "Ingrese su contraseña: ";
        std::cin >> password;

        auto it = accounts.find(username);
        if (it != accounts.end() && it->second.password == password) {
            std::cout << "Inicio de sesión exitoso.\n";
            return &it->second;
        }

        std::cout << "Nombre de usuario o contraseña incorrectos.\n";
        return nullptr;
        };

    // Función para realizar depósitos
    auto deposit = [](Account* account) {
        double amount;
        std::cout << "Ingrese el monto a depositar: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "El monto debe ser mayor a 0.\n";
            return;
        }

        account->balance += amount;
        std::cout << "Depósito realizado con éxito. Saldo actual: " << account->balance << " USD\n";
        };

    // Función para realizar retiros
    auto withdraw = [](Account* account) {
        double amount;
        std::cout << "Ingrese el monto a retirar: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "El monto debe ser mayor a 0.\n";
            return;
        }

        if (amount > account->balance) {
            std::cout << "Fondos insuficientes.\n";
            return;
        }

        account->balance -= amount;
        std::cout << "Retiro realizado con éxito. Saldo actual: " << account->balance << " USD\n";
        };

    // Función para consultar el saldo
    auto checkBalance = [](const Account* account) {
        std::cout << "Saldo actual: " << account->balance << " USD\n";
        };

    // Menú principal
    auto menu = [&]() {
        int choice;
        Account* loggedInAccount = nullptr;

        loadAccounts();

        do {
            std::cout << "\n--- Simulador de Cajero Automático ---\n";
            if (!loggedInAccount) {
                std::cout << "1. Registrarse\n";
                std::cout << "2. Iniciar sesión\n";
                std::cout << "3. Salir\n";
            }
            else {
                std::cout << "1. Depositar\n";
                std::cout << "2. Retirar\n";
                std::cout << "3. Consultar saldo\n";
                std::cout << "4. Cerrar sesión\n";
            }

            std::cout << "Seleccione una opción: ";
            std::cin >> choice;

            if (!loggedInAccount) {
                switch (choice) {
                case 1:
                    registerAccount();
                    break;
                case 2:
                    loggedInAccount = login();
                    break;
                case 3:
                    std::cout << "Gracias por usar el simulador. ¡Adiós!\n";
                    break;
                default:
                    std::cout << "Opción inválida. Intente de nuevo.\n";
                }
            }
            else {
                switch (choice) {
                case 1:
                    deposit(loggedInAccount);
                    break;
                case 2:
                    withdraw(loggedInAccount);
                    break;
                case 3:
                    checkBalance(loggedInAccount);
                    break;
                case 4:
                    loggedInAccount = nullptr;
                    std::cout << "Sesión cerrada.\n";
                    break;
                default:
                    std::cout << "Opción inválida. Intente de nuevo.\n";
                }
            }
        } while (choice != 3 || loggedInAccount);
        };

    menu();

}



int main() {
    int option = 0;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Console 1 (valor almacenado)\n";
        std::cout << "2. Console 2 (Acceso a Puertos de Entrada/Salida (I/O))\n";
        std::cout << "3. Console 3 (Abrir nueva terminal)\n";
        std::cout << "4. Console 4 (Calculadora)\n";
        std::cout << "5. Console 5 (Juego de Adivinanza)\n";
        std::cout << "6. Console 6 (Gestor de Tareas)\n";
        std::cout << "7. Console 7 (Gestor de finanzas)\n";
        std::cout << "8. Console 8 (Simulador básico de cajero automático)\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
        case 1:
            console1();
            break;
        case 2:
            console2();
            break;
        case 3:
            console3();
            break;
        case 4:
            console4();
            break;
        
        case 5:
            console5();
            break;

        case 6:
            console6();
            break;

        case 7:
            console7();
			break;

		case 8:
			console8();
			break;

        case 9:
            std::cout << "Exiting...\n";
            return 0; // Termina el programa
        default:
            std::cout << "Invalid option, please try again.\n";
            break;
        }
    }

    return 0;
}
