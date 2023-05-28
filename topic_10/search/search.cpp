#include<queue>
#include<functional>

struct Vertex
{
    char id;
    size_t pathCost;
};

struct Problem
{
    
};
//todo replace with problem
size_t UniformCostSearch(Vertex initial, char goal)
{
    std::priority_queue<Vertex, 
        std::vector<Vertex>, 
        std::function<bool(const Vertex&, const Vertex&)>> frontier([] (const Vertex& a, const Vertex& b) {
        return a.pathCost > b.pathCost;
    });

    frontier.push(initial);

    while(!frontier.empty())
    {
        Vertex curr = frontier.top();
        frontier.pop();

        if(curr.id == goal)
            return curr.pathCost;
        
        for (size_t i = 0; i < arr; i++)
        {
            frontier.push(arr[i]);
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
