class BSTree {
    /**
     * The constructor return a Node of the BSTree
     * @param {*} v An object with a key property and a value property
     */
    constructor(v) {
      this.parent = null;
      this.left = null;
      this.right = null;
      this.value = v.value;
      this.key = v.key;
    }
  
    /**
     * 
     * @param {*} x The starting node, by default is this which is the root of the tree
     * @returns The node with the lowest key value
     */
    min = (x = this) => {
      let node = x;
      while (node.left != null) node = node.left;
      return node;
    };
  
    /**
     * 
     * @param {*} x The starting node, by default is this which is the root of the tree
     * @returns The node with the highest key value
     */
    max = (x = this) => {
      let node = x;
      while (node.right != null) node = node.right;
      return node;
    };
  
    /**
     * 
     * @param {*} x The starting node, by default is this which is the root of the tree
     * @returns The successor node of the given argument
     */
    successor = (x = this) => {
      if (x.right != null) return this.min(x.right);
      let y = x.parent;
      while (y != null && x == y.right) {
        x = y;
        y = x.parent;
      }
      return y;
    };
  
    /**
     * @param {*} x The starting node, by default is this which is the root of the tree
     * @returns The predecessor node of the given argument
     */
    predecessor = (x = this) => {
      if(x.left != null) return this.max(x.left);
      let y = this.parent;
      while(y != null && x == y.left) {
          x = y;
          y = x.parent;
      }
      return y;
    }
  
    /**
     * Add a new Node in tree and keep the order property of a BSTree
     * @param {*} o An object with a key property and a value property
     */
    insert = (o) => {
      let z = new BSTree(o)
      y = null;
      x = this;
      while(x != null) {
          y = x;
          if(z.key < x.key)
              y = x.left
          else
              y = x.right
      }
      z.parent = y
    }
  
  }
  
  module.exports = {
      BinarySearchTree: BSTree
  };
  