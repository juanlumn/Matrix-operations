#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

//Clase Matriz
class Matriz{
protected:
    int **M;
    int NF,NC;
public:
    //Default constructor
    Matriz(){
        M=NULL;
        NF=0;
        NC=0;
        return;
    }
    //Copy constructor
    Matriz(const Matriz &orig){
        for (int i=0;i<NF;i++){
            for (int j=0;j<NC;j++)M[i][j]=orig.M[i][j];
        }
        return;
    }
    //Input constructor
    Matriz(int filas, int columnas){
        NF=filas;
        NC=columnas;
        for (int i=0;i<NF;i++){
            for (int j=0;j<NC;j++)M[i][j]=(rand() % 20);
        }
        return;
    }
    //Destructor
    ~Matriz(){
        if (M) delete M;
        return;
    }
    //Equal operator
    Matriz operator=(Matriz m){
        for (int i=0;i<NF;i++){
            for (int j=0;j<NC;j++)M[i][j]=m.M[i][j];
        }
        return(*this);
    }
    //Output's operator
    friend ostream& operator << (ostream &medio, Matriz m){
        for (int i=0;i<m.NF;i++){
            for (int j=0;j<m.NC;j++){ medio<<m.M[i][j]<<" ";}
            medio<<endl;
        }
        return(medio);
    }
    //Checks if the operation is possible
    bool comprobar(int NF1,int NC1,int NF2,int NC2,bool centinela){
        if (centinela==true){
            if (NF1==NC2 && NC1==NF2)return (true);
        }
        else{
            if (NF1==NF2 && NC1==NC2)return (true);
        }
        return(false);
    }
    
    //Matrix Addition's operator
    Matriz operator + (Matriz m){
        Matriz resultado;  
        if (resultado.comprobar(NF,NC,m.NF,m.NC,false)){
            for (int i=0;i<m.NF;i++){
                for (int j=0;j<m.NC;j++)resultado.M[i][j]=M[i][j]+m.M[i][j];
            }
        }
        return (resultado);
    }
    //Matrix Substraction's operator
    Matriz operator - (Matriz m){
        Matriz resultado;
        if (resultado.comprobar(NF,NC,m.NF,m.NC,false)){
            for (int i=0;i<m.NF;i++){
                for (int j=0;j<m.NC;j++)resultado.M[i][j]=M[i][j]-m.M[i][j];
            }
        }
        return (resultado);
    }
    //Matrix Multiplication's Operator
    Matriz operator * (Matriz m){
        Matriz resultado(NF,m.NC);
        if (resultado.comprobar(NF,NC,m.NF,m.NC,true)){
            for(int i=0;i<NF;i++){
                for(int j=0;j<NC;j++){
                    resultado.M[i][j]=0;
                    for(int k=0;k<NC;k++)resultado.M[i][j]=(resultado.M[i][j]+(M[i][k] * m.M[k][j]));
                }
            }
        }
        return resultado;
    }
    
};

class MatrizD:public Matriz{
    
    //Input constructor
    MatrizD(int N){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (i==j)M[i][j]=(rand() % 20);
            }
        }
        return;
    }
    //Addition's operator
    MatrizD operator + (MatrizD m){
        Matriz::operator + (m);
        return (*this);
    }
    //Subtraction's operator
    MatrizD operator - (MatrizD m){
        Matriz::operator - (m);
        return (*this);
    }
    //Multiplication's operator
    MatrizD operator * (MatrizD m){
        Matriz::operator * (m);
        return (*this);
    }
};

int main(void)
{
    return (0);
}
