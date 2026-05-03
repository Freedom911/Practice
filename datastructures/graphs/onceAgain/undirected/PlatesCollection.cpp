/**
 * Question Asked in Microsoft Interview .Similar to no of components
 * We give three solution. bfs with grid where we use n*n matrix
 * Second we optimize it by hashing the indices
 * Third we use disjoint set
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

void bfs(int startx, int starty, std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &vis, int r, int c)
{
    std::queue<std::pair<int, int>> q;
    q.push({startx, starty});
    vis[startx][starty] = 1;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int tr = grid.size();
    int tc = grid[0].size();

    while (!q.empty())
    {
        std::pair<int, int> topper = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ar = dr[i] + topper.first;
            int ac = dc[i] + topper.second;

            if (ar >= 0 && ar < tr && ac >= 0 && ac < tc && vis[ar][ac] == 0 && grid[ar][ac] == 1)
            {
                q.push({ar, ac});
                vis[ar][ac] = 1;
            }
        }
    }
}

int getMin(int n, int d, std::vector<int> x, std::vector<int> y)
{
    int max_x = 0, max_y = 0;
    for (int i = 0; i < n; i++)
    {
        max_x = std::max(max_x, x[i]);
        max_y = std::max(max_y, y[i]);
    }

    std::vector<std::vector<int>> grid(max_x + 1, std::vector<int>(max_y + 1, 0));
    std::vector<std::vector<int>> vis(max_x + 1, std::vector<int>(max_y + 1, 0));

    for (int i = 0; i < n; i++)
    {
        grid[x[i]][y[i]] = 1;
    }
    int total = 0;
    for (int i = 0; i <= max_x; i++)
    {
        for (int j = 0; j <= max_y; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                bfs(i, j, grid, vis, max_x + 1, max_y + 1);
                total += d;
            }
        }
    }
    return total;
}

void bfsOptimized(int node, std::map<std::pair<int, int>, int> &us,
                  std::map<int, std::pair<int, int>> &us1, std::vector<int> &vis)
{
    std::queue<int> q;
    q.push(node);
    vis[node] = 1;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int topper = q.front();
        q.pop();
        if (us1.find(topper) == us1.end())
        {
            return;
        }
        int xx = us1[topper].first;
        int yy = us1[topper].second;

        for (int i = 0; i < 4; i++)
        {
            int ar = dr[i] + xx;
            int ac = dc[i] + yy;

            if (us.find({ar, ac}) != us.end())
            {
                int acNode = us[{ar, ac}];
                if (vis[acNode] == 0)
                {
                    q.push(acNode);
                    vis[acNode] = 1;
                }
            }
        }
    }
}

int optimized(int n, int d, std::vector<int> x, std::vector<int> y)
{
    // Cell to index
    std::map<std::pair<int, int>, int> us;
    // Index to cell
    std::map<int, std::pair<int, int>> us1;

    for (int i = 0; i < n; i++)
    {
        int xval = x[i];
        int yval = y[i];
        us[{xval, yval}] = i;
        us1[i] = {xval, yval};
    }

    std::vector<int> vis(n, 0);
    int total = 0;

    for (auto it : us1)
    {
        int node = it.first;
        if (vis[node] == 0)
        {
            bfsOptimized(node, us, us1, vis);
            total += d;
        }
    }
    return total;
}

class DisjointSet
{
public:
    DisjointSet(int n)
    {
        IsPartOf.resize(n, 0);
        SizeOf.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            IsPartOf[i] = i;
        }
    }
    int findUP(int node)
    {
        // Base condition
        // This means we have reached the ultimate parent
        if (IsPartOf[node] == node)
        {
            return node;
        }

        // Path Compression
        return IsPartOf[node] = findUP(IsPartOf[node]);
    }

    bool UnionBySize(int u, int v)
    {
        int uPar = findUP(u);
        int vPar = findUP(v);
        if (uPar == vPar)
        {
            return false;
        }
        // Union by size
        if (SizeOf[uPar] > SizeOf[vPar])
        {
            SizeOf[uPar] += SizeOf[vPar];
            IsPartOf[vPar] = IsPartOf[uPar];
        }
        else
        {
            SizeOf[vPar] += SizeOf[uPar];
            IsPartOf[uPar] = IsPartOf[vPar];
        }

        return true;
    }

    const std::vector<int> GetIsPartOf()
    {
        return IsPartOf;
    }

private:
    std::vector<int> IsPartOf;
    std::vector<int> SizeOf;
};

int optimizedDis(int n, int d, std::vector<int> x, std::vector<int> y)
{
    DisjointSet set(n);
    // Cell to index
    std::map<std::pair<int, int>, int> us;
    // Index to cell
    std::map<int, std::pair<int, int>> us1;

    for (int i = 0; i < n; i++)
    {
        int xval = x[i];
        int yval = y[i];
        us[{xval, yval}] = i;
        us1[i] = {xval, yval};
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    for (auto it : us1)
    {
        int node = it.first;

        if (us1.find(node) == us1.end())
        {
            continue;
        }
        int xx = us1[node].first;
        int yy = us1[node].second;

        for (int i = 0; i < 4; i++)
        {
            int ar = dr[i] + xx;
            int ac = dc[i] + yy;

            if (us.find({ar, ac}) != us.end())
            {
                int acNode = us[{ar, ac}];
                if (set.UnionBySize(node, acNode))
                {
                }
            }
        }
        // Total Components
    }
    int total = 0;
    const std::vector<int> PartOf = set.GetIsPartOf();
    for (int i = 0; i < PartOf.size(); i++)
    {
        if (PartOf[i] == i)
        {
            total++;
        }
    }
    return total * d;
}
int main()
{
    std::cout << "\n ANS = " << getMin(4, 1, {0, 0, 1, 2}, {0, 1, 0, 2});
    std::cout << "\n ANS = " << getMin(5, 1, {0, 0, 1, 3, 5}, {1, 0, 0, 0, 2});

    std::cout << "\n OPTIANS = " << optimized(4, 1, {0, 0, 1, 20}, {0, 1, 0, 20});
    std::cout << "\n OPTIANS = " << optimized(5, 1, {0, 0, 1, 3, 5}, {1, 0, 0, 0, 2});

    std::cout << "\n DisOPTIANS = " << optimizedDis(4, 1, {0, 0, 1, 20}, {0, 1, 0, 20});
    std::cout << "\n DisOPTIANS = " << optimizedDis(5, 1, {0, 0, 1, 3, 5}, {1, 0, 0, 0, 2});
}