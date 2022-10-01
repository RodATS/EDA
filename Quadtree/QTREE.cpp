#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int R[4][4];
int G[4][4];
int B[4][4];

void Update(int x, int y, int x_fin, int y_fin, int *RR, int *GG, int *BB, int promR, int promG, int promB){
  int factor=15;
  if(*RR>factor){
    for(int i=x;i<x_fin;i++){
    for(int j=y;j<y_fin;j++){
      R[i][j]=promR;
    }
  }
  }
  if(*GG>factor){
    for(int i=x;i<x_fin;i++){
    for(int j=y;j<y_fin;j++){
      G[i][j]=promG;
    }
  }
  }
  if(*BB>factor){
    for(int i=x;i<x_fin;i++){
    for(int j=y;j<y_fin;j++){
      B[i][j]=promB;
    }
  }
  }
  
}
//------------------------------------------



void Promedio(int x, int y, int x_fin, int y_fin, int *RR, int *GG, int *BB){
  int suR=0,suG=0,suB=0,n=pow((x_fin-x),2);
  for(int i=x;i<x_fin;i++){
    for(int j=y;j<y_fin;j++){
      suR+=R[i][j];
      suG+=R[i][j];
      suB+=R[i][j];
    }
  }
  *RR=suR/n;
  *GG=suG/n;
  *BB=suB/n;
}

void Desv_est(int x, int y, int x_fin, int y_fin, int *RR, int *GG, int *BB)
{
  int N=pow((x_fin-x),2);
  int sumatR=0,sumatG=0,sumatB=0;
  for(int i=x;i<x_fin;i++){
    for(int j=y;j<y_fin;j++){
      sumatR+=pow(R[i][j]-*RR,2);
      sumatG+=pow(G[i][j]-*GG,2);
      sumatB+=pow(B[i][j]-*BB,2);
    }
  }
  *RR=sqrt(sumatR/N);*GG=sqrt(sumatG/N);*BB=sqrt(sumatB/N);
}

void Agrupar(int tam){
  int quad1x=0,quad1y=0,
  quad2x=0,quad2y=tam/2,
  quad3x=tam/2,quad3y=0,
  quad4x=tam/2,quad4y=tam/2;
  
  int Rquad1,Gquad1,Bquad1,
  Rquad2,Gquad2,Bquad2,
  Rquad3,Gquad3,Bquad3,
  Rquad4,Gquad4,Bquad4;

  //1er cuadrante
  Promedio(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1);
  //2do cuadrante
  Promedio(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2);
    //3er cuadrante
  Promedio(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3);
  //4to cuadrante
  Promedio(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4);

  int Rp1=Rquad1,Gp1=Gquad1,Bp1=Bquad1,
  Rp2=Rquad2,Gp2=Gquad2,Bp2=Bquad2,
  Rp3=Rquad3,Gp3=Gquad3,Bp3=Bquad3,
  Rp4=Rquad4,Gp4=Gquad4,Bp4=Bquad4;

  //----
//1er cuadrante
  Desv_est(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1);
  //2do cuadrante
  Desv_est(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2);
  //3er cuadrante
  Desv_est(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3);
   //4to cuadrante
  Desv_est(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4);

  cout<<"\nDesviacion:\n";
  cout<<"quad1:\t"<<Rquad1<<", "<<Gquad1<<", "<<Bquad1<<endl;
  cout<<"quad2:\t"<<Rquad2<<", "<<Gquad2<<", "<<Bquad2<<endl;
  cout<<"quad3:\t"<<Rquad3<<", "<<Gquad3<<", "<<Bquad3<<endl;
  cout<<"quad4:\t"<<Rquad4<<", "<<Gquad4<<", "<<Bquad4<<endl<<endl;
    //----
//1er cuadrante
  Update(quad1x,quad1y,quad3x,quad2y,&Rquad1,&Gquad1,&Bquad1,Rp1,Gp1,Bp1);
  //2do cuadrante
  Update(quad2x,quad2y,quad4x,tam,&Rquad2,&Gquad2,&Bquad2,Rp2,Gp2,Bp2);
  //3er cuadrante
  Update(quad3x,quad3y,tam,quad4y,&Rquad3,&Gquad3,&Bquad3,Rp3,Gp3,Bp3);
   //4to cuadrante
  Update(quad4x,quad4y,tam,tam,&Rquad4,&Gquad4,&Bquad4,Rp4,Gp4,Bp4);

  
}

//---------------------------------------
void Print( int tam){
  cout<<"R:\n";
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      cout<<R[i][j]<<"\t";
    }
    cout<<endl;
  }
cout<<"G:\n";
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      cout<<G[i][j]<<"\t";
    }
    cout<<endl;
  }
cout<<"B:\n";
  for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
      cout<<B[i][j]<<"\t";
    }
    cout<<endl;
  }
}

//------------------------------------
int main(){
  int t=4,l=50;
  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++,l++){
      R[i][j]=l;
    }
  }

  for(int i=0;i<t;i++,l=l/2){
    for(int j=0;j<t;j++,l++){
      G[i][j]=l;
    }
  }

  for(int i=0;i<t;i++){
    for(int j=0;j<t;j++,l++){
      B[i][j]=l;
    }
  }
 Print(t);
  Agrupar(t);
 Print(t);

  
}
