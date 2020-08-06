//
//  main.cpp
//  test
//
//  Created by louis on 8/4/20.
//  Copyright © 2020 louis. All rights reserved.
//
#include <iostream>
#include "vertex.h"
#include "edge.h"
#include "sphere.h"
#include "triangle.h"

#include "testing.h"

using namespace CGL;

int main(int argc, const char * argv[]) {
    // insert code here...
    //Vector3D a = Vector3D(1,2,3);
    //Vector3D b = Vector3D(4,5,6);
    //Vector3D c = Vector3D(7,8,9);
    //Vector3D d = Vector3D(0,0,0);
    //Vertex x = Vertex(a, b);
    //Vertex y = Vertex(c, d);
    //Edge e1 = Edge(&x, &y);
    //std::cout << e1.b->point.y;
    //std::cout << "\n";
    //Sphere s1 = Sphere(a, 2.0);
    //std::cout << s1.center.z;
    //std::cout << "\n";
    //Vector3D p1 = Vector3D(2,0,0);
    //Vector3D p2 = Vector3D(0,2,0);
    //Vector3D p3 = Vector3D(0,0,2);
    //Vector3D n = Vector3D(1,1,1);
    //Vertex x1 = Vertex(p1, n);
    //Vertex x2 = Vertex(p2, n);
    //Vertex x3 = Vertex(p3, n);
    //Triangle t1 = Triangle(&x1, &x2, &x3);
    //Sphere s2 = t1.construct_ball(2.0);
    //std::cout << s2.center.x;
    //std::cout << "\n";
    //std::cout << s2.center.y;
    //std::cout << "\n";
    //std::cout << s2.center.z;
    //std::cout << "\n";
    //std::cout << x.adjacent_edges.size();
    //std::cout << "\n";
    //std::cout << x1.adjacent_edges.size();
    //std::cout << "\n";
    //std::cout << x1.adjacent_triangles.size();
    //std::cout << "\n";
    //bool test_1 = (t1.ab->face1 == &t1);
    //std::cout << test_1;
    //std::cout << "\n";
    //return 0;
    testing::octree_test();
}
