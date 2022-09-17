#include <iostream>
using namespace std;

void swapp_char(unsigned char &tmp, unsigned char *data, int j){
  tmp = data[j];
  data[j] = data[j+2];
  data[j+2] = tmp;
}


unsigned char* LeerBMP(char* filename)
{
    //Abrir el archivo
    FILE* f = fopen(filename, "rb");

    if(f == NULL)
        throw "Argument Exception";

    //Leemos el archivo y alamacenamos los headers del bitmap
    unsigned char info[54];//windows bitmap
    fread(info, sizeof(unsigned char), 54, f);

    // extraer la altura y ancho header BMP
    int height = *(int*)&info[22];
    int width = *(int*)&info[18];

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
}
