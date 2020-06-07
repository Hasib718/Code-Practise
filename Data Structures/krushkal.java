import java.util.*;

class Edge {
    int u, v, w;

    public Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }

    @Override
    public String toString() {
        return "("+ u +","+ v +","+ w +")";
    }
};

class DisjointSet {
    Map<Integer, Integer> parent = new HashMap<>(), rnk = new HashMap<>();

    public void makeSet(int n) {
        for (int i=0; i<n; i++) {
            parent.put(i, i);
            rnk.put(i, 0);
        }
    }

    private int find(int k) {
        if(parent.get(k) == k) {
            return k;
        }
        return parent.put(k, find(parent.get(k)));
    }

    private void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if(rnk.get(a) > rnk.get(b)) {
            parent.put(b, a);
        } else {
            parent.put(a, b);
        }

        if(rnk.get(a) == rnk.get(b)) {
            rnk.put(b, rnk.get(b)+1);
        }
    }

    public static void KrushkalAlgo(List<Edge> edge, int n) {
        List<Edge> MST = new ArrayList<>();

        DisjointSet ds  = new DisjointSet();
        ds.makeSet(n);

        int cost=0;
        for(Edge x : edge) {
            if(ds.find(x.u) != ds.find(x.v)) {
                System.out.println(x.u + " - " + x.v);

                cost += x.w;
                ds.Union(x.u, x.v);
            }
        }
        System.out.println("Minimum Cost" + cost);
    }
};