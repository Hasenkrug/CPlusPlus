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

    if(this->getRootNode() == 0) { // wenn noch kein root node vorhanden ist...

        m_root = new Map::Node(key, "default", 0); // erstelle ihn
        m_size++;
        return m_root->m_pair.second;

    } else {

        if(this->m_root->find(key)) { // wenn der übergebene key vorhanden ist...

            return this->m_root->find(key)->m_pair.second; // gib eine Referenz auf den Value zurück

        } else { // der übergebene key ist noch nicht vorhanden...

            m_size++;
            return m_root->insert(key, "default")->m_pair.second; // also erstelle eine neue node
        }
    }
}

bool Map::Node::contains(const Map::key_t &key) const {    

    if(m_pair.first > key) {

        if(m_left) {
            return m_left->contains(key);
        } else {
            return false;
        }

    } else if(m_pair.first < key) {

        if(m_right) {
            return m_right->contains(key);
        } else {
            return false;
        }

    } return true;
}

const Map::mapped_t& Map::operator[](const Map::key_t& key) const {

    if(m_root == 0) {
        return M_NOT_IN_MAP;
    }

    Node* node = m_root->find(key);

    if(node != 0) {

        return node->m_pair.second;

    } else {

        return M_NOT_IN_MAP;
    }
}

Map::Node* Map::Node::clone(Map::Node* parent) {
    Map::Node* node = new Map::Node(m_pair.first, m_pair.second, parent);
    this->m_left ? node->m_left = this->m_left->clone(node) : node->m_left = 0;
    this->m_right ? node->m_right = this->m_right->clone(node) : node->m_right = 0;

    return node;
}

void Map::operator =(Map& map) {
    this->m_size = map.m_size;
    this->m_root = map.m_root->clone(map.m_root);
}

