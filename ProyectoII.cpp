#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (nodo *)malloc(sizeof(nodo))

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};
struct Pila{
	int dato;
	Pila *siguiente;
};
int cant,i,aleatorio;
FILE *archivo;
nodo *inicial = NULL;
nodo *fin = NULL;
Pila *pilita=NULL;
int n=0;
int tam,num;
//generales
void menu();
int pedir_datos();
int pedir_datos_buscar();
int pedir_datos_modificar();

void generar_datos(nodo *&, nodo *&);
void ordenar_datos_burbuja();
void imprimir_datos(nodo *);

//colas
bool cola_vacia(nodo *);
void cola_insertar_nodo(nodo *&,nodo *&, int);
void cola_mostrar(nodo *);
void cola_buscar(nodo *,int);
void cola_modificar_nodo(nodo *&, int);
void cola_eliminar_nodo();
void cola_eliminar_completa(nodo *&,nodo *&,int & );
void Cargar();
void salvarElementos();

//pilas
void datos_pila();
void cargar_Pila();
void mostrar_Pila();
void buscar_Pila();
void modificar_Pila();
void eliminar_Pila();
void eliminar_completa_Pila();
void insertar_Pila_archivo();
void mostrar_Pila_archivo();
void ordenar_Pila_burbuja();
/////////////////////////////Funciones De Archivos////////////////////7


int main(){
	menu();
	return 0;
}


void menu(){
	int opcion;
	do{
		printf("\n|------------------------------------------------------|");
        printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
        printf("\n|-------------------------|----------------------------|");
        printf("\n|                         |                            |");
        printf("\n| 1. PILA                 | 3. FINALIZAR               |");
        printf("\n|                         |                            |");
        printf("\n| 2. COLA                 | 0. SALIR                   |"); 
        printf("\n|-------------------------|----------------------------|");
        printf("\n|------------------------------------------------------|");
        
		printf("\n\n -Ingrese una opcion:----->");
		scanf("\n%d", &opcion);
		system("cls");
		switch(opcion){
		case 1: {
			printf("******************************PILAS***************************\n");
			float ini;
			float final;
			int opcion1;
			do{
				printf("\n|------------------------------------------------------|");
                printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
                printf("\n|                     DE LA PILA                       |");
                printf("\n|-------------------------|----------------------------|");
                printf("\n|                         |                            |");
                printf("\n| 1.GENERAR DATO          | 2. VER DATOS                |");
                printf("\n|                         |                            |");
                printf("\n| 3.ELIMINAR DATO         | 4. BUSCAR DATOS            |");
                printf("\n|                         |                            |");
                printf("\n| 5.MODIFICAR             | 6. ELIMINAR ESTRUCTURA     |");
                printf("\n|                         |                            |");
				printf("\n| 7. ORDENAR DATOS        | 8. CARGAR ARCHIVO          |");
				printf("\n|                         |                            |");
				printf("\n| 9. MOSTRAR DESDE ARCHIVO| 0. ANTERIOR                |");
				printf("\n|-------------------------|----------------------------|");
				printf("\n|------------------------------------------------------|");
				printf("\n---Ingrese una opcion:------>");
				scanf("%d", &opcion1);
				switch(opcion1){
					
				case 1:
					printf("Insertar Pila\n");
					ini=clock();
					datos_pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
				
				case 2:
			        printf("Mostrar Pila\n");
					ini=clock();
					mostrar_Pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
					
				case 3:
					printf("Eliminar Dato de la Pila\n");
					ini=clock();
					eliminar_Pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
					
				case 4:
					printf("Buscar Dato de la Pila\n");
					ini=clock();
					buscar_Pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
					
				case 5:
					printf(" Modificar dato de la Pila\n");
					ini=clock();
					modificar_Pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
				 
				case 6:
					printf(" Eliminar Pila completa\n");
					ini=clock();
					eliminar_completa_Pila();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
				case 7:
					printf("-ORDENAR PILA\n");
					ini=clock();
					ordenar_Pila_burbuja();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;
				case 8:
					ini=clock();
					insertar_Pila_archivo();
					final=clock();
					printf("\nTiempo: %.2f milisegundos\n", (final-ini)/(float)CLK_TCK);
					break;
				case 9:
					//ini=clock();
					mostrar_Pila_archivo();
					//final=clock();
					//printf("\nTiempo: %.2f segundos\n", (final-ini)/(float)CLK_TCK);
					break;      
				case 0:
					printf("ANTERIOR\n");
					menu();
					break;
					
				default:
					printf(" Error\n");
					break;
				}
				system("pause");
				system("cls");
			}while(opcion1 != 0);
			break;
			
			
		case 2:{
			printf("*********************COLAS***************************\n");
			
			int opcion2;
			int n;
			float ini,final;
			do{
				
				
		printf("\n|------------------------------------------------------|");
        printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
        printf("\n|                     DE LA COLA                       |");
        printf("\n|-------------------------|----------------------------|");
        printf("\n|                         |                            |");
        printf("\n| 1. GENERAR DATO         | 2. VER DATOS               |");
        printf("\n|                         |                            |");
        printf("\n| 3. ELIMINAR DATO        | 4. BUSCAR DATOS            |");
        printf("\n|                         |                            |");
        printf("\n| 5. MODIFICAR            | 6. ELIMINAR ESTRUCTURA     |");
        printf("\n|                         |                            |");
        printf("\n| 7. ORDENAR DATOS        | 8. CARGAR ARCHIVO          |");
        printf("\n|                         |                            |");
        printf("\n| 9. MOSTRAR DESDE ARCHIVO| 0. ANTERIOR                |");
        printf("\n|-------------------------|----------------------------|");
        printf("\n|------------------------------------------------------|");
				
				
				printf("\n-----Ingrese una opcion:------>");
				scanf("%d", &opcion2);
				switch(opcion2){
					
				case 1:
					printf("-Insertar cola\n");
					ini=clock();
					generar_datos(inicial,fin);
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
				
				case 2:
					printf("-Mostrar cola\n");
					ini=clock();
					cola_mostrar(inicial);
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
					
				case 3:	
					ini=clock();
					cola_eliminar_nodo();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
				
				case 4:
					printf("-Buscar Dato de la cola\n");
					ini=clock();
					cola_buscar(inicial,pedir_datos_buscar());
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
					
				case 5:
					printf("-Modificar dato de la cola\n");
					ini=clock();
					cola_modificar_nodo(inicial,pedir_datos_modificar());
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
					
				case 6:
					printf("-Eliminar cola completa\n");
					ini=clock();
					cola_eliminar_completa(inicial,fin,n);
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
				 
				case 7:
					printf("-ORDENAR COLA\n");
					ini=clock();
					ordenar_datos_burbuja();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
				case 8:
					ini=clock();
					void salvarElementos();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;
				case 9:
					ini=clock();
					void Cargar();
					final=clock();
					printf("\nTiempo: %.2f segundos\n", (final-ini)/CLK_TCK);
					break;               
				 
				case 0:
					printf("-ANTERIOR\n");
					system("cls");
					menu();
					break;
                 
				default:
					printf("-Error\n");
					break;
				}
				system("pause");
				system("cls");
			}while(opcion2 != 0);
			break;
		} 
		case 3: {
				printf("**********************************************\n");
				printf("**********--HASTA LA VISTA BABY--*************\n");
				printf("**********************************************\n");
				break;
			}
		case 0: 
		exit(-1);
		break;
		default: 
			printf("**********************************************\n"); 
			printf("\n*No es una opcion valida, intentelo de nuevo*\n");
			printf("**********************************************\n");
		break;
		}
		
		}
		system("pause");
		system("cls");
		
	}while(opcion != 0);
}


