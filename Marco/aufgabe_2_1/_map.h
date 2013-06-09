#include "map.h"
#include "mydate.h"
#include "iostream"

using namespace std;
//using namespace MyTemplate;

namespace MyTemplate{
    template<class KeyT, class T>
    size_t Map<KeyT,T>::size() const {
        return m_size;
    }

    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT,T>::getRootNode() {
        return m_root;
    }

    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::find(const typename Map<KeyT,T>::key_t &key) {

        if(m_pair.first > key) {

            return m_left ? m_left->find(key) : 0;

        } else if(m_pair.first < key) {

           return m_right ? m_right->find(key) : 0;
        }

        return this;
    }

    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT, T>::Node::find1st(){
        if(m_left){
            return m_left->find1st();
        }
        return this;
    }

    template<class KeyT, class T>
    bool Map<KeyT, T>::Node::isLeftChild(const  Map<KeyT,T>::Node*node){
        if(node->m_up == 0)
            return false; // Die Wurzel ist kein Kind
        else
            return node->m_up->m_left == node;
    }


    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT, T>::Node::findNext(){
        Node* node = this;
        if(node->m_right != 0){
            node = node->m_right;
            while(node->m_left!= 0){
                node = node->m_left;
            }
            return node;
        }else{
            while(node){
                if(isLeftChild(node)){
                    return node->m_up;
                }else{
                    node = node->m_up;
                }
            }
            return 0; // Wir sind am Ende angekommen
        }


/*        if(m_pair.first > key){

        }*/
/*        if(m_left != 0){
            if(m_left->m_pair.first )
        }*/

        /*cout << "Zwischschritt:" << m_pair.first << endl;

        if(m_right != 0 ){
            if(m_right->m_left != 0){
                return m_right->m_left->findNext(true);
            }
            return m_right;
        }
        if(m_up != 0 ){
            if(m_up->m_pair.first < m_pair.first){
                return this;
            }
            if(!left){
                return m_up->findNext(false);
            }
        }
        if(m_left!= 0){
            if (m_left->m_pair.first > m_pair.first){
                return m_left->findNext(false);
            }
        }

        return this;
        */
    }


    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::insert(const typename Map<KeyT,T>::key_t &key, const typename Map<KeyT,T>::mapped_t &value) {

        if(m_pair.first < key) {

            return m_right ? m_right->insert(key, value) : m_right = new Node(key, value, this);

        } else if(m_pair.first > key) {

            return m_left ? m_left->insert(key, value) : m_left = new Node(key, value, this);
        }

        return 0;
    }

    template<class KeyT, class T>
    typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::operator[](const typename Map<KeyT,T>::key_t& key) {

        if(m_root == 0) {

            m_root = new typename Map<KeyT,T>::Node(key, "default", 0);
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

    template<class KeyT, class T>
    bool Map<KeyT,T>::Node::contains(const typename Map<KeyT,T>::key_t &key) const {

        if(m_pair.first > key) {

            return m_left ? m_left->contains(key) : false;

        } else if(m_pair.first < key) {

            return m_right ? m_right->contains(key) : false;

        } return true;
    }

    template<class KeyT, class T>
    const typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::operator[](const typename Map<KeyT,T>::key_t& key) const {

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

    template<class KeyT, class T>
    typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::clone(typename Map<KeyT,T>::Node* parent) {
        typename Map<KeyT,T>::Node* node = new typename Map<KeyT,T>::Node(m_pair.first, m_pair.second, parent);

        this->m_left ? node->m_left = this->m_left->clone(node) : node->m_left = 0;
        this->m_right ? node->m_right = this->m_right->clone(node) : node->m_right = 0;

        return node;
    }

    template<class KeyT, class T>
    void Map<KeyT,T>::operator=(Map& map) {
        this->m_size = map.m_size;
        this->m_root = map.m_root->clone(map.m_root);
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //iterator
    template<class KeyT, class T>
    void Map<KeyT,T>::Iterator::operator=(const typename Map<KeyT,T>::Iterator &rhs){
        this->I_m_root = rhs.I_m_root;
    }


    template<class KeyT, class T>
    bool Map<KeyT,T>::Iterator::operator==(const typename Map<KeyT,T>::Iterator &hs){
        return I_m_root == hs.I_m_root;
    }
    template<class KeyT, class T>
    bool Map<KeyT,T>::Iterator::operator!=(const typename Map<KeyT,T>::Iterator &hs){
        return I_m_root != hs.I_m_root;
    }

/*
    template<class KeyT, class T>
    typename Map<KeyT,T>::value_t& Map<KeyT,T>::Iterator::operator*(){
        return getRootNode()->m_pair;
    }
    template<class KeyT, class T>
    typename Map<KeyT,T>::value_t* Map<KeyT,T>::Iterator::operator->(){
        return &getRootNode()->m_pair;
    }*/

    template<class KeyT, class T>
    typename Map<KeyT,T>::Iterator Map<KeyT,T>::Iterator::operator++(int){
        Iterator old(*this);
        Node* n = old.I_m_root;
        cout << "Einagbe:" << n->m_pair.first<< endl;
        Node* nn = n->findNext();
        if(nn){
            cout << "Ausgabe:" << nn->m_pair.first<< endl;
            return nn;
        }else{
            return 0;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //adds in Map

    template<class KeyT, class T>
    typename Map<KeyT,T>::Iterator Map<KeyT,T>::end() {
            return Map<KeyT,T>::Iterator(0);
    }


    template<class KeyT, class T>
    typename Map<KeyT,T>::Iterator Map<KeyT,T>::begin() {
        if (m_root == 0) {
            return Map<KeyT,T>::end();
        }
        return Map<KeyT,T>::Iterator(m_root->find1st());
    }
}
