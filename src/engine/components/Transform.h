#ifndef TRANSFORM_H
#define TRANSFORM_H

#define GLM_FORCE_RADIANS

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Component.h"
#include "engine/physics/Ray.h"

class Transform : public virtual Component
{
public:
    Transform(GameObject *parent);

    glm::vec3 getPosition();
    glm::quat getRotation();
    glm::vec3 getScale();
    glm::mat4x4 getTransformMatrix();
    glm::mat4x4 getInverseTransformMatrix();
    glm::mat4x4 getInverseTransposeMatrix();

    void setPosition(glm::vec3 position);
    void setRotation(glm::quat rotation);
    void setScale(glm::vec3 scale);

    void translate(glm::vec3 trans);
    void rotate(glm::quat rot);
    void rotateAngularAmt(const glm::vec3 &angularAmt);
    void scale(glm::vec3 scale);

    glm::vec3 transformPoint(const glm::vec3 &point);
    glm::vec3 inverseTransformPoint(const glm::vec3 &point);
    glm::vec3 transformVector(const glm::vec3 &vec);
    Ray transformRay(const Ray &ray);
    glm::vec3 transformNormal(const glm::vec3 &normal);
    glm::vec3 inverseRotateVector(const glm::vec3 &vec);

    static glm::vec3 transformPoint(const glm::vec3 &point, const glm::mat4x4 &m);
    static glm::vec3 transformVector(const glm::vec3 &vec, const glm::mat4x4 &m);

private:

    glm::vec3 m_position;
    glm::quat m_rotation;
    glm::vec3 m_scale;
    glm::mat4x4 m_transformMatrix, m_inverseTransformMatrix, m_inverseTransposeMatrix;

    bool m_rebuild = false;
};

#endif // TRANSFORM_H