int pedir_datos(){
	int dato;
	printf("Ingrese el dato a insertar\n");
	scanf("%d", &dato);
	return dato;
}

int pedir_datos_buscar(){
	int dato;
	printf("Ingrese el dato a buscar\n");
	scanf("%d", &dato);
	return dato;
}

int pedir_datos_modificar(){
	int dato;
	printf("Ingrese el dato a modificar\n");
	scanf("%d", &dato);
	return dato;
}

void generar_datos(nodo *&inicial, nodo *&fin){
	int cant, i, aleatorio;
	printf("Ingrese la cantidad de datos a generar\n");
	scanf("%d", &cant);
	srand(time(NULL));
	for(i = 1; i <= cant; i++){
		aleatorio = (rand() % (499 + 1)+ 500);
		cola_insertar_nodo(inicial,fin,aleatorio);
	}
}


void ordenar_datos_burbuja(){
    if(inicial != NULL){
		nodo *p = reservar_memoria;
		nodo *j = reservar_memoria;
		int aux;
		p = inicial;
		while(p != NULL){
			j = p -> siguiente;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = p -> dato;
					p -> dato = j -> dato;
					j -> dato = aux;
				}
				j = j -> siguiente;
			}
			p = p -> siguiente;
		}
	}else{
		printf("\nLISTA VACIA\n");
	}
	printf("\nDatos Ordenados.\n");
}

	
void imprimir_datos(nodo *inicial){
	nodo * aux = inicial;
	if(inicial == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d \n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
}

////////////////////////Funciones De colas//////////////////////////////

bool cola_vacia(nodo *inicial){
	
	return (inicial == NULL)? true:false;
}

void cola_insertar_nodo(nodo *&inicial,nodo *&fin,int n){
	nodo *nuevo = new nodo();
	nuevo->dato=n;
	nuevo->siguiente=NULL;
	if(cola_vacia(inicial)){
		inicial=nuevo;
	}else{
		fin->siguiente=nuevo;
	}
	fin = nuevo;
	
	printf("Dato %d fue insertado\n",n);
}

void cola_mostrar(nodo *colas){
	nodo *aux = colas;
	if(cola_vacia(inicial)){
		printf("Cola esta Vacia");
	}else{
		
		while(aux!=NULL){
			
			printf("\n%d",aux->dato);
			aux = aux->siguiente;
		}
		
	}
	
}

void cola_buscar(nodo *colas,int dato){
	nodo *aux = colas;
	int cont=0;
	if(cola_vacia(inicial)){
		printf("Lacola se encuentra vacia");
	}else{
		
		while(aux!=NULL){
			
			if(aux->dato==dato){
				
				cont+=1;
				break;
			}
			aux = aux->siguiente;
		}
		if(cont==0){
			printf(":( lo siento el dato requerido no fue encontrado\n");
		}else{
			printf("El dato fue encontrado con total exito\n");
		}
		
	}
	
}

void cola_modificar_nodo(nodo *&colas, int dato){
	nodo *aux = colas;
	int cont=0,nuevodato;
	if(cola_vacia(inicial)){
		printf("Cola esta Vacia");
	}else{
		
		while(aux!=NULL){
			
			if(aux->dato==dato){
				int h;
				printf("Ingrese el dato nuevo: ");
				scanf("%d",&h);
				nuevodato=h;
				cont+=1;
				aux->dato=nuevodato;
				break;
			}
			aux = aux->siguiente;
		}
		if(cont == 0){
			printf(":( lo siento no encontre el dato a modificar\n");
		}else{
			printf("El dato fue modificado con exito\n");
			//listar_elementos(pilita);
			cola_mostrar(colas);
		}
	}
}

void cola_eliminar_nodo(){	
   int n;
    printf("Ingrese dato a eliminar:\n");
    scanf("%d",&n);
    if(inicial!= NULL){
      nodo *aux_borrar;
      nodo *anterior =NULL;
     aux_borrar = inicial;
 
     while((aux_borrar != NULL) && (aux_borrar ->dato != n)){
     anterior = aux_borrar;
      aux_borrar=aux_borrar->siguiente;
   }
    if(aux_borrar ==NULL){
     printf("El elemento no existe\n");
   }else if(anterior == NULL){
     inicial= inicial->siguiente;
     printf("Elemento %d eliminado \n",n);
      delete aux_borrar;
    }else{
     anterior->siguiente=aux_borrar->siguiente;
    printf("Elemento %d eliminado \n",n);
     delete aux_borrar;
 }
 }
}

void cola_eliminar_completa(nodo *&inicial,nodo *&fin,int &n){
	n=inicial->dato;
	nodo *aux = inicial;
	while(inicial!=NULL){
		if(inicial == fin){
			inicial = NULL;
			fin = NULL;
		}else{
			inicial = inicial -> siguiente;
		}
		delete aux;
	}
}
void salvarElementos(){
 nodo *polo = inicial;
 int dato;
 archivo = fopen("ProyectoII.txt","w");
 while(polo != NULL){
 dato = polo->dato;
 fprintf(archivo, "%d\n", dato);
 polo = polo->siguiente;
 }
 fclose(archivo);
 printf("\nArchivo cargado con Exito.\n");
}

void Cargar(){
 nodo *polo=inicial;
 int dato;
 archivo = fopen("ProyectoII.txt", "r");
 while(!feof(archivo)){
 fscanf(archivo,"%d\n",&dato);
 printf("dato desde archivo %d\n",dato);
 }printf("Cargado con exito\n");
 fclose(archivo);
}


////////////////////////Funciones De pilas//////////////////////////////
void datos_pila(){
	int opcion;
	srand(time(NULL));
	printf("\n ***********Cuantos numeros desea ingresar a la pila***********\n");
	printf("***************************1- 100******************************** \n");
	printf("***************************2- 200******************************** \n");
	printf("***************************3- 300**********************************\n");
	printf("***************************4- 400********************************** \n");
	printf("***************************5- 500********************************** \n\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
	printf("\n");
	switch(opcion){
	case 1:
		tam=100;
		for(int i=0;i<tam;i++){
			num=rand()%1000;
			cargar_Pila();
		}		
		break;
	case 2:
		tam=200;
		for(int i=0;i<tam;i++){
			num=rand()%1000;
			cargar_Pila();
		}
		break;
	case 3:
		tam=300;
		for(int i=0;i<tam;i++){
			num=rand()%1000;
			cargar_Pila();
		}
		break;
	case 4:
		tam=400;
		for(int i=0;i<tam;i++){
			num=rand()%1000;
			cargar_Pila();
		}
		break;
	case 5:
		tam=500;
		for(int i=0;i<tam;i++){
			num=rand()%1000;
			cargar_Pila();
		}
		break;		
	}
}
void cargar_Pila(){	
	Pila *nuevo_nodo= new Pila();
	nuevo_nodo->dato=num;
	nuevo_nodo->siguiente=pilita;
	pilita=nuevo_nodo;	
}
void mostrar_Pila(){
	Pila *Nueva_Pila = pilita;
	if(pilita==NULL){
		printf("\n<<<<<<La pila esta vacia!>>>>>>>\n");
	}else if(Nueva_Pila != NULL){
		while(Nueva_Pila != NULL){
			printf("%d",Nueva_Pila->dato);
			Nueva_Pila = Nueva_Pila->siguiente;
			printf("\n");
		}
	}else{
		printf("%d\n",Nueva_Pila->dato);
	}
	printf("\n");
}
void buscar_Pila(){
	Pila *p=pilita;
	int encontrado=0;
	printf("\n Ingrese el numero que desee buscar en la pila\n");
	scanf("%d",&n);
	for(int i=0;i<tam;i++){
		if(p->dato==n){
			encontrado=1;
		}
		p=p->siguiente;
	}
	if(encontrado==1){
		printf("\nEl Numero se encuentra en la Pila\n\n");
	}else{
		printf("\nEl Numero No se encuentra en la Pila\n\n");
	}
}
void modificar_Pila(){
	Pila *p=pilita;
	int encontrado=0;
	printf("\nIngrese Dato a Modificar:\n");
	scanf("%d",&n);
	for(int i=0;i<tam;i++){
		if(p->dato==n){
			printf("\n Dato Encontrado\n");
			printf("\n Ingrese dato que quiere modificar\n");
			scanf("%d",&p->dato);
			printf("El dato se modifico\n");
			encontrado=1;
		}
		p=p->siguiente;
	}
	if(encontrado==0){
		printf("\nEl Numero NO se encuentra en la pila\n");
	}
}
void eliminar_Pila(){
	printf("\n Ingrese numero que desea eliminar \n");
	scanf("%d",&n);
	if(pilita!=NULL){
		Pila *aux_borrar;
		Pila *anterior=NULL;
		aux_borrar=pilita;
		while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		if(aux_borrar==NULL){
			printf("\n Numero NO encontrado\n\n");
		}else if(anterior==NULL){
			pilita=pilita->siguiente;
			delete aux_borrar;
		}else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
	printf("\nDato Eliminado.\n\n");
}
void eliminar_completa_Pila(){
	while(pilita!=NULL){
		Pila *aux=pilita;
		pilita=aux->siguiente;
		printf("\nBorrando el dato %d\n",aux->dato);
		delete aux; 
	}	
}
void insertar_Pila_archivo(){
	Pila *polo = pilita;
	int dato;
	archivo = fopen("ProyectoII.txt", "w");
	while(polo != NULL){
		dato= polo->dato;
		fprintf(archivo, "%d\n",dato);
		polo = polo->siguiente;
	}
	fclose(archivo);
	printf("Archivo cargado con Exito\n\n");
}
void mostrar_Pila_archivo(){
	int dato;
	archivo = fopen("ProyectoII.txt", "r");
	printf("\nMostrando datos desde el Archivo.\n");
	while(!feof(archivo)){
		fscanf(archivo,"%d\n",&dato);
		printf("%d\n",dato);
		cargar_Pila();
	}
	fclose(archivo);
}
void ordenar_Pila_burbuja(){
	Pila *p=pilita;
	Pila *j;
	while(p!=NULL){
		j=p->siguiente;
		while(j!=NULL){
			if(p->dato > j->dato){
				int aux=j->dato;
				j->dato=p->dato;
				p->dato=aux;
			}
			j=j->siguiente;
		}
		p=p->siguiente;
	}
	printf("\nLos datos se han ordenado.\n\n");
}
