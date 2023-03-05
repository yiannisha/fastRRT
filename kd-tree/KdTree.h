
template <typename T>
class KdTree {
    public:
    
    struct Node
    {
        Node *left, *right;
        T *point;
    };

    /**
     * A k-dimension tree.
     * 
     * @param dimensions of the data that the tree stores. 
    */
    KdTree ( unsigned dimensions );

    /**
     * A k-dimension tree.
     * 
     * @param kdtree to copy into the new k-dimension Tree.
    */
    KdTree ( const KdTree &kdtree );
    
    /**
     * Insert node to tree.
     * 
     * @param point array of type T with k length. Point to insert in the tree.
     * 
     * @throws InvalidEntryError if `point` is not of length k.
     * @throws DuplicateEntryError if a point with the same value already exists inside the tree.
    */
    void insert ( T point[] );

    /**
     * Nearest Neighbor Search.
     * 
     * @param query array of type T with k length. Point to find the NN of.
     * 
     * @return pointer to the node of the nearest neighbor to the point.
     * 
     * @throws TreeEmptyError when searching an empty tree.
     * @throws InvalidEntryError if `query` is not of length k.
    */
    Node *NNS ( T query[] );

    private:

    unsigned dimensions;
    Node *root;

    /**
     * Create a new Node.
     * 
     * @param array of type T with k length. Node's data.
     * 
     * @return pointer to the new Node.
    */
    Node *createNode ( T point[] );

    /**
     * Euclidean distance.
     * 
     * @param a point to find distance from b.
     * @param b point to find distance from a.
     * 
     * @returns euclidean distance between points.
    */
    T distance (T a[], T b[]);

    /**
     * Insert node to tree helper function.
     * 
     * @param point array of type T with k length. Point to insert in the tree.
     * @param depth keep track of the depth during recursion. Initial call shouldn't provide a value.
    */
    void insert_help ( Node **root, T point[], unsigned depth = 0 );

    /**
     * Nearest Neighbor Search recursive helper function.
     * 
     * @param query array of type T with k length. Point to find the NN of.
     * @param node of tree to search
     * @param best_point reference to the currently closest point to the query.
     * @param best_dist reference to the currently closests distance to the query.
     * @param depth keep track of the depth during recursion. Initial call shouldn't provide a value.
    */
    void NNS_help ( T query[], Node *node, Node *best_point, T &best_dist = __INT_MAX__, unsigned depth = 0 );

    /**
     * Validate point.
     * 
     * @param point to validate.
     * 
     * @return true if point is an array of k length, false otherwise.
    */
    // bool validate ( T point[] );

};