// Tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SerializeTests.h"
#include "ColliderTests.h"


int main()
{
    SerializeTests serializeTest;
    serializeTest.Run();

    ColliderTests colliderTest;
    colliderTest.Run();

    std::cout << "All Test passed" << std::endl;
}



