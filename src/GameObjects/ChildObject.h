#pragma once
#include "Matrix.h"
class ChildObject
{
public:
    Matrix TransformMatrix =
    {{
        {{1, 0, 0, 10}}, 
        {{0, 1, 0, 3}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
     }};

};
