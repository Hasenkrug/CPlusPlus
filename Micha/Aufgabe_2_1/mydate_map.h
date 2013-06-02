#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H

#include "mydate.h"
#include "iostream"

using namespace MyDate;

class Map {
public:

    typedef MyDate::Date key_t;
    typedef std::string mapped_t;

    class Node {

        public:
            std::pair<key_t, mapped_t> m_pair;
            Node *m_up, *m_left, *m_right;            

            Node(const key_t& key, const mapped_t& value, Node* parent):
                m_pair(key, value), m_up(parent), m_left(0), m_right(0) {}

//            Node(const Node& n) :
//                m_pair(n.m_pair.first, n.m_pair.second), m_up(n.m_up), m_left(n.m_left), m_right(n.m_right) {}

            ~Node() {
                if(!m_left) {
                    delete(m_left);
                }

                if(!m_right) {
                    delete(m_right);
                }
            }

            Node* find(const key_t& key);
            Node* insert(const key_t& key, const mapped_t& value);
            bool contains(const Map::key_t &key) const;
            Node* clone(Node* parent);
    };

    const mapped_t M_NOT_IN_MAP; // return value if not in map
    Node* m_root;
    Node* getRootNode();
    size_t m_size;
    size_t size() const;
    mapped_t& operator[](const Map::key_t& key);
    void operator=(Map& map);
    const mapped_t& operator[](const Map::key_t& key) const;

    Map():
        m_root(0), m_size(0) {}

//    Map(const Map& map) :
//        m_root(map.m_root), m_size(map.m_size) {}

    ~Map() {
        delete(m_root);
    }
};

#endif
