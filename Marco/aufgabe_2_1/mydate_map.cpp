#include "mydate_map.h"
#include "mydate.h"
#include "iostream"
#include <stdio.h>

namespace MyDate {

    size_t Map::size() const {
        return m_size;
    }

    /*Map::Node* Map::getRootNode() {
        return m_root;
    }*/


    Map::Node* Map::Node::find(const Map::key_t &key) {
        printf("1");
        Map::key_t ke= key;
        Date k = Date(1,5,2013);//this->m_pair.first;
        /*if (key == 0){
            return;
        }*/
        int i = 1;
        printf("1a int1: %i\n",k);
        if(&this->m_pair.first == &key){
            printf("1b");
            return this;
        }
        printf("2");
        if(&this->m_pair.first < &key && this->m_right != 0){
            return find(this->m_right->m_pair.first);
        }
        printf("3");
        if(&this->m_pair.first > &key){
            return find(this->m_left->m_pair.first);
        }
        printf("4");
        return 0;
    }

    Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {

        Node *n;
        Node *t = this->find(key);
        printf("Wer");
        if(this->find(key) == 0){
            printf("W");
            n = new Node(key,value,this);
        }else {
            n = 0;
            printf("W");
        }
        return n;
    }



    Map::mapped_t& Map::operator[](const Map::key_t& key) {
        m_root->insert(key,"");
        /*if(n == 0){
            m_root->insert(key,m_root->m_pair.second);
            return;
        }*/
    }
    bool Map::contains(const key_t& key){
        if(m_root->find(key) == 0){
            return false;
        }
        return true;
    }

    /*const Map::mapped_t& Map::operator[](const Map::key_t& key){
       // if(m_root[m_root];
    }*/
}
