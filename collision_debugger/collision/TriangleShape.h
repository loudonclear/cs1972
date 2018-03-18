#ifndef TRIANGLESHAPE_H
#define TRIANGLESHAPE_H

#include "PolyhedralConvexShape.h"

class TriangleShape : public PolyhedralConvexShape
{
public:
    TriangleShape(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);

    virtual glm::vec3 getSupport(const glm::vec3 &dir, std::shared_ptr<Transform> t = nullptr);
    virtual bool pointInside(const glm::vec3 &point, std::shared_ptr<Transform> t = nullptr);
    virtual bool raycast(const Ray &ray, std::shared_ptr<Transform> t, RaycastResult &result);
    bool pointWithinEdges(const glm::vec3 &point);

    glm::vec3 getV0() { return vertices[0]; }
    glm::vec3 getV1() { return vertices[1]; }
    glm::vec3 getV2() { return vertices[2]; }
    glm::vec3 getNormal() { return normal; }

protected:
    glm::vec3 vertices[3];
    glm::vec3 normal;
    glm::vec4 plane;

};

#endif // TRIANGLESHAPE_H