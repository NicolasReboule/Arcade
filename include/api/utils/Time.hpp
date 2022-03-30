/*
** EPITECH PROJECT, 2022
** Time.hpp
** File description:
** Time.hpp
*/

#ifndef ARCADE_TIME_HPP
#define ARCADE_TIME_HPP

#include <chrono>

namespace arcade::api::utils {
    /**
     * @brief Utility class to manipulate std::chrono
     */
    class Time {
    public:
        Time() = default;
        ~Time() = default;

        /**
         * @brief Get the current timestamp in seconds
         * @return the current timestamp in seconds
         */
        inline static long getSecondsTime() {
            std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
        }

        /**
         * @brief Get the current timestamp in milliseconds
         * @return the current timestamp in milliseconds
         */
        inline static long getMillisecondsTime() {
            std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
        }

        /**
         * @brief Get the current timestamp in microseconds
         * @return the current timestamp in microseconds
         */
        inline static long getMicrosecondsTime() {
            std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
        }

        /**
         * @brief Get the current timestamp in nanoseconds
         * @return the current timestamp in nanoseconds
         */
        inline static long getNanosecondsTime()  {
            std::chrono::time_point<std::chrono::system_clock, std::chrono::nanoseconds> now = std::chrono::system_clock::now();
            return std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
        };

    };
}

using Time = arcade::api::utils::Time;

#endif //ARCADE_TIME_HPP
