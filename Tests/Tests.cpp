// Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SerializeTests.h"
#include "ColliderTests.h"


int main()
{
  /*  Scene scene = Scene("MainScene");
    Engine* engine = new Engine(Vector2(15,5), 20);
    engine->Start(scene, false);*/

    SerializeTests serializeTest;
    serializeTest.Run();

    ColliderTests colliderTest;
    colliderTest.Run();

    std::cout << "All Test passed" << std::endl;
}



