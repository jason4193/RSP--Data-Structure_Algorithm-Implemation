# Adjacency List Graph Implementation


# Vertex Class
# Each vertex have a name and a list of neighbors
# Time Complexity: add_neighbor() -> O(1) : append a neighbor into a list
class Vertex:
    def __init__(self, n):
        self.name = n
        self.neighbors = list()
        self.visited = False
    
    def add_neighbor(self, v): 
        if v not in self.neighbors:
            self.neighbors.append(v)

# Graph Class
# Graph class contain a list of vertices
# Time Complexity: check_same_name() -> O(V) : check if a vertex is already exist
#                  add_vertex() -> O(V) : append a vertex by calling check_same_name()
#                  add_edge() -> O(V) : append an edge by calling add_neighbor(), require to check vertices exist so O(V)
#                  remove_vertex() -> O(V+E) : remove a vertex by calling remove_edges() and remove the vertex from vertices list 
#                  remove_edges() -> O(E) : remove all edges that connect to the vertex
#                  print_graph() -> O(VE) : print all vertices and their neighbors
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
            vertex_u.add_neighbor(vertex_v)
            vertex_v.add_neighbor(vertex_u)
            return True
        

    def remove_vertex(self, vertex):
        # search the vertex in vertices list
        for v in self.vertices:
            if v.name == vertex:
                # remove all edges that connect to the vertex
                self.remove_edges(v)
                # remove the vertex from vertices list
                self.vertices.remove(v)
                return True
        return False

    def remove_edges(self, vertex):
        # remove all edges that connect to the vertex
        for neighbor in vertex.neighbors:
                    neighbor.neighbors.remove(vertex)

    def print_graph(self):
        for vertex in self.vertices:
            neighors_names = [neighbor.name for neighbor in vertex.neighbors]
            print(vertex.name, neighors_names)