#pragma once
#include "Matrix.h"
class ChildObject
{
public:

    Matrix TransformMatrix =
    {{
        {{1, 0, 0, 2}}, 
        {{0, 1, 0, 0}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
     }};
    Matrix LocalTransformMatrix =
    {{
        {{1, 0, 0, 1}}, 
        {{0, 1, 0, 0}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
     }};

};
