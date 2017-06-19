//
//  Graph.cpp
//  Graph_Final
//
//  Created by Yoel Lev on 1/22/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#include "Graph.h"

Graph::Graph(){
    outPutFileName="output.dat";
}

//Add New Vertex to Graph
void Graph:: addVertx(string a){
    
    //checks String is valid
    if (a.size() >= 16) {
        throw badStringInput();
    }
    
    for (int i = 0 ; i < a.size(); i++) {
        if (a[i]== ' ') {
            throw badStringInput();
        }
    }
    
    if (a == "exit") {
          throw badStringInput();
    }
  
   
   
    //Adds to Places array
    if ( Places.size() == 0  ) {
        Places.push_back(a);
    }else{
       
       // vector<string>::iterator it=find(Places.begin(),Places.end(),a);
        int found = 0;
        
        for (int i = 0 ; i < Places.size(); i++) {
            if (Places[i] == a ) {
                found++;;
            }
        }
        
        if (found == 0 ) {
            Places.push_back(a);
        }
    }
    
    
    //allocates vector
    for (int i = 0 ; i < v2d2.size(); i++) {
        v2d2[i].push_back(0);
    }
    vector<int> temp(v2d2.size()+1);
    v2d2.push_back(temp);
    
    
}

//removeVertex from Graph
void Graph:: removeVertex(string a){
    
      vector<string>::iterator it = Places.begin();
    
    //finds the place if exists and returns index.
    int i = inPosition(a);
    
    //removes place from Vertex Vector.
    if (i > -1 ) {
        cout<<*(it+i)<<" Was removed"<<endl;
        Places.erase (Places.begin()+i);
        
    }else{
       //  cout<<"This Place does not Exists"<<endl;
        throw VertexDoesNotExists();
    }
}

//Add New Edge to Graph
void Graph:: addEdge(string a ,string b ,int w){
    
    int row =-1 ,col=-1;
    
    row =inPosition(a);
    col =inPosition(b);
    
    //Adds a to b weight to vector Matrix.
    if (row != -1 || col != -1) {
        v2d2[row][col]=w;
    }else{
        throw OutOfRange();
    }
  
}

//remove Edge from Graph
void Graph:: removeEdge(string a ,string b){
    
    int row =-1 ,col=-1;
    
    row =inPosition(a);
    col =inPosition(b);
    
    //Adds a to b weight to vector Matrix.
    if (row != -1 || col != -1) {
        v2d2[row][col]=0;
    }else{
        throw OutOfRange();
    }
    
}

//gets the x position from Places vector
int Graph:: inPosition(string location ){
    
    for (int i = 0 ; i < Places.size() ; i++) {
        if (Places[i] == location) {
            return i;
        }
    }
    return -1;
    
}

//update edge
void Graph:: updateEdge(string a ,string b){
   
    if(std::find(Places.begin(), Places.end(), a )!=Places.end()){
        if(std::find(Places.begin(), Places.end(), b )!=Places.end()){
            int w = 0;
            
            cout<<a<<" To "<<b<<endl;
            cout<<"Please Enter new Weight"<<endl;
            cin>>w;

            v2d2[inPosition(a)][inPosition(b)]=w;
             cout<<"Edge Updated succesfuly !"<<endl;
        }
    }else{
        //cout<<"No Such Path"<<endl;
        throw NoSuchEdge();
    }
}

//Print Vertexs to console
void Graph:: printVertexes(){
    
    vector<string>::iterator it = Places.begin();
      for (; it != Places.end() ; it++) {
          cout<<*it<<endl;
      }
    
}

//Print edges to console.
void Graph:: printEdge(){
    
    // Print out the elements
    for(int i=0;i<v2d2.size(); i++) {
        for (int j=0;j<v2d2[i].size(); j++)
            cout <<v2d2[i][j]<< "\t";
        cout << endl;
    }
}

//returns the weight from A to B
int Graph:: getTravelTime(string a, string b ){
    
    if (inPosition(a) == -1 || inPosition(b) == -1) {
        throw VertexDoesNotExists();
    }
    return v2d2[inPosition(a)][inPosition(b)];
}

//prints the neighbor Vertcies from a specific Vertex.
void Graph:: neighborVertcies(string a){
    int weight=-1;
    
    if (a == "exit") {
        return;
    }
    
    int i = inPosition(a);
    
    if (i != -1){
        
         cout<<"<"<<a<<">";
        for (int index = 0 ; index < v2d2.size() ; index++) {
           
           weight =v2d2[i][index];
            
            if (weight) {
                cout<<"\t"<<Places[index]<<"";
            }
        }
                 cout<<endl;
        return;
    }else if(weight == 0){
        cout<<"<"<<a<<">"<<"<SPACE> : <SPACE> no outbound travel"<<endl;
    }else{
        cout<<"<"<<a<<">"<<"does not exist in the current network"<<endl;
           }
   
}


void Graph:: printGraph(){
    
    vector<string>::iterator it = Places.begin();
    
    for (; it != Places.end() ; it++) {
        neighborVertcies(*it);
        cout<<endl;
    }

}


void Graph:: writeToFile(){
   
    string line;

    vector<string>::iterator it = Places.begin();
    ofstream WFile(outPutFileName.c_str(),ios::app);
    
    for (; it != Places.end() ; it++) {

        int i = inPosition(*it);
        
        if (i != -1){
           // cout<<"<"<<*it<<">";
            //string from = *it;
            WFile<<endl<<"<"<<*it<<">"<<"\t";
            for (int index = 0 ; index < v2d2.size() ; index++) {
                
                int weight=v2d2[i][index];
                
                if (weight) {
                    line=Places[index];
                    WFile<<line<<"\t";
                    WFile<<endl;
                  }
                
              }
          }
    
    }
}

