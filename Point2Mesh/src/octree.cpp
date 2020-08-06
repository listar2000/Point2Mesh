#include "octree.h"
#include <iostream>
#include <queue>

using namespace std;

namespace CGL {
    OcTree::OcTree() {
        root = NULL;
        max_depth = 0;
        binsize = 0;
        size = Vector3D();
        origin = Vector3D();
    }

//    OcTree::OcTree(uint depth) : OcTree() { max_depth = depth; binsize = (uint)pow(2, depth); }

    OcTree::OcTree(Vector3D og, Vector3D sz, uint depth) {
        origin = og;
        size = sz;
        max_depth = depth;
        binsize = (uint)pow(2, depth - 1);
        root = new OcNode(og, sz, NULL, NULL, depth - 1);
    }

    OcTree::~OcTree() {
        origin = NULL;
        size = NULL;
        max_depth = 0;
        binsize = 0;
        if (root != NULL) {
            delete root;
            root = NULL;
        }
    }

    void OcTree::populate_tree(vector<Vertex*>::iterator start, vector<Vertex*>::iterator end) {

        vector<Vertex*>::iterator it = start;
        for (; it != end; it++) {
            OcNode* node = root;
            uint l = node->depth - 1;

            Vector3D& p = (*it)->point, q = node->origin;
            uint xloc = (uint) binsize * (p.x - q.x) / size.x;
            uint yloc = (uint) binsize * (p.y - q.y) / size.y;
            uint zloc = (uint) binsize * (p.z - q.z) / size.z;

            while (node->depth > 0) {
                uint branch_bit = 1 << l;

                //cout << branch_bit << endl;

                uint x = (xloc & branch_bit) >> l;
                uint y = (yloc & branch_bit) >> l;
                uint z = (zloc & branch_bit) >> l;

                //cout << Vector3D(x, y, z) << endl;

                uint index = (x << 2) + (y << 1) + z;

                if (node->children[index] == NULL) {
                    Vector3D child_sz = node->size / 2.0;
                    Vector3D child_og(origin.x + x * child_sz.x, origin.y + y * child_sz.y, origin.z + z * child_sz.z);
                    node->addChildren(index, child_og, child_sz);
                }

                xloc += x << l; yloc += y << l; zloc += z << l;
                node = node->children[index];
                l--;
            }

            node->pts.push_back(*it);
        }
    }

    void OcTree::print_node_info(bool verbose) {
        queue<OcNode*> q;
        q.push(root);

        int l = max_depth - 1;

        while (!q.empty()) {
            OcNode* node = q.front();
            q.pop();
            if (node->depth != l) {
                l -= 1;
                cout << "*** layer: " << l << " ***" << endl;
            }
            if (node->is_leaf) {
                if (verbose)
                    cout << node->origin << " " << node->size << endl;
                for (auto v : node->pts)
                    cout << v->point << " ";
                continue;
            }
            for (int i = 0; i < 8; i++)
                if (node->children[i] != NULL)
                    q.push(node->children[i]);
        }
    }
}

