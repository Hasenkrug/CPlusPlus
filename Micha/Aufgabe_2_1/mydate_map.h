#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H

#include "mydate.h"
#include "iostream"

using namespace MyDate;

class Map {
public:

    typedef int key_t;
    typedef std::string mapped_t;

    class Node {

        public:
            std::pair<key_t, mapped_t> m_pair;
            Node *m_up, *m_left, *m_right;            

            Node(const key_t& key, const mapped_t& value, Node* parent):
                m_pair(key, value), m_up(parent), m_left(0), m_right(0) {}

            Node* find(const key_t& key);
            Node* insert(const key_t& key, const mapped_t& value);
    };

    const mapped_t M_NOT_IN_MAP; // return value if not in map
    Node* m_root;
    Node* getRootNode();
    size_t m_size;
    size_t size() const;
    mapped_t& operator[](const Map::key_t& key);

    Map():
        m_root(0), m_size(0){}
};

#endif
