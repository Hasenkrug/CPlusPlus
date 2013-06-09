#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H

#include "mydate.h"
#include "iostream"


namespace MyTemplate{

    template<class KeyT, class T> class Map {
    public:

        typedef KeyT key_t;
        typedef T mapped_t;
        typedef std::pair<key_t, mapped_t> value_t;


        size_t size() const;
        mapped_t& operator[](const Map::key_t& key);
        void operator=(Map& map);
        const mapped_t& operator[](const Map::key_t& key) const;

        Map():
            m_root(0), m_size(0) {}

        Map(const Map& map)
            : m_root(map.m_root->clone(map.m_root)), m_size(map.m_size) {}

        ~Map() {
            delete(m_root);
        }
        class Node {

            public:
                std::pair<key_t, mapped_t> m_pair;
                Node *m_up, *m_left, *m_right;

                Node(const key_t& key, const mapped_t& value, Node* parent):
                    m_pair(key, value), m_up(parent), m_left(0), m_right(0) {}

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
        class Iterator{
        public:
            Node* I_m_root;
            Iterator(Node* node=0)
                :I_m_root(node){}

            Iterator(const Iterator& rhs): I_m_root(rhs.m_root){}

            Iterator& operator=(const Iterator& rhs);

            bool operator==(const Iterator &rhs);
            bool operator!=(const Iterator &rhs);

            value_t& operator*();
            value_t* operator->();

        };

        typedef Iterator iterator;

        const mapped_t M_NOT_IN_MAP; // return value if not in map
        Node* m_root;
        size_t m_size;
        Node* getRootNode();
        //mapped_t& value_t();
    };
}
#include "_map.h"
#endif
