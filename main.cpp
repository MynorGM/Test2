#include <iostream>
#include <string>
#include <mysql.h>
#include <mysqld_error.h>


using namespace std;
void mostrarMenu_Admin() {
	cout << "Menu de opciones - Administrador"<<endl;
	cout << "---------------Favor digite el valor al que desea ingresar---------------" << endl;
	cout << "(1) - Opcion 1" << endl;
	cout << "(2) - Opcion 2 " << endl;
	cout << "(3) - Opcion 3" << endl;
	cout << "(4) - Salir" << endl;
	cout << "------------------------------------------------------------------------" << endl;
}

//Función para mostrar el menú Colaborador
void mostrarMenu_Colaborador() {
	cout << "Menu de opciones - Colaborador"<<endl;
	cout << "---------------Favor digite el valor al que desea ingresar---------------" << endl;
	cout << "(1) - Opcion 1" << endl;
	cout << "(2) - Opcion 2 " << endl;
	cout << "(3) - Opcion 3" << endl;
	cout << "(4) - Salir" << endl;
	cout << "------------------------------------------------------------------------" << endl;	
	
}


int main()
{
int opcion;
int Id;
char* us;
char* Contra;
int contrarow;
char s[1];
	int TipoUser;	
		
	int ContraIngresada;
   char Usuario[20];

   char *consulta;
   int ResulConsulta=0;
   char sentencia[] =  "SELECT * FROM sistema_gasolinera.users WHERE NombreUsuario=\'%s\'";
   MYSQL_RES *res;
   MYSQL_ROW  row;
   MYSQL   *objDatos;

	cout << "LOGIN"<<endl;
	cout << "---------------------------------BIENVENIDO-----------------------------" << endl;
	cout << "Ingrese Usuario: ";
  	 cin >> Usuario;
  	 cout << "Ingrese Contra: ";
  	 cin >> ContraIngresada;
	cout << "------------------------------------------------------------------------" << endl;


   

   consulta = new char[strlen(sentencia)+strlen(Usuario)];
   sprintf(consulta, sentencia, Usuario);

   // Intentar iniciar MySQL:
  if(!(objDatos = mysql_init(0))) {
      // Imposible crear el objeto objDatos
      cout << "ERROR: imposible crear el objeto objDatos." << endl;
      return 1;

  }

   if(mysql_real_connect(objDatos,"localhost","root","Mynor2002*","sistema_gasolinera",3306,NULL,0)){

     mysql_query(objDatos, consulta);
    res = mysql_store_result(objDatos);
    ResulConsulta = mysql_num_rows(res);

   if(ResulConsulta>0)
   {
       row = mysql_fetch_row(res);
	 
	Contra = row[3];
	us = row[1];
	TipoUser= atoi(us);
	contrarow= atoi(Contra);
	  
	     

	   
	   if(contrarow==ContraIngresada){
	   	  system ("cls"); 
	   	cout<<"Bienvenido";
	   	switch(TipoUser){
			case 1:
					do {
	       mostrarMenu_Admin();
	       cout << "Seleccione una opcion" << endl;
				cin >> opcion;		
				switch (opcion){	
						
						//Opcion 1
					case 1: {								
							system ("cls");
							cout << "Opcion 1"<<endl;
							system ("pause");
							break;							
							}
							
						//Opcion 2
					case 2: {
							system ("cls");
							cout << "Opcion 2"<<endl;
							system ("pause");
							break;
							}
						//Opcion 3
					case 3: {
							system ("cls");
							cout << "Opcion 3" << endl;
							system ("pause");
							break;
							}
						//Opcion 4 - Salir			
					case 4: {
							system ("cls");
							cout << "Gracias por usar nuestros servicios, saliendo del programa..." << endl;
							exit(1);
							break;
							}
						default:
							cout << "Opcion no valida, favor intente de nuevo." << endl;
							system ("pause");
							break;
				} 
		}while (opcion != 4);
			
			break;	   	
			case 2:
				
        // Menú para usuarios de caja      
       do {
	   
	       mostrarMenu_Colaborador();
	       cout << "Seleccione una opcion" << endl;
				cin >> opcion;		
				switch (opcion){	
						
						//Opcion 1
					case 1: {								
							system ("cls");
							cout << "Opcion 1"<<endl;
							system ("pause");
							break;							
							}
							
						//Opcion 2
					case 2: {
							system ("cls");
							cout << "Opcion 2"<<endl;
							system ("pause");
							break;
							}
						//Opcion 3
					case 3: {
							system ("cls");
							cout << "Opcion 3" << endl;
							system ("pause");
							break;
							}
						//Opcion 4 - Salir			
					case 4: {
							system ("cls");
							cout << "Gracias por usar nuestros servicios, saliendo del programa..." << endl;
							exit(1);
							break;
							}
						default:
							cout << "Opcion no valida, favor intente de nuevo." << endl;
							system ("pause");
							break;
				} 
		}while (opcion != 4);  
			break;
			case 3:
			break;	
	   		default:
	   			cout<<"";
		   }
	   	
	   	  cout<< TipoUser ;
			cout<< us ;
			
			
  			cout<< Contra <<"\n";
  			
  			
  			
  			
	   	
	   }else{
	   	
	   	
	   	cout<<"Contrase;a incorrecta";
	   	
	   	
	   }
	   
	    
	

	
   }else{  cout << "Persona no encontrada" << endl;  }    
     }else{
    cout<<"Usuario o contrase;a incorrectos..-->"<<mysql_error(objDatos);
    }



  return 0;

}



