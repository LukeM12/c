
/*Insertion to a binary tree iteratively */
public void Insert(int value)
{        
    TreeNode current = this;
    while (current != null)
    {
        if(current.Data < value)         
            if(current.LeftNode == null) 
            { current.LeftNode = new TreeNode(value); break; }
            else current = current.LeftNode;            
        else 
            if(current.RightNode == null) 
            { current.RightNode = new TreeNode(value); break; }
            else current = current.RightNode;                            
    }
}


/*Insertion to a binary tree recursively*/

//C sharp here is A NODE


public class Node<T>
{
        // Private member-variables
        private T data;
        private NodeList<T> neighbors = null;

        public Node() {}
        public Node(T data) : this(data, null) {}
        public Node(T data, NodeList<T> neighbors)
        {
            this.data = data;
            this.neighbors = neighbors;
        }

        public T Value
        {
            get
            {
                return data;
            }
            set
            {
                data = value;
            }
        }

        protected NodeList<T> Neighbors
        {
            get
            {
                return neighbors;
            }
            set
            {
                neighbors = value;
            }
        }
    }


