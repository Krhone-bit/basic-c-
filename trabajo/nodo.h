#include <cstddef>
#include <iostream>
using namespace std;

class Nodo{
    public:
        int dato;
        Nodo* next;
        Nodo(int d){
            dato = d;
            next = NULL;
        };

        void Mostrar(string label) {
            cout << label;
            cout<<"dato= "<<dato;
            cout<<endl;
        };
};

class NodoAlpha{
    public:
        char dato;
        NodoAlpha* next;
        NodoAlpha(char d){
            dato = d;
            next = NULL;
        };

        NodoAlpha(){
            dato = 0;
            next = NULL;
        };

        void Mostrar(string label) {
            cout << label;
            cout<<"dato= "<<dato;
            cout<<endl;
        };
};

class Ejercicios{
    public:
        void mostrar(Nodo*ini){
            for(Nodo*tmp = ini; tmp != NULL; tmp = tmp->next){
                cout<<tmp->dato<<", ";
            }
            cout<<endl;
        };

        void mostrarAlpha(NodoAlpha*ini){
            for(NodoAlpha*tmp = ini; tmp != NULL; tmp = tmp->next){
                cout<<tmp->dato<<", ";
            }
            cout<<endl;
        };

    NodoAlpha* mergeLists(NodoAlpha* p, NodoAlpha* q) {
        if (!p) return q;
        if (!q) return p;

        NodoAlpha* head = NULL;
        NodoAlpha* tail = NULL;

        if (p->dato < q->dato) {
            head = tail = p;
            p = p->next;
        } else {
            head = tail = q;
            q = q->next;
        }

        while (p && q) {
            if (p->dato < q->dato) {
                tail->next = p;
                tail = p;
                p = p->next;
            } else {
                tail->next = q;
                tail = q;
                q = q->next;
            }
        }

        if (p) {
            tail->next = p;
        } else {
            tail->next = q;
        }

        return head;
    };

