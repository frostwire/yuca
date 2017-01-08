//
// Created by gubatron on 11/19/16.
//

#ifndef YUCA_YUCA_H
#define YUCA_YUCA_H

#include <string>
#include <set>
#include <map>

namespace yuca {
    class Key;
    class Document;
    typedef std::string string;
    typedef std::set<Document *> DocumentSet;
    typedef std::set<Key *> KeySet;

    /** map<string, KeySet>> */
    typedef std::map<string, KeySet> DocumentKeysMap;

    std::string  version() {
        return "yuca-0.0.1-";// + std::string(libtorrent::version());
    }
}
#endif //YUCA_YUCA_H
