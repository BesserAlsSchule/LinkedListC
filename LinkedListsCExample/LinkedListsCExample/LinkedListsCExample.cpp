#include <iostream>             //IO Operations
#include <Windows.h>            //Console Title
#include <stdlib.h>             //malloc(), realloc()

//LIST DECLARATION
struct ListNode                                                     //Declare Node struct used for the list
{
    int* data;                                                      //
    struct ListNode* next;
}; 
//NAMING BEI POINTERN xyzptr
int main()
{
    SetConsoleTitle(L"Linked Lists Example");

    //build node rootNode
    std::cout << "Allocating memory for root element" << "\n";
    std::cout << "\n";
     
    struct ListNode* rootNode = 0;                                  //init rootNode/head
    rootNode = (struct ListNode*)malloc(sizeof(ListNode));          //für rootnode wird mit malloc() speicher auf dem heap reserviert
    rootNode-> data = 0;                                            //greife auf member data zu und initialisiere mit 0
    rootNode-> next = 0;                                            //greife auf member next zu und initialisiere mit 0

    std::cout << "Adress of root element is: " << rootNode << "\n";  //print rootNode mem adress
    std::cout << "\n";                                              

    //build further nodes   
    struct ListNode* newNode = 0;                                   //init newNode mit Wert 0
    struct ListNode* prevNode = rootNode;                           //init prevNode bekommt Wert rootNode weil dieser mit dem zeiger auf den vorherigen wert zeigen muss

    for (int i = 1; i <= 5; ++i)                                    //for loop für node erstellung -> 
    {
        newNode = (struct ListNode*)malloc(sizeof(ListNode));       //alloziiere speicher auf dem heap für nodes
        newNode-> data = (int*)i;                                   //greife auf member data zu und weise int i als Datensatz zu
        newNode-> next = 0;                                         //greife auf zeiger next zu und initialisere mit 0
        prevNode->next = newNode;                                   //der next-Zeiger des vorherigen Knotens muss auf den neuen Knoten zeigen
        prevNode = newNode;                                         //in der nächsten Iteration ist der aktuell neue Knoten der vorherige Knoten (als vorlage)
    }
 
    std::cout << "\n";
    std::cout << "Laufe durch alle Knoten und gebe Werte aus\n";
    std::cout << "\n";

    struct ListNode* currentNode = rootNode;                        //current node wird mit wert der rootNode initialisiert

    do {
        std::cout << currentNode->data << "\n";                     //printe die werte, welche mit der for-schleife in die nodes gepackt wurden
        currentNode = currentNode->next;                            //auf zum nächsten Knoten
    } while (currentNode != 0);                                     //solange node da oder ungleich null

        std::cout << "\n";
        std::cout << "Freeing memory" << "\n";
        std::cout << "\n";

    struct ListNode* nextNode = rootNode;                           //gehe zu rootnode zurück

    do {                                                            
        currentNode = rootNode;                                     //zu verarbeitende node wird auf root gesetzt 
        rootNode = rootNode->next;                                  //und root = root greift auf next pointer zu
        
        //currentNode = nextNode;                                   //die aktuelle node rootnode
        //nextNode = currentNode->next;                             //auf zum nächsten Knoten
        free(currentNode);                                           //free mem (root->nextNode->nextNode->nextNode->nextNode->nextNode=endNode)
    } while (rootNode != 0);                                         //solange node da oder ungleich null

    free(nextNode);                                                  // free mem

    std::cout << "End of List" << std::endl;

    std::cin.get();

}
