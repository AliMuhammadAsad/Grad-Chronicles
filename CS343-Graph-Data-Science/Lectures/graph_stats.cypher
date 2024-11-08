// Introduction:
// Graph statistics play a fundamental role in understanding the structural properties and behavior of networks. 
// These statistics provide valuable insights into various aspects of a graph, including the connectivity patterns, 
// centrality of nodes, and overall density. In this Cypher code, we explore several key graph statistics using 
// a sample graph dataset. These statistics include node degree, clustering coefficient, graph density, average 
// path length, and diameter. Each calculation offers unique perspectives on the underlying graph structure 
// and can be essential in various fields such as social network analysis, transportation planning, and 
// biological network modeling.

// This Cypher code demonstrates various graph statistics calculations using Neo4j. 
// It begins by generating sample graph data representing users and their follow relationships. 
// Then, it computes statistics such as node degree, in-degree, out-degree, clustering coefficient, 
// graph density, average path length, and diameter.

// Sample Graph
MERGE (a:User{Name:"A"})
MERGE (b:User{Name:"B"})
MERGE (c:User{Name:"C"})
MERGE (d:User{Name:"D"})
MERGE (e:User{Name:"E"})
MERGE (f:User{Name:"F"})
MERGE (g:User{Name:"G"})
MERGE (h:User{Name:"H"})
MERGE (a)-[:FOLLOWS]->(b)
MERGE (a)-[:FOLLOWS]->(c)
MERGE (b)-[:FOLLOWS]->(c)
MERGE (c)-[:FOLLOWS]->(d)
MERGE (f)-[:FOLLOWS]->(g)
MERGE (g)-[:FOLLOWS]->(h)
MERGE (h)-[:FOLLOWS]->(f)
MERGE (a)-[:FOLLOWS]->(h)
MERGE (a)-[:FOLLOWS]->(f)

// Degree of each node: Determines the total number of relationships connected to each node.
MATCH (n)
OPTIONAL MATCH (n)-[r]-()
RETURN n, COUNT(r)

// In-degree of each node: Counts the number of incoming relationships for each node.
MATCH (n)
OPTIONAL MATCH (n)<-[r]-()
RETURN n, COUNT(r)

// Out-degree of each node:Counts the number of outgoing relationships for each node.
MATCH (n)
OPTIONAL MATCH (n)-[r]->()
RETURN n, COUNT(r)

//  coefficient:
//    - Measures the degree to which nodes in a graph cluster together.
//    - Calculates the ratio of actual links between neighboring nodes to the maximum possible links.
MATCH (n)
OPTIONAL MATCH (n)-[]-(m)
WITH n, count(distinct m) as neigh
OPTIONAL MATCH (n)-[]-(m)-[r]-(p)-[]-(n)
WITH n, neigh, count(DISTINCT r) as links, (neigh*(neigh-1))/2 as exp_links
WITH n,neigh, links, exp_links,
    CASE WHEN neigh<2 THEN 0 ELSE round(toFloat(links)/exp_links,2) END as cc
RETURN n, neigh, links, exp_links, cc

//  coefficient using triangles count:
//    - Alternative method to compute clustering coefficient.
//    - Calculates the ratio of triangles connected to a node to the maximum possible triangles.
MATCH (a)
OPTIONAL MATCH (a)--(b)
WITH a, count(distinct b) as deg
OPTIONAL MATCH (a)-[]-(b)-[]-(c)-[]-(a)
WITH a, deg, count(c) as triag, (deg*(deg-1)) as max_e
RETURN a.Name, CASE WHEN deg>1 THEN round(toFloat(triag)/max_e,2) ELSE 0 END as cc2

//  density:
//    - Indicates how dense a graph is by calculating the ratio of actual edges to the maximum possible edges.
MATCH (m)
OPTIONAL MATCH (m)-[r]-()
WITH count(distinct m) as V, count(distinct r) as E
RETURN V,E,tofloat(E) / ((V*(V-1))/2)

// Average path length:
//    - Computes the average length of all shortest paths between pairs of nodes in the graph.
MATCH (start), (end)
WHERE start <> end
MATCH p=shortestPath((start)-[*]-(end))
RETURN avg(length(p)) AS average_path_length

// Diameter:
//    - Determines the maximum length of the shortest paths between pairs of nodes in the graph.
MATCH (start), (end)
WHERE start <> end
MATCH p=shortestPath((start)-[*]-(end))
RETURN max(length(p)) AS diameter

// Recommending Friends/missing links:
// This Cypher query aims to identify missing triplets, which are the edges that, if introduced, could form a triangle in the graph. Specifically, these are the edges that can create a "friends-of-a-friend" relationship, indicating  indirect connections between nodes.
MATCH (a)-[:FOLLOWS]-(x)-[:FOLLOWS]-(b)
WHERE NOT (a)-[:FOLLOWS]-(b)
RETURN a, b

// Assign random weights to each edges
MATCH ()-[r]-()
SET r.weight = toInteger(rand()*100)

// Calculates Weighted Degree: the sum of the weights of all edges incident to that node.
MATCH (m)
OPTIONAL MATCH (m)-[r]-()
WITH m, sum(r.weight) as WeightedDegree, count(r) as Degree
RETURN m.Name, WeightedDegree, 
    CASE WHEN Degree>0 
        THEN WeightedDegree/Degree 
        ELSE 0 
    END as Normalized

// Number of friends/neigbours
MATCH (m)
OPTIONAL MATCH (m)--(f)
RETURN m.Name, count(f)


// Calculate average number of friendsMATCH (m)
OPTIONAL MATCH (m)--(f)
WITH m,f
OPTIONAL MATCH (f)--(ff)
WITH m,count(distinct f) as friends, count(ff) as friends_friends
RETURN m, CASE WHEN friends>1 
    THEN friends_friends/toFloat(friends)
    ELSE 0
    END as average_friends

// Degree distribution: degree of each node along with the count of nodes for each degree.
match (m)
OPTIONAL MATCH (m)-[r]-()
WITH m, count(r) as degree
RETURN degree, count(degree)
ORDER BY degree

