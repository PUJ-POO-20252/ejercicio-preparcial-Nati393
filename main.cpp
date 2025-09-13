#include <iostream>   // Incluye la biblioteca para entrada y salida (cout, cin)
#include <string>     // Incluye la biblioteca para usar strings (texto)
using namespace std;  // Permite usar cout y cin sin tener que poner std:: delante

// Declaraciones de las funciones
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();

int main() {  // Función principal
    int opcion;  // Variable para guardar la opción que elija el usuario

    do {  // Inicia un bucle que se repetirá hasta que el usuario elija salir (opción 7)
        // Mostrar el menú
        cout << "\n=== MENU PRINCIPAL ===\n";
        cout << "1. Ejercicio 1: Calificaciones de estudiantes\n";
        cout << "2. Ejercicio 2: Encuesta de cine\n";
        cout << "3. Ejercicio 3: Secuencia ascendente\n";
        cout << "4. Ejercicio 4: Descuentos en tienda\n";
        cout << "5. Ejercicio 5: Primer caracter no repetido\n";
        cout << "6. Ejercicio 6: Secuencia de Fibonacci\n";
        cout << "7. Salir\n";
        cout << "Elige una opcion: ";

        cin >> opcion;  // Lee la opción que el usuario ingresa

        // El switch permite que dependiendo de la opción, ejecuta una función
        switch (opcion) {
            case 1:
                ejercicio1();  // Llama a la función del ejercicio 1
                break;  // Sale del switch
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 5:
                ejercicio5();
                break;
            case 6:
                ejercicio6();
                break;
            case 7:
                cout << "¡Hasta luego!\n";  // Mensaje de despedida
                break;
            default:  // Si la opción no es entre 1 y 7
                cout << "Opción no válida.\n";
        }
    } while (opcion != 7);  // Repite el bucle mientras la opción no sea 7 (salir)

    return 0;
}

// Implementaciones de los ejercicios

void ejercicio1() {
    double calificaciones[8];  // Arreglo para guardar 8 calificaciones (números con decimales)
    int aprobados = 0, reprobados = 0, excelentes = 0;  // Contadores para cada categoría
    double suma = 0.0;  // Variable para acumular la suma de todas las calificaciones

    cout << "Ingrese las calificaciones de 8 estudiantes:\n";
    for (int i = 0; i < 8; i++) {  // Bucle que se repite 8 veces
        cout << "Estudiante " << i+1 << ": ";  // Pide la calificación del estudiante i+1
        cin >> calificaciones[i];  // Lee la calificación y la guarda en el arreglo
        suma += calificaciones[i];  // Suma la calificación a la suma total

        // Verifica si está aprobado (>=3.0) y aumenta el contador correspondiente
        if (calificaciones[i] >= 3.0) {
            aprobados++;
        } else {
            reprobados++;
        }

        // Verifica si es excelente (>=4.5) y aumenta el contador
        if (calificaciones[i] >= 4.5) {
            excelentes++;
        }
    }

    // Mostrar resultados
    cout << "\nResultados:\n";
    cout << "a) Aprobados: " << aprobados << endl;
    cout << "b) Reprobados: " << reprobados << endl;
    cout << "c) Excelentes: " << excelentes << endl;
    cout << "d) Promedio: " << suma / 8.0 << endl;  // Calcula el promedio dividiendo la suma entre 8
}

