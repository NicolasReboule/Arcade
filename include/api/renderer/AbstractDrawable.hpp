/*
** EPITECH PROJECT, 2022
** AbstractDrawable.hpp
** File description:
** AbstractDrawable.hpp
*/

#ifndef ARCADE_ABSTRACTDRAWABLE_HPP
#define ARCADE_ABSTRACTDRAWABLE_HPP

#include "IDrawable.hpp"
#include "api/utils/Time.hpp"
#include "api/utils/SHA1.hpp"
#include <string>

namespace arcade::api::renderer {
    /**
     * @brief Abstract only to specify an id
     */
    class AbstractDrawable : public IDrawable {
    public:
        AbstractDrawable()
        {
            long time = Time::getNanosecondsTime();
            this->_id = SHA1::create(std::to_string(time));
            #ifdef DEBUG
                std::cout << "AbstractDrawable created with id: " << this->_id << std::endl;
            #endif
        }

        /**
         * @brief Get the id of the drawable
         * @return the id (sha1 hash)
         */
        std::string getId() const { return this->_id; }

        /**
         * @brief Set the id of the drawable
         * @param id the new id
         */
        void setId(const std::string &id) { this->_id = id; }

    protected:
        std::string _id; /**< The id of the drawable (sha1 hash using timestamp) */
    };

}

#endif //ARCADE_ABSTRACTDRAWABLE_HPP
