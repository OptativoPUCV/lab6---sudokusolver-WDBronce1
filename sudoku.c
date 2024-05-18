#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct
{
   int sudo[9][9];
}Node;



Node* createNode()
{
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n)
{
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name)
{
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++)
  {
       for(j=0;j<9;j++)
       {
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n)
{
    int i,j;
    for(i=0;i<9;i++)
    {
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

/*2.Cree la función int is_valid(Node * n), para validar si un estado/nodo es válido (cumple con las restricciones del problema). Debe validar que:

No se repitan números en las filas
No se repitan números en las columnas
No se repitan números en las submatrices de 3x3
Si el estado es válido la función retorna 1, si no lo es retorna 0.
*/
int is_valid(Node* n)
{
   
   int i, j, numSub, k;
   int mapFila[9][9] = {};
   int mapCol[9][9] = {};
   int *submatriz;

   for (numSub = 0; numSub < 9; numSub++) 
   {
      submatriz = calloc(9, sizeof(int));                                  
      for (k = 0; k < 9; k++)             
      {
         i = 3 * (numSub / 3) + (k / 3);
         j = 3 * (numSub % 3) + (k % 3); 
         
         int dato = n->sudo[i][j];
         if (dato == 0)
         {
            continue;
         }

         if (mapFila[i][dato - 1] == 1) 
         {
            return 0;
         }
         else
         {
            mapFila[i][dato - 1] = 1;
         }
         if (mapCol[dato - 1][j] == 1)
         {
            return 0;
         }
         else
         {
            mapCol[dato - 1][j] = 1;
         }

         if (submatriz[dato - 1] == 1)
         {
            return 0;
         }   
         else
         {
            submatriz[dato - 1] = 1;
         }
       }
       free(submatriz);
   }
     return 1;
}

//1.Cree una función que a partir de un nodo genere una lista con los nodos adyacentes
//3.Modifique la función get_adj_nodes para que sólo los nodos válidos sean retornados (use la función is_valid).
List* get_adj_nodes(Node* n)
{
   List* list=createList();
   int k,j;
   for(k = 0 ; k < 8 ; k++)
   {   
      for(j = 0 ; j < 8 ; j++)
      {
         if (n->sudo[k][j] == 0)
         {
             for(int i = 1 ; i < 10 ; i++)
               {
                  Node *New = copy(n);
                  New->sudo[k][j] = i;
                  if(is_valid(New) == 1)
                  {
                     pushBack(list, New);
                  }
                  else
                  {
                     free(New);
                  }
               }
         }
      }
   }
  
   
   return list;
}

//4.Implemente la función int is_final(Node * n). Esta función retorna 1 si el nodo corresponde a un nodo final (es decir, todos los valores de la matriz son distintos a 0) y 0 en caso contrario.
int is_final(Node* n)
{
   int i,j;
   for(i = 0 ; i < 8 ; i++)
   {
      for(j = 0 ; j < 8 ; j++)
      {
         if (n->sudo[i][j] == 0)
         {
             return 0;
         }
      }
   }
    return 1;
}

/*
5.Implemente la función Node* DFS(Node* n, int* cont). Esta función realiza una búsqueda en profundidad a partir del nodo n. El algoritmo es el siguiente:

Cree un stack S (pila) e inserte el nodo.

Mientras el stack S no se encuentre vacío:

a) Saque y elimine el primer nodo de S.

b) Verifique si corresponde a un estado final, si es así retorne el nodo.

c) Obtenga la lista de nodos adyacentes al nodo.

d) Agregue los nodos de la lista (uno por uno) al stack S.

e) Libere la memoria usada por el nodo.

Si terminó de recorre el grafo sin encontrar una solución, retorne NULL.
*/
Node* DFS(Node* initial, int* cont)
{
   Stack* pila = createStack();
   push(pila, initial);

   
   return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/