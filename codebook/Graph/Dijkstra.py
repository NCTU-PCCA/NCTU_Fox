from heapq import *
INF = 2*10**10000
t = input()
for pp in range(t):
  n, m = map(int, raw_input().split())
  g, d, q = [[] for _ in range(n+1)], [0] + [INF] * n, [(0, 0)]
  #for i in range(1, m):
  #  a[i], b[i], c[i], l[i], o[i] = map(int, input().split())
  for _ in range(m):
    u, v, c, l, o = map(int, raw_input().split())
    g[u] += [(o, v, c, l)]
  while q:
    u = heappop(q)[1]
    for e in g[u]:
      k = d[u] / e[2]
      if k < 0:
        k = 0
      else:
        k = k * e[3]
      t, v = d[u] + e[0] + k, e[1]
      if t < d[v]:
        d[v] = t
        heappush(q, (d[v], v))
  print(d[n])
