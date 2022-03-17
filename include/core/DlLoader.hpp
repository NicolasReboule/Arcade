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
        public :
            std::shared_ptr<T> getInstance(std::string name);
            void closeInstance(void);
    };

    template <class T>
    std::shared_ptr<T> DlLoader<T>::getInstance(std::string name)
    {
        std::cout << "Openning library" << std::endl;
        void *handler = dlopen(name.c_str(), RTLD_LAZY);
        if (!handler) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        _handler = handler;
        std::shared_ptr<T> (*entryPoint)(void) = (std::shared_ptr<T> (*)(void))dlsym(handler, "entryPoint");
        if (!entryPoint) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
        return (*entryPoint)();
    }

    template <class T>
    void DlLoader<T>::closeInstance(void)
    {
        std::cout << "Closing library" << std::endl;
        dlclose(_handler);
    }
}
#endif /* !DLLOADER_HPP_ */
