#include <iostream>
#include <cctype>//necesario para usar tolower
using namespace std;

// Declaraci�n de variables globales
char vocales[] = {'a', 'e', 'i', 'o','s','t'};
char numeros[] = {'4', '3', '1', '0','5','7'};

// Funci�n para sumar los valores de una cadena
void sumaValores(string& suma) {
	// Declaraci�n de variables locales
	string valor;
	int suma_total = 0;
	int j;
	
	// ciclo para recorrer la cadena car�cter por car�cter
	for (j = 0; j < suma.length(); j++) {
		/* Si el car�cter no es '+', se a�ade al valor actual
		nota si el usuario coloca otro caracter diferente al operador suma, no lo tomara en cuenta es decir 
		si el usuario coloca 5+5+5/3+5 el resultado que mostrara sera los los valores que contengan el signo +
		en esta ocacion = 20
		*/if (suma[j] != '+') {
			valor += suma[j];
		} else {
			// Si el car�cter es '+', se convierte el valor actual a entero y se suma al total
			suma_total += stoi(valor);//Esta funci�n convierte la cadena de texto valor en un n�mero entero.
			// Se reinicia el valor actual
			valor = "";
		}
	}
	// Se suma el �ltimo valor despu�s del �ltimo '+'
	suma_total += stoi(valor);
	// Se imprime la suma total
	cout << "La suma total es: " << suma_total << endl;
}

// Funci�n para procesar los datos
void procesarDatos() {
	// Declaraci�n de variables locales
	string suma;
	
	// Se pide al usuario que ingrese los valores a sumar
	cout << "Ingrese los valores que desea sumar, separados por '+': ";
	getline(cin,suma);
	// Se llama a la funci�n sumaValores para sumar los valores
	sumaValores(suma);
}

void cambiarvocales(string& palabra, char vocal, char numero) {
	int i = 0;
	// Bucle para recorrer la cadena car�cter por car�cter
	while (palabra[i]) {
		// Si el car�cter es una vocal, se cambia por el n�mero correspondiente
		if (palabra[i] == vocal) {
			palabra[i] = numero;
		}
		i++;
	}
}

void mostrarvocales() {
	// Declaraci�n de variables locales
	string palabra;
	
	// Se pide al usuario que ingrese la palabra a ofuscar
	cout << "Ingrese la palabra a ofuscar: ";
	getline(cin, palabra);
	int i = 0;
	// ciclo para convertir la palabra a min�sculas
	while (palabra[i]) {
		palabra[i] = tolower(palabra[i]);//tolower toma a minuscula y mayuscula como uno solo//avanzado en clases
		i++;
	}
	// ciclo para cambiar las vocales por n�meros
	for (int i = 0; i < 6; i++) {
		cambiarvocales(palabra, vocales[i], numeros[i]);
	}
	
	// Se imprime la palabra ofuscada
	cout << "Palabra: " << palabra << endl;
}

void datos() {
	// Declaraci�n de variables locales
	string nombrecompleto,nombre,paterno,materno;
	int pini, pfinal;
	// Se pide al usuario que ingrese su nombre completo
	cout<<"ingresa tu nombre completo : ";
	getline(cin,nombrecompleto);
	
	pini=0;
	// Se busca la posici�n del primer espacio despu�s del nombre
	pfinal=nombrecompleto.find(" ",pini);
	// Se extrae el nombre
	nombre =nombrecompleto.substr(pini,(pfinal-pini));
	
	// Se actualiza la posici�n inicial al car�cter despu�s del primer espacio
	pini = pfinal + 1 ;
	// Se busca la posici�n del segundo espacio
	pfinal=nombrecompleto.find(" ",pini);
	// Se extrae el apellido paterno
	paterno = nombrecompleto.substr(pini, pfinal - pini);
	
	// Se actualiza la posici�n inicial al car�cter despu�s del segundo espacio
	pini = pfinal + 1 ;
	// Se extrae el apellido materno
	materno = nombrecompleto.substr(pini);
	
	// Se convierten las iniciales a may�sculas
	nombre[0] = toupper(nombre[0]);  
	paterno[0] = toupper(paterno[0]);  
	materno[0] = toupper(materno[0]);  
	
	// Se imprimen el nombre y los apellidos
	cout<<"Apellido paterno : "<<paterno<<endl;
	cout<<"apellido materno : "<<materno<<endl;
	cout<<"nombre : "<<nombre<<endl<<endl;
}   

void Menu()
{
	// Declaraci�n de variables locales
	char opcion;
	
	do
	{
		// Se muestra el men� principal
		cout<<"  "<<" MENU PRINCIPAL "<<endl<<endl;
		cout<<"1: String suma de una cadena. "<<endl<<endl;
		cout<<"2: String Nombre completo. "<<endl<<endl;
		cout<<"3: Strin ofuscar."<<endl<<endl;
		cout<<"(s/S) Salir"<<endl;
		// Se pide al usuario que elija una opci�n
		cin>>opcion;
		cin.get();
		switch(opcion)
		{
			case'1':
				system("cls");
				cout<<"  "<<"String suma de una cadena."<<endl<<endl;
				procesarDatos();
				cout<<"presione cualquier tecla para regresar ";
				cin.get();
				system("cls");
			break;
			case'2':
				system("cls");
				cout<<"  "<<"String Nombre completo.."<<endl<<endl;
				datos();
				cout<<"presione cualquier tecla para regresar ";
				cin.get();
				system("cls");
			break;
			case'3':
				system("cls");
				cout<<"  "<<"Strin ofuscar."<<endl<<endl;
				mostrarvocales();
				cout<<"presione cualquier tecla para regresar ";
				cin.get();
				system("cls");
			break;
			case's':
			case'S':
			break;
		default:
			system("cls");
			cout<<"OPCION INVALIDA"<<endl<<endl;
			
		}
		
	}while(opcion != 's' && opcion !='S' );
}

int main() {
	Menu();
	return 0;
}
