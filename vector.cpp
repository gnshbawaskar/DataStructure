// Test2
//  main.cpp
//  Vector
//
//  Created by Apple on 03/03/20.
//  Copyright © 2020 Apple. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <curl/curl.h>
using namespace std;
//split by space character
void strsplit(){
    char str[100] = "my name is ganesh";
    
    char *p = strtok(str, " ");
    
    while (p!=NULL){
        
        cout<<"\n" <<"Token:"<<p;
        p = strtok(NULL, " ");
    }
    
}

//Reverse using stack
void stackreverse(){
    
    stack<char *> stk;
    
    char str[100] = "My Name Is Ganesh";
    char * p = strtok(str, " ");
    while (p!=NULL){
        stk.push(p);
        p = strtok(NULL, " ");
    }
    
    while (!stk.empty()){
        cout <<"\n" <<stk.top();
        stk.pop();
    }
    
}



// Occurence + remove duplicate
void function1(){
     vector<int> str = {1,2,3,4,5,6,7,8,9,10};
     
     int count = 0;
     for (int i=0;i<str.size();i++) {
         count = count + str[i];
     }
     
     cout<< "Total:" <<count;
     string sentence = " My My Name is is Name Ganesh is";
     sentence.append(" is ");
     set<string> keys;
     std::map<string, int> ctmap;
     string word="";
     for (auto ch : sentence){
     
         if (ch == ' '){
             cout << "\nword:" <<word;
             keys.insert(word);
             int ct = ctmap[word];
             ctmap[word] = ++ct;
             word = "";
         }
         else{
             word = word + ch;
         }
     }
     
    
     vector<string> vect1;
     vector<string>:: iterator vitr;

     for (auto xyz:ctmap){
         cout << "\n" <<xyz.first << ":" <<xyz.second;
         vect1.push_back(xyz.first);
     }
     
    for (vitr = vect1.begin();vitr!=vect1.end();vitr++){
        
        cout << "\n" << "Vector Itr:"<< *vitr;
    }
     for (auto xyz: vect1){
         cout << "value:"<<xyz << endl;
     }
     
     map<string ,int>:: reverse_iterator itr1,itr2;
     itr1 = ctmap.rbegin();
     itr2 = ctmap.rend();
     for (; itr1!=itr2; itr1++)
     {
         cout << "\n" <<itr1->first << ":" <<itr1->second;
     }
    
    for (auto ijk:keys){
        cout << "\n" <<"set keys:" << ijk ;
    }
     string str1 = "Hello word";
}

bool isPalidrom(string str1){
    string str2;
    str2.assign(str1);
    reverse(str2.begin(), str2.end());
    if (str1 == str2){
        return true;
    }
    else{
        return false;
    }
    
    return false;
}

void reversestring(){
    string str = "Ganesh";
    int j = str.length();
    for (int i=0;i<j/2;i++){
        swap(str[i], str[j-i-1]);
    }
    
    cout << "Reverse String:"<<str;
    
}

//count palidromic word in sentence or remove
void palindromsentence(){
    
    char str[100] = "nitin speaks malayalam";
     
    char *p = strtok(str, " ");
    string word= "";
     while (p!=NULL){
         string str1;
         str1.assign(p);
         cout<<"\n" <<"Palimndrome:"<<isPalidrom(p);
         if (!isPalidrom(p))
             word = word + p;
         p = strtok(NULL, " ");
     }
    cout<<"\n"<<"Non Palindromic sentence:" << word;
    
}

void findSubString(){
    string str1 = "My Name is Ganesh Name";
    string str2 = "Name";
    size_t found = str1.find(str2);
    if (found != string::npos)
    cout << found;
    
    found = str1.find(str2, found+1);
    if (found != string::npos)
       cout << found;
    
    for (int i = 0;i<str1.length();i++){
        string ret = str1.substr(i, str2.length());
        if (ret == str2){
             cout << i;
        }
    }
    
}


int count(string s, char c)
{
    int res = 0;
    for (int i=0;i<s.length();i++)

        if (s[i] == c)
            res++;
  
    return res;
}

void removeDuplicate1(vector<string> str1){
    sort(str1.begin(), str1.end());
    set<string> duplicate;
    for (int i =1;i<str1.size();i++){
        if (str1[i-1] == str1[i]){
            duplicate.insert(str1[i]);
        }
    }
    
    for(auto x:duplicate){
        cout<< "\nDuplicate:"<<x;
    }
}

void removeDuplicate(){
    vector<string> str{"My", "Name", "Is","My" ,"Ganesh", "My", "Name"};
    removeDuplicate1(str);
}

void func(string &ref){
    
    ref.append("XXX");
}
//remove erase for_each
void removeErase(){
    vector<string> str{"My", "Name", "Is","My" ,"Ganesh", "My", "Name"};
    //str.erase(str.begin(),str.end());
    //str.erase(str.begin(),str.begin()+2);
    //str.erase(str.begin());
    //str.clear();
    
    for (auto x:str){
        cout<< x << " "<<endl;
    }
    
    for_each(str.begin(), str.end(), func);
    
    for (auto x:str){
        cout<< x << " "<<endl;
    }
}

//replace_if
bool isVowel(char ch){
    
    if (ch =='A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U')
        return true;
    
    return false;
}

