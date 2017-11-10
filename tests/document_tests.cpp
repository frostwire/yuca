//
// Created by gubatron on 11/19/2016.
//
#ifndef YUCA_DOCUMENT_TESTS_H
#define YUCA_DOCUMENT_TESTS_H

#include <gtest/gtest.h>
#include <yuca/key.hpp>
#include <yuca/document.hpp>

using namespace yuca;

class DocumentTests : public ::testing::Test {
public:
    void SetUp() {
        fooTag = ":foo";
        barTag = ":bar";

        fooKey = Key(fooTag);
        barKey = Key(barTag);
        barKey2 = Key(barTag);
        document = Document();
    }

    std::string fooTag;
    Key fooKey;
    std::string barTag;

    Key barKey;
    Key barKey2;
    Document document;
};


TEST_F(DocumentTests, TestIfKeyCanBeAdded) {

    KeySet isEmpty;
    document.getTagKeys(fooTag, isEmpty);
    ASSERT_TRUE(isEmpty.empty());

    document.addKey(fooKey);
    KeySet fooKeys;
    document.getTagKeys(fooTag, fooKeys);
    ASSERT_TRUE(fooKeys.size() == 1);

    document.addKey(barKey);
    document.addKey(barKey2);

    KeySet barKeys;
    document.getTagKeys(barTag, barKeys);
    ASSERT_TRUE(barKeys.size() == 2);

    // make sure it's the same one we've added
    auto it = fooKeys.find(fooKey);
    ASSERT_TRUE(fooKeys.size() == 1);
    ASSERT_TRUE(it == fooKeys.end());

    Key isThisFooKey = *it;
    std::cout << "tag found? " << isThisFooKey.getTag() << std::endl;

    ASSERT_TRUE(isThisFooKey.getTag() == fooTag);
    ASSERT_TRUE(isThisFooKey == fooKey);

    it = barKeys.find(barKey);
    Key isThisBarKey = *it;
    std::cout << "tag found? " << isThisBarKey.getTag() << std::endl;
    ASSERT_TRUE(isThisBarKey.getTag() == barTag);
    ASSERT_TRUE(isThisBarKey == barKey);

    it++;
    Key isThisBarkey2 = *it;
    ASSERT_TRUE(isThisBarkey2.getTag() == barTag);
    ASSERT_TRUE(isThisBarkey2 == barKey2);

    // now let's try adding the same element again, size should be the same as we're dealing with a set of unique keys
    document.addKey(barKey);
    document.getTagKeys(barTag, barKeys);
    ASSERT_TRUE(barKeys.size() == 2);
}

TEST_F(DocumentTests, TestsIfSingleKeyCanBeRemoved) {
    document.addKey(fooKey);
    document.addKey(barKey);
    KeySet fooKeySet;
    document.getTagKeys(fooTag, fooKeySet);
    ASSERT_TRUE(fooKeySet.size() == 1);

    KeySet barKeySet;
    document.getTagKeys(barTag, barKeySet);
    ASSERT_TRUE(barKeySet.size() == 1);
    document.addKey(barKey2);

    document.getTagKeys(barTag, barKeySet);
    ASSERT_TRUE(barKeySet.size() == 2);

    document.removeKey(fooTag, fooKey);
    document.getTagKeys(fooTag, fooKeySet);
    ASSERT_TRUE(fooKeySet.size() == 0);

    KeySet::iterator it_not_there = fooKeySet.find(fooKey);
    ASSERT_TRUE(it_not_there == fooKeySet.end());

    document.getTagKeys(barTag, barKeySet);
    KeySet::iterator bar_there = barKeySet.find(barKey);
    ASSERT_TRUE(*bar_there == barKey);

    KeySet::iterator bar2_there = barKeySet.find(barKey2);
    ASSERT_TRUE(bar2_there != barKeySet.end());
    ASSERT_TRUE(*bar2_there == barKey2);
}

TEST_F(DocumentTests, TestGetTags) {
    std::string zeeTag = "zeeTag:";
    Key zeeKey(zeeTag);
    document.addKey(zeeKey);
    document.addKey(fooKey);
    document.addKey(barKey);

    std::cout << "Getting all the tags...";

    std::set<std::string> tags;
    document.getTags(tags);
    std::cout << "Got " << tags.size() << " tags" << std::endl;
    auto it = tags.begin();
    std::cout << "tags[0] => " << *it++ << std::endl;
    std::cout << "tags[1] => " << *it++ << std::endl;
    std::cout << "tags[2] => " << *it << std::endl;

    // elements will be sorted as they're inserted in the set
    // they are not in the set in the order they were inserted.
    it = tags.begin();
    ASSERT_TRUE(*it++ == barTag);
    ASSERT_TRUE(*it++ == fooTag);
    ASSERT_TRUE(*it == zeeTag);
}

TEST_F(DocumentTests, TestRemoveTag) {
    std::string nameTag = "name:";
    Key nameKey = Key(nameTag);
    document.addKey(nameKey);
    document.addKey(barKey);
    document.addKey(barKey2);
    KeySet nameTagKeys;
    document.getTagKeys("name:", nameTagKeys);
    KeySet::iterator foundKeys = nameTagKeys.find(barKey);
    ASSERT_TRUE(foundKeys == nameTagKeys.end()); //assert not found
    foundKeys = nameTagKeys.find(nameKey);
    ASSERT_FALSE(foundKeys == nameTagKeys.end());
    ASSERT_TRUE(*foundKeys == nameKey);
    ASSERT_TRUE(foundKeys == nameTagKeys.begin());
    document.removeKey(nameTag, nameKey);
    document.getTagKeys("name:", nameTagKeys);
    ASSERT_TRUE(nameTagKeys.empty());
    KeySet barKeys;
    document.getTagKeys(barKey.getTag(), barKeys);
    ASSERT_TRUE(barKeys.size() == 2);
    document.removeTag(barKey.getTag());
    document.getTagKeys(barKey.getTag(), barKeys);
    ASSERT_TRUE(barKeys.empty());
}

#endif
