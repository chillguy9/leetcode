#include<iostream>
#include<list>
#include<queue>
using namespace std;



class Graph{
    private:
    int v;
    list<int>* l;
    
    public:
    Graph(int v){
    this->v = v;
    l = new list<int>[v];
    }

    void AddEadge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void PrintEadge(){

        for(int i=0 ; i<v ; i++){
            cout<<i<<" : ";
            for(int x : l[i]){
                cout<<x<<" "; 
            }
            cout<<endl;
        }
    }

    void bfs(){
    
        queue<int> q;
        
        vector<bool> vis(v , false);
        q.push(0);
        vis[0]=true;

        while(!q.empty()){

            int u = q.front();
            q.pop();

            cout<<u<<" ";

             for( int x : l[u]){
       
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
             }

        }
        cout<<endl;



    }

    void kansAlgo(){



    vector<int> inEadge(v,0);

    for(int u=0;u<v;u++){
        for(int v : l[u]){
            inEadge[v]++;
        }
    }

    queue<int> q;

    for(int i=0; i<v;i++){
        if(inEadge[i]==0){
            q.push(i);
        }
    }
     
    vector<int> ans;

    while(!q.empty()){
    
        int x =q.front();
        q.pop();
        ans.push_back(x);

        for(int v : l[x]){
            inEadge[v]--;
            if(inEadge[v]==0){
                q.push(v);
            }
        }
    }

  

}

    
    void dfshelper(int u , vector<bool>& vis){
     vis[u]= true;
     cout<<u<<" ";
     for(int x : l[u]){
        if(!vis[x]){
            dfshelper(x , vis);
        }
    }
    }
    void dfs(){
    
        vector<bool> vis(v , false);
        for(int i=0 ; i<v ; i++){
        if(!vis[i]){
        dfshelper(i , vis);
        }
        }

        cout<<endl;

    }

    bool isCycleHelper(int u , int par , vector<bool> &vis){

        vis[u]=true;

        for( int  x : l[u]){
            if(!vis[x]){
                if(isCycleHelper(x , u , vis)) return true;
            }else if(x!=par) return true;
        }

        return false;

    }

    bool isCycle(){

        vector<bool> vis(v , false);

        for(int i=0 ; i<v ; i++){
            if(!vis[i]){
                if(isCycleHelper(i , -1 , vis)) return true;
            }
        }
        return false;
    }


};

int main(){

Graph g(5);


g.AddEadge(0,1);
g.AddEadge(1,2);
g.AddEadge(1,3);
g.AddEadge(3,4);
// g.AddEadge(2,4);


g.PrintEadge();
cout<<"bfs : ";
g.bfs();
cout<<"dfs : ";
g.dfs();

cout<<"is Cycle : "<<g.isCycle();


}

//0 : 1
//1 : 0,2,3
//2 : 1,4
//3 : 1,4
//4 : 2,3


