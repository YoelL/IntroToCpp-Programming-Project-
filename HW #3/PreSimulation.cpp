//
//  PreSimulation.cpp
//  SimCyber-Ex3
//
//  Created by Yoel Lev on 12/30/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "PreSimulation.h"

PreSimulation::PreSimulation(string configF,string offenseF ,string defenseF){
    
    configFile  = configF;
    offenseFile = offenseF;
    defenseFile = defenseF;
    
    if (!(configFile == "config.dat" ) || !(offenseFile == "offense.dat" ) || !(defenseFile == "defense.dat")) {
        cout<<"Cannot find files!"<<endl;
        cout<<"Please verify that the file names are enterd!"<<endl;
        exit(1);
    }
    
    getInfo();
    getOffense();
    doubleCheckParam();
    createDeffenseMat();
}

PreSimulation::  ~PreSimulation(){
    
    for(int i = 0; i < offenseGroupSize; ++i) {
        delete [] offense[i];
    }
    delete [] offense;
    
    
    for(int i = 0; i < defenseGroupSize; ++i) {
        delete [] defense[i];
    }
    delete [] defense;
    
}

void PreSimulation:: getInfo(){
    
    int flag = 0 ;
    
    
    string s;
    int Case=1;
    ifstream confile("config.dat");
    while (confile.good()) {
        getline(confile, s);
        stringstream ss(s);
        size_t s1;
        ss >>s1;
        if (Case == 1) {
            vectorLength =s1;
            flag++;
            if (vectorLength < 8 ) {
                cout<<"The dimension of string is less then 8 Bit !"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
            
        }
        if (Case == 2) {
            defenseGroupSize =s1;
            flag++;
            if (defenseGroupSize == 0) {
                exit(1);
            }
            if ( (defenseGroupSize < 2) || !(defenseGroupSize % 2 == 0) || (defenseGroupSize > 1024 )  ) {
                cout<<"The defense Group Size is not a valid parameter!"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
        }
        if (Case == 3) {
            maxGen =s1;
            flag++;
            if (maxGen > 10*10*10*10*10*10) {
                cout<<"The Max Generation Size is not a valid parameter!"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
        }
        Case++;
        if (ss.fail()){
            //if failed!
        }
    }
    
    confile.close();
    
    if (flag < 3) {
        cout<<"Data Missing !Program will exit"<<endl;
        exit(1);
    }
    
    Case=1;
    ifstream offefile("offense.dat");
    while (offefile.good()) {
        getline(offefile, s);
        stringstream ss(s);
        size_t s1;
        ss >>s1;
        if (Case == 1) {
            offenseGroupSize =s1;
            Case++;
        }else{
            break;
        }
        
    }

   
}

void PreSimulation:: getOffense(){
    
    createOffensMat();
    

 std::ifstream ifs ("offense.dat", std::ifstream::in);
    char c = ifs.get();
    char buffer[1024];
    int pos = 0;
    int count = 0;
    int index =0;
    
    while (ifs.good()) {
      //  std::cout << c;
        
        c = ifs.get();
        
        if (c == '\n' && count == vectorLength ) {
            buffer[pos++]='\0';
           // cout<<buffer<<endl;
            string temp = string(buffer);
           // cout<<temp<<endl;
            *offense[index++]=temp;
            pos=0;
            count=0;
        }
        
        if (c == '0' || c== '1') {
            buffer[pos++]=c;
            count++;
        }
    }
  
}

void PreSimulation:: createDeffenseMat(){
    
    //creates the cyberPackage string array.
    defense = new string *[defenseGroupSize];
    
    for(int i = 0; i < defenseGroupSize; ++i) {
        defense[i] = new string[vectorLength];
    }
    
    
    //Creates the random defense packages.
    string final;
    srand((int)time(NULL));
    
    
    for (int index = 0 ; index < defenseGroupSize; index++) {
        for (int atPath = 0 ; atPath < vectorLength; atPath++) {
            
            string temp= NumberToString ( (int)(rand())%2 );
            final+=temp;
        }
        *defense[index]=final;
        final="";
    }
    
    
}

void PreSimulation:: createOffensMat(){
    
    //creates the cyberPackage string array.
    offense = new string *[offenseGroupSize];
    
    for(int i = 0; i < offenseGroupSize; ++i) {
        offense[i] = new string[vectorLength];
    }
    
}

string PreSimulation:: toString(string line){
    
    string vector="";
    cout<<line;

    for(int i = 0 ;i< vectorLength;i++ ){
        
        if (line[i] == '0' )
            vector.append("0");
        
        if (line[i] == '1')
            vector.append("1");
    }
    return vector;
}

string PreSimulation::  NumberToString ( int Number ){
    stringstream ss;
    ss << Number;
    return ss.str();
}

void PreSimulation::displayAllInfo(){
    
    cout<<"-File Names-"<<endl<<endl;
    cout<<"Config fileName: "<<configFile<<endl;
    cout<<"Offense fileName: "<<offenseFile<<endl;
    cout<<"Defense fileName: "<<defenseFile<<endl;
    
    cout<<"-Vars Values-"<<endl<<endl;
    cout<<"Vector Length: "<<vectorLength<<endl;
    cout<<"The amount of Vectors in Defense Team: "<<defenseGroupSize<<endl;
    cout<<"The amount of Vectors in Offense Team: "<<offenseGroupSize<<endl;
    cout<<"The Max Number of Generations: "<<maxGen<<endl;
    
    
    //prints to console Offense Cyber Package.
    cout<<"Offense Cyber Package:"<<endl;
    
    for (int row = 0 ; row <offenseGroupSize; row++) {
        cout<<*offense[row]<<endl;
    }
    
    //prints to console Defense Cyber Package.
    cout<<"Defense Cyber Package:"<<endl;
    
    for (int row = 0 ; row < defenseGroupSize; row++) {
        cout<<*defense[row]<<endl;
    }
    
}

void PreSimulation:: doubleCheckParam(){
    int flag=0;
    
    if (vectorLength < 2) {
        flag++;
        
    }
    if (offenseGroupSize < 2 || offenseGroupSize %2 ==1 || offenseGroupSize > 1024 ) {
        flag++;
    }
    if (defenseGroupSize < 2) {
        flag++;
    }
    
    if (flag) {
        cout<<"Bad Param.. Program will exit"<<endl;
        exit(1);
    }
    
    
}
