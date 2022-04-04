/*
** EPITECH PROJECT, 2022
** CircularVector.hpp
** File description:
** CircularVector.hpp
*/

#ifndef ARCADE_CIRCULARVECTOR_HPP
#define ARCADE_CIRCULARVECTOR_HPP

#include <vector>
#include <iostream>
#include <functional>

namespace arcade::api::utils {
    /**
     * @brief A vector that can be used to store elements in a circular way.
     * @tparam T the type of the vector
     */
    template <class T>
    class CircularVector {
    public:
        /**
         * @brief Construct a new Circular Vector object
         */
        CircularVector() : _size(0), _index(0) {}

        /**
         * @brief Return the current T object
         * @return a reference to the current object
         */
        inline T &operator->() const { return this->_vector[this->_index]; }

        /**
         * @brief Return the current T object
         * @return a reference to the current object
         */
        inline T &operator*() const { return this->_vector[this->_index]; }

        /**
         * @brief Return the current T object
         * @return a reference to the current object
         */
        inline const T &get() const { return this->_vector[this->_index]; }

        /**
         * @brief Return the T object at index
         * @param index the index of the object
         * @throws std::out_of_range if index is out of range
         * @return a reference to the object
         */
        inline T &operator[](std::size_t index)
        {
            if (index >= this->_size)
                throw std::out_of_range("Index out of range");
            return this->_vector[index];
        }

        /**
         * @brief Increment the actual index (in a circular way)
         * @return this
         */
        inline void operator++(int)
        {
            if (this->_index + 1 >= this->_size)
                this->_index = 0;
            else
                this->_index++;
        }

        /**
         * @brief Decrement the actual index (in a circular way)
         * @return this
         */
        inline void operator--(int)
        {
            if (this->_index == 0)
                this->_index = this->_size - 1;
            else
                this->_index--;
        }

        /**
         * @brief Return the size of the vector
         * @return
         */
        inline std::size_t size() const
        {
            return this->_size;
        }

        /**
         * @brief Return the current index value
         * @return the current index value
         */
        inline std::size_t index() const
        {
            return this->_index;
        }

        /**
         * @brief Set the actual index
         * @param index the new index value
         * @throws std::out_of_range if index is out of range
         */
        inline void setIndex(std::size_t index)
        {
            if (index >= this->_size)
                throw std::out_of_range("Index out of range");
            this->_index = index;
        }

        /**
         * @brief Return if the circular vector is empty
         * @return if the circular vector is empty
         */
        inline bool empty() const
        {
            return this->_size == 0;
        }

        /**
         * @brief Add an item to the circular vector
         * @param item an item to add
         */
        inline void push(T item)
        {
            this->_vector.push_back(item);
            this->_size++;
        }

        /**
         * @brief Remove the item passed as parameter
         * @param item the item to remove
         * @return true if the item was removed, false otherwise
         */
        inline bool remove(T &item)
        {
            bool removed = false;
            std::remove_if(this->_vector.begin(), this->_vector.end(), [&item, &removed](T &i) {
                if (i == item)
                    removed = true;
                return i == item;
            });
            if (removed)
                this->_size--;
            return removed;
        }

        /**
         * @brief Remove the item at the current index
         * @return true if the item was removed, false otherwise
         */
        inline bool remove()
        {
            return remove(this->_vector[this->_index]);
        }

        /**
         * @brief Remove the item at the index passed as parameter
         * @param index the index of the item to remove
         * @throws std::out_of_range if index is out of range
         * @return true if the item was removed, false otherwise
         */
        inline bool remove(std::size_t index)
        {
            return this->remove(this[index]);
        }

        /**
         * @brief Get the vector used as storage
         * @return the vector
         */
        inline std::vector<T> &getVector()
        {
            return this->_vector;
        }

    private:
        std::vector<T> _vector;
        std::size_t _size;
        std::size_t _index;
    };
}

template<typename T>
using CircularVector = arcade::api::utils::CircularVector<T>;

#endif //ARCADE_CIRCULARVECTOR_HPP
