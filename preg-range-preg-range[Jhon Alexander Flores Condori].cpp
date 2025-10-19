#include <iostream>

struct CNode
{
    CNode(int _v)
    { v = _v; left = right = 0; }
    int v;
    CNode *left, *right;
};



class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    bool find(int x, CNode**& p);//cambiar
    bool ins(int x); //insertar
    void inorder(CNode* n);//izquierda - root - derecha
    void print();//imprime arbol completo 
    void printRange(int min, int max );//diametro de los numeros que quiero imprimir
private:
    CNode* root;
    void deleteTree(CNode* n);
};

CBinTree::CBinTree()
{   root = 0;   }//declaro la raiz cuando no apunta a nada

CBinTree::~CBinTree()
{   deleteTree(root);   }// elimino la raiz 

void CBinTree::deleteTree(CNode* n)
{
    if (!n) return;
    deleteTree(n->left);
    deleteTree(n->right);
    delete n;
}

bool CBinTree::find(int x, CNode**& p)
{
    p = &root;
    while ( *p && (*p)->v != x )
        if ( (*p)->v < x )
            p = &( (*p)->right );
        else
            p = &( (*p)->left );
    return *p != 0;
}

bool CBinTree::ins(int x)
{
    CNode** p;
    if ( find(x,p) ) return 0;
    *p = new CNode(x);
    return 1;
}

void CBinTree::print()
{
    inorder(root);
    std::cout<<"\n";
}

void CBinTree::inorder(CNode* n)
{
    if ( !n ) return;
    inorder(n->left);
    std::cout<<n->v<<" ";
    inorder(n->right);
}

void CBinTree::printRange(int min, int max)
{
  


}
// Debe imprimir todos los elementos en el rango [min, max]
// en orden ascendente, sin recorrer todo el árbol.
// Es decir, no debe recorrer los N nodos del arbol.

int main()
{

    CBinTree t;
    t.ins(60); t.ins(30); t.ins(70);
    t.ins(20); t.ins(40); t.ins(65);
    t.ins(80); t.ins(15); t.ins(25);
    t.ins(35); t.ins(45); t.ins(62);
    t.ins(68); t.ins(75); t.ins(85);
    
    std::cout << "Arbol completo: ";
    t.print();
        
    std::cout << "\nRango [35, 75]: ";
    t.printRange(35, 75);
    // Salida esperada: 35 40 45 60 62 65 68 70 75
    
    std::cout << "\nRango [40, 70]: ";
    t.printRange(40, 70);
    // Salida esperada: 40 45 60 62 65 68 70

    std::cout << "\nRango [10, 25]: ";
    t.printRange(10, 25);
    // Salida esperada: 15 20 25
    
    std::cout << "\nRango [65, 100]: ";
    t.printRange(65, 100);
    // Salida esperada: 65 68 70 75 80 85
    
    std::cout << "\n\n";
    return 0;
}