void replaceif(){
    vector<char> vect{'A','B','C','D','E','F','G'};
    replace_if(vect.begin(), vect.end(), isVowel, 'V');
    for (auto x:vect){
           cout<< x << " "<<endl;
    }
}

//swap-reverse
void swapVector(){
    vector<char> vect1{'A','B','C','D','E','F'};
    vector<char> vect2{'I','J','K','L','M','N','O'};
    swap(vect1, vect2);
    for (auto x:vect1){
        cout<< x << " "<<endl;
    }
    
    reverse(vect1.begin(), vect1.end());
    for (auto x:vect1){
        cout<< x << " "<<endl;
    }
}

void arryofvector(){
    //array of vectors
    vector<int> v[5];
    
    //vector of vectors
    vector<vector<int>> vect = { { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9, 4 } };
    
    //map of vectors
    map<vector<int>, int> mapl;
}

void mergeTwoVector1(){
    vector<int> vector1 = { 1, 45, 54, 71, 76, 12 };
    vector<int> vector2 = { 1, 7, 5, 4, 6, 12 };
    vector<int> v(vector1.size() + vector2.size());
    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());
    vector<int>::iterator it;
    it = set_union(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), v.begin());
    
    for (auto x : v) {
        cout << " " << x;
        
    }
}
void mergeTwoVector2(){
    
    vector<int> vector1 = { 1, 45, 54, 71, 76, 12 };
    vector<int> vector2 = { 1, 7, 5, 4, 6, 12 };
    vector<int> vector3(12);
    //sort(vector1.begin(),vector1.end());
    //sort(vector2.begin(), vector2.end());
    
    merge(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), vector3.begin());
    for (auto x : vector3) {
        cout << " " << x;
        
    }
}
void mergeTwoVector3(){
    
    int A[4] = {1,2,3,4};
    int B[4] = {5,6,7,8};
    int C[8];
    merge(A, A+4, B, B+4, C);
    
    for (int i=0 ;i<8;i++){
        cout << " " << C[i];
    }
}

// Remove duplicate
void rDuplicate(){
    vector<int> vect = {1,1,2,2,3,3,4,3,2,5,6,7,7,5};
    vector<int>::iterator it;
    sort(vect.begin(),vect.end());
    it = unique(vect.begin(), vect.end());
    vect.resize(distance(vect.begin(), it));
    for (auto x:vect) {
        cout << " " <<x;
    }
}

// compare two vector
void compareTwoVect(){
    vector<int> vect1 = {1,2,3,4,5};
    vector<int> vect2 = {1,2,3,4,5};
    if (vect1==vect2){
        cout << "Two vectors are same";
    }
    else{
         cout << "Two vectors are not same";
    }
}

void pushbackpopback(){
    vector<int> vect1;
    vect1.push_back(1);
    vect1.push_back(2);
    vect1.push_back(3);
    vect1.push_back(4);
    vect1.push_back(5);
    vect1.push_back(6);
    int count = 0 ;
    while(!vect1.empty())
    {
        count++;
        vect1.pop_back();
    }
    
    cout << count;
}

//constant iterator can not change
void constantIterator(){
     vector<string> vec;
     vec.push_back("first");
     vec.push_back("second");
     vec.push_back("third");
     vec.push_back("forth");
     vec.push_back("fifth");
     
    for (auto itr = vec.cend()-1;itr>=vec.cbegin();itr--){
        cout<< " " << *itr;
    }
}
void stringOperation()
{
    string str;
      cin>>str;      //takes word
    //getline(cin,str);//takes complete line
    str.push_back('B');
    str.push_back('A');
    str.push_back('W');
    str.push_back('A');
    str.push_back('S');
    str.push_back('K');
    str.push_back('R');
    cout << str;
    
    str.pop_back();
    str.pop_back();
    str.pop_back();
    cout <<"\n"<< str;
    
    string str1 = "geeksforgeeks is for geeks";
    str1.resize(13);
     cout << str1;
    char str2[100];
    string str3 = "geeksforgeeks is for geeks";
    str3.copy(str2, 13);
    cout << "\n" << "copy:"<< str2 << endl;
    
    str3.append("Ganesh");
    cout << str3;
}

//copy vector
void copyvector(){
    vector<int> vect1 = {1,2,3,4,5,6};
    vector<int> vect2;
    //copy(vect1.begin(), vect1.end(), back_inserter(vect2));
    vect2.assign(vect1.begin(), vect1.end());
    cout << vect2.size();
    
     vector<int> vect3(vect1);
     cout << vect3.size();
     vector<int> vect4;
     vect4= vect1;
     cout << vect4.size();
}

int main(int argc, const char * argv[]) {
    
    
    // insert code here...
    //reversestring();
    //palindromsentence();
    //stackreverse();
    //function1();
    //strsplit();
    //findSubString();
    //removeDuplicate();
    //int countval =  count("My Name Is Ganesh", 'a');
    //std::cout << "\nHello, World!\n";
    //removeErase();
    //replaceif();
    //swapVector();
    //mergeTwoVector1();
    //mergeTwoVector2();
    //mergeTwoVector3();
    //rDuplicate();
    //compareTwoVect();
    //pushbackpopback();
    //constantIterator();
    //stringOperation();
    //copyvector();
    //h
    return 0;
}
