#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;
double prom = 0;
double parseCSV(const char* archivotxt);


int main()
{
    prom = parseCSV("Promedio5Estud.csv");
    cout <<"El promedio de los estudiantes es: " << prom << "\n";
    prom = parseCSV("Promedio10Estud.csv");
    cout <<"El promedio de los estudiantes es: " << prom << "\n";
    prom = parseCSV("Promedio15Estud.csv");
    cout <<"El promedio de los estudiantes es: " << prom << "\n";
    prom = parseCSV("Promedio20Estud.csv");
    cout <<"El promedio de los estudiantes es: " << prom << "\n";
    return 0;

}
double parseCSV(const char* archivotxt)
{
    
    ifstream data(archivotxt);
    string line;
    vector<vector<string>> parsedCSV;
    int contadordefila = 0;
    int contadordecolumna = 0;

   while(getline(data,line))        
	{
		stringstream linestream(line); //en esta de linea de comado se lee la linea correspondiente en el CSV
		string celda;
		vector<string> parsedfila;
		contadordecolumna = 0;    //este while es mas grande que el siguiente aqui se reinicia el contador de columna 

		while(getline(linestream,celda,','))
		{
			parsedfila.push_back(celda);   // con este comando push_back se lee y define la celda de texto que se encuentra ubicada con el contador de dolumans 
			contadordecolumna++;   //en este while el contador de columanas va iterando hasta que no hay mas datos
	
		}
        
		contadordefila++;  //cuando el contador de columnas termina su trabajo sale de lwhile anterior y lo que hace este es que suma uno mas a la fila, pasando a la siguiete linea de datos del CSV
		parsedCSV.push_back(parsedfila);
	}
	for(int i=0; i<contadordefila;i++){             //luego de que los push back definan los datos, este for se encarga de escribirlos en el termnal uno por uno siguiendo la "cordenas" que se definieron anteriormente 
		for (int j=0; j< contadordecolumna ; j++){
			cout << parsedCSV[i][j] <<"-";
		}
		cout <<'\n';
	}
	double suma = 0;
    for (int j=0; j<4; j++){
	for(int i=0; i<contadordefila;i++){       //con este for se mueve por la cade de datos 
		stringstream nota(parsedCSV[i][2]); // con esta función podemos almacenar los datos en el string nota
		double x = 0;   
         nota >> x;  //como nota es un string no puede ser poerado directamento con las variable de tipo float, aqui introducimos la información en x que ya habiamos definido 
         suma=x+suma;  // se realiza una suma interativa dentro de for cada vez que cambia de fila
	}
    int n=0;
	n=parsedCSV.size();
    double promedio=0; //para tener el dato del numero de estudiantes mas facil y accesible, generamos otra variable para almacenar este dato de parsedCSV.size
	promedio=suma/n; //aplicamos la operación del promedio artmetico 
	//cout<< "El promedio de las notas es: " << promedio; //imprimimos el valor del promedio 
	return promedio;
    }
    

};

