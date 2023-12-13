# import the graph
import sys
sys.path.append('..')
from Adjacency_List_Graph.adjacency_list_graph import Graph, Vertex

# Depth First Search
class DFS:
    def __init__(self):
        self.order = []
    
    def recursive_DFS(self, start):
        start.visited = True
        self.order.append(start.name)

        for neighbor in start.neighbors:
            if neighbor.visited == False:
                self.recursive_DFS(neighbor)

        return self.order

# Create a graph
def build_graph():
    g = Graph()
    # Create vertices
    a = Vertex('A')
    b = Vertex('B')
    c = Vertex('C')
    d = Vertex('D')
    e = Vertex('E')
    
    # Add vertices to graph
    g.add_vertex(a)
    g.add_vertex(b)
    g.add_vertex(c)
    g.add_vertex(d)
    g.add_vertex(e)
    
    # Add edges to graph
    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'C')
    g.add_edge('C', 'D')
    g.add_edge('D', 'E')
    
    return g



# Driver code
if __name__ == '__main__':
    g = build_graph()
    g.print_graph()
    print()

    dfs = DFS()
    order = dfs.recursive_DFS(g.vertices[3]) # starting from vertex D
    print(order)