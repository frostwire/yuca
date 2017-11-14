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

        explicit Key(long id, std::string &my_tag) : tag(my_tag), id(id) {
        }

        // THIS OPERATOR IS USED FOR std::set.find()
        virtual bool operator<(const Key &right_side) const;

        virtual bool operator==(const Key &other) const;

        std::string getTag() const;

        long getId() const;

        void dumpToStream(std::ostream &output_stream) const;

    private:
        std::string tag;
        long id;
    };
}

#endif //YUCA_KEY_H

