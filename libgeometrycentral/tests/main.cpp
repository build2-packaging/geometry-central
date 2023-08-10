#include <memory>
//
#include <geometrycentral/surface/manifold_surface_mesh.h>
#include <geometrycentral/surface/meshio.h>
#include <geometrycentral/surface/surface_mesh.h>

using namespace std;
using namespace geometrycentral;
using namespace geometrycentral::surface;

int main() {
  unique_ptr<SurfaceMesh> mesh;
  unique_ptr<VertexPositionGeometry> geometry;
  tie(mesh, geometry) = readSurfaceMesh("spot.ply");

  for (Vertex v : mesh->vertices()) {
    std::cout << "Vertex " << v << " has degree " << v.degree() << "\n";
    for (Face fn : v.adjacentFaces()) {
      std::cout << "  incident on face " << fn << "\n";
    }
  }
}
