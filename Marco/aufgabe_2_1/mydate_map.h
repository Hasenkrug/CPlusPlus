#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H


namespace MyDate
{
    // associative map date --> string
    class Map
    {
        Node node;
    public:
        Map()
            :node()
        {
        }
        // aliases for key type and mapped type
        typedef MyDate::Date key_t;
        typedef std::string mappes_t;

    protected:

        // internal node type for binary search tree
        class Node{
            Node()
            {
            }
        public:
            std::pair<key_t, mapped_t> m_pair; // key/value pair
            Node *m_up, *m_right; // pointers to other nodes
            size_t size();//
            mapped_t& operator[](const key_t& key);
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