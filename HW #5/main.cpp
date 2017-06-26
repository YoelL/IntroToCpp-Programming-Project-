//
//  main.cpp
//  Graph_Final
//
//  Created by Yoel Lev on 1/22/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;
using std::string;


int main(int argc, const char * argv[]) {
    
    string str,s1,s2,strArg,str2="";
    int time;
    Graph graph;
   /* argv[0]="main";
    argv[1]="MiddleEarth.txt";
    argv[2]="-oOut";
   */
    
    try {
        
        if (argc == 1) {
        
            throw Graph::BadParameters();
        }
        
        //goes over all files(Parameters that are enterd in Terminal ).
        for (int iArgc= 1 ; iArgc <argc ; iArgc++) {
           
            unsigned long pos = -1;
            strArg = argv[iArgc];
            pos = strArg.find("-o");
            
            //goes in if finds the -o flag to create a file with the Graph info.
            if (pos > -1 || pos <16 ) {
                str2 = strArg.substr(2,strArg.size()-2);
                graph.outPutFileName=str2;
                graph.writeToFile();
                break;
            }
           
            //reads from file
            ifstream aFile(strArg.c_str());
            
            while (aFile.good()) {
                getline(aFile, str);
                stringstream ss(str);
                ss >>s1>>s2>>time;
               
                graph.addVertx(s1);
                graph.addVertx(s2);
                graph.addEdge(s1,s2,time);
            }
        }
        
        
        cout<<"Where would you like to travel ?"<<endl;
        do {
            cin>>str;
            graph.neighborVertcies(str);
        } while (str != "exit");
        
        //Default Graph to file.
        graph.writeToFile();
        
        
      //Exceptions
        
    }catch (Graph::CorruptedFile) {
        cout<<"Somthing went wrong..."<<endl;
        exit(1);
        
    }catch(Graph::OutOfRange){
        cout<<" Vector Out of Range"<<endl;
         exit(1);
        
    }catch(Graph::badStringInput){
        cout<<"Bad File.."<<endl;
         exit(1);
        
    }catch(Graph::VertexDoesNotExists){
        cout<<"No Such Vertex in Graph."<<endl;
         exit(1);
        
    }catch(Graph::NoSuchEdge){
        cout<<"No Such Edge in Graph"<<endl;
         exit(1);
        
    }catch(Graph::BadParameters){
        cout<<"Bad Parameters were enterd..."<<endl;
        exit(1);
        
    }catch (...) {
        cout<<"Somthing went wrong..."<<endl;
         exit(1);
    }

    return 0;
}




