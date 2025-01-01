#pragma once
#include "Matrix.h"
class LocalToWorldPosition //this is an example to show local to world poisition
{
public:
    Vector carPositionVector = {
    {10, 5, 0, 1}};
    //example a car in (10, 5, 0) world position without rotation
    Matrix carMatrixToWorld = {{
        {{1, 0, 0, 10}}, 
        {{0, 1, 0, 5}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
    }};


    //another object in (2, 3, 0) CAR POSITION without rotation
    Vector objectLocalPositionVector = {
        {2, 3, 0, 1}
    };
    Matrix objectMatrixToCar {{
        {{1, 0, 0, 2}}, 
        {{0, 1, 0, 3}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 1}}
    }};

  //to find object's world position carMatrixToWorld x objectPosition
    Vector objectWorldPosition = MultiplyMatrix(carMatrixToWorld, objectLocalPositionVector);


};
