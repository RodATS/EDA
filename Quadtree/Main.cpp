#include <iostream>
#include "BMP.h"
#include "Qtree.h"
using namespace std;


void swapp_char(unsigned char &tmp, unsigned char *data, int j){
  tmp = data[j];
  data[j] = data[j+2];
  data[j+2] = tmp;
}


unsigned char* LeerBMP(char* filename)
{
    FILE* f = fopen(filename, "rb");

    if(f == NULL)
        throw "Argument Exception";

    unsigned char info[54];//windows bitmap
    fread(info, sizeof(unsigned char), 54, f);

    // extraer la altura y ancho header BMP
    int height = *(int*)&info[22];
    int width = *(int*)&info[18];
    cout << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    
    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            // Lo invierte por la forma de leerlo (B, G, R) a (R, G, B)
          swapp_char(tmp,data,j);

            cout << "R: "<< (int)data[j] << " G: " <<(int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
        }
    }

    fclose(f);
    return data;
}

int main() {
  char* nombre="imagen_prueba.bmp";
   LeerBMP(nombre);


  // Create a 24 bits/pixel BMP image in memory, modify it, save it on disk
	BMP bmp3(200, 200, false);
	bmp3.fill_region(50, 20, 100, 100, 255, 0, 255, 255);
	bmp3.write("img_test_24bits01.bmp");
  char a[2]={'5','6'};
 //cout<<(int)a[1]<<endl;
}
