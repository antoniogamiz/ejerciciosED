

/* EJERICCIO 4*/

int NumeroCaminos(bintree<int> & ab, int k){
    return numero_caminos_recursivo(ab.root(), k, 0);
}

int numero_caminos_recursivo(bintree<int>::node n, int k, int acumulador){
    if( !n.null() ){
        acumulador+=(*n);
        int n = ( acumulador == k ) ? 1 : 0;
        n += numero_caminos_recursivo(n.left(), k, acumulador) + numero_caminos_recursivo(n.right(), k, acumulador);
        return n;
    } else return 0;
}


APO=>
                12
        15              22
    45      20      23      24
55      52

AVL=>
        20
    15      45    
12        23   55
        22 24 52 