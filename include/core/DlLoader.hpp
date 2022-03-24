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
#include "api/library/IDLLoader.hpp"
#include "api/library/ILibrary.hpp"

namespace arcade {
    template <typename T>
    class DlLoader : public arcade::api::library::IDLLoader<T> {
        private:
            std::string _path;
            void *_handle;
            T *_instance;
        public:
            DlLoader() : _handle(nullptr)
            {
                this->_instance = nullptr;
            }

            inline void load(const std::string &path) override
            {
                this->_handle = dlopen(path.c_str(), RTLD_LAZY);
                if (!this->_handle)
                    throw arcade::api::ex::LibraryNotFound(dlerror());
                this->_path = path;
            }

            inline void unload() override
            {
                if (this->_handle && dlclose(_handle))
                    throw arcade::api::ex::LibraryInvalidHandle(dlerror());
            }

            inline void loadInstance() override
            {
                if (!this->_handle)
                    throw arcade::api::ex::LibraryNotFound(dlerror());
                void *sym =  dlsym(_handle, ENTRY_POINT_NAME);
                if (!sym)
                    throw arcade::api::ex::LibraryEntryPointNotFound(dlerror());
                auto tmp = reinterpret_cast<T *(*)()>(sym)();
                this->_instance = tmp;
            }

            inline T *operator->() const override
            {
                return this->_instance;
            }

            inline T *operator*() const override
            {
                return this->_instance;
            }

            inline T *getInstance() const override
            {
                return this->_instance;
            }

            inline const std::string &getPath() const override
            {
                return this->_path;
            }
    };
}
#endif /* !DLLOADER_HPP_ */
