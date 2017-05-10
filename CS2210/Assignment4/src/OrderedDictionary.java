/**
 * OrderedDictionary
 * @author Yimin Xu 250876566
 *
 */
public class OrderedDictionary implements OrderedDictionaryADT 
{
	
	//Tree nodes
	private class node
	{
		private Record elem;
		private node left;
		private node right;
		private node parent;
		
		//Constructor
		private node()
		{
			elem = null;
			left = null;
			right = null;
			parent = null;
		}
		
		//Constructor 
		private node(Record element)
		{
			elem = element;
			left = null;
			right = null;
			parent = null;
		}
		
		//Return the record element of the node
		private Record getElem()
		{
			return elem;
		}
		
		//Return the left child of the node
		private node getLeft()
		{
			return left;
		}
		
		//Return the right child of the node
		private node getRight()
		{
			return right;
		}
		
		//Return the parent of the node
		private node getParent()
		{
			return parent;
		}
		
		//Set the left child of the node
		private void setLeft(node newLeft)
		{
			left = newLeft;
			if (newLeft != null)
				newLeft.setParent(this);
		}
		
		//Set the right child of the node
		private void setRight(node newRight)
		{
			right = newRight;
			if (newRight != null)
				newRight.setParent(this);
		}
		
		//Set the parent of the node
		private void setParent(node newPar)
		{
			parent = newPar;
		}
		
		//Set the record element of the node
		private void setElem(Record newElem)
		{
			elem = newElem;
		}
		
		//Helpful method to find the largest node  
		private node findLargest()
		{
			if (right.isLeaf())
				return this;
			else
				return (right.findLargest());
		}

		
		//Helpful method to find the record with key k 
		//With this method we can use recursion instead of putting too much code in the find method in dictionary
		private Record find(Key k)
		{
			if (elem == null)
				return null;
			
			if (elem.getKey().compareTo(k) == 0)
				return elem;
			else if (isLeaf())
				return null;
			else if (elem.getKey().compareTo(k) < 0)
				return right.find(k);
			else return left.find(k);
		}
		
		//Return whether the node is a leaf (null element)
		private boolean isLeaf()
		{
			if (elem == null)
				return true;
			else 
				return false;
		}
		
	}
	
	private node root;
	
	//Constructor
	public OrderedDictionary(){}
	
	//Use the find method of the node to find the record with key k
	public Record find(Key k) 
	{
		return root.find(k);
	}

	//Insert record r
	//If there is a record that has the same key, throw an exception
	public void insert(Record r) throws DictionaryException 
	{
		//If the tree is empty, make it the root
		if (root == null)
		{
			root = new node(r);
			root.setLeft(new node());
			root.setRight(new node());
			return;
		}
		
		node target = root;
		
		//Find an appropriate leaf to insert the record
		while (!target.isLeaf())
		{
			if (target.getElem().getKey().compareTo(r.getKey()) == 0)
			{
				throw new DictionaryException("Insert error");
			}
			if (target.getElem().getKey().compareTo(r.getKey()) < 0)
				target = target.getRight();
			else target = target.getLeft();
		}
		
		target.setElem(r);
		target.setLeft(new node());
		target.setRight(new node());
	}
	
