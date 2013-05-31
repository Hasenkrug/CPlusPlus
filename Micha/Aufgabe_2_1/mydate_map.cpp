#include "mydate_map.h"
#include "mydate.h"
#include "iostream"

using namespace std;
using namespace MyDate;


size_t Map::size() const {
    return m_size;
}

Map::Node* Map::getRootNode() {
    return m_root;
}

Map::Node* Map::Node::find(const Map::key_t &key) {    

    if(m_pair.first > key) {

        if(m_left) {
            return m_left->find(key);
        }

        return 0;

    } else if(m_pair.first < key) {

        if(m_right) {
            return m_right->find(key);
        }

        return 0;
    }
    return this;
}

Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {

    if(m_pair.first < key) {

        if(m_right != 0) {
            return m_right->insert(key, value);
        }

        return m_right = new Node(key, value, this);

    } else if(m_pair.first > key) {

        if(m_left != 0) {
            return m_left->insert(key, value);
        }

        return m_left = new Node(key, value, this);
    }

    return 0;
}

Map::mapped_t& Map::operator[](const Map::key_t& key) {

    if(this->getRootNode() == 0) { // wenn noch kein root node vorhanden ist

        m_root = new Map::Node(key, "default", 0);
        m_size++;
        return m_root->m_pair.second;

    } else {

        if(this->m_root->find(key)) { // wenn der übergebene key vorhanden ist, gib eine Referenz auf den Value zurück

            return this->m_root->find(key)->m_pair.second;

        } else { // der übergebene key ist noch nicht vorhanden, also erstelle eine neue node

            m_size++;
            return m_root->insert(key, "default")->m_pair.second;
        }
    }
}

bool Map::contains(const Map::key_t& key) const {
    return false;
}

