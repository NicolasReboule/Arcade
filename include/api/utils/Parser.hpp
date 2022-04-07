/*
** EPITECH PROJECT, 2022
** Parser.hpp
** File description:
** Parser.hpp
*/

#ifndef ARCADE_PARSER_HPP
#define ARCADE_PARSER_HPP

#include "Vector.hpp"
#include "api/ex/ParserException.hpp"
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <sstream>

namespace arcade::api::utils {
    /**
     * @brief Parser class, with templated enum
     * @code
     * enum class MapType {
     *      UNKNOWN = -1,
     *      NONE = 0,
     *      BORDER,
     *      WALL,
     *      CORNER,
     *      SNAKE,
     *      FOOD,
     *      POWERUP
     * }
     *
     * int main() {
     *      std::unordered_map<char, MapType> map = {
     *          {'#', MapType::BORDER},
     *          {' ', MapType::NONE},
     *          {'X', MapType::WALL},
     *          {'+', MapType::CORNER},
     *          {'S', MapType::SNAKE},
     *          {'.', MapType::FOOD},
     *          {'*', MapType::POWERUP}
     *      };
     *      Parser<MapType> parser("assets/map/nibbler.txt", map, {60, 45}); //instanciate a parser with the map file, the map type enum, and the size max of the map
     *      parser.parse(); //parse the map, will throw some errors @see Parser::parse()
     *      parser.getMap(); //get the map (2d std::vector<MapType>)
     *      std::cout << parser.getBuffer() << std::endl; //contains the map in string
     *
     *      for (auto &item : parser.getMap()) { //display the map type
     *          for (auto &c : item)
     *              std::cout << static_cast<int>(c) << " ";
     *          std::cout << std::endl;
     *      }
     *
     * @endcode
     * @tparam T an Enum class
     */
    template<typename T>
    class Parser {
    public:
        /**
         * @brief Construct a Parser object
         * @param fileName the file to parser
         * @param symbols the map containing the key value of the file to parse
         * @param maxSize the size max of the map (like 60x45)
         */
        explicit Parser(const std::string &fileName, const std::unordered_map<char, T> &symbols, Vector2u maxSize)
            : _maxSize(maxSize), _size({0, 0})
        {
            this->_fileName = fileName;
            this->_symbols = symbols;
        }

        /**
         * @brief Parse the file, "//" is a comment
         * @attention Will throw some errors if the file is not valid
         * @throws arcade::api::ex::ParserException if the file is not found, is empty, has unknown symbols or is too big
         */
        void parse() {
            this->_file.open(this->_fileName);
            if (!this->_file.is_open())
                throw arcade::api::ex::ParserException("File not found");
            if (this->_file.rdbuf()->in_avail() == 0)
                throw arcade::api::ex::ParserException("File is empty");
            this->parseMap();
        }

        /**
         * @brief Get the file name
         * @return the file name
         */
        const std::string &getFileName() const { return this->_fileName; }

        /**
         * @brief Get the actual map size
         * @return the size of the map
         */
        const Vector2u &getSize() const { return this->_size; }

        /**
         * @brief Get the symbols map
         * @return the symbols map
         */
        const std::unordered_map<char, T> &getSymbols() const { return this->_symbols; }

        /**
         * @brief Get the size max of the map
         * @return the size max of map
         */
        const Vector2u &getMaxSize() const { return this->_maxSize; }

        /**
         * @brief Get the map buffer
         * @return the buffer
         */
        const std::string &getBuffer() const { return this->_buffer; }

        /**
         * @brief Get the map
         * @return the parsed map
         */
        const std::vector<std::vector<T>> &getMap() const { return this->_map; }

    private:
        std::string _fileName; /**< The file name */
        std::unordered_map<char, T> _symbols; /**< The symbols map */
        Vector2u _maxSize; /**< The sizem max of the map */
        Vector2u _size; /**< The actual size of the map */
        std::string _buffer; /**< The buffer */
        std::vector<std::vector<T>> _map; /**< The map */
        std::ifstream _file; /**< The file */

        /**
         * @brief Remove the comment of the buffer (aka //text)
         */
        std::string removeComment(const std::string &line)
        {
            std::regex commentaryRegex("//.*");
            return std::regex_replace(line, commentaryRegex, "");
        }

        /**
         * @brief Parse the map
         */
        void parseMap()
        {
            std::string line;
            while (std::getline(this->_file, line)) {
                line = this->removeComment(line);
                if (line.empty())
                    continue;
                this->_buffer += line + "\n";
                this->_size.x = std::max(this->_size.x, static_cast<unsigned int>(line.size()));
                if (this->_size.x > this->_maxSize.x || this->_size.y + 1 > this->_maxSize.y)
                    throw arcade::api::ex::ParserException("Map is too big");
                std::vector<T> tmp;
                for (char &sym : line) {
                    if (!this->_symbols.contains(sym))
                        throw arcade::api::ex::ParserException(std::string("Unknown map symbol: ") + sym);
                    tmp.push_back(this->_symbols[sym]);
                }
                this->_map.push_back(tmp);
                this->_size.y++;
            }
        }
    };
}

template<typename T>
using Parser = arcade::api::utils::Parser<T>;

#endif //ARCADE_PARSER_HPP
