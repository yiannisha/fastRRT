#include "KdTree.h"
#include "exceptions.cpp"

#include <cstdio>
#include <cmath>
#include <iostream>

template <typename T>
KdTree<T>::KdTree ( unsigned dimensions ) {
    this->dimensions = dimensions;
    this->root = nullptr;
}

template <typename T>
KdTree<T>::KdTree ( const KdTree &kdtree ) {
    this->dimensions = kdtree->dimensions;
    this->root = kdtree->root;
}

template <typename T>
void KdTree<T>::insert ( T point[] ) {

    this->insert_help(&this->root, point);

}

template <typename T>
typename KdTree<T>::Node *KdTree<T>::NNS ( T query[] ) {

    if (this->root == nullptr) {
        throw TreeEmptyError();
    }

    // initialize an "empty" Node
    T zeros[2] = {0, 0};
    KdTree<T>::Node *best_node = this->createNode(zeros);
    
    T best_dist = __INT_MAX__;

    this->NNS_help(query, this->root, best_node, best_dist);

    return best_node;
}

template <typename T>
typename KdTree<T>::Node *KdTree<T>::createNode ( T point[] ) {
    Node *node;
    node = new Node();
    node->left = node->right = nullptr;
    node->point = new T[this->dimensions];
    for (int i = 0; i < this->dimensions; i++) {
        node->point[i] = point[i];
    }
    return node;
}

template <typename T>
T KdTree<T>::distance ( T a[], T b[] ) {
    T sum = 0;

    for (int i=0; i<this->dimensions; i++) {
        sum += pow(a[i] - b[i], 2);
    }

    return sqrt(sum);
}

template <typename T>
void KdTree<T>::insert_help ( KdTree<T>::Node **root, T point[], unsigned depth ) {
    
    if (*root == nullptr) {
        *root = this->createNode(point);
        return;
    }

    unsigned current_depth = depth % this->dimensions;

    if (point[current_depth] < (*root)->point[current_depth]) {
        insert_help(&(*root)->left, point, depth + 1);
    }
    else {
        insert_help(&(*root)->right, point, depth + 1);
    }
}

template <typename T>
void KdTree<T>::NNS_help ( T query[], KdTree<T>::Node *node, KdTree<T>::Node *best_point, T &best_dist, unsigned depth ) {
    T dist = this->distance(query, node->point);
    
    if (dist < best_dist) {
        best_dist = dist;
        for (int i=0; i<this->dimensions; i++) {
            best_point->point[i] = node->point[i];
        }
    }

    unsigned current_depth = depth % this->dimensions;

    // leaf case
    if (node->left == nullptr && node->right == nullptr) return;

    if (query[current_depth] <= node->point[current_depth]) {
        if (node->left != nullptr) {
            this->NNS_help(query, node->left, best_point, best_dist, depth + 1);
        }
        if (query[current_depth] + best_dist > node->point[current_depth] && node->right != nullptr) {
            this->NNS_help(query, node->right, best_point, best_dist, depth + 1);
        }
    }
    else {
        if (node->right != nullptr) {
            this->NNS_help(query, node->right, best_point, best_dist, depth + 1);
        }
        if (query[current_depth] - best_dist <= node->point[current_depth] && node->left != nullptr) {
            this->NNS_help(query, node->left, best_point, best_dist, depth + 1);
        }
    }
}