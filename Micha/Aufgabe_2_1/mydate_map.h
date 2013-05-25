#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H

#include "mydate.h"
#include "iostream"

namespace MyDate {

    class Map {

        public:
            // aliases for key type and mapped type
            typedef MyDate::Date key_t;
            typedef std::string mapped_t;
            mapped_t& operator[](const key_t& key);

        protected:
            // internal node type for binary search tree
            class Node {

                public:
                    std::pair<key_t, mapped_t> m_pair; // key/value pair
                    Node *m_up, *m_left, *m_right; // pointers to other nodes

                    explicit Node(const key_t key, const mapped_t mapped, Node* parent):
                        m_pair(key, mapped), m_up(parent) {}
            };

        Node* m_root; // root node of search tree
        size_t m_size; // number of elements in tree
        const mapped_t M_NOT_IN_MAP; // return value if not in map

        Map():
            m_root(0), m_size(0){}

        Node* getRootNode();
        mapped_t& operator[](const Map::key_t& key);
    };
}

#endif // MYDATE_MAP_H
