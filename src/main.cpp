#include "Renderer.h"
#include "Matrix.h"

int main(int argc, char *argv[])
{
    
    Renderer renderer;

    Matrix matrix1 = {{
        {{1, 0, 0, 5}}, 
        {{0, 1, 0, -2}}, 
        {{0, 0, 1, 3}}, 
        {{0, 0, 0, 1}}}};

    Matrix matrix2 = {{
        {{1, 0, 0, 0}}, 
        {{0, 1, 0, 0}}, 
        {{0, 0, 1, 0}}, 
        {{0, 0, 0, 5}}}};
    Vector vector1 {
        {2,3,4,1}
    }; 
    Vector result = MultiplyMatrix(matrix1, vector1);

    renderer.RenderVector(result);
    //    renderer.GoToXY(10, 10);
    //    renderer.Render();
    return 0;
}
