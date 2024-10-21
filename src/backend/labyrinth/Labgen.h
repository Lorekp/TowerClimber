//
// Created by laure on 21.10.2024.
//

#ifndef LABGEN_H
#define LABGEN_H
#include "Labcell.h"
#include <vector>


class Labgen {

    public:
        Labgen();
        int Generate(int seed, std::tuple<int, int> sizexy);

    private:
        std::vector<std::vector<Labcell>> labcells;

        void FillLabcells(std::tuple<int, int> sizexy);
};



#endif //LABGEN_H
