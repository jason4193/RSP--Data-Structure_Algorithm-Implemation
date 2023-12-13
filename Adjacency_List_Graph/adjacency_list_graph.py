# Adjacency List Graph Implementation


# Vertex Class
# Each vertex have a name and a list of neighbors
# Time Complexity: add_neighbor() -> O(1) : append a neighbor into a list
class Vertex:
    def __init__(self, n):
        self.name = n
        self.neighbors = list()
    
    def add_neighbor(self, v): 
        if v not in self.neighbors:
            self.neighbors.append(v)

# Graph Class
# Graph class contain a list of vertices
# Time Complexity: check_same_name() -> O(n) : check if a vertex is already exist
#                  add_vertex() -> O(n) : append a vertex by calling check_same_name()
#                  add_edge() -> O(n) : append an edge by calling add_neighbor()
#                  print_graph() -> O(n) : print all vertices and their neighbors
class Graph:
    vertices = []

    def check_same_name(self, vertex, vertices):
        for v in vertices:
            if vertex.name == v.name:
                return False
        return True

    def add_vertex(self, vertex):
        if isinstance(vertex, Vertex) and self.check_same_name(vertex, self.vertices):
            self.vertices.append(vertex)
            return True
        
        else:
            return False
        
    def add_edge(self, u, v):
        vertex_u = None
        vertex_v = None

        # check u and v are exist vertex names
        for vertex in self.vertices:
            if vertex.name == u:
                vertex_u = vertex
            if vertex.name == v:
                vertex_v = vertex
        
        # if u and v are exist vertex names, add edge
        if vertex_u is None or vertex_v is None:
            return False
        else: 
            vertex_u.add_neighbor(v)
            vertex_v.add_neighbor(u)
            return True

    def print_graph(self):
        for vertex in self.vertices:
            print(vertex.name, vertex.neighbors)


# Driver code
if __name__ == '__main__':
    g = Graph()
    a = Vertex('A')
    g.add_vertex(a)
    g.add_vertex(Vertex('B'))
    
    for i in range(ord('A'), ord('K')):
        g.add_vertex(Vertex(chr(i)))
    
    edges = [ 'AF', 'AB', 'AE', 'BF', 'CG', 'DE', 'DH', 'EH', 'GF', 'FI', 'FJ', 'GJ']
    
    # for vertex in g.vertices:
    #     print(vertex.name)

    for edge in edges:
        g.add_edge(edge[0], edge[1])
    
    g.print_graph()
