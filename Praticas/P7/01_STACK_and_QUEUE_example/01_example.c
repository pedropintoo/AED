//
// TO DO : desenvolva um algoritmo para verificar se um numero inteiro positivo
//         e uma capicua
//         Exemplos: 12321 e uma capiacua, mas 123456 nao e
//         USE uma PILHA DE INTEIROS (STACK) e uma FILA DE INTEIROS (QUEUE)
//
// TO DO : design an algorithm to check if the digits of a positive decimal
//         integer number constitue a palindrome
//         Examples: 12321 is a palindrome, but 123456 is not
//         USE a STACK of integers and a QUEUE of integers
//

#include <stdio.h>
#include <assert.h>

#include "IntegersQueue.h"
#include "IntegersStack.h"

#define MAX_SIZE 20

int main(void) {

    int number;
    scanf("%d",&number);

    assert(number >= 0);

    if (number < 10) {
        printf("O número é uma capicua!\n");
        return 0;
    }

    Stack* stack = StackCreate(MAX_SIZE);
    Queue* queue = QueueCreate(MAX_SIZE);

    // Save the values
    int aux;
    while (number != 0) {
        aux = number % 10;
        number = number / 10;
        StackPush(stack, aux);
        QueueEnqueue(queue, aux);
    }

    // Process the values
    int limit = StackSize(stack)/2;
    while (StackSize(stack) >= limit) {
        if (StackPop(stack) != QueueDequeue(queue)) {
            printf("O número não é uma capicua.\n");
            StackDestroy(&stack);
            QueueDestroy(&queue);
            return 0;
        }
    }

    printf("O número é uma capicua!\n");

    StackDestroy(&stack);
    QueueDestroy(&queue);

    return 0;
}
