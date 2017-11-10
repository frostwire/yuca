//
// Created by gubatron on 11/16/16.
//

#ifndef YUCA_KEY_H
#define YUCA_KEY_H

#include <string>

namespace yuca {
    class Key {
    public:
        Key() = default;

        explicit Key(std::string myTag) : tag(myTag) {
        }

        virtual bool operator<(Key other) const;

        virtual bool operator==(Key other) const;

        std::string getTag() const;

    private:
        // TODO, make const
        std::string tag;
    };
}

#endif //YUCA_KEY_H

