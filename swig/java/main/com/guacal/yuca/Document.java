/*
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

package com.guacal.yuca;

import com.guacal.yuca.collections.StringKeyList;
import com.guacal.yuca.collections.StringList;
import com.guacal.yuca.swig.PropertyType;

import java.util.List;

public class Document {
    private final com.guacal.yuca.swig.Document swig;

    public Document(int docId) {
        swig = new com.guacal.yuca.swig.Document(docId);
    }

    public Document(String strBasedId) {
        swig = new com.guacal.yuca.swig.Document(strBasedId);
    }

    public Document(com.guacal.yuca.swig.Document swigDoc) {
        swig = swigDoc;
    }

    public com.guacal.yuca.swig.Document swig() {
        return swig;
    }

    public int getId() {
        return swig.getId();
    }

    public void addKey(StringKey key) {
        this.swig.addKey(key.swig());
    }

    public List<StringKey> getGroupKeys(String group) {
        return new StringKeyList(swig.getGroupKeysList(group));
    }

    public List<String> getGroups() {
        return new StringList(swig.getGroupsList());
    }

    public boolean boolProperty(String key) {
        return swig.boolProperty(key);
    }

    public void boolProperty(String key, boolean value) {
        swig.boolProperty(key, value);
    }

    public char byteProperty(String key) {
        return swig.byteProperty(key);
    }

    public void byteProperty(String key, char value) {
        swig.byteProperty(key, value);
    }

    public void delete() {
        swig.delete();
    }

    public boolean hasKeys(String group) {
        return swig.hasKeys(group);
    }

    public int intProperty(String key) {
        return swig.intProperty(key);
    }

    public void intProperty(String key, int value) {
        swig.intProperty(key, value);
    }

    public int longProperty(String key) {
        return swig.longProperty(key);
    }

    public void longProperty(String key, long value) {
        swig.longProperty(key, (int) value);
    }

    public String stringProperty(String key) {
        return swig.stringProperty(key);
    }

    public void stringProperty(String key, String value) {
        swig.stringProperty(key, value);
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Document)) {
            return false;
        }
        return swig.op_eq(((Document) obj).swig);
    }

    @Override
    public int hashCode() {
        return swig.getId();
    }

    public void removeBoolProperty(String key) {
        swig.removeBoolProperty(key);
    }

    public void removeByteProperty(String key) {
        swig.removeByteProperty(key);
    }

    public void removeIntProperty(String key) {
        swig.removeIntProperty(key);
    }

    public void removeLongProperty(String key) {
        swig.removeLongProperty(key);
    }

    public void removeStringProperty(String key) {
        swig.removeStringProperty(key);
    }

    public void removeGroup(String group) {
        swig.removeGroup(group);
    }

    public List<String> propertyList(PropertyType propertyType) {
        return new StringList(swig.propertyKeys(propertyType));
    }
}
