#ifndef QTREE_H_
#define QTREE_H_

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void Update(vector<vector<int>> *mapa, int pos_ini_x,int pos_ini_y,int pos_fin_x,int pos_fin_y, int dato){
  for(int i=pos_ini_x;i<pos_fin_x;i++){
    for(int j=pos_ini_y;j<pos_fin_y;j++){
      (*mapa)[i][j]=dato;
    }
  }
}

void Agrupar(vector<vector<int>> *mapa){
  int quad1,quad2,quad3,quad4;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      quad1+=(*mapa)[i][j];
    }
  }

  for(int i=8;i<16;i++){
    for(int j=0;j<8;j++){
      quad2+=(*mapa)[i][j];
    }
  }

  for(int i=0;i<8;i++){
    for(int j=8;j<16;j++){
      quad3+=(*mapa)[i][j];
    }
  }

  for(int i=8;i<16;i++){
    for(int j=8;j<16;j++){
      quad4+=(*mapa)[i][j];
    }
  }
  //cout<<quad1<<"\t"<<quad2<<"\t"<<quad3<<"\t"<<quad4<<endl;
  quad1=quad1/64;  quad2=quad2/64; quad3=quad3/64; quad4=quad4/64;
  
  Update(mapa,0,0,8,8,quad1);
  Update(mapa,8,0,16,8,quad2);
  Update(mapa,0,8,8,16,quad3);
  Update(mapa,8,8,16,16,quad4);
}

void Print(vector<vector<int>> mapa){
  for(int i=0;i<16;i++){
    for(int j=0;j<16;j++){
      cout<<mapa[i][j]<<"\t";
    }
    cout<<endl;
  }
}



//----------------------------------------
// Used to hold details of a point
struct Point {
	int x;
	int y;
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Point()
	{
		x = 0;
		y = 0;
	}
};

// The objects that we want stored in the quadtree
struct Node {
	Point pos;
	//int data[3]={0,0,0}; //RGB
  int data;
	Node(Point _pos, int _data=0)
	{
		pos = _pos;
		data=_data;
	}

  Node(){
    pos.x = 0;
    pos.y=0;
    data=0;
  }
};

// The main quadtree class
class Quad {
	// Hold details of the boundary of this node
public:
	Point topLeft;
	Point botRight;

	// Contains details of node
	Node* n;

	// Children of this tree
	Quad* topLeftTree;
	Quad* topRightTree;
	Quad* botLeftTree;
	Quad* botRightTree;

public:
	Quad()
	{
		topLeft = Point(0, 0);
		botRight = Point(0, 0);
		n = NULL;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
	}
	Quad(Point topL, Point botR)
	{
		n = NULL;
		topLeftTree = NULL;
		topRightTree = NULL;
		botLeftTree = NULL;
		botRightTree = NULL;
		topLeft = topL;
		botRight = botR;
	}
	void Agregar(Node*);
	Node* Buscar(Point);
	bool EnRango(Point);
  vector<vector<int>> Imprimir();
};

// Insert a node into the quadtree
void Quad::Agregar(Node* node)
{
	if (node == NULL)
		return;

	// Current quad cannot contain it
	if (!EnRango(node->pos))
		return;

	// We are at a quad of unit area
	// We cannot subdivide this quad further
	if (abs(topLeft.x - botRight.x) <= 1
		&& abs(topLeft.y - botRight.y) <= 1) {
		if (n == NULL)
			n = node;
		return;
	}

	if ((topLeft.x + botRight.x) / 2 >= node->pos.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topLeftTree == NULL)
				topLeftTree = new Quad(
					Point(topLeft.x, topLeft.y),
					Point((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2));
			topLeftTree->Agregar(node);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				botLeftTree = new Quad(
					Point(topLeft.x,
						(topLeft.y + botRight.y) / 2),
					Point((topLeft.x + botRight.x) / 2,
						botRight.y));
			botLeftTree->Agregar(node);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 >= node->pos.y) {
			if (topRightTree == NULL)
				topRightTree = new Quad(
					Point((topLeft.x + botRight.x) / 2,
						topLeft.y),
					Point(botRight.x,
						(topLeft.y + botRight.y) / 2));
			topRightTree->Agregar(node);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				botRightTree = new Quad(
					Point((topLeft.x + botRight.x) / 2,
						(topLeft.y + botRight.y) / 2),
					Point(botRight.x, botRight.y));
			botRightTree->Agregar(node);
		}
	}
}

// Find a node in a quadtree
Node* Quad::Buscar(Point p)
{
	// Esta dentro de los limites del quadtree
	if (!EnRango(p))
		return NULL;

	// We are at a quad of unit length
	// We cannot subdivide this quad further
	if (n != NULL)
		return n;

  //divide y busca
	if ((topLeft.x + botRight.x) / 2 >= p.x) {
		// Indicates topLeftTree
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topLeftTree == NULL)
				return NULL;
			return topLeftTree->Buscar(p);
		}

		// Indicates botLeftTree
		else {
			if (botLeftTree == NULL)
				return NULL;
			return botLeftTree->Buscar(p);
		}
	}
	else {
		// Indicates topRightTree
		if ((topLeft.y + botRight.y) / 2 >= p.y) {
			if (topRightTree == NULL)
				return NULL;
			return topRightTree->Buscar(p);
		}

		// Indicates botRightTree
		else {
			if (botRightTree == NULL)
				return NULL;
			return botRightTree->Buscar(p);
		}
	}
};


// Check if current quadtree contains the point
//revisar si el punto se encuentra dentro del Quadtree
bool Quad::EnRango(Point p)
{
	return (p.x >= topLeft.x && p.x <= botRight.x
			&& p.y >= topLeft.y && p.y <= botRight.y);
}

vector<vector<int>> Quad::Imprimir(){
  vector<vector<int>> mapax(16);
  for(int i=0;i<=botRight.x;i++){
    vector<int> aux(16);
    for(int j=0;j<=botRight.y;j++){
      if(Buscar(Point(i,j))!=NULL){
        //cout<<Buscar(Point(i,j))->data<<"\t";
          aux[j]=Buscar(Point(i,j))->data;
        }
      //else {cout<<0<<"\t"; 
      aux[j]=0;
        }
    mapax[i]=aux;
    }
    
    //cout<<endl;
  return mapax;
}

// Driver program


#endif 
