
using System.Collections.Generic;

class BaseNode
{
    private List<BaseNode> children = new List<BaseNode>();

    public void AddChild( BaseNode child )
    {
        children.Add(child);
    }

    public void ShowChildren()
    {
        foreach (var child in children )
        {
            child.Log();
        }
    }

    protected virtual void Log(){}
}