void ejercicio2() {
    int edad, total_encuestados = 0, jovenes = 0, calif_perfecta = 0;
    double calificacion, suma_calificaciones = 0.0;

    cout << "Encuesta de satisfacción (ingrese edad 0 para terminar)\n";
    while (true) {  // Bucle infinito hasta que se ingrese edad 0
        cout << "Edad: ";
        cin >> edad;
        if (edad == 0) {  // Si la edad es 0, termina el bucle
            break;
        }
        cout << "Calificación (1-10): ";
        cin >> calificacion;

        total_encuestados++;  // Aumenta el total de encuestados
        suma_calificaciones += calificacion;  // Suma la calificación

        // Verifica si es joven (entre 18 y 25)
        if (edad >= 18 && edad <= 25) {
            jovenes++;
        }

        // Verifica si la calificación es perfecta (10)
        if (calificacion == 10) {
            calif_perfecta++;
        }
    }

    // Mostrar reporte
    cout << "\nReporte:\n";
    cout << "a) Total encuestados: " << total_encuestados << endl;
    // Calcula el promedio solo si hay encuestados para evitar división por cero
    if (total_encuestados > 0) {
        cout << "b) Promedio de calificación: " << suma_calificaciones / total_encuestados << endl;
    } else {
        cout << "b) Promedio de calificación: 0" << endl;
    }
    cout << "c) Jóvenes (18-25 años): " << jovenes << endl;
    cout << "d) Calificación perfecta (10): " << calif_perfecta << endl;
}

void ejercicio3() {
    int n;  // Cantidad de números
    cout << "Ingrese la cantidad de números: ";
    cin >> n;

    int anterior, actual;
    bool esAscendente = true;  // Suponemos que es ascendente hasta que se demuestre lo contrario

    if (n > 0) {
        cout << "Ingrese el número 1: ";
        cin >> anterior;
    }

    for (int i = 2; i <= n; i++) {  // Empezamos desde el segundo número
        cout << "Ingrese el número " << i << ": ";
        cin >> actual;

        // Si el número actual es menor o igual al anterior, ya no es ascendente
        if (actual <= anterior) {
            esAscendente = false;
        }
        anterior = actual;  // Actualizamos el anterior para la siguiente comparación
    }

    if (esAscendente) {
        cout << "La secuencia ES estrictamente ascendente." << endl;
    } else {
        cout << "La secuencia NO es estrictamente ascendente." << endl;
    }
}

void ejercicio4() {
    double precio;
    int cantidad;
    double descuento = 0.0;

    cout << "Ingrese el precio unitario: ";
    cin >> precio;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    // Aplicar descuentos según la cantidad
    if (cantidad >= 1 && cantidad <= 10) {
        descuento = 0.0;
    } else if (cantidad >= 11 && cantidad <= 20) {
        descuento = 0.05;  // 5%
    } else if (cantidad >= 21 && cantidad <= 50) {
        descuento = 0.10;  // 10%
    } else if (cantidad > 50) {
        descuento = 0.15;  // 15%
    } else {
        cout << "Cantidad no válida." << endl;
        return;
    }

    double totalSinDescuento = precio * cantidad;
    double totalConDescuento = totalSinDescuento * (1 - descuento);

    cout << "Total a pagar: $" << totalConDescuento << endl;
}

void ejercicio5() {
    string palabra;
    cout << "Ingrese una palabra (en minúsculas): ";
    cin >> palabra;

    int n = palabra.length();
    bool encontrado = false;

    // Recorremos cada carácter de la palabra
    for (int i = 0; i < n; i++) {
        bool repetido = false;
        // Comparamos con todos los demás caracteres
        for (int j = 0; j < n; j++) {
            if (i != j && palabra[i] == palabra[j]) {
                repetido = true;
                break;  // Si encuentra repetido, sale del bucle interno
            }
        }
        // Si no está repetido, lo mostramos y salimos
        if (!repetido) {
            cout << "El primer carácter no repetido es: " << palabra[i] << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Todos los caracteres se repiten." << endl;
    }
}

void ejercicio6() {
    int n;
    cout << "Ingrese la cantidad de números de Fibonacci a mostrar: ";
    cin >> n;

    if (n <= 0) {
        cout << "Debe ingresar un número positivo." << endl;
        return;
    }

    long long a = 0, b = 1, c;  // Usamos long long para números grandes

    cout << "Secuencia de Fibonacci: ";
    if (n >= 1) {
        cout << a;
    }
    if (n >= 2) {
        cout << " " << b;
    }

    for (int i = 3; i <= n; i++) {
        c = a + b;
        cout << " " << c;
        a = b;
        b = c;
    }
    cout << endl;
}