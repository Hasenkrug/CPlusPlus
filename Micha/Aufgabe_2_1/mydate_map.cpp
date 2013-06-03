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

        return m_left ? m_left->find(key) : 0;

    } else if(m_pair.first < key) {

       return m_right ? m_right->find(key) : 0;
    }

    return this;
}

Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {

    if(m_pair.first < key) {

        return m_right ? m_right->insert(key, value) : m_right = new Node(key, value, this);

    } else if(m_pair.first > key) {

        return m_left ? m_left->insert(key, value) : m_left = new Node(key, value, this);
    }

    return 0;
}

Map::mapped_t& Map::operator[](const Map::key_t& key) {

    if(m_root == 0) {

        m_root = new Map::Node(key, "default", 0);
        m_size++;
        return m_root->m_pair.second;

    } else {

        if(this->m_root->find(key)) { // wenn der übergebene key vorhanden ist...
            return m_root->find(key)->m_pair.second; // gib eine Referenz auf den Value zurück
        } else { // wenn der übergebene key noch nicht vorhanden ist...
            m_size++;
            return m_root->insert(key, "default")->m_pair.second; // erstelle eine neue node und gib den default Value zurück
        }
    }
}

bool Map::Node::contains(const Map::key_t &key) const {        

    if(m_pair.first > key) {

        return m_left ? m_left->contains(key) : false;

    } else if(m_pair.first < key) {

        return m_right ? m_right->contains(key) : false;

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

