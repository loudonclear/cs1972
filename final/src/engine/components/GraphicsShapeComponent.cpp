#include "GraphicsShapeComponent.h"
#include "engine/components/Transform.h"
#include "engine/physics/ShapeCollider.h"
#include "engine/physics/Collision.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>

GraphicsShapeComponent::GraphicsShapeComponent(std::shared_ptr<GameObject> &parent, const std::string &shapeName, const std::string &materialName) :
    GraphicsComponent(parent, materialName), m_shapeName(shapeName)
{
}


void GraphicsShapeComponent::draw(Graphics *g) {

    g->clearTransform();
    g->setMaterial(m_materialName);
    g->setTransform(m_transform->getTransformMatrix());
    g->drawShape(m_shapeName);
}