	//Remove the record with key k (I might have made it too complicated)
	public void remove(Key k) throws DictionaryException 
	{
		//If the tree is null or the root is empty, throw exception 
		if (root == null)
				throw new DictionaryException("Remove error");
		
		if (root.getElem() == null)
				throw new DictionaryException("Remove error");
		
		node target = root;
		
		//Try to find the target node, if found the leaf, throw exception
		//Use a boolean variable to record whether target is the left or right child of its parent
		boolean isLeft = true;
		while (target.getElem().getKey().compareTo(k) != 0)
		{
			if (target.getElem().getKey().compareTo(k) < 0)
			{
				if (target.getRight().getElem() == null)
					throw new DictionaryException("Remove error");
				target = target.getRight();
				isLeft = false;
			}else if (target.getElem().getKey().compareTo(k) > 0)
			{
				if (target.getLeft().getElem() == null)
					throw new DictionaryException("Remove error");
				target = target.getLeft();
				isLeft = true;
			}
		}
		
		//Target to be removed has no child
		if (target.getLeft().getElem() == null && target.getRight().getElem() == null)
		{
			//If no parent, the whole tree would be empty
			if (target.getParent() == null)
				root = null;
			else if (isLeft)
				target.getParent().setLeft(new node());
			else target.getParent().setRight(new node());
		
		//Left child is not null and right child is null
		}else if (target.getLeft().getElem() != null && target.getRight().getElem() == null)
		{
			if (target.getParent() == null)
				root = root.getLeft();
			else if (isLeft)
				target.getParent().setLeft(target.getLeft());
			else
				target.getParent().setRight(target.getLeft());
		
		//Left child is null and right child is not null
		}else if (target.getLeft().getElem() == null && target.getRight().getElem() != null)
		{
			if (target.getParent() == null)
				root = root.getRight();
			else if (isLeft)
				target.getParent().setLeft(target.getRight());
			else
				target.getParent().setRight(target.getRight());
			
		//Both children are not null
		}else 
		{
			//Replace the target with the largest node in its left tree
			node rep = target.getLeft().findLargest();
			if (rep.equals(target.getLeft()))
			{
				rep.setRight(target.getRight());
				if (target.getParent() == null)
					root = rep;
				else
					rep.setParent(target.getParent());
			}else
			{
				rep.setLeft(target.getLeft());
				rep.setRight(target.getRight());
				rep.getParent().setRight(new node());
				if (target.getParent() == null)
				{
					root = rep;
				}else
					rep.setParent(target.getParent());
			}
		}
	}
	
	//Return the record with smallest key larger than k
	//If there is no record with key larger than k or target node with key k is not found, return null
	public Record successor(Key k) 
	{
		node target = root;
		
		//Find the target with key k, and add every node above the target into an array
		//We don't know the size of the tree, but 1000 should be enough for the array (or not?)
		int i = 0;
		Record[] recList = new Record[1000];
		while (target.getElem().getKey().compareTo(k) != 0)
		{
			if (target.getElem().getKey().compareTo(k) < 0)
			{
				recList[i] = target.getElem();
				i++;
				target = target.getRight();
			}
			else 
			{
				recList[i] = target.getElem();
				i++;
				target = target.getLeft();
			}
			if (target.getElem() == null)
				return null;
		}
		
		//If the target has right child, the right child would be its successor
		if (target.getRight().getElem() != null)
			return target.getRight().getElem();
		else
		{
			//If there is no right child (I mean no right child that is not leaf), find the successor in the array
			for (int j = i - 1; j >= 0; j --)
			{
				if (recList[j].getKey().compareTo(k) > 0)
					return recList[j];
			}
			
			return null;
		}
	}
	
	//Return the record with largest key smaller than k
	//Same thing like above
	public Record predecessor(Key k) 
	{
		node target = root;
		
		int i = 0;
		Record[] recList = new Record[1000];
		while (target.getElem().getKey().compareTo(k) != 0)
		{
			if (target.getElem().getKey().compareTo(k) < 0)
			{
				recList[i] = target.getElem();
				i++;
				target = target.getRight();
			}
			else 
			{
				recList[i] = target.getElem();
				i++;
				target = target.getLeft();
			}
			if (target.getElem() == null)
				return null;
		}
		
		if (target.getLeft().getElem() != null)
			return target.getLeft().getElem();
		else
		{
			for (int j = i - 1; j >= 0; j --)
			{
				if (recList[j].getKey().compareTo(k) < 0)
					return recList[j];
			}
			
			return null;
		}
	}

	//Return the record with smallest key in the tree
	public Record smallest() 
	{
		node smallest = root;
		while (!smallest.getLeft().isLeaf())
			smallest = smallest.getLeft();
		
		return smallest.getElem();
	}

	//Return the record with largest key in the tree
	public Record largest() 
	{
		node largest = root;
		while (!largest.getRight().isLeaf())
			largest = largest.getRight();
		
		return largest.getElem();
	}
}
