/**
 * MIT License
 *
 * Copyright (c) 2016-2018 Angel Leon, Alden Torres
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

//
// Created by gubatron on 11/16/16.
//

#ifndef YUCA_KEY_H
#define YUCA_KEY_H

#include <string>
#include <utility>

namespace yuca {
    class Key {
    public:
        Key() = default;

        explicit Key(long my_id, std::string my_group) : id(my_id), group(std::move(my_group)) {
        }

        Key(Key const&) = default;

        virtual ~Key() = default;

        // THIS OPERATOR IS USED FOR std::set.find()
        virtual bool operator<(const Key &right_side) const;

        virtual bool operator<=(const Key &right_side) const;

        virtual bool operator>(const Key &right_side) const;

        virtual bool operator>=(const Key &right_side) const;

        virtual bool operator==(const Key &other) const;

        std::string getGroup() const;

        long getId() const;

        friend std::ostream &operator<<(std::ostream &output_stream, Key &key);

    protected:
        long id{};
        std::string group;
    };

    class StringKey : public Key {
    public:
        explicit StringKey(const std::string &string_key, const std::string &my_group) :
        Key(static_cast<long>(std::hash<std::string>{}(my_group + string_key)), my_group), str_key(string_key) {
        }

        std::string getString() const {
            return str_key;
        }

        friend std::ostream &operator<<(std::ostream &output_stream, StringKey &key);

    private:
        std::string str_key;
    };
}

#endif //YUCA_KEY_H

