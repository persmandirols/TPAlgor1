#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXTITULO 30
#define MAXDISCOS 500
#define MAXCODIGO 8001
#define MINCODIGO 1000
#define MINPRECIO 1

#define MINTRACK 1
#define MAXTRACK 25

typedef struct t_discos{

     int codigo;
     char titulo[MAXTITULO];
     short cant_track;  
	 float precio;

} t_discos;

typedef t_discos t_cant_discos[MAXDISCOS];

int main()
{
     /*prototipos*/
     void cargar_datos(t_cant_discos,int *);
     void mostrar(t_cant_discos,int);
     void mostrar_datos(t_cant_discos ,int );
     void ordenar_datos(t_cant_discos ,int );
     void mostrar_discos_precio_min(t_cant_discos,int);
     void mostrar_discos_precio_max(t_cant_discos,int);
     void mostrar_ordenado_codigo(t_cant_discos ,int );
     void mostrar_promedio_p(t_cant_discos ,int );
	 /*variables*/
     
	 int max_logico;
     t_cant_discos discos;
	 
	
     
	 /*Punto A*/
     cargar_datos(discos,&max_logico);
     
     ordenar_datos(discos, max_logico);/*Esto es para el punto B*/
     
     
     
     /*Punto B*/

     mostrar_promedio_p(discos,max_logico);
     
     
     mostrar_discos_precio_min(discos,max_logico);
     
     mostrar_discos_precio_max(discos,max_logico);
     
     
     /*Punto C*/
	 mostrar_ordenado_codigo(discos,max_logico);
	 
     

     printf("valor maxlogico %d", max_logico );

    return 0;
}
/*funciones*/
void cargar_datos(t_cant_discos discos,int *max_logico)
{
     int i,j,codigo,cant_track,cod_repetido;
     float precio;
     char titulo[MAXTITULO];

     i=0;
     codigo=0;
     cod_repetido=0;
     
	 printf("Punto A\n");
     printf("La carga finaliza al ingresar 9999 como codigo \n");
     printf("Ingrese codigo: ");
     scanf("%d",&codigo);
     
     while(((codigo!=9999)&&(i<MAXDISCOS))){
     if((codigo>MINCODIGO)&&(codigo<MAXCODIGO)){
     discos[i].codigo=codigo;
     /*TITULO*/

     printf("ingrese el titulo ");
     fflush(stdin);
     scanf("%[^\n]s",titulo);
     strcpy(discos[i].titulo,titulo);

     /*TRACKS*/
     printf("ingrese cantidad  tracks ");
     scanf("%d",&cant_track);
     while((cant_track<MINTRACK)||(cant_track>MAXTRACK)){

          printf("La cantidad de tracks debe estar entre %d y %d  vuelva a intentarlo :",MINTRACK,MAXTRACK);
          scanf("%d",&cant_track);
     }
     discos[i].cant_track=cant_track;

     /*PRECIO*/

     printf("ingrese precio ");
     scanf("%f",&precio);

     while(precio<1){
          printf("El precio debe ser mayor a %d ingrese precio mayor a %d ",MINPRECIO,MINPRECIO);
          scanf("%f",&precio);
     }
     discos[i].precio=precio;
     

     i++;
     
     printf("---nueva carga--- \n");

     printf("Ingrese codigo: ");
     scanf("%d",&codigo);
     
     /*Al ingresar mas de una vez un codigo aumenta un contador*/
     for(j=0;j<*max_logico;j++)
     {
     	if(codigo==(discos[j].codigo))
     	{
     		cod_repetido++;
     		printf("Cofigo repetido ---\n");
		 }
     	
	 }

     }/*fin del if*/
     else
     {printf("codigo no valido, DEBE SER UN VALOR ENTRE %d y %d  intente otra vez ",MINCODIGO,MAXCODIGO);
     scanf("%d",&codigo);
     }
     }/*fin while*/
          *max_logico=i-cod_repetido;



}/*fin funcion*/
void mostrar_disco(t_cant_discos discos ,int n)
{
/*muestra todos los datos del disco que se le pasa por parametro */

printf("codigo: %d \n",discos[n].codigo);
printf("titulo: %s \n",discos[n].titulo);
printf("cantidad e track: %d \n",discos[n].cant_track);
printf("precio: %f \n\n",discos[n].precio);

}
void mostrar(t_cant_discos discos ,int max_logico)
{/*muestra todos los datos de todos los discos ingresados*/
int i;
for(i=0;i<max_logico;i++){
	mostrar_disco(discos,i);
}
}

void mostrar_promedio_p(t_cant_discos discos,int max_logico)
{
/*Mostrar el precio promedio */
printf("\nPunto B\n");
float acumulador_precio=0;
float precio_promedio;
int i;
for(i=0;i<max_logico;i++)
{
	acumulador_precio=acumulador_precio+discos[i].precio;
		
}
 		precio_promedio=acumulador_precio/max_logico;

 		printf("el precio promedio es:%f  \n",precio_promedio);


}
void ordenar_datos(t_cant_discos discos,int max_logico)
{	/*ordena ascendente por precio pero es burbuja simple*/
	/*printf("ordena ascendente por precio\n");*/

	int i,j,cambio;
	cambio=1;
	t_discos aux;
	for(i=0;i<max_logico;i++)
	{
		
		for(j=0;j<max_logico-1;j++)
		{
			
			if(discos[j].precio>discos[j+1].precio)
			{
				cambio=1;
				aux=discos[j];
				discos[j]=discos[j+1];
				discos[j+1]=aux;
			}
		}
	
	}
	
	
}
     
void mostrar_discos_precio_min(t_cant_discos discos,int max_logico)
{	int i;
	printf("discos con precio miinmo \n");
	for(i=0;i<max_logico;i++)
	{
		if(discos[i].precio==discos[0].precio)
		{
			mostrar_disco(discos,i);
					
			
		}
		
	}
	
}
void mostrar_discos_precio_max(t_cant_discos discos,int max_logico)
{	int i;
	printf("discos con precio maximo \n");
	for(i=0;i<max_logico;i++)
	{
		if(discos[i].precio==discos[max_logico-1].precio)
		{
			mostrar_disco(discos,i);
					
			
		}
		
	}
	
}
     
void mostrar_ordenado_codigo(t_cant_discos discos,int max_logico){
	printf("\nPunto C ordena ascendente por codigo\n");

	int i,j,cambio;
	cambio=1;
	t_discos aux;
	/*Los ordena por codigo ascendente burbuja simple*/
	for(i=0;i<max_logico;i++)
	{
		
		for(j=0;j<max_logico-1;j++)
		{
			
			if(discos[j].codigo>discos[j+1].codigo)
			{
				cambio=1;
				aux=discos[j];
				discos[j]=discos[j+1];
				discos[j+1]=aux;
			}
		}
	
	}
	
	/*Los muestra*/
	for(i=0;i<max_logico;i++)
	{
		mostrar_disco(discos,i);
		
	}
}
