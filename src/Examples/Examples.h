#pragma once
#include "../GameObjects/ChildObject.h"
#include "../GameObjects/ParentObject.h"
#include "Matrix.h"
#include "Polygon.h"
#include "Renderer.h"
#include "TranslateAndRotate.h"
#include "ncurses.h"
#include <iostream>
#include <sys/resource.h>
#include <chrono>
#include <thread>

void static RotateObject(Renderer &renderer)
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ParentObject parentObject;
    for (size_t i = 0; i < 10; i++)
    {
        rotationAngleDegrees += 1;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        parentObject.TransformMatrix = translateAndRotate.RotateMatrixOnZ(
            parentObject.TransformMatrix, rotationAngle);

        renderer.DrawObject(parentObject.TransformMatrix, 2);
    }
}
void static RotateObjectWithChild(Renderer &renderer)
{
    TranslateAndRotate translateAndRotate;
    double rotationAngleDegrees = 0;

    ChildObject childObject;
    ParentObject parentObject;
    Matrix translateMatrix = {
        {{1, 0, 0, 0}, {0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

    while (true)
    {
        clear(); // Clear the screen

        rotationAngleDegrees = 30;
        double rotationAngle = rotationAngleDegrees * M_PI / 180;
        childObject.LocalTransformMatrix = translateAndRotate.RotateMatrixOnZ(
            childObject.LocalTransformMatrix, rotationAngle);
        childObject.TransformMatrix = MultiplyMatrix(
            parentObject.TransformMatrix, childObject.LocalTransformMatrix);

        parentObject.TransformMatrix =
            MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);

        renderer.DrawObject(parentObject.TransformMatrix, 3);
        renderer.DrawObject(childObject.TransformMatrix, 5);

        refresh(); // Refresh the screen to apply changes
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
void static MoveParentWithChildren(Renderer &renderer)
{
    ParentObject parentObject;
    ChildObject childObject;
    Matrix translateMatrix = {
        {{1, 0, 0, 2}, {0, 1, 0, 2}, {0, 0, 1, 2}, {0, 0, 0, 1}}};
    for (size_t i = 0; i < 4; i++)
    {
        parentObject.TransformMatrix =
            MultiplyMatrix(parentObject.TransformMatrix, translateMatrix);
        renderer.DrawObject(parentObject.TransformMatrix, 2);

        childObject.TransformMatrix = MultiplyMatrix(
            parentObject.TransformMatrix, childObject.LocalTransformMatrix);
        renderer.DrawObject(childObject.TransformMatrix, 1);
    }
}

void static PrintMemoryUsage()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Memory usage: " << usage.ru_maxrss << " KB" << std::endl;
    mvprintw(1, 0, "Memory usage: %lu", usage.ru_maxrss);
}

void static RenderPolygon(Renderer &renderer)
{
    int polygonCount = 400;
    Polygon* polygons[polygonCount];
    for (int i = 0; i < polygonCount; i++)
    {
        Polygon *polygon = new Polygon();
        polygons[i] = polygon;

    }
    auto startTime = std::chrono::high_resolution_clock::now();
    auto prevTime = startTime;

    for (int a = 0; a < 1000; a++)
    {
        clear();

        auto endTime = std::chrono::high_resolution_clock::now();
        auto deltaTimeInSeconds =
            std::chrono::duration_cast<std::chrono::duration<double>>(endTime -
                                                                      prevTime)
                .count();
        prevTime = endTime;

        auto start = std::chrono::high_resolution_clock::now();
        for(int i=0; i < polygonCount; i++)
        {
            polygons[i]->RotateAround(deltaTimeInSeconds);
            renderer.RenderPolygon(*polygons[i]);
        }
        
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        // Print frame time
        mvprintw(0, 0, "Frame Time: %.2f ms", duration.count());

        // Print memory usage
        PrintMemoryUsage();

        refresh();
    }
    for (int i = 0; i < polygonCount; i++)
    {
        delete polygons[i];
    }
    PrintMemoryUsage();
    getch();
}
