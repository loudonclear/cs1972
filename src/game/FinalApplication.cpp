#include "FinalApplication.h"

#include "FinalMenuScreen.h"
#include "FinalDebugScreen.h"
#include "engine/graphics/Material.h"
#include "engine/graphics/Graphics.h"
#include "engine/graphics/Shape.h"
#include "engine/graphics/Obj.h"

#include <iostream>

FinalApplication::FinalApplication()
{
    Graphics *graphics = Graphics::getGlobalInstance();

    graphics->addFont("dragon", ":/fonts/dragonslapper.ttf");

    Material grass;
    grass.textureName = "grass";
    grass.textureRepeat = glm::vec2(10, 10);
    graphics->addMaterial("grass", grass);


    std::vector<std::string> shapes = {"cube", "tetrahedron", "rhombicuboctahedron"};
    for (const std::string &shape : shapes) {
        std::shared_ptr<OBJ> shapeOBJ = std::make_shared<OBJ>(":/" + shape + ".obj");
        graphics->addOBJ(shape, shapeOBJ);
        graphics->addShape(shape, shapeOBJ->vboData.toStdVector());
    }

    Light light2(Light::LIGHT_TYPE::AMBIENT, glm::vec3(0.35f), glm::vec3(1.f), glm::vec3(0), glm::vec2(0, 0));
    Graphics::getGlobalInstance()->addLight(light2);

    Light light(Light::LIGHT_TYPE::DIRECTIONAL, glm::vec3(1), glm::vec3(-0.1f, -0.5f, 1), glm::vec3(0), glm::vec2(0, 0));
    Graphics::getGlobalInstance()->addLight(light);



    addScreen("menu", std::make_shared<FinalMenuScreen>());
    addScreen("debug", std::make_shared<FinalDebugScreen>(shapes));
    setScreen("menu");
}
