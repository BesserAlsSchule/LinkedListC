#include <iostream>             //IO Operations
#include <Windows.h>            //Console Title
#include <stdlib.h>             //malloc(), realloc()

//LIST DECLARATION
struct ListNode                //Declare Node struct used for the list
{
    int* data;
    struct test_List* next;
};

int main()
{
    SetConsoleTitle(L"Linked Lists Example");

    //LIST INSTANCE
    std::cout << "Allocating memory for root element" << "\n";
    struct ListNode* rootNode = 0;
    rootNode = (struct ListNode*)malloc(sizeof(ListNode));
    rootNode > data = 0;
    rootNode > next = 0;


    std::cout << "adress of root element is:" << root << "\n";


    //build further nodes
    struct ListNode* newNode = 0;
    struct ListNode* prevNode = root;

    for (int i = 1; i <= 5; ++i)
    {
        newNode = (struct ListNode*)malloc(sizeof(ListNode));
        newNode > data = i;
        newNode > next = NULL;

        prevNode->next = newNode;       // der next-Zeiger des vorherigen Knotens muss auf den neuen Knoten zeigen
        prevNode = newNode;             // in der nächsten Iteration ist der aktuell neue Knoten der vorherige Knoten
    }

    std::cout << "\n";
    std::cout << "Laufe durch alle Knoten und gebe Werte aus\n";
    std::cout << "\n";

    struct ListNode* currentNode = root;

    do {
        std::cout << currentNode->data << "\n";
        currentNode = currentNode->next;           // auf zum nächsten Knoten
    } while (currentNode != 0)

        std::cout << "Freeing memory" << "\n";

    struct ListNode* nextNode = root;

    do {
        currentNode = nextNode;
        nextNode = currentNode->next;           // auf zum nächsten Knoten
        free(currentNode);
    } while (nextNode != 0)

        free(next);                             // free mem

    std::cout << "End of List" << std::endl;

    std::cin.get();

}
