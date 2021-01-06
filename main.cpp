#include <iostream>
#include <fstream>
using namespace std;

//Estructura que almacena en memória dinámica el contenido de cada una de las líneas del CSV
struct nodo{
    string provincia;
    string municipio;
    string localidad;
    int codigoPostal;
    string direccion;
    string margen;
    float longitud;
    float latitud;
    float precio95E5;
    float precio95E10;
    float precio95E5Premium;
    float precio98E5;
    float precio98E10;
    float precioGaseleoA;
    float precioGasoleoPremium;
    float precioGasoleoB;
    float precioGasoleoC;
    float precioBioetanol;
    float bioalcohol;
    float precioBiodiesel;
    float estermetilico;
    float precioGasesLicuados;
    float precioGasNaturalComprimido;
    float precioGasNaturalLicuado;
    float precioHidrogeno;
    string rotulo;
    string tipoVenta;
    string rem; //Creo que esto es el tipo de distribuidor
    string horario;
    string tipoServicio;

    nodo *sgt;
};
nodo *head=NULL, *final=NULL, *a=NULL;   //Declaramos el head, final y

//Dejamos este espacio para declarar las funciones
void add(nodo *a);
//Declaramos las funciones a continuación:

//Le pasamos el nodo que queremos añadir a la lista
void add(nodo *a){
    if(head==NULL && final==NULL){  //Si la lista está vacía
        head=a;
        final=a;
    }
    else{   //Si la lista contiene al menos un elemento
        final->sgt=a;
        final=a;
    }
}

void eQ(string provincia,string municipio,string localidad,int c,string direccion,string margen,float longitud,float latitud,float precio95E5
        ,float precio95E10,float precio95E5Premium,float precio98E5,float precio98E10,float precioGaseleoA, float precioGasoleoPremium, float precioGasoleoB,
        float precioGasoleoC, float precioBioetanol, float bioalcohol, float precioBiodiesel, float estermetilico, float precioGasesLicuados, float precioGasNaturalComprimido,
        float precioGasNaturalLicuado, float precioHidrogeno, string rotulo, string tipoVenta, string rem, string horario, string tipoServicio){
    nodo *actual = new nodo;
    actual->provincia=provincia;actual->municipio=municipio;actual->localidad=localidad;actual->direccion=direccion;actual->margen=margen;actual->longitud=longitud;
    actual->latitud=latitud;actual->precio95E5=precio95E5;actual->precio95E10=precio95E10;actual->precio95E5Premium=precio95E5Premium;actual->precio98E5=precio98E5;
    actual->precio98E10=precio98E10;actual->precioGaseleoA=precioGaseleoA;actual->precioGasoleoPremium=precioGasoleoPremium;actual->precioGasoleoB=precioGasoleoB;
    actual->precioGasoleoC=precioGasoleoC;actual->precioBioetanol=precioBioetanol;actual->bioalcohol=bioalcohol;actual->precioBiodiesel=precioBiodiesel;
    actual->estermetilico=estermetilico;actual->precioGasesLicuados=precioGasesLicuados;actual->precioGasNaturalComprimido=precioGasNaturalComprimido;
    actual->precioGasNaturalLicuado=precioGasNaturalLicuado;actual->precioHidrogeno=precioHidrogeno;actual->rotulo=rotulo;actual->tipoVenta=tipoVenta;actual->rem=rem;
    actual->horario=horario;actual->tipoServicio=tipoServicio;
    if(final==NULL){
        actual->sgt=NULL;
        final=actual;head=final;
    }else{
        final->sgt=actual;
        actual->sgt=NULL;
        final=actual;
    }
}

int main() {
    string provincia;
    string municipio;
    string localidad;
    int codigoPostal;
    string direccion;
    string margen;
    float longitud;
    float latitud;
    float precio95E5;
    float precio95E10;
    float precio95E5Premium;
    float precio98E5;
    float precio98E10;
    float precioGaseleoA;
    float precioGasoleoPremium;
    float precioGasoleoB;
    float precioGasoleoC;
    float precioBioetanol;
    float bioalcohol;
    float precioBiodiesel;
    float estermetilico;
    float precioGasesLicuados;
    float precioGasNaturalComprimido;
    float precioGasNaturalLicuado;
    float precioHidrogeno;
    string rotulo;
    string tipoVenta;
    string rem; //Creo que esto es el tipo de distribuidor
    string horario;
    string tipoServicio;

    ifstream fin("../Dataset.tsv");//Declaramos fin como variable de entrada
    ofstream fout("../resultadoAct.tsv");//Declaramos fin como variable de entrada


    try{ // Declaro inicio del bloque que pudiese generar alguna excepcion

        fin>>provincia;


        while(!fin.eof()){

            //Definimos el orden en el que se seguirá la estructura
            fin >> municipio>> localidad>> codigoPostal>> direccion>> margen>> longitud>> latitud>> precio95E5>>
                precio95E10>> precio95E5Premium>> precio98E5>> precio98E10>> precioGaseleoA>> precioGasoleoPremium>>
                precioGasoleoB>> precioGasoleoC>> precioBioetanol>> bioalcohol>> precioBiodiesel>> estermetilico>>
                precioGasesLicuados>> precioGasNaturalComprimido>> precioGasNaturalLicuado>> precioHidrogeno>> rotulo>>
                tipoVenta>> rem>> horario>> tipoServicio;

            eQ(provincia,municipio,localidad,codigoPostal,direccion,margen,longitud,latitud,precio95E5,precio95E10,precio95E5Premium,
               precio98E5,precio98E10,precioGaseleoA,precioGasoleoPremium,precioGasoleoB,precioGasoleoC,precioBioetanol,bioalcohol,precioBiodiesel,
               estermetilico,precioGasesLicuados,precioGasNaturalComprimido,precioGasNaturalLicuado,precioHidrogeno,rotulo,tipoVenta,rem,
               horario,tipoServicio);
            fin>>tipoServicio;
        }
        //Esto es de otro proyecto y lo dejo aquí para que mas o menos sepais donde ponerlo
        masViejo("../resultadoAct.tsv");
        cout<<endl;
        cumpleanero("../resultadoAct.tsv");
        cout<<endl;
        expImpar("../resultadoAct.tsv");
        cout<<endl;
        expPar("../resultadoAct.tsv");
        cout<<endl;
        porcA1("../resultadoAct.tsv");
        cout<<endl;
        asistentesPresenciales("../resultadoAct.tsv");
        cout<<endl;
        asistentesOnline("../resultadoAct.tsv");
        cout<<endl;
    }
    //Cerramos archivo .tsv
    catch(...){//Captura todas las excepciones posibles para no romper el program de forma descontrolada.
        fin.close();
    }
}
