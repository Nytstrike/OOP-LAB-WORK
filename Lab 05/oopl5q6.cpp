// Write a program that uses composition to implement a game engine. A game engine is madeup of several components. For example:
// a) Graphics rendering engine
// b) Input handler
// c) Physics engine
// You don’t have to write the logicforhow these individual components work.


#include <iostream>
using namespace std;

class GraphicsRenderEngine
{
public:
    GraphicsRenderEngine()
    {
        cout << "Graphics created." << endl;
    }

    ~GraphicsRenderEngine()
    {
        cout << "Graphics destroyed." << endl;
    }
};

class InputHandler
{
public:
    InputHandler()
    {
        cout << "Input created." << endl;
    }

    ~InputHandler()
    {
        cout << "Input destroyed." << endl;
    }
};

class PhysicsEngine
{
public:
    PhysicsEngine()
    {
        cout << "Physics created." << endl;
    }

    ~PhysicsEngine()
    {
        cout << "Physics destroyed." << endl;
    }
};

class GameEngine
{
    GraphicsRenderEngine renderEngine;
    InputHandler input;
    PhysicsEngine phyEngine;

public:
    GameEngine()
    {
        cout << "created." << endl;
    }

    ~GameEngine()
    {
        cout << "Game destroyed." << endl;
    }
};

int main()
{
    GameEngine game;
    return 0;
}