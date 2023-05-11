#include<stdio.h>
#include<string.h>
typedef struct{
    char cadena[30];
    int vocales;
} cadenas;
int vocals(char);
int main(){
    int n, i, j, c, maximo, imaximo, contador=0;
    FILE *ap;
    ap=fopen("resultado.txt", "w");
    if(ap==NULL){
        printf("Todo lo que pudo salir mal, salio mal");
        return -1;
    }
    printf("Cuantas cadenas vas a ingresar? ");
    scanf("%d", &n);
    cadenas cantidad[n];
    for(i=0;i<n;i++){
        printf("Ingrese la cadena numero %d: ", i+1);
        fflush(stdin);
        gets(cantidad[i].cadena);
    }
    for(i=0;i<n;i++){
        c=strlen(cantidad[i].cadena);
        for(j=0;j<c;j++){
            if(vocals(cantidad[i].cadena[j])==1)
                contador++;
        }
        cantidad[i].vocales=contador;
        contador=0;
    }
    for(i=0;i<n;i++){
        if (cantidad[i].vocales>maximo)
            imaximo=i;
    }
    printf("La cadena (%s) tiene %d vocales siendo asi la que mas vocales tiene de las %d cadenas ingresadas", cantidad[imaximo].cadena, cantidad[imaximo].vocales, n);
    fprintf(ap, "La cadena (%s) tiene %d vocales siendo asi la que mas vocales tiene de las %d cadenas ingresadas\n", cantidad[imaximo].cadena, cantidad[imaximo].vocales, n);
    fclose(ap);
    return 0;
}
int vocals(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U'){
        return 1;
    }
    else
        return 0;
}
