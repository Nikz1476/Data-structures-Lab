#include <iostream>
using namespace std;

#define max 100

class graph{
private:
    int adjmat[max][max];
    int vertices;
public:
    graph(int n){
        vertices = n;
        for(int i =0; i<vertices; i++){
            for(int j = 0; j<vertices; j++){
                adjmat[i][j] = 0;
                cout << adjmat[i][j]<< " ";
            }
            cout << endl;
        }
    }
    void insert(int u, int v){
        if (u>=0 && u<vertices && v>=0 && v<vertices)
        {
            adjmat[u][v] = 1;
            cout << "Edge inserted from " << u << "->" << v <<endl;
            return;
        }else{
            cout << "Invalid Edges. "<<endl;
            return;
        }
        
    }
    void delet(int u, int v){
        if (u>=0 && u<vertices && v>=0 && v<vertices)
        {
            if(adjmat[u][v] == 1){
                adjmat[u][v] = 0;
                cout << "Edge deleted from " << u << "->" << v <<endl;
                return;
            }
            else{
                cout << "Edge not found."<<endl;
                return;
            }
            
        }else{
            cout << "Invalid Edges. ";
            return;
        }
    }
    void search(int u, int v){
        if (u>=0 && u<vertices && v>=0 && v<vertices){
            if (adjmat[u][v] == 1)
            {
                cout << "Edge found from " << u << "->" << v <<endl;
                return;
            }else{
                cout << "Edge not found." << endl;
                return;
            }            
        }else{
            cout << "Invalid Edges. ";
            return;
        }
    }
    void display(){
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjmat[i][j]<< " ";
            }
            cout << endl;          
        }        
    }
};

int main(){
    int n;
    int ch;
    cout << "Enter number of vertices: ";
    cin >> n;
    int u,v;
    graph g(n);
    do
    {
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter the choice (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter edges u and v to insert: ";
            cin >> u >> v;
            g.insert(u,v);
            break;

        case 2:
            cout << "Enter edges u and v to delete: ";
            cin >> u >> v; 
            g.delet(u,v);
            break;

        case 3:
            cout << "Enter edges u and v to search: ";
            cin >> u >> v; 
            g.search(u,v);
            break;
        
        case 4:
            cout << "Matrix elements are: "<< endl;
            g.display();
            break;
        
        case 5:
            cout << "Thank you, Exiting. \n";
            break;

        default:
            cout << "Invalid choice. ";
            break;
        }

    } while (ch != 5);    
    return 0;
}