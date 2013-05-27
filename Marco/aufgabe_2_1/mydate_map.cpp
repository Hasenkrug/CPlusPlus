#include "mydate_map.h"
#include "mydate.h"
#include "iostream"

namespace MyDate {

    size_t Map::size() const {
        return m_size;
    }

    Map::Node* Map::getRootNode() {
        return m_root;
    }


    Map::Node* Map::Node::find(const Map::key_t &key) {

        if(this->m_pair.first == key){
            return this;
        }
        if(this->m_pair.first < key){
            find(this->m_right->m_pair.first);
        }
        if(this->m_pair.first > key){
            find(this->m_left->m_pair.first);
        }
        return 0;
    }

    Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {
        Node *n;
        if(this->find(key) == 0){
            n = new Node(key,value,this);
        }
        return n;
    }

    Map::mapped_t& Map::operator[](const Map::key_t& key) {

        if(find){
            m_root->insert(key,m_root->m_pair.second);
            return;
        }
        if(m_root->m_pair.first > key){
            m_root[m_root->m_left->m_pair.first];
        }
        if(m_root->m_pair.first < key){
            m_root[m_root->m_right->m_pair.first];
        }
        if(m_root->m_pair.first == key){

            return m_root->m_pair.second;
        }

    }
    bool Map::contains(const key_t& key){
        if(m_root.find(key) == 0){
            return false;
        }
        return true;
    }

    const Map::mapped_t& operator[](const Map::key_t& key){
        if(m_root[m_root];
    }
}
