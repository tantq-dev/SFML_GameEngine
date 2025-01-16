
#include "imgui.h"
#include "imgui-SFML.h"
#include "Vec2.h"
#include "GameEngine.h"

#include <SFML/Graphics.hpp>
#include<iostream>


int main()
{

    GameEngine engine = GameEngine();
    engine.run();
    
 
    return 0;
}