# Southern Scholars Camp
## ABOUT
Southern Scholars Camp is a Winter Camp hosted by renowned professors in the Competitive Programming field of Vietnam.\
As a camp participant, I was supposed to apply the knowledge taught by theese professors to solve a certain set of given problems.\
I really hope that the way I approached these problems can help you in solving real-life problems and improve your programming skills.
## Editorial for some problems
- Go school: We will run Dijkstra algorithm on the given graph and the reverse graph to get shortest paths from the boy's house, the boy's school and mom's office to every other places in the map. After that we can just iterate over every places on the map, check if the boy is able to get to school on time and optimize mom's best route if the boy is.
- Color: Let $f(i, j, z)$ be the number of tools we have used in the first $i$ letters for type $z$ and currently have used $j$ over $k$ uses of a tool. This approach using dynamic programming has a time complexity of $O(n * k)$, which is obviously not gonna pass. \
Observing that we need to both minimize the number of tools and the amount used, we can stores both values in $f(i, z)$ thus get the time complexity of $O(n)$.
