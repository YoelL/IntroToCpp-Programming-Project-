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
    
    
    for(int i = 0; i < defenseGroupSizeT; ++i) {
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
      
        if (Case == 1) {
            
            size_t s1;
            ss >>s1;
            
            vectorLength =s1;
            ++vectorLength;
            flag++;
            if (vectorLength < 8 ) {
                cout<<"The dimension of string is less then 8 Bit !"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
            
        }
        if (Case == 2) {
            
            size_t s1 ,s2,s3;
            ss >>s1>>s2>>s3 ;
            
            defenseGroupSizeT =s1;
            defenseGroupSizeL =s2;
            defenseGroupSizeC =s3;
            
            flag++;
            if (s1 == 0 || s2 == 0 || s3 == 0 ) {
                exit(1);
            }
            
            if ( (s1 < 2) || !(s1 % 2 == 0) || (s1 > 1024 )  ) {
                cout<<"The defense Group Size is not a valid parameter!"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
            if ( (s2 < 2) || !(s2 % 2 == 0) || (s2 > 1024 )  ) {
                cout<<"The defense Group Size is not a valid parameter!"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
            if ( (s3 < 2) || !(s3 % 2 == 0) || (s3 > 1024 )  ) {
                cout<<"The defense Group Size is not a valid parameter!"<<endl;
                cout<<"Program will exit"<<endl;
                exit(1);
            }
            
        }
        if (Case == 3) {
            
            size_t s1;
            ss >>s1;
            
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
        
        if (c == '\n' && count == vectorLength-1 ) {
            buffer[pos++]='\0';
           // cout<<buffer<<endl;
            string temp = string(buffer);
            //cout<<temp<<endl;
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
    size_t DefenseMatSize =(defenseGroupSizeT+defenseGroupSizeL+defenseGroupSizeC);
    
    defense = new string *[DefenseMatSize];
    
    for(int i = 0; i < DefenseMatSize ; ++i) {
        defense[i] = new string[vectorLength];
    }
    
    
    //Creates the random defense packages.
    string final;
    srand((int)time(NULL));
    
    int flagTLC =0;
    
    for (int index = 0 ; index < DefenseMatSize; index++) {
        for (int atPath = 0 ; atPath < vectorLength-1; atPath++) {
            
            string temp= NumberToString ( (int)(rand())%2 );
            final+=temp;
            
        }
        
        if (flagTLC < defenseGroupSizeT) {
            final+="T";
            flagTLC++;
        }else if (flagTLC >=defenseGroupSizeT  && flagTLC < (defenseGroupSizeT+defenseGroupSizeL) ){
            final+="L";
            flagTLC++;
        }else if(flagTLC >= (defenseGroupSizeT+defenseGroupSizeL) ) {
            final+="C";
            flagTLC++;
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
    cout<<"The amount of Vectors in Tackle Defense Team: "<<defenseGroupSizeT<<endl;
    cout<<"The amount of Vectors in Linebacker Defense Team: "<<defenseGroupSizeL<<endl;
    cout<<"The amount of Vectors in Cornerback Defense Team: "<<defenseGroupSizeC<<endl;
    cout<<"The amount of Vectors in Offense Team: "<<offenseGroupSize<<endl;
    cout<<"The Max Number of Generations: "<<maxGen<<endl;
    
    
    //prints to console Offense Cyber Package.
    cout<<"Offense Cyber Package:"<<endl;
    
    for (int row = 0 ; row <offenseGroupSize; row++) {
        cout<<*offense[row]<<endl;
    }
    
    //prints to console Defense Cyber Package.
    size_t DefenseMatSize =(defenseGroupSizeT+defenseGroupSizeL+defenseGroupSizeC);
    cout<<"Defense Cyber Package:"<<endl;
    
    for (int row = 0 ; row < DefenseMatSize; row++) {
        cout<<*defense[row]<<endl;
    }
    
}

void PreSimulation:: doubleCheckParam(){
    int flag=0;
    
    if (vectorLength < 2) {
        flag++;
        
    }
    if (offenseGroupSize < 2  || offenseGroupSize > 1024 ) {
        flag++;
    }
    if (defenseGroupSizeT < 2) {
        flag++;
    }
    
    if (flag) {
        cout<<"Bad Param.. Program will exit"<<endl;
        exit(1);
    }
    
    
}
