
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include "Direction.hpp"
#include "Notebook.hpp"
using ariel ::Direction ;
map<unsigned int , char>::iterator itr;
 const map<unsigned int , map<unsigned int ,char>> ::iterator itrr;
  namespace ariel  {
           map<unsigned int , char>::iterator itr;
           map<unsigned int , map<unsigned int ,char>> ::iterator itrr;
           unsigned int freq=0;
           int Notebook::checkvalid1(unsigned   int i ,unsigned  int j,unsigned int c ,Direction d, int unsigned l){
               if (c>c_length){
                    throw invalid_argument("ERROR , the coulmn should be less than 100");

               }
               if(i <0 ||j<0 ||c<0 ||l<0){
                   throw invalid_argument("ERROR");

               }
              


               return 0;
           }
           int checkvalid2(unsigned int i ,unsigned int j,unsigned int c ,Direction d, string const &write){
               if (write.find('~')!=string::npos){
                    throw invalid_argument("ERROR");

               }
               if (c>c_length){
                    throw invalid_argument("ERROR , the coulmn should be less than 100");

               }
               if(i < 0 ||j<0 ||c<0 ){
                   throw invalid_argument("ERROR");

               }
               if(d==Direction::Horizontal && (unsigned int)write.length()-1+c >=c_length){
                   throw invalid_argument("ERROR");

               }
               if(d==Direction::Vertical && (unsigned int)write.length()-1+c > c_length){
                   throw invalid_argument("ERROR");

               }
               return 0;
           }

     void Notebook::write( unsigned int i ,unsigned int j , unsigned int c, Direction d, std::string const &write){
         unsigned int freq=0;
         if (write.find('~')!=string::npos){
                    throw invalid_argument("ERROR");

               }
               if (c>c_length){
                    throw invalid_argument("ERROR , the coulmn should be less than 100");

               }
               if(i < 0 ||j < 0 ||c <0 ){
                   throw invalid_argument("ERROR");

               }
               if(d==Direction::Horizontal && (unsigned int)write.length()-1+c >=c_length){
                   throw invalid_argument("ERROR");

               }
               if(d==Direction::Vertical && (unsigned int)write.length()-1+c >=c_length){
                   throw invalid_argument("ERROR");

               }
         for (auto it =write.begin(); it!=write.end();++it)
         {
             if(d==ariel::Direction::Vertical){
             map1[j+freq][c]=*it;
             freq++;
         }
           
                if(d==ariel::Direction::Horizontal){
                    map1[j][c+freq]=*it;
                 freq++;
         }
     }
   
     }
      string Notebook::read(unsigned int i ,unsigned int j, unsigned int  c , Direction d ,unsigned int l){
         string res;
          if (c>c_length){
                    throw invalid_argument("ERROR , the coulmn should be less than 100");

               }
               if(i <0 ||j<0 ||c<0 ||l<0){
                   throw invalid_argument("ERROR");

               }
               if (l<0 || l> c_length-1){
                    throw invalid_argument("ERROR");
               } 
         if(d==ariel::Direction::Vertical){
             for(unsigned int freq=0; freq<l;++freq ){
                 itrr=map1.find(j+freq);
                 itr=map1[j+freq].find(c);
                 if(itrr!=map1.end()&& itr!=map1[j+freq].end()){
                     res+=map1[j+freq][c];

                 }
                 else{
                     if(map1.empty()){
                         res+='_';
                     }
                 }

             }

         }

         else {
             if(d==ariel::Direction::Vertical){
             for(unsigned int freq=0; freq<l;++freq ){
                 itrr=map1.find(j);
                 itr=map1[j].find(c+freq);
                 if(itrr !=map1.end() && itr!=map1[j].end()){
                     res+=map1[j][c+freq];



                 }
              }
             }
             else {
                 res+='_';
             }
         }
         
         return res;
     }
     void Notebook::erase ( unsigned int i ,unsigned int j,  unsigned int c , Direction d , unsigned int l){
        if (c>c_length){
                    throw invalid_argument("ERROR , the coulmn should be less than 100");

               }
               if(i <0 ||j<0 ||c<0 ||l<0){
                   throw invalid_argument("ERROR");

               }
               if (l<0||l>c_length-1){
                   throw invalid_argument("ERROR");
               } 
         for(unsigned int k=0 ;k < l; k++){
             if(d==ariel::Direction::Vertical){
                 map1[j][c+k]='~';
             }
             else{
                 map1[j+k][c]='~';
             }

         }

     }
     void Notebook:: show(const unsigned int x) {
         int maxR=25;
            int maxC=25;
            char p ='_';
          for( auto y=0 ; y< maxR-1 ;++y ){
             // cout < <<" ";<y
             // itrr=map1.find(y);
              for (auto i = 0; i< maxC-1; i++)
              {
                  itrr=map1.find(y);
                  itr=map1[y].find(i);
                  if(itrr !=map1.end()&& itr !=map1[y].end()){
                 cout <<map1[y][i] <<" ";
                  }
               else{
                     cout << p;
                 }
            }
              cout << endl;

         }

     }

 }