        void mostrar2(Nodo* ini) {
            Nodo* slow = ini;
            Nodo* fast = ini;
            Nodo* loopStart = nullptr;
            
            // Detectar el bucle
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    loopStart = slow;
                    break;
                }
            }

            if (loopStart) {
                // Encontrar el inicio del bucle
                Nodo* start = ini;
                while (start != loopStart) {
                    cout << start->dato << ", ";
                    start = start->next;
                    loopStart = loopStart->next;
                }
                // Mostrar el nodo donde comienza el bucle
                cout << start->dato << ", ";
                // Mostrar el resto del bucle una vez
                Nodo* tmp = start->next;
                while (tmp != start) {
                    cout << tmp->dato << ", ";
                    tmp = tmp->next;
                }
                cout << tmp->dato << " (bucle infinito ...)" << endl;
            } else {
                // No hay bucle, mostrar normalmente
                mostrar(ini);
            }
        };

        void ejercicio1(){
            Nodo*p=new Nodo(1);
            Nodo*r=new Nodo(3);
            p->next = new Nodo(2);
            p->next->next = r;
            p-> Mostrar("p: ");
            r->Mostrar("r: ");
            mostrar(p);
            
            p=p->next;
            p-> Mostrar("p: ");
            r->Mostrar("r: ");
            mostrar(p);
        };

        void ejercicio2(){
            Nodo*p=new Nodo(1);
            Nodo*q=new Nodo(2);
            Nodo*r=new Nodo(3);
            p->next = q;
            p->next->next = r;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            r-> Mostrar("r: ");
            mostrar(p);

            p=p->next;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            r-> Mostrar("r: ");
            mostrar(p);
        }

        void ejercicio3(){
            Nodo*p=new Nodo(1);
            Nodo*q=new Nodo(2);
            Nodo*r=new Nodo(3);
            p->next = q;
            p->next->next = r;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            r-> Mostrar("r: ");
            mostrar(p);

            q=p;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            r-> Mostrar("r: ");
            mostrar(p);
        };

        void ejercicio4(){
            Nodo*p=new Nodo(1);
            Nodo*r=new Nodo(3);
            p->next = new Nodo(2);
            p->next->next = r;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);

            r=p->next;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);
        };

        void ejercicio5(){
            Nodo*p=new Nodo(1);
            Nodo*r=new Nodo(3);
            p->next = new Nodo(2);
            p->next->next = r;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);

            p->dato = r->dato;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);
        };

        void ejercicio6(){
            Nodo*p=new Nodo(1);
            Nodo*r=new Nodo(3);
            p->next = new Nodo(2);
            p->next->next = r;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);

            p->dato = p->next->next->dato;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);
        };

        void ejercicio7(){
            Nodo*p=new Nodo(1);
            Nodo*r=new Nodo(3);
            p->next = new Nodo(2);
            p->next->next = r;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar(p);

            p->next->next->next = p;
            p-> Mostrar("p: ");
            r-> Mostrar("r: ");
            mostrar2(p);
        };

        void ejercicio8(){
            Nodo*p=new Nodo(1);
            Nodo*q=new Nodo(2);
            p->next = q;
            p->next->next = new Nodo(3);
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrar(p);


            p->next->next->next=p;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            // mostrar(p);
            // faltaria parar el bucle
            mostrar2(p);
        };

        void ejercicio9(){
            Nodo*p = new Nodo(1);
            p->next = new Nodo(2);
            p->next->next = new Nodo(3);
            p-> Mostrar("p: ");
            mostrar(p);

            p->next->next->next = p;
            p-> Mostrar("p: ");
            mostrar2(p);
        };

        void ejercicio10(){
            NodoAlpha*p = new NodoAlpha('A');
            NodoAlpha*q = new NodoAlpha('C');
            p->next = new NodoAlpha('B');
            p->next->next = q;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);

            p->next = q;
            p->Mostrar("p: ");
            q->Mostrar("q: ");
            mostrarAlpha(p);
        };

        void ejercicio11(){
            NodoAlpha*p = new NodoAlpha('A');
            p->next = new NodoAlpha('B');
            p->next->next = new NodoAlpha('C');
            p-> Mostrar("p: ");
            mostrarAlpha(p);

            p->next = p->next->next;
            p-> Mostrar("p: ");
            mostrarAlpha(p);
        };

        void ejercicio12(){
            NodoAlpha*p = new NodoAlpha('_');
            NodoAlpha*q = p;
            p->next = new NodoAlpha('_');
            p->next->next = new NodoAlpha('_');
            p->next->next->next = new NodoAlpha('_');
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);

            q=p->next->next->next;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);
        };

        void ejercicio13(){
            NodoAlpha*p = new NodoAlpha('a');
            NodoAlpha*q = p;
            p->next = new NodoAlpha('b');
            p->next->next = new NodoAlpha('c');
            p->next->next->next = new NodoAlpha('c');
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);

            q=p->next->next;
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);    
        };

        void ejercicio14(){
            NodoAlpha*p = new NodoAlpha();
            p-> Mostrar("p: ");
            mostrarAlpha(p);

            p = new NodoAlpha('A');
            p->next = new NodoAlpha('B');
            p->next->next = new NodoAlpha('C');
            p->next->next->next = new NodoAlpha('D');
            p-> Mostrar("p: ");
            mostrarAlpha(p);
        };

        void ejercicio15(){
            NodoAlpha*p = new NodoAlpha('B');
            NodoAlpha*q = new NodoAlpha();
            p->next = new NodoAlpha('C');
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);

            p = new NodoAlpha('A');
            p->next = new NodoAlpha('B');
            p->next->next = new NodoAlpha('C');
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);
        };

        void ejercicio16(){
            NodoAlpha*p = new NodoAlpha('A');
            p->next = new NodoAlpha('B');
            p->next->next = new NodoAlpha('C');
            p-> Mostrar("p: ");
            mostrarAlpha(p);


            p->next->next->next = new NodoAlpha('D');
            p-> Mostrar("p: ");
            mostrarAlpha(p);
        };

        void ejercicio17(){
            NodoAlpha*p = new NodoAlpha('A');
            p->next = new NodoAlpha('B');
            p->next->next = new NodoAlpha('C');
            NodoAlpha*q = new NodoAlpha();
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);

            q = p; // q apunta al nodo que será removido
            p = p->next; // p ahora apunta al nuevo primer nodo (nodo 'B')

            // Encontrar el último nodo para insertar el nodo removido al final
            NodoAlpha* temp = p;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // Insertar el nodo 'A' al final de la lista
            temp->next = q;
            q->next = nullptr;
            q = new NodoAlpha();
            p-> Mostrar("p: ");
            q-> Mostrar("q: ");
            mostrarAlpha(p);
        };

    void ejercicio18() {
        NodoAlpha* p = new NodoAlpha('A');
        p->next = new NodoAlpha('B');
        p->next->next = new NodoAlpha('C');
        p->Mostrar("p: ");
        mostrarAlpha(p);

        // Guardar referencia al nodo original
        NodoAlpha* temp = p;
        // Avanzar p para apuntar al segundo nodo
        p = p->next;

        // Buscar el último nodo
        NodoAlpha* last = p;
        while (last->next != NULL) {
            last = last->next;
        }

        // Mover el nodo original (A) al final
        last->next = temp;
        temp->next = NULL;

        // Mostrar la lista modificada
        p->Mostrar("p: ");
        mostrarAlpha(p);
    }

    void ejercicio19() {
        NodoAlpha* p = new NodoAlpha('E');
        p->next = new NodoAlpha('H');
        p->next->next = new NodoAlpha('M');
        NodoAlpha* q = new NodoAlpha('B');
        q->next = new NodoAlpha('F');
        q->next->next = new NodoAlpha('G');
        q->next->next->next = new NodoAlpha('R');
        p->Mostrar("p: ");
        q->Mostrar("q: ");
        mostrarAlpha(p);
        mostrarAlpha(q);

         NodoAlpha* merged = mergeLists(p, q);

        // Hacer que p apunte al nodo B (nuevo cabeza de la lista)
        p = merged;
        
        // Mostrar p apuntando a nodo B
        p->Mostrar("p: ");
        mostrarAlpha(p);
    }

    void ejercicio20() {
        NodoAlpha* p = new NodoAlpha('A');
        p->next = new NodoAlpha('B');
        p->next->next = new NodoAlpha('C');
        p->next->next->next = new NodoAlpha('D');

        p->Mostrar("p :");
        mostrarAlpha(p);

        NodoAlpha* q = nullptr;
        NodoAlpha* r = nullptr;

        // Invertir la lista
        while (p != NULL) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        // p ahora debería apuntar al nuevo primer nodo (D)
        p = q;

        // Mostrar la lista invertida
        p->Mostrar("p: ");
        mostrarAlpha(p);
    };
};
