/*
** EPITECH PROJECT, 2022
** AbstractDrawable.hpp
** File description:
** AbstractDrawable.hpp
*/

#ifndef ARCADE_ABSTRACTDRAWABLE_HPP
#define ARCADE_ABSTRACTDRAWABLE_HPP

#include "IDrawable.hpp"
#include "ITransformable.hpp"
#include "api/utils/Time.hpp"
#include "api/utils/SHA1.hpp"
#include "api/ex/Exceptions.hpp"
#include "api/Constant.hpp"

namespace arcade::api::renderer {
    /**
     * @brief Abstract only to specify an id
     * @attention Setter should be overrided in child class, and method who add/multiply the transform
     */
    class AbstractDrawable : public IDrawable, public ITransformable {
    public:
        /**
         * @brief Construct an AbstractDrawable
         */
        AbstractDrawable() : _position({0, 0}), _size({1, 1}), _scale({1, 1}), _origin({0, 0})
        {
            this->_lastUpdate = Time::getNanosecondsTime();
            this->_id = SHA1::create(std::to_string(this->_lastUpdate));
            this->_rotation = 0;
            #ifdef DEBUG
                std::cout << "AbstractDrawable created with id: " << this->_id << " Timestamp: " << this->_lastUpdate << std::endl;
            #endif
        }

        /**
         * @brief Get the id of the drawable
         * @return the id (sha1 hash)
         */
        const std::string &getId() const final { return this->_id; }

        /**
         * @brief Set the id of the drawable
         * @param id the new id
         * @deprecated this method will be removed in the future
         */
        void setId(const std::string &id) { this->_id = id; }

        /**
         * @brief Update the abstract drawable
         * @attention Needs to be implemented in child class
         * NEVER USE THIS METHOD
         * @param drawable the updated rectangle
         * @throws arcade::api::ex::DrawableException
         */
        void update(const IDrawable &drawable) override
        {
            (void) drawable;
            this->_lastUpdate = Time::getNanosecondsTime();
            throw ex::DrawableException("AbstractDrawable::update() should not be called");
        }

        /**
         * @brief Get the last update timestamp
         * @return the last update timestamp in nanoseconds
         */
        long getLastUpdate() const final { return this->_lastUpdate; }

        void setPosition(const Vector2f &pos) override { this->_position = pos; }
        void setPosition(float x, float y) override { this->_position = {x, y}; }

        void setRotation(float rotation) override { this->_rotation = rotation; }

        void setScale(const Vector2f &scale) override { this->_scale = scale; }
        void setScale(float factorX, float factorY) override { this->_scale = {factorX, factorY}; }

        void setOrigin(const Vector2f &origin) override { this->_origin = origin; }
        void setOrigin(float x, float y) override { this->_origin = {x, y}; }

        const Vector2f &getPosition() const final { return this->_position; }
        float getRotation() const final { return this->_rotation; }
        const Vector2f &getScale() const final {  return this->_scale; }
        const Vector2f &getOrigin() const final { return this->_origin; }

        void move(const Vector2f &offset) override {  this->_position = { this->_position.x += offset.x, this->_position.y += offset.y}; }
        void move(float offsetX, float offsetY) override {  this->_position = {this->_position.x += offsetX, this->_position.y += offsetY}; }

        void rotate(float angle) override { this->_rotation += angle; }

        void scale(const Vector2f &factor) override {  this->_scale = {this->_scale.x * factor.x, this->_scale.y * factor.y}; }
        void scale(float factorX, float factorY) override { this->_scale = {this->_scale.x * factorX, this->_scale.y * factorY}; }

        /**
         * @brief Get the size of the sprite
         * @return the size of the sprite
         */
        const Vector2f &getSize() const { return this->_size; }

        /**
         * @brief Set the size of the sprite
         * @param size the new size of the sprite
         */
        virtual void setSize(const Vector2f &size) { this->_size = size; }

    protected:
        std::string _id; /**< The id of the drawable (sha1 hash using timestamp) */
        long _lastUpdate;
        Vector2f _position; /**< The position of the drawable */
        Vector2f _size; /**< The the size of the drawable */
        Vector2f _scale; /**< The scale of the drawable */
        Vector2f _origin; /**< The origin of the drawable */
        float _rotation; /**< The rotation of the drawable */
    };

}

#endif //ARCADE_ABSTRACTDRAWABLE_HPP
