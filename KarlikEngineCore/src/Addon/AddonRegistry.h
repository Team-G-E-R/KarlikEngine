#pragma once
#include <functional>
#include <memory>
#include <typeindex>
#include "Graphics/GraphicsBase.h"
#include "AddonBase.h"
#include "Runtime/Runtime.h"

class AddonRegistry {
public:
    using FactoryFn = std::function<std::unique_ptr<AddonBase>(GraphicsBase*, Runtime*)>;

    static AddonRegistry& Instance() {
        static AddonRegistry instance;
        return instance;
    }

    template<typename T>
    void Register(std::function<std::unique_ptr<T>(GraphicsBase*, Runtime*)> factory) {
        factories[typeid(T)] = [factory = std::move(factory)](GraphicsBase* graphics, Runtime* runtime) {
            return factory(graphics, runtime);
            };
    }

    template<typename T>
    void Create(GraphicsBase* graphics, Runtime* runtime) {
        auto it = factories.find(typeid(T));
        if (it != factories.end()) {
            auto basePtr = it->second(graphics, runtime);
            auto addon = std::unique_ptr<T>(dynamic_cast<T*>(basePtr.release()));
            graphics->AddAddon(std::move(addon));
        }
    }

    void Clear() {
        factories.clear();
    }

private:
    std::unordered_map<std::type_index, FactoryFn> factories;
};
