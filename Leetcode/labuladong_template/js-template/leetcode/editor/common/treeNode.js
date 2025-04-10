export class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    static createRoot(arr) {
        if (arr.length === 0) {
            return null;
        }
        let root = new TreeNode(arr[0]);
        let queue = [root];
        let index = 1;
        while (index < arr.length) {
            let current = queue.shift();
            if (arr[index] != null) {
                current.left = new TreeNode(arr[index]);
                queue.push(current.left);
            }
            index++;
            if (index < arr.length && arr[index] != null) {
                current.right = new TreeNode(arr[index]);
                queue.push(current.right);
            }
            index++;
        }
        return root;
    }

}
