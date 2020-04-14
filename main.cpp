//
//  main.cpp
//  map
//
//  Created by Apple on 03/03/20.
//  Copyright © 2020 Apple. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
//https://www.geeksforgeeks.org/searching-map-using-stdmap-functions-c/
//find
void function1(){
      map<char, int> mapl;
      mapl['A']=1;
      mapl['B']=2;
      mapl['C']=3;
      mapl['D']=4;
      mapl['E']=5;
      mapl['F']=6;
      
      map<char,int>::iterator itr1,itr2;
      
      itr1 = mapl.find('E');
      if (itr1!=mapl.end())
      {
          cout<<"Value Present:" <<itr1->first << " "<< itr1->second;
          itr1++;
          cout<<"Value Present:" <<itr1->first << " "<< itr1->second;
      }
      else
          cout<<"Value Not Present";
      
      mapl.erase(itr1);
      for(auto x:mapl){
          cout << "\n" << x.first <<" "<< x.second;
      }
}

//lower bound
void function2(){
    map<char, int> mapl;
    mapl['A']=1;
    mapl['B']=2;
    mapl['C']=3;
    mapl['H']=4;
    mapl['J']=5;
    mapl['L']=6;
    mapl.insert(make_pair('Z', 8));
    
    map<char,int>::iterator itr1;
    map<char,int>::iterator itr2;
    map<char,int>::iterator itr3;
    
    itr1 = mapl.lower_bound('C');
    if (itr1 == mapl.end()){
        cout << "Value not present";
    }
    else{
        cout << "Value present ";
        cout  <<itr1->first << itr1->second;
    }
    
    itr1 = mapl.lower_bound('I');
     if (itr1 == mapl.end()){
         cout << "Value not present";
     }
     else{
         cout <<"\n" <<itr1->first << itr1->second;
     }
    
    itr1 = mapl.lower_bound('P');
    if (itr1 == mapl.end()){
        cout << "Value not present";
    }
    else{
        cout <<"\n" <<itr1->first << itr1->second;
    }
    
}
//upper bound
void function3(){
   map< char, int > mp;
      
    // declaring iterators
    map<char, int>::iterator it ;
    map<char, int>::iterator it1 ;
    map<char, int>::iterator it2 ;
      
      
    // inserting values
    mp['a']=5;
    mp['b']=10;
    mp['c']=15;
    mp['h']=20;
    mp['k']=30;
    mp['z']=90;
      
    // using upper_bound() to search for 'b'
    // key found
    // "it" has address of key value pair next to 'b' i.e 'c'.
    it = mp.upper_bound('b');
      
    if(it == mp.end())
        cout << "Key-value pair not present in map" ;
    else
        cout << "Key-value pair returned : "
            << it->first << "->" << it->second ;
      
    cout << endl ;
      
    // using upper_bound() to search for 'd'
    // key not found
    // "it1" has address of next greater key.
    // key - 'h'
    it1 = mp.upper_bound('d');
      
    if(it1 == mp.end())
        cout << "Key-value pair not present in map" ;
    else
        cout << "Key-value pair returned : "
        << it1->first << "->" << it1->second ;
      
    cout << endl;
      
    // using upper_bound() to search for 'p'
    // key not found
    // "it2" has address of next greater key.
    // all keys are smaller, hence returns mp.end()
    it2 = mp.upper_bound('p');
      
    if(it2 == mp.end())
        cout << "Key-value pair not present in map" ;
    else
        cout << "Key-value pair returned : "
            << it2->first << "->" << it2->second ;
}

void function4(){
    map<int,int> mapl;
    mapl.insert({1,100});
    mapl.insert({2,200});
    mapl.insert({3,300});
    mapl.insert({4,400});
    mapl.insert({5,500});
    
    size_t cnt = mapl.count(5);
    if(cnt==1){
        cout << "value present";
    }
    else{
        cout << "value not present";
    }
    
    int i= mapl.at(4);//mapl[4]
    mapl.at(4) = 600;
    i= mapl.at(4);
    cout<<i;
    
    auto itr = mapl.find(4);
    if (itr!=mapl.end())
        mapl.erase(itr);
    
    mapl.erase(mapl.begin(), mapl.end());
    
    
    size_t length = mapl.size();
    mapl.clear();
    length = mapl.size();
   
}
//
//
//
int main(int argc, const char * argv[]) {
    // insert code here...
    function2();
    //function1();
    function3();
    //function4();
    
    
    
    
    
    return 0;
}
