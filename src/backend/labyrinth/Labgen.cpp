//
// Created by laure on 21.10.2024.
//

#include "Labgen.h"

Labgen::Labgen()
{

}

int Labgen::Generate(int seed, std::tuple<int, int> sizexy)
{
    FillLabcells(sizexy);
}

void Labgen::FillLabcells(std::tuple<int, int> sizexy)
{
    const int sizex = std::get<0>(sizexy);
    const int sizey = std::get<1>(sizexy);
    for(int i = 0; i < sizex; i++)
    {
        labcells.emplace_back();
        for(int j = 0; j < sizey; j++)
        {
            labcells.at(i).emplace_back();
        }
    }
}
