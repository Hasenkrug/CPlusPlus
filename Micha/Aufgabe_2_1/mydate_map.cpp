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

    }

    Map::Node* Map::Node::insert(const Map::key_t &key, const Map::mapped_t &value) {

    }

    Map::mapped_t& Map::operator[](const Map::key_t& key) {

    }
}
