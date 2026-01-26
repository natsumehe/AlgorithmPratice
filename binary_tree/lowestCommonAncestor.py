class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncesstor(self, root, p, q):

        if root is None or q == root or p == root:
            return root
        
        left = self.lowestCommonAncesstor(root.left, p ,q)
        right = self.lowestCommonAncesstor(root.right, p ,q)

        if left and right:
            return root
        
        return left if  left else right
    
def createtree():
    

    nodes = {i : TreeNode(i) for i in [3, 5, 1 , 6 ,7, 2, 0, 8, 4]}

    nodes[3].left = nodes[5]
    nodes[3].right = nodes[1]

    nodes[5].left = nodes[6]
    nodes[5].right = nodes[2]

    nodes[6].left = nodes[7]
    nodes[6].right = nodes[4]

    nodes[1].left = nodes[0]
    nodes[1].right = nodes[8]

    return nodes
    
def main():
    nodes = createtree()
    root = nodes[3]

    q = nodes[5]
    p = nodes[1]

    sol = Solution()
    lca = sol.lowestCommonAncesstor(root, p, q)
    print(f"lca of {p.val} and {q.val} is: {lca.val}")

    q = nodes[6]
    p = nodes[4]
    print(f"lca of {p.val} and {q.val} is: {lca.val}")

if __name__ == "__main__":
    main()




        
        