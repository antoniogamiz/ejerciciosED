#include<iostream>
#include<vector>
#include<list>

using namespace std;



struct info{
    int key;
    int value;

    bool operator!=(info i) const {
        return (key==i.key) && (value==i.value);
    }
};

vector<list<info> > th;

class iterator {
    public:
        iterator();
        iterator(const iterator & i){
            *this=i;
        }
        bool operator!=(const iterator & i) const{ return object != i.object; }
        bool operator==(const iterator & i) const{ return !(object != i.object); }
        iterator & operator=(const iterator & i){
            indice_cubeta=i.indice_cubeta;
            it_dentro_cubeta=i.it_dentro_cubeta;
            object=i.object;
            return *this;
            }
        int operator*(){ return object.value; }
        iterator & operator++(){
            list<info>::iterator aux = it_dentro_cubeta;
            // Comprobamos si el iterador apunta al final de su cubeta.
            if( ++aux == th[indice_cubeta].end() ){
                // En caso afirmativo, hay que encontrar la siguiente cubeta que no esté vacía.
                bool encontrado=false;
                for(int i=indice_cubeta+1; i < th.size() && encontrado; i++){
                    if( !th.empty() ){
                        indice_cubeta=i; // Guardamos el índice de la nueva cubeta.
                        encontrado=true;          
                    }
                }
                // Si se ha encontrado una cubeta que no esté vacía, le asociamos el primer elemento que tenga, en caso contrario, devolvemos un iterator vacío.
                if(encontrado){
                    it_dentro_cubeta=th[indice_cubeta].begin();
                } else iterator();
            } else it_dentro_cubeta=aux; // Si hay más elementos en la cubeta, simplemente hay que avanzar el iterador de la cubeta.

            //Actualizamos el valor de 'object'.
            object=(*it_dentro_cubeta);

            return *this;
            
        }
    private:
        info object;
        int indice_cubeta;
        list<info>::iterator it_dentro_cubeta;
        iterator(info o);
};

int main(){}