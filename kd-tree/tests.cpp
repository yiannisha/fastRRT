#include <iostream>
#include "KdTree.cpp"

int main() {
    // Test case 1
    double points1[][2] = {
        {3, 6},
        {17, 15},
        {13, 15},
        {6, 12},
        {9, 1},
        {2, 7},
        {10, 19}
    };
    KdTree<double> kd1(2);
    for (auto point : points1) {
        kd1.insert(point);
    }
    double query1[2] = {17.5, 5};
    KdTree<double>::Node *best_node1 = kd1.NNS(query1);
    if (best_node1->point[0] == 9 && best_node1->point[1] == 1) {
        std::cout << "Test case 1 passed" << std::endl;
    } else {
        std::cout << "Test case 1 failed" << std::endl;
    }

    // Test case 2
    double points2[][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        {0.5, 0.5},
        {0.25, 0.25},
        {0.75, 0.75}
    };
    KdTree<double> kd2(2);
    for (auto point : points2) {
        kd2.insert(point);
    }
    double query2[2] = {0.1, 0.1};
    KdTree<double>::Node *best_node2 = kd2.NNS(query2);
    if (best_node2->point[0] == 0 && best_node2->point[1] == 0) {
        std::cout << "Test case 2 passed" << std::endl;
    } else {
        std::cout << "Test case 2 failed" << std::endl;
    }

    // Test case 3
    double points3[][2] = {
        {3, 6},
        {17, 15},
        {13, 15},
        {6, 12},
        {9, 1},
        {2, 7},
        {10, 19}
    };
    KdTree<double> kd3(2);
    for (auto point : points3) {
        kd3.insert(point);
    }
    double query3[2] = {11, 16};
    KdTree<double>::Node *best_node3 = kd3.NNS(query3);
    if (best_node3->point[0] == 13 && best_node3->point[1] == 15) {
        std::cout << "Test case 3 passed" << std::endl;
    } else {
        std::cout << "Test case 3 failed" << std::endl;
    }

    return 0;
}
