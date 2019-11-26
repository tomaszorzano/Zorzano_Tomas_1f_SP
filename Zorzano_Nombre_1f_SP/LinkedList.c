#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eComputer.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}



/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int sizeList = ll_len(this);

    if(this != NULL)
    {
        if(nodeIndex >=0 && nodeIndex < sizeList)
        {
           // pNode = (Node*)malloc(sizeof(Node));

            for(int i = 0;i <= nodeIndex;i++)
            {
                if(i == 0)
                {
                    pNode = this->pFirstNode;
                }
                else if(pNode == NULL)
                {
                    pNode = this->pFirstNode;
                }
                else
                {
                    pNode = pNode->pNextNode;
                }
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;
    Node* pNextNode;
    Node* pPreviousNode;
    int sizeList = ll_len(this);

    if(this != NULL)
    {
        pNewNode = (Node*)malloc(sizeof(Node));
        pNextNode = (Node*)malloc(sizeof(Node));
        pPreviousNode = (Node*)malloc(sizeof(Node));

        if(nodeIndex == 0)/** Si es el primero **/
        {
            if(sizeList == 0)
            {
                pNewNode->pElement = pElement;
                pNewNode->pNextNode = NULL;
            }
            else
            {
                pNextNode = this->pFirstNode;
                pNewNode->pElement = pElement;
                pNewNode->pNextNode = pNextNode;
            }
            this->pFirstNode = pNewNode;
        }
        else/** Si es el ultimo **/
        {
            pNextNode = getNode(this, nodeIndex+1);
            pPreviousNode = getNode(this, nodeIndex-1);
            if(sizeList == nodeIndex)
            {
                pNewNode->pElement = pElement;
                pNewNode->pNextNode = NULL;
                pPreviousNode->pNextNode = pNewNode;
            }
            else
            {
                pNewNode->pElement = pElement;
                pNewNode->pNextNode = pNextNode;
                pPreviousNode->pNextNode = pNewNode;
            }
        }

    this->size++;
    returnAux = 0;
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int sizeList = ll_len(this);
    if(this != NULL)
    {
        addNode(this, sizeList, pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{

      void* returnAux = NULL;
    Node* pNodeAux = NULL;
    int sizeList = ll_len(this);

    if(this != NULL)
    {
       //pNodeAux = (Node*)malloc(sizeof(Node));

       if(index >= 0 && index <= sizeList)
       {
            pNodeAux = getNode(this, index);
            if(pNodeAux != NULL)
            {
                returnAux = (void*)pNodeAux;
                returnAux = pNodeAux->pElement;
            }
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int sizeList = ll_len(this);
    Node* pNode;
    if(this != NULL)
    {
       if(index >= 0 && index < sizeList)
       {
            //pNode = (Node*)malloc(sizeof(Node*));
            pNode  = getNode(this, index);
            pNode->pElement = pElement;
            returnAux = 0;
       }
    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNextNode;
    Node* pPreviousNode = NULL;

    int listSize = ll_len(this);
    if((this != NULL) && (index < listSize) && (index >= 0))
    {
      //  pNode = (Node*)malloc(sizeof(Node*));
        //pNextNode = (Node*)malloc(sizeof(Node*));
       // pPreviousNode = (Node*)malloc(sizeof(Node*));

        pNode = getNode(this, index);
        pPreviousNode = getNode(this, index-1);
        pNextNode = getNode(this, index+1);

        if(pNode != NULL)
        {
            if(pPreviousNode == NULL)
            {
                pNode = pNode->pNextNode;
            }
            else
            {
                pPreviousNode->pNextNode = pNode->pNextNode;
            }
        }
    this->size--;
    returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    int listSize = ll_len(this);
    if(this != NULL)
    {
        if(listSize != 0)
        {
            for(int i = 0; i <= listSize;i++)
            {
                ll_remove(this, i);
            }
        }
    returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this != 0)
        {
            returnAux =  ll_clear(this);
        }
        else
        {
            returnAux = 1;
        }

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int listSize = ll_len(this);
    Node* pNode;
    if(this != NULL)
    {

        for(int i = 0;i < listSize; i++)
        {
            pNode = getNode(this, i);
            if(pElement == pNode->pElement)
            {
                returnAux = i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int listSize = ll_len(this);
    if(this != NULL)
    {
        if(listSize == 0)
        {
           returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int listSize = ll_len(this);

    if(this != NULL)
    {
        if((index >= 0) && (index <= listSize))
        {
            addNode(this, index, pElement);
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int listSize = ll_len(this);
    Node* pNode;
    if(this != NULL)
    {
        if((index >= 0) && (index < listSize))
        {
            pNode = getNode(this, index);
            returnAux = pNode->pElement;
            ll_remove(this, index);

        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int listSize = ll_len(this);

    if(this != NULL)
    {
        if(ll_indexOf(this, pElement)!= -1)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* pNode;
    int aux;
    int listSize = ll_len(this);
    int listSize2 = ll_len(this2);
    if((this != NULL)&&(this2 != NULL))
    {
        if(listSize == listSize2)
        {
            for(int i=0; i<listSize2;i++)
            {
                pNode = getNode(this, i);
                aux = ll_contains(this, pNode->pElement);
                if(returnAux != 1)
                {
                    break;
                }
            }
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int listSize = ll_len(this);

    if(this != NULL)
    {
        if(listSize == 0)
        {
            if(from == 0 && to > from)
            {
                cloneArray = ll_newLinkedList();
                Node* pNode = (Node*)malloc(sizeof(Node*));
                pNode = getNode(this, 0);
                addNode(cloneArray, 0, pNode->pElement);
            }
        }
        else  if((from >= 0)&&(from < listSize))
        {
            if((to >= from)&&(to <= listSize))
            {
                cloneArray = ll_newLinkedList();
                Node* pNode = (Node*)malloc(sizeof(Node*));

                for(int i = from;i < to; i++)
                {
                    pNode = getNode(this, i);
                    addNode(cloneArray, i, pNode->pElement);
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int listSize = ll_len(this);
    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, listSize);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    Node* pNodeA;
    Node* pNodeB;
    Node* pNodeAux;
    int listSize = ll_len(this);
    int i;
    int j;
    int func;
    if((this != NULL) && ((*pFunc) != NULL) && (order == 1) ||  (order == 0))
    {
        if(listSize > 1)
        {
            for(i = 0;i < listSize-1; i++)
            {
                for(j = i+1; j < listSize;j++)
                {
                    pNodeA = getNode(this, i);
                    pNodeB = getNode(this, j);

                    if(order == 1)/** Ascendente **/
                    {
                        func = pFunc((void*)pNodeA->pElement, (void*)pNodeB->pElement);
                        if(func == 1)
                        {
                            pNodeAux = pNodeA->pElement;
                            ll_set(this, i, pNodeB->pElement);
                            ll_set(this, j, pNodeAux);

                        }
                    }
                    else/** Descendente **/
                    {
                        func = pFunc((void*)pNodeA->pElement, (void*)pNodeB->pElement);
                        if(func == -1)
                        {
                            pNodeAux = pNodeA->pElement;
                            ll_set(this, i, pNodeB->pElement);
                            ll_set(this, j, pNodeAux);

                        }
                    }
                }
            }
        }
    returnAux = 0;
    }

    return returnAux;

}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

char ll_map(LinkedList* this, float (*pFunc)(void*))
{
    eComputer* pComp;
    if(this != NULL)
    {
        for(int i = 0; i < ll_len(this);i++)
        {
           pComp = ll_get(this, i);
           pComp->precio = pFunc(pComp);
        }
    }
    return  pComp->precio;
}


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* computers, char idTipo))
{
    LinkedList* filterList;
    int filterRet;
    void* pElement;
    char idTipoAux;

    filterList = ll_newLinkedList();
    if(filterList != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);
            filterRet = pFunc(pElement, idTipoAux);
            ll_add(filterList, pElement);
        }
    }
    return  filterList;
}


