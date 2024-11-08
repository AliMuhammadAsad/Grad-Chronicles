import networkx as nx
class MaxFlow:
    def __init__(self, file) -> None:
        self.dag = nx.DiGraph()
        for i in range(len(file)):
            node1, node2, capacity = file[i].split()
            self.dag.add_edge(node1, node2, capacity=int(capacity))
            if not self.dag.has_edge(node2, node1):
                self.dag.add_edge(node2, node1, capacity=0)
        print("Graph edges and their capacities")
        print(self.dag.edges(data=True))

    def get_value(self):
        ''' Get the maximum flow value of the DAG '''
        residual = self.dag.copy()
        parent = {}

        max_flow = 0

        while self.bfs(residual, 's', 't', parent):
            path_flow = float("Inf")
            s = 't'
            while s != 's':
                path_flow = min(path_flow, residual[parent[s]][s]['capacity'])
                s = parent[s]
            max_flow += path_flow
            v = 't'
            while v != 's':
                u = parent[v]
                residual[u][v]['capacity'] -= path_flow
                residual[v][u]['capacity'] += path_flow
                v = parent[v]
        return max_flow

    def bfs(self, residual, source, sink, parent):
        visited = {node: False for node in residual.nodes()}
        queue = []
        queue.append(source)
        visited[source] = True

        while queue:
            u = queue.pop(0)
            for ind, val in enumerate(residual[u]):
                if visited[val] == False and residual[u][val]['capacity'] > 0:
                    queue.append(val)
                    visited[val] = True
                    parent[val] = u

        return True if visited[sink] else False

    def get_flow(self):
        ''' Get the flow of each node in the DAG '''
        residual = self.dag.copy()
        parent = {}

        flow = {}
        for u, v in self.dag.edges():
            flow[(u, v)] = 0

        while self.bfs(residual, 's', 't', parent):
            path_flow = float("Inf")
            s = 't'
            path = []
            while s != 's':
                path.append((parent[s], s))
                path_flow = min(path_flow, residual[parent[s]][s]['capacity'])
                s = parent[s]

            for u, v in path:
                flow[(u, v)] += path_flow

            v = 't'
            while v != 's':
                u = parent[v]
                residual[u][v]['capacity'] -= path_flow
                residual[v][u]['capacity'] += path_flow
                v = parent[v]

        flow = {edge: f for edge, f in flow.items() if f > 0}
        return flow