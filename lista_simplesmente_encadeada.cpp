#include <iostream>

using namespace std;

class No {
private:
	int valor;
    No* proximo;

public:
	No (): valor(0), proximo(nullptr){}
	
	void set_valor(int valor) {this->valor = valor;}
	void set_proximo(No *proximo) {this->proximo = proximo;}
	
	int get_valor() {return this->valor;}
	No *get_proximo() {return this->proximo;}
};

class Lista {
private:
	No* inicio;
	No* fim;
	int tamanho;
	    
public:
    Lista() : inicio(nullptr), fim(nullptr), tamanho(0) {}

    void inserir_no_inicio(int valor) {
        No* novo = new No;

        if(novo) {
        	novo->set_valor(valor);
	        novo->set_proximo(this->inicio);
	        if(this->tamanho == 0)
	            this->fim = novo;
	        this->inicio = novo;
	        this->tamanho++;
        }
    }
    
    void inserir_no_fim(int valor) {
    	No* novo = new No;

        if(novo) {
        	novo->set_valor(valor);
	        novo->set_proximo(nullptr);
	        if(this->tamanho == 0)
	        	this->inicio = novo;
	        else
	        	this->fim->set_proximo(novo);
	        this->fim = novo;
	        this->tamanho++;
        }
	}
	
	void retirar_do_inicio() {
		No *no_inicio = this->inicio;
		
		if(this->tamanho == 0) {
			cout << "\nLista Vazia. Impossivel retirar elemento!\n";
			return;
		}
		else if(this->tamanho == 1)
			this->fim = nullptr;
			
		this->inicio = this->inicio->get_proximo();
		delete no_inicio;
		this->tamanho--;
	}
	
	void retirar_do_fim() {
		No *no_fim = this->fim;
		
		if(this->tamanho == 0) {
			cout << "\nLista Vazia. Impossivel retirar elemento!\n";
			return;
		}
		else if(this->tamanho == 1)
			this->inicio = nullptr;
			
		No *penultimo_no = this->inicio;
		for(int i = 0; i < this->tamanho - 2; i++)
			penultimo_no = penultimo_no->get_proximo();
			
		penultimo_no->set_proximo(nullptr);
		this->fim = penultimo_no;
		delete no_fim;
		this->tamanho--;
	}
	
    void listar() {
    	cout << "\n";
        for(No *i = this->inicio; i; i = i->get_proximo())
        	cout << i->get_valor() << " ";
        cout << "\n";
    }

    ~Lista() {
        while (this->inicio) {
            retirar_do_inicio();
        }
    }
};

int main(void) {
    Lista lista;

    int opcao, valor;

    do {
        cout << "\n0 - Sair\n1 - Inserir no Inicio\n2 - Inserir no Fim\n3 - Retirar do Inicio\n4 - Retirar do Fim\n5 - Listar:\n";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;
        
        switch(opcao) {
        	case 0:
        		break;
        	case 1:
        		cout << "\nDigite o valor que deseja inserir: ";
	            cin >> valor;
	            lista.inserir_no_inicio(valor);
	            break;
	        case 2:
	        	cout << "\nDigite o valor que deseja inserir: ";
	            cin >> valor;
	            lista.inserir_no_fim(valor);
	            break;
	        case 3:
	        	lista.retirar_do_inicio();
	        	break;
	        case 4:
	        	lista.retirar_do_fim();
	        	break;
	        case 5:
	        	lista.listar();
	        	break;
	        default:
	        	cout << "\nOpcao Invalida\n";
	        	break;
		}
    }
	while (opcao != 0);

    return 0;
}
