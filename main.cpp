#include <iostream>


int main() {
	
	
	do{
		int opcion; 	
	
			cout << "------------GESTOR DE FINANZAS PERSONAL------------" << endl; 
			cout << " [1] Mostrar registro general. " << endl; 
			cout << " [2] Registrar ingresos o gastos. " << endl; 
			cout << " [3] Modificar algun monto. " << endl; 
			cout << " [4] Filtrar por fecha. " << endl; 
			cout << " [5] Filtrar por tipo de monto." << endl; 
			cin >> opcion; 
			
			switch(opcion){
				case 1: {
				
					break;
				}
				case 2: {
					
					break;
				}
				case 3: {
					
					break;
				}
				case 4:{
					
					break;
				} 
				case 5: {
					
					break;
				}
				default: {
					err << "Opcion no valida, vuelva a ingresar" << endl; 
					break;
				}
			}
		
		
	}while(opcion != 0); 
	
		
	return 0;
}