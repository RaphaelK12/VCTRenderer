#pragma once

#include <glm/detail/type_vec3.hpp>
#include <glm/mat4x4.hpp>

#include "../util/single_active.h"
#include "../types/frustum.h"

/// <summary>
/// Describes a scene camera.
/// </summary>
/// <seealso cref="SingleActive{Camera}" />
class Camera : public SingleActive<Camera>
{
    public:
        Camera();

        float ClipPlaneFar() const;
        /// <summary>
        /// Sets the <see cref="clipPlaneFar"> value.
        /// Value is in the range [0.01, inf]
        /// </summary>
        /// <param name="val">The value.</param>
        void ClipPlaneFar(float val);

        float ClipPlaneNear() const;
        /// <summary>
        /// Sets the <see cref="clipPlaneNear"> value.
        /// Value is in the range [0.01, inf]
        /// </summary>
        /// <param name="val">The value.</param>
        void ClipPlaneNear(float val);

        float HorizontalFoV() const;
        /// <summary>
        /// Sets the <see cref="horizontalFoV"> value.
        /// Value is in the range [1, 179]
        /// </summary>
        /// <param name="val">The value.</param>
        void HorizontalFoV(float val);

        float AspectRatio() const;
        void AspectRatio(float val);

        const glm::vec3 &LookAt() const;
        void LookAt(const glm::vec3 &val);

        const glm::vec3 &Position() const;
        void Position(const glm::vec3 &val);

        const glm::vec3 &Up() const;
        void Up(const glm::vec3 &val);

        const glm::mat4x4 &ViewMatrix();
        const glm::mat4x4 &ProjectionMatrix();

        /// <summary>
        /// Checks if the bounding volume is inside the
        /// camera frustum <see cref="frustum">
        /// </summary>
        /// <param name="volume">The volume.</param>
        /// <returns></returns>
        bool InFrustum(const BoundingVolume &volume);
    private:
        float clipPlaneFar;
        float clipPlaneNear;
        float horizontalFoV;
        float aspectRatio;
        glm::vec3 lookAt;
        glm::vec3 position;
        glm::vec3 up;

        void ComputeViewMatrix();
        void ComputeProjectionMatrix();

        bool viewValuesChanged;
        bool projectionValuesChanged;
        bool frustumValuesChanged;

        glm::mat4x4 viewMatrix;
        glm::mat4x4 projectionMatrix;
        Frustum frustum;
};

