#include <iostream>
#include <string>
#include <map>
#include "Direction.hpp"
#include <stdexcept>
using ariel::Direction;
using namespace std;

 namespace ariel
{
    const  int c_length =100;
    class Notebook {
        
        public :
        
        const  char p ='_';

          static  map<unsigned int,std::map<unsigned int,char>> map1;
          Notebook(){};
         // Notebook (std::string t= "new tile ");
         static int checkvalid1(unsigned int i , unsigned int j,unsigned int c ,Direction d,unsigned int l);
          static int checkvalid2(unsigned int i , unsigned int j,unsigned int c ,Direction d, string const &write);
         static void write( unsigned int i , unsigned  int j ,unsigned int c, Direction d,  string const &write);
         static string read(unsigned int i , unsigned  int j,  unsigned int c , Direction d ,unsigned int l);
         static void erase (unsigned int i , unsigned int j,  unsigned int  c , Direction d ,unsigned int l);
          static void show (unsigned int i);
       



    };
}