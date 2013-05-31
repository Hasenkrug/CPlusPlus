#include "mydate_map.h"
#include "mydate.h"
#include "iostream"
#include "stdio.h"
#include <iostream>
#include <assert.h>


namespace MyDate {

    Map::Map():
        m_root(NULL),m_size(0)
    {}

    size_t Map::size() const {
        return m_size;
    }

    Map::Node* Map::Node::find(const Map::key_t &key) {

        if(m_pair.first < key){
            if(m_left){
                return m_left->find(key);
            }else{
                return NULL;
            }
        }else if(m_pair.first > key){
            if(m_right){
                return m_right->find(key);
            }else{
                return NULL;
            }
        }return this;
    }





    Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {

        //Node* newNode = find(key);
        //newNode = new Node(key, value, this);
//        std::cout << m_pair.second << std::ends;
        if(m_pair.first == key){
            m_pair = std::pair<key_t, mapped_t>(key,value);
            return this;
        }else if(m_pair.first < key){
            if(m_left){
                return m_left->insert(key, value);
            }else{
                std::cout << key << "left" << std::endl;
                return m_left = new Node(key, value, this);
            }
        }else if(m_pair.first > key){
            if(m_right){
                return m_right->insert(key, value);
            }else{
                std::cout << key << "right" << std::endl;
                return m_right = new Node(key, value, this);
            }
        }
    }

    Map::mapped_t& Map::operator[](const Map::key_t& key) {
        if(!m_root){
            m_root = new Node(key, mapped_t(), this->m_root);
            m_size++;
        }

        Node* node = m_root->find(key);

        if(node){
            return node->m_pair.second;
        }else{
            m_size++;
            return m_root->insert(key, mapped_t())->m_pair.second;
        }
    }

    const Map::mapped_t& Map::operator[](const Map::key_t& key) const{
        if(!m_root){
            return M_NOT_IN_MAP;
        }

        Node* node = m_root->find(key);

        if(node){
            return node->m_pair.second;
        }else{
            return M_NOT_IN_MAP;
        }
    }
    bool Map::Node::contains(const Map::key_t &key) const
    {
        if(m_pair.first < key){
            if(m_left){
                return m_left->contains(key);
            }else{
                return false;
            }
        }else if(m_pair.first > key){
            if(m_right){
                return m_right->contains(key);
            }else{
                return false;
            }
        }return true;
    }
}
