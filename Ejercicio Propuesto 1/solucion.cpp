#include<list>
#include<iostream>

using namespace std;

/*=============MOSTRAR LISTA=============*/
template<class T>
void mostrar_lista(list<T> & l){
    for(typename list<T>::iterator i=l.begin(); i!=l.end(); i++){
        cout << (*i) << "   ";
    }
    cout << endl;
}
/*=============SOLUCIÓN=============*/
template<class T>
void duplicar_lista(list<T>& l, list<T>& resultado){
    resultado.clear();

    typename list<T>::iterator i = l.begin();
    typename list<T>::reverse_iterator ri = l.rbegin();
    
    for( ; i!=l.end(); i++, ri++){
        resultado.push_back(*i);
        resultado.push_back(*ri);
    }

}
int main(){
    list<int> ejemplo1={1, 2, 3, 4, 5};
    list<int> ejemplo1_d;
    duplicar_lista(ejemplo1, ejemplo1_d);
    mostrar_lista(ejemplo1_d);

    list<char> ejemplo2={97, 98, 99, 100};
    list<char> ejemplo2_d;
    duplicar_lista(ejemplo2, ejemplo2_d);
    mostrar_lista(ejemplo2_d);
}