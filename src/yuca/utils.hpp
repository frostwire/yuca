//
// Java Collections Inspired wrappers for std:: collections
// Created by gubatron on 3/23/18.
//

#ifndef YUCA_UTILS_HPP
#define YUCA_UTILS_HPP

#include <set>
#include <map>

namespace yuca {
    namespace utils {
	    template<class T>
        class Set {
        public:
	        void add(T e) {
                s.insert(e);
            }

            void addAll(Set<T> other_set) noexcept {
                for (auto const& x : other_set.s) {
                	add(x);
                }
            }

            bool contains(T something) const noexcept {
                return s.find(something) != s.end();
            }

            bool containsAll(Set<T> other) const noexcept {
                for (auto const& x : other.s) {
                	if (!contains(x)) {
                		return false;
                	}
                }
                return true;
	        }

            bool isEmpty() const noexcept {
                return s.empty();
            }

            bool remove(T something) {
                auto it = s.find(something);
                if (it == s.end()) {
                    return false;
                }
                s.erase(it);
                return true;
            }

            void removeAll(Set<T> other_set) {
                for (auto const& x : other_set.s) {
                    remove(x);
                }
            }

            void clear() {
	        	s.clear();
	        }

            /**
             * @return a copied std::set<T> instance of the containing std::set<T> s
             */
	        std::set<T> getStdSet() const {
	        	return s;
	        }

	        unsigned long size() const {
	        	return s.size();
	        }

	        friend std::ostream& operator<<(std::ostream &output_stream, Set<T> set) {
	        	long last_index = set.size() - 1;
	        	long i=0;
		        std::string sep(", ");
	        	for (auto const& x : set.s) {
	        		output_stream << x;
	        		if (i++ != last_index) {
			        	output_stream << sep;
			        }
	        	}
		        return output_stream;
	        }

        private:
            std::set<T> s;
        };


        template<class K, class V>
        class Map {
        public:
            bool containsKey(K key) {
                return m.find(key) != m.end();
            }

            V get(K key) {
                auto it = m.find(key);
                if (it == m.end()) {
                    return nullptr;
                }
                return *it->second;
            }

        private:
            std::map<K, V> m;
        };
    }
}

#endif //YUCA_UTILS_HPP