#pragma once
#include "Matrix.h"
class ParentObject
{
public:
    Matrix TransformMatrix =
    {{
        {{1, 0, 0, 50}}, 
        {{0, 1, 0, 0}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
     }};

};
