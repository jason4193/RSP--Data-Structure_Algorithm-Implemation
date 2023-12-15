# import the graph
import sys
sys.path.append('..')
from Adjacency_List_Graph.adjacency_list_graph import Graph, Vertex

# Breadth First Search
class BFS:
    def __init__ (self):
        self.order = []
    
    def while_BFS(self, start):
        queue = []

        # visit the start vertex
        queue.append(start)
        start.visited = True

        while queue:
            # dequeue a vertex
            vertex = queue.pop(0)
            self.order.append(vertex.name)

            # enqueue all unvisited neighbors
            for neighbor in vertex.neighbors:
                if neighbor.visited == False:
                    queue.append(neighbor)
                    neighbor.visited = True
        
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

    bfs = BFS()
    order = bfs.while_BFS(g.vertices[3]) # starting from vertex D
    print(order)