from adjacency_list_graph import Graph, Vertex
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

    g.remove_vertex('A')
    print()
    g.print_graph()
