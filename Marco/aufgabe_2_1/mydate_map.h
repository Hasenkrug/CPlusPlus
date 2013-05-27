#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H
#include <mydate.h>


namespace MyDate
{
    // associative map date --> string
    class Map
    {
    public:

        // aliases for key type and mapped type
        typedef MyDate::Date key_t;
        typedef std::string mapped_t;
        Map()
        {

        }

    protected:

        // internal node type for binary search tree
        class Node{

        public:
            std::pair<key_t, mapped_t> m_pair; // key/value pair
            Node *m_up, *m_left, *m_right; // pointers to other nodes

            size_t size() const;//


            /*Node(const key_t& key, const mapped_t& value, Node* parent)

            {
                m_pair<key,value> ;
                m_up = parent;
            }*/

            mapped_t& operator[](const key_t& key);
            //Node* find(const key_t& key);
            //Node* insert(const key_t& key,
            //const mapped_t& value);

            //bool contains(const key_t& key) const;

            //const mapped_t& operator[](const key_t& key) const;
        };

        Node* m_root;// root node of search tree
        size_t m_size;// number of elements in tree
        const mapped_t M_NOT_IN_MAP; // return value if not in map

    };
}
class mydate_map
{
public:
    mydate_map();
};

#endif // MYDATE_MAP_H
