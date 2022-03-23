#include <iostream>
#pragma once

#include "Direction.hpp"
// #include "Notebook.hpp"
using ariel::Direction;
#include <stdexcept>
#include <string>
#include <vector>
#include <array>
using namespace std;
namespace ariel{
    class Page{
        public:
            char arr[200][100];
            // vector<array<char, 100>> arr;
            Page(){
            for (int i=0;i<200;i++){
                for(int j=0;j<100;j++){
                    arr[i][j] = '_';
                }
            }
        }
};
}