//
//  Graph.h
//  Graph_Final
//
//  Created by Yoel Lev on 1/22/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#ifndef __Graph_Final__Graph__
#define __Graph_Final__Graph__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;
using std::string;

class Graph{
public:
    
    Graph();
    
    vector<string> Places;
    vector<vector<int> > v2d2;
    
    string outPutFileName;
    
    void addVertx(string a);
    void removeVertex(string a);
    void addEdge(string a ,string b ,int w);
    void removeEdge(string a ,string b);
     int inPosition(string location);
    void updateEdge(string a ,string b);
    void printVertexes();
    void printEdge();
     int getTravelTime(string a, string b );
    void neighborVertcies(string a);
    void printGraph();
    void writeToFile();
    
    //Exception Classes
    class CorruptedFile{};
    class OutOfRange{};
    class VertexDoesNotExists{};
    class NoSuchEdge{};
    class badStringInput{};
    class BadParameters{};
    
    
    
    
};

#endif /* defined(__Graph_Final__Graph__) */
