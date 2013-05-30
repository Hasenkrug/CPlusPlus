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

    if(m_pair.first < key) {

        if(m_left) {
            return m_left->find(key);
        }

        return 0;

    } else if(m_pair.first  > key) {

        if(m_right) {
            return m_right->find(key);
        }

        return 0;
    }

    return this;
}

Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {    
    //cout << "inside insert() key: " << key << endl;
    //cout << "inside insert() value: " << value << endl;

    if(m_pair.first < key) {

        if(m_left != 0){
            return m_left->insert(key, value);
        }

        return m_left = new Node(key, value, this);

    } else if(m_pair.first > key) {

        if(m_right != 0) {
            return m_right->insert(key, value);
        }

        return m_right = new Node(key, value, this);
    }

return 0;

    //Map::Node *node = new Map::Node(key, value, this);
    //cout << "inside insert() node->m_pair.first: " << node->m_pair.first << endl;
    //cout << "inside insert() node->m_pair.second: " << node->m_pair.second << endl;
    //return node;
}

Map::mapped_t& Map::operator[](const Map::key_t& key) {

    if(this->getRootNode()==0) {
        m_root = new Map::Node(key, "default", 0);
        m_size++;
        return m_root->m_pair.second;
    } else {
        m_size++;
        return m_root->insert(key, "blub")->m_pair.second;
    }
}

