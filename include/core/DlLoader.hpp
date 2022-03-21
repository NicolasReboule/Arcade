/*
** EPITECH PROJECT, 2022
** B-OOP-400-RUN-4-1-arcade-nicolas.reboule
** File description:
** DlLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>
#include <unistd.h>
#include <memory>

namespace arcade {
    template <typename T>
    class DlLoader {
        private:
            void *_handler;
            std::shared_ptr<T> _instance;
            std::string _name;
        public :
            DlLoader();
            ~DlLoader();
            DlLoader(const std::string &name);
            DlLoader(const DlLoader &);
            DlLoader &operator=(const DlLoader &);
            std::shared_ptr<T> operator->(void);
            inline std::shared_ptr<T> getInstance() const {return _instance;};
            void setInstance(std::string name);
            void closeInstance(void);
    };

    template <class T>
    DlLoader<T>::DlLoader() : _name("DlLoader")
    {
        _handler = nullptr;
        _instance = nullptr;
        std::cout << _name << ": No library given" << std::endl;
    }

    template <class T>
    DlLoader<T>::~DlLoader()
    {
        _instance = nullptr;
        closeInstance();
    }

    template <class T>
    DlLoader<T>::DlLoader(const DlLoader &cpy)
    {
        *this = cpy;
    }

    template <class T>
    DlLoader<T> &DlLoader<T>::operator=(const DlLoader &cpy)
    {
        this->_name = cpy._name;
        this->_handler = cpy._handler;
        this->_instance = cpy._instance;
        return *this;
    }

    template <class T>
    std::shared_ptr<T> DlLoader<T>::operator->(void)
    {
        return _instance;
    }

    template <class T>
    DlLoader<T>::DlLoader(const std::string &name) : _name(name)
    {
        std::cout << _name << ": Openning library " << name << std::endl;
        _handler = dlopen(name.c_str(), RTLD_LAZY);
        if (!_handler) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        std::shared_ptr<T> (*entryPoint)(void) =
        (std::shared_ptr<T> (*)(void))dlsym(_handler, "entryPoint");
        if (!entryPoint) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        _instance = (*entryPoint)();
    }

    template <class T>
    void DlLoader<T>::setInstance(std::string name)
    {
        if (_handler != nullptr || _instance != nullptr) {
            std::cerr << _name << ": Already has a library open" << std::endl;
            exit(84);
        }
        std::cout << _name << ": Openning library " << name << std::endl;
        _handler = dlopen(name.c_str(), RTLD_LAZY);
        if (!_handler) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        _name = name;
        std::shared_ptr<T> (*entryPoint)(void) =
        (std::shared_ptr<T> (*)(void))dlsym(_handler, "entryPoint");
        if (!entryPoint) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        _instance = (*entryPoint)();
    }

    template <class T>
    void DlLoader<T>::closeInstance(void)
    {
        std::cout << _name << ": Closing library" << std::endl;
        dlclose(_handler);
        _handler = nullptr;
    }
}
#endif /* !DLLOADER_HPP_ */
