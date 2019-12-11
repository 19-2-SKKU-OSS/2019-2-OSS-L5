using System;
using System.Collections.Generic;
using System.Linq


public class Tree<K, V> where K : class, IComparable<K> where V: class
{
	private Node<K, V> root;

	public V DepthFirstSearch( K key ){
		Stack<Node<K, V>> stack = new Stack<Node<K, V>>();

		while( stack.Any() ){
			var node = stack.Pop();

			if( node.key == key ) return node.value;

			foreach( var i in node.children ) stack.Push(child)
		}
		return default( V );
	}

	private class Node<K, V> where K: class, IComparable<K> while V: class
	{
		public K key;
		public V value;
		public Node<K, V>[] children;
}
