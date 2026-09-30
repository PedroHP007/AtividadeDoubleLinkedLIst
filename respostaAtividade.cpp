#include <iostream>
using namespace std;

struct No {
    int valor;
    No* anterior;
    No* proximo;
};

int tamanho(No* head) {
    int cont = 0;
    No* aux = head;
    while (aux != NULL) {
        cont++;
        aux = aux->proximo;
    }
    return cont;
}

void imprimir(No* head) {
    if (head == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }
    No* aux = head;
    while (aux != NULL) {
        cout << aux->valor;
        if (aux->proximo != NULL) cout << " <-> ";
        aux = aux->proximo;
    }
    cout << endl;
}


void inserirInicio(No*& head, int data) {
    No* novoNo = new No;
    novoNo->valor = data;
    novoNo->anterior = NULL;
    novoNo->proximo = head;

    if (head != NULL) {
        head->anterior = novoNo;
    }
    head = novoNo;
}

void inserirFim(No*& head, int data) {
    No* novoNo = new No;
    novoNo->valor = data;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    if (head == NULL) {         
        head = novoNo;
        return;
    }

    No* aux = head;
    while (aux->proximo != NULL) {   
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
    novoNo->anterior = aux;
}


void inserirPosicao(No*& head, int pos, int data) {
    int tam = tamanho(head);

    if (pos < 1 || pos > tam + 1) {
        cout << "Posicao invalida!" << endl;
        return;
    }
    if (pos == 1) {
        inserirInicio(head, data);
        return;
    }

    No* novoNo = new No;
    novoNo->valor = data;

    No* aux = head;
    for (int i = 1; i < pos - 1; i++) {   
        aux = aux->proximo;
    }

    novoNo->proximo = aux->proximo;
    novoNo->anterior = aux;
    if (aux->proximo != NULL) {           
        aux->proximo->anterior = novoNo;
    }
    aux->proximo = novoNo;
}


void removerInicio(No*& head) {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }
    No* temp = head;
    head = head->proximo;
    if (head != NULL) {
        head->anterior = NULL;
    }
    delete temp;
}

void removerFim(No*& head) {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    No* aux = head;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }

    if (aux->anterior == NULL) {      
        head = NULL;
    } else {
        aux->anterior->proximo = NULL;
    }
    delete aux;
}

// posição começa em 1
void removerPosicao(No*& head, int pos) {
    int tam = tamanho(head);

    if (pos < 1 || pos > tam) {
        cout << "Posicao invalida!" << endl;
        return;
    }
    if (pos == 1) {
        removerInicio(head);
        return;
    }

    No* aux = head;
    for (int i = 1; i < pos; i++) {   
        aux = aux->proximo;
    }

    aux->anterior->proximo = aux->proximo;
    if (aux->proximo != NULL) {
        aux->proximo->anterior = aux->anterior;
    }
    delete aux;
}

int main() {
    No* head = NULL;

    inserirInicio(head, 10);
    inserirInicio(head, 5);
    inserirFim(head, 20);
    inserirFim(head, 30);
    inserirPosicao(head, 3, 15);

    cout << "Lista: ";
    imprimir(head);                        
    cout << "Tamanho: " << tamanho(head) << endl;

    removerInicio(head);
    cout << "Apos remover inicio: ";
    imprimir(head);                     

    removerFim(head);
    cout << "Apos remover fim: ";
    imprimir(head);                       

    removerPosicao(head, 2);
    cout << "Apos remover posicao 2: ";
    imprimir(head);                      

    cout << "Tamanho final: " << tamanho(head) << endl;

    return 0;
}