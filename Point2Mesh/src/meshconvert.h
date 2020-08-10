#ifndef meshconvert_h
#define meshconvert_h

#include "types.h"
#include "utils.h"
#include "ocsearch.h"
#include <string>
#include <vector>

using namespace std;

namespace CGL {
    class MeshConvert {
    public:
        // constructor & destructor
        MeshConvert(string file, double radius);

        void init_data();
        void init_ocsearch();

        bool findSeedTriangle();
        bool findSeedTriangle(OcNode* node);
        bool trySeedVertex(Vertex* v);
        bool trySeedVertices(Vertex* v, Vertex* u, Vertex* w, Neighbor_map* map);
        bool emptyBallConfig(Vertex* v, Vertex* u, Vertex* w);
        Vertex* FindCandidate(Edge* e);
        void expandTriangulation();
        void postProcess();

        double m_radius;
        uint m_vtx_count;
        uint m_tri_count;
        string m_filename;

        OcSearch m_ocsearch;
        OcTree m_tree;

        vector<Vertex> m_vertices;
        list<Triangle*> m_triangles;
        list<Edge*> m_front_edges;
        list<Edge*> m_border_edges;

        vector<Vector3D> m_range; 

    };
}

#endif
