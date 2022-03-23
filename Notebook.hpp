#include <iostream>
#include "Direction.hpp"
#include "Page.hpp"
# include <vector>
using ariel::Direction;
#include <stdexcept>
#include <string>
using namespace std;
namespace ariel{

    class Notebook{
        Page *array;
            public:
                Notebook(){
                    array = new Page[250];
                    // for(int i=0;i<250;i++){
                    //     array[i] = new Page();
                    // }
            }
            ~Notebook(){
                delete[] array;
            }
            Page getP(int page){
                return array[page];
            }

            void write( int page,  int row,  int col, Direction dir, string to_write){
                // array[row][col] = 't';
                Page p = array[page];
                p.arr[row][col] = 't';
            }
            string read( int page,  int row,  int col, Direction dir, int length){
                // Page p = getP(page);
                // return p.arr[row+1][col-1];
                // return "_p_";
                return "";
            }
            void erase( int page,  int row,  int col, Direction dir, int length){
                // array[row][col] = 't';
            }
            void show( int page){
                cout << "show";
            }

    };
}