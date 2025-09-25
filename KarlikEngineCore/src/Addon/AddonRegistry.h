#pragma once
#include <functional>
#include <memory>
#include <typeindex>
#include "Graphics/GraphicsBase.h"
#include "AddonBase.h"

class AddonRegistry {
public:
    using FactoryFn = std::function<std::unique_ptr<AddonBase>(GraphicsBase*)>;

    static AddonRegistry& Instance() {
        static AddonRegistry instance;
        return instance;
    }

    template<typename T>
    void Register(std::function<std::unique_ptr<T>(GraphicsBase*)> factory) {
        factories[typeid(T)] = [factory = std::move(factory)](GraphicsBase* graphics) {
            return factory(graphics);
            };
    }

    template<typename T>
    void Create(GraphicsBase* graphics) {
        auto it = factories.find(typeid(T));
        if (it != factories.end()) {
            auto basePtr = it->second(graphics);
            auto addon = std::unique_ptr<T>(dynamic_cast<T*>(basePtr.release()));
            graphics->AddAddon(std::move(addon));
        }
    }

private:
    std::unordered_map<std::type_index, FactoryFn> factories;